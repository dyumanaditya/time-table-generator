#include "time-table-generator/time_table_generator.h"
#include "time-table-generator/sections.h"
#include "time-table-generator/courses.h"

#include <iostream>
#include <algorithm>
#include <random>


TimeTableGenerator::TimeTableGenerator(std::string teacher_data_path, std::string student_data_path)
{
    teachers = csv_parser.parseTeacherData(teacher_data_path);
    students = csv_parser.parseStudentData(student_data_path);

}

TimeTableGenerator::~TimeTableGenerator()
{
}

void TimeTableGenerator::generateTimeTable()
{
    // Initial setup for metrics and classes etc
    setNumStudentsSection();
    initClasses();
    populateClassMatrix();
    sortClassMatrix();
    removeRedundantClasses();

    // Start the algo
    fillPeriods();

    while (!programCompleted())
    {
        int random_period = generateRandomPeriod();
        bool result = fixClass(random_period, 0);
        sortClassMatrix();
    }

    std::cout << "complete" << std::endl;
    printTimetable();
}

void TimeTableGenerator::populateClassMatrix()
{
    // Store the classes in class matrix according to teachers free periods
    for (auto &c : classes)
    {
        for (int free_period : c.teacher->getFreePeriods())
        {
            class_matrix[free_period].push_back(&c);
        }
    }
}    

void TimeTableGenerator::setNumStudentsSection()
{
    // Initialize all data so that we can calculate metrics easily
    // First set the students who want to do a teacher's class in the Teacher object
    // num_students_{section} variable
    for (auto &teacher : teachers)
    {
        for (auto &teacher_course : teacher->courses)
        {
            int num_students_k1 = 0;
            int num_students_k2 = 0;
            int num_students_k3 = 0;

            for (auto &student : students)
            {
                for (auto &student_course : student->courses)
                {
                    // If the student is taking this particular course then proceed
                    if (std::get<0>(student_course) == teacher_course.first && std::get<1>(student_course) == teacher->getName())
                    {
                        switch (student->getSection())
                        {
                        case Sections::K1:
                        {
                            num_students_k1 += 1;
                            break;
                        }
                        case Sections::K2:
                        {
                            num_students_k2 += 1;
                            break;
                        }
                        case Sections::K3:
                        {
                            num_students_k3 += 1;
                            break;
                        }
                        }
                    }
                }
            }
            teacher->setNumStudents(Sections::K1, teacher_course.first, num_students_k1);
            teacher->setNumStudents(Sections::K2, teacher_course.first, num_students_k2);
            teacher->setNumStudents(Sections::K3, teacher_course.first, num_students_k3);
        }
    }
}


void TimeTableGenerator::initClasses()
{
    // Set up all the available classes by going through the teachers
    for (auto &teacher : teachers)
    {
        for (auto &course : teacher->courses)
        {
            Class c;
            c.course = course.first;
            c.science = course.second;
            c.teacher = teacher;
            classes.push_back(c);
        }
    }

    // Set up the students in the classes by going through the students
    for (auto &student : students)
    {
        for (auto &course : student->courses)
        {
            for (auto &c : classes)            {
                // If the class' course and teacher is correct
                if (c.course == std::get<0>(course) and c.teacher->getName() == std::get<1>(course))
                {
                    c.students[student->getSection()].push_back(student);

                    // Update class max periods if necessary
                    if (c.max_num_periods[student->getSection()] < std::get<2>(course))
                    {
                        c.max_num_periods[student->getSection()] = std::get<2>(course);
                    }
                }
            }
        }
    }
}


void TimeTableGenerator::sortClassMatrix()
{
    // Start by calculating metric for each class
    for (auto &c : classes)
    {
        // Number describing the number of classes the teacher will take. If non science this will be approximated by:
        // class_periods = [max_periods_k1 + max_periods_k2 + max_periods_k3]
        float class_periods;
        if (c.science)
        {
            class_periods = fixed_period_courses[c.course] * 3;
        }
        else
        {
            class_periods = c.max_num_periods[Sections::K1] + c.max_num_periods[Sections::K2] + c.max_num_periods[Sections::K3];
        }

        float teacher_availability = class_periods / (float)c.teacher->getFreePeriods().size();
        float student_demand = (float)(c.teacher->getNumStudents(Sections::K1, c.course) + c.teacher->getNumStudents(Sections::K2, c.course) + c.teacher->getNumStudents(Sections::K3, c.course)) / 3.0;
        c.metric = teacher_availability * student_demand;
//        c.print();
//        std::cout << "class_periods: " << class_periods << std::endl;
//        std::cout << "teacher_availability: " << teacher_availability << std::endl;
//        std::cout << "student_demand: " << student_demand << std::endl << std::endl;
    }

    // Now sort the courses based on metric calculated
    for (auto & [key, val] : class_matrix)
    {
        std::sort(val.begin(), val.end(), [](Class *c1, Class *c2) {return c1->metric > c2->metric;});
    }
}


void TimeTableGenerator::fillPeriods()
{
    periods.clear();
    for (int i=1; i<=42; ++i)
    {
        periods.push_back(i);
    }
}


int TimeTableGenerator::generateRandomInt(int lower, int upper)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution dist(lower, upper);
    return dist(gen);
}


int TimeTableGenerator::generateRandomPeriod()
{
    if (periods.size()==0)
    {
        fillPeriods();
    }
    int lower = 0;
    int upper = periods.size()-1;
    int rand_int = generateRandomInt(lower, upper);
    int period = periods[rand_int];
    periods.erase(periods.begin()+rand_int);
    return period;
}


void TimeTableGenerator::removeRedundantClasses()
{
    for (auto & [period, class_vector] : class_matrix)
    {
        for (int i=0; i<class_vector.size(); ++i)
        {
            if (class_vector[i]->metric == 0.0)
            {
                class_vector.resize(i);
                break;
            }
        }
    }
}


bool TimeTableGenerator::fixClass(int period, int class_position)
{
    // Variables describing which classes failed
    bool k1_success = true;
    bool k2_success = true;
    bool k3_success = true;

    // Check if there are available classes in this period
    if (class_matrix.contains(period))
    {
//        std::cout << getPeriodFromNumber(period) << std::endl;
        // Make sure there are classes in the period
        if (class_matrix[period].size()>class_position)
        {
            // FOR K1
            // Make sure this class has not already been fixed
            if (!class_matrix[period][class_position]->k1_fixed)
            {
                // Make sure each K1 student is free in this period
                for (Student* student : class_matrix[period][class_position]->students[Sections::K1])
                {
                    if (!student->isFree(period))
                    {
                        k1_success = false;
                        break;
                    }

                }
            }
            // Otherwise the class has already been fixed for k1
            else
            {
                k1_success = false;
            }

            // FOR K2
            // Make sure this class has not already been fixed
            if (!class_matrix[period][class_position]->k2_fixed)
            {
                // Make sure each K2 student is free in this period
                for (Student* student : class_matrix[period][class_position]->students[Sections::K2])
                {
                    if (!student->isFree(period))
                    {
                        k2_success = false;
                        break;
                    }

                }
            }
            // Otherwise the class has already been fixed for k1
            else
            {
                k2_success = false;
            }

            // FOR K3
            // Make sure this class has not already been fixed
            if (!class_matrix[period][class_position]->k3_fixed)
            {
                // Make sure each K3 student is free in this period
                for (Student* student : class_matrix[period][class_position]->students[Sections::K3])
                {
                    if (!student->isFree(period))
                    {
                        k3_success = false;
                        break;
                    }

                }
            }
            // Otherwise the class has already been fixed for k1
            else
            {
                k3_success = false;
            }
        }
        // There are no more classes that can be fixed
        else
        {
            return false;
        }
    }
    // Return successfully if the period is not there in the class_matrix
    else
    {
        return true;
    }

    // If all have failed, then call the fixClass function again with class_position + 1
    if (!k1_success && !k2_success && !k3_success)
    {
        fixClass(period, class_position+1);
    }
    // Fix class for k1
    else if (k1_success)
    {
        std::cout << "Fixing for k1" << std::endl;
        time_table[period].push_back(class_matrix[period][class_position]);
        class_matrix[period].erase(class_matrix[period].begin()+class_position);
        // Remove the free period from student and teacher
        for (Student* student : class_matrix[period][class_position]->students[Sections::K1])
        {
            student->removeFreePeriod(period);
        }
        class_matrix[period][class_position]->teacher->removeFreePeriod(period);
    }
    // Fix class for k2
    else if (k2_success)
    {
        std::cout << "Fixing for k2" << std::endl;
        time_table[period].push_back(class_matrix[period][class_position]);
        class_matrix[period].erase(class_matrix[period].begin()+class_position);
        // Remove the free period from student and teacher
        for (Student* student : class_matrix[period][class_position]->students[Sections::K2])
        {
            student->removeFreePeriod(period);
        }
        class_matrix[period][class_position]->teacher->removeFreePeriod(period);
    }
    // Fix class for k3
    else if (k3_success)
    {
        std::cout << "Fixing for k3" << std::endl;
        time_table[period].push_back(class_matrix[period][class_position]);
        class_matrix[period].erase(class_matrix[period].begin()+class_position);
        // Remove the free period from student and teacher
        for (Student* student : class_matrix[period][class_position]->students[Sections::K3])
        {
            student->removeFreePeriod(period);
        }
        class_matrix[period][class_position]->teacher->removeFreePeriod(period);
    }
}


bool TimeTableGenerator::programCompleted()
{
    bool result = true;
    for (int i=1; i<=42; ++i)
    {
        result = result && class_matrix[i].empty();
    }
    return result;
}

void TimeTableGenerator::printTimetable()
{
    for (int i=1; i<=42; ++i)
    {
//        std::cout << class_matrix[i].size() << std::endl;
        for (int j=0; j<class_matrix[i].size(); ++j)
        {
            std::cout << getPeriodFromNumber(i) << std::endl;
            std::cout << class_matrix[i][j]->course << " " << class_matrix[i][j]->teacher->getName() << " ";
            for (auto &student : class_matrix[i][j]->students[Sections::K3])
            {
                std::cout << student->getName();
            }
            std::cout << std::endl;
        }
    }
}

std::string TimeTableGenerator::getPeriodFromNumber(int period)
{
    std::string result;
    int day = (period-1)/7;
    switch (day)
    {
    case 0:
    {
        result = "Monday: ";
        break;
    }
    case 1:
    {
        result = "Tuesday: ";
        break;
    }
    case 2:
    {
        result = "Wednesday: ";
        break;
    }
    case 3:
    {
        result = "Thursday: ";
        break;
    }
    case 4:
    {
        result = "Friday: ";
        break;
    }
    case 5:
    {
        result = "Saturday: ";
        break;
    }
    }

    result += std::to_string(period - 7*day);
    return result;
}



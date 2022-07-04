#include "time-table-generator/time_table_generator.h"
#include "time-table-generator/sections.h"
#include "time-table-generator/courses.h"

#include <iostream>
#include <algorithm>

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
    initClasses();
    populateClassMatrix();
    setNumStudentsSection();
    sortClassMatrix();
    for (auto c : class_matrix[1])
    {
        c.print();
    }
}

void TimeTableGenerator::populateClassMatrix()
{
    // Store the classes in class matrix according to teachers free periods
    for (auto c : classes)
    {
        for (int free_period : c.teacher->getFreePeriods())
        {
            class_matrix[free_period].push_back(c);
        }
    }
}    

void TimeTableGenerator::setNumStudentsSection()
{
    // Initialize all data so that we can calculate metrics easily
    // First set the students who want to do a teacher's class in the Teacher object
    // num_students_{section} variable
    for (auto teacher : teachers)
    {
        int num_students_k1 = 0;
        int num_students_k2 = 0;
        int num_students_k3 = 0;
        for (auto student : students)
        {
            for (auto course : student->courses)
            {
                if (std::get<1>(course) == teacher->getName())
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

            // After going through all the students, set the number in Teacher object
            teacher->setNumStudents(Sections::K1, num_students_k1);
            teacher->setNumStudents(Sections::K2, num_students_k2);
            teacher->setNumStudents(Sections::K3, num_students_k3);
        }
     }
}


void TimeTableGenerator::initClasses()
{
    // Set up all the available classes by going through the teachers
    for (auto teacher : teachers)
    {
        for (auto course : teacher->courses)
        {
            Class c;
            c.course = course.first;
            c.science = course.second;
            c.teacher = teacher;
            classes.push_back(c);
        }
    }

    // Set up the students in the classes by going through the students
    for (auto student : students)
    {
        for (auto course : student->courses)
        {
            for (auto c : classes)
            {
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
    for (auto c : classes)
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
        float student_demand = (c.teacher->getNumStudents(Sections::K1) + c.teacher->getNumStudents(Sections::K2) + c.teacher->getNumStudents(Sections::K3)) / 3;
        std::cout << teacher_availability << std::endl;
        std::cout << student_demand << std::endl;
        c.metric = teacher_availability * student_demand;
    }

    // Now sort the courses based on metric calculated
    for (auto & [key, val] : class_matrix)
    {
        std::sort(val.begin(), val.end(), [](Class &c1, Class &c2) {return c1.metric < c2.metric;});
    }
}

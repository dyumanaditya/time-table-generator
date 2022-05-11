#include "time-table-generator/time_table_generator.h"
#include "time-table-generator/sections.h"

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
    setTeacherAvailability();
    initClasses();
}

void TimeTableGenerator::setTeacherAvailability()
{
    // Store the teachers in the availability matrix
    for (int i=0; i<teachers.size(); ++i)
    {
        for (int free_period : teachers[i]->getFreePeriods())
        {
            teacher_availability[free_period].push_back(teachers[i]);
        }
    }
}    

void TimeTableGenerator::sortTeacherAvailability()
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

    // Find max_periods for students

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

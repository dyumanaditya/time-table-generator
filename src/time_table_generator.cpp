#include "time-table-generator/time_table_generator.h"
#include "time-table-generator/sections.h"

#include <iostream>
#include <algorithm>

TimeTableGenerator::TimeTableGenerator(std::string teacher_data_path, std::string student_data_path)
{
    teachers = csv_parser.parse_teacher_data(teacher_data_path);
    students = csv_parser.parse_student_data(student_data_path);

}

TimeTableGenerator::~TimeTableGenerator()
{
}

void TimeTableGenerator::generateTimeTable()
{
    set_teacher_availability();
}

void TimeTableGenerator::set_teacher_availability()
{
    for (int i=0; i<teachers.size(); ++i)
    {
        for (int free_period : teachers[i]->get_free_periods())
        {
            teacher_availability[free_period] = teachers[i];
        }
    }
}    

void TimeTableGenerator::sort_teacher_availability()
{
    // Initialize all data so that we can calculate metrics easily
    // First set the students who want to do a teacher's class in the Teacher object
    for (auto teacher : teachers)
    {
        int num_students_k1 = 0;
        int num_students_k2 = 0;
        int num_students_k3 = 0;
        for (auto student : students)
        {
            for (auto course : student->courses)
            {
                if (std::get<1>(course) == teacher->get_name())
                {
                    switch (student->get_section())
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
            teacher->set_num_students(Sections::K1, num_students_k1);
            teacher->set_num_students(Sections::K2, num_students_k2);
            teacher->set_num_students(Sections::K3, num_students_k3);
        }
     }

    // Find max_periods for students
    for (auto teacher : teachers)
    {
        int max_periods_k1 = 0;
        int max_periods_k2 = 0;
        int max_periods_k3 = 0;
        for (auto student : students)
        {
            for (auto course : student->courses)
            {
                if (std::get<1>(course) == teacher->get_name() && (std::find(Science_Courses.begin(), Science_Courses.end(), Science_Courses.size()) == Science_Courses.end()))
                {
                    switch (student->get_section())
                    {
                    case Sections::K1:
                    {
                        if(max_periods_k1 < std::get<2>(course))
                            max_periods_k1 = std::get<2>(course);
                        break;
                    }
                    case Sections::K2:
                    {
                        if(max_periods_k2 < std::get<2>(course))
                            max_periods_k2 = std::get<2>(course);
                        break;
                    }
                    case Sections::K3:
                    {
                        if(max_periods_k3 < std::get<2>(course))
                            max_periods_k3 = std::get<2>(course);
                        break;
                    }
                    }
                }
            }
        }
    }
}

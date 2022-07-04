#include "time-table-generator/csv_parser.h"
#include "time-table-generator/days.h"
#include "time-table-generator/sections.h"
#include "time-table-generator/utils.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>


CSVParser::CSVParser()
{
}

CSVParser::~CSVParser()
{
}

std::vector<Teacher*> CSVParser::parseTeacherData(std::string teacher_data_path)
{
    std::vector<Teacher*> teachers;
    std::ifstream stream(teacher_data_path);
    std::string line;

    // Get first line and ignore
    std::getline(stream, line);

    std::getline(stream, line);
    while (line.size()!=0)
    {
        // Process data
        std::vector<std::string> data;
        std::string data_field;
        std::stringstream data_stream(line);
        while (std::getline(data_stream, data_field, ','))
        {
            data.push_back(data_field);
        }

        // Place data inside teacher object
        Teacher* teacher = new Teacher;
        teacher->setName(data[0]);
        teacher->setEmail(data[1]);
        teacher->setPhone(data[2]);

        int num_courses = std::stoi(data[3]);
        for (int i=0; i<num_courses; ++i)
        {
            teacher->addCourse(data[4+i], utils::isScience(data[4+i]));
        }

        for (int i=0; i<6; ++i)
        {
            std::string free_period;
            std::stringstream free_periods(data[4+num_courses+i]);
            while (std::getline(free_periods, free_period, ';'))
            {
                teacher->addFreePeriod((Days)i, std::stoi(free_period));
            }

        }

        for (int i=0; i<3; ++i)
        {
            if (data[4+num_courses+6+i]=="yes")
            {
                teacher->addSection((Sections)i);
            }
        }

        teachers.push_back(teacher);

        // Go to next line
        std::getline(stream, line);
    }

    return teachers;
}

std::vector<Student*> CSVParser::parseStudentData(std::string student_data_path)
{
    std::vector<Student*> students;
    std::ifstream stream(student_data_path);
    std::string line;

    // Get first line and ignore
    std::getline(stream, line);

    std::getline(stream, line);
    while (line.size()!=0)
    {
        // Process data
        std::vector<std::string> data;
        std::string data_field;
        std::stringstream data_stream(line);
        while (std::getline(data_stream, data_field, ','))
        {
            data.push_back(data_field);
        }

        // Place data inside teacher object
        Student* student = new Student;
        student->setName(data[0]);

        if (data[1]=="K1")
            student->setSection(Sections::K1);
        else if (data[1]=="K2")
            student->setSection(Sections::K2);
        else if (data[1]=="K3")
            student->setSection(Sections::K3);

        student->setEmail(data[2]);
        student->setPhone(data[3]);

        int num_courses = std::stoi(data[4]);
        for (int i=0; i<num_courses; ++i)
        {
            // Process ; delimited data
            std::string course_teacher_periods = data[5+i];
            std::vector<std::string> course_teacher_periods_vec;
            std::string course_teacher_periods_data_field;
            std::stringstream course_teacher_periods_data_stream(course_teacher_periods);
            while (std::getline(course_teacher_periods_data_stream, course_teacher_periods_data_field, ';'))
            {
                course_teacher_periods_vec.push_back(course_teacher_periods_data_field);
            }
            student->addCourse(course_teacher_periods_vec[0], course_teacher_periods_vec[1], std::stoi(course_teacher_periods_vec[2]));
        }

        students.push_back(student);

        // Go to next line
        std::getline(stream, line);
    }

    return students;
}

#include "include/csv_parser.h"
#include "include/days.h"
#include "include/sections.h"

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

std::vector<Teacher>* CSVParser::parse_teacher_data(std::string teacher_data_path)
{
    std::vector<Teacher>* teachers = new std::vector<Teacher>;
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
        Teacher teacher;
        teacher.set_name(data[0]);
        teacher.set_email(data[1]);
        teacher.set_phone(data[2]);

        int num_courses = std::stoi(data[3]);
        for (int i=0; i<num_courses; ++i)
        {
            teacher.add_course(data[4+i]);
        }

        for (int i=0; i<6; ++i)
        {
            std::string free_period;
            std::stringstream free_periods(data[4+num_courses+i]);
            while (std::getline(free_periods, free_period, ';'))
            {
                teacher.add_free_period((Days)i, std::stoi(free_period));
            }

        }

        for (int i=0; i<3; ++i)
        {
            if (data[4+num_courses+6+i]=="yes")
            {
                teacher.add_section((Sections)i);
            }
        }

        teacher.print();
        teachers->push_back(teacher);

        // Go to next line
        std::getline(stream, line);
    }

    return teachers;
}

std::vector<Student>* CSVParser::parse_student_data(std::string student_data_path)
{
    std::vector<Student>* students = new std::vector<Student>;
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
        Student student;
        student.set_name(data[0]);

        if (data[1]=="K1")
            student.set_section(Sections::K1);
        else if (data[1]=="K2")
            student.set_section(Sections::K2);
        else if (data[1]=="K3")
            student.set_section(Sections::K3);

        student.set_email(data[2]);
        student.set_phone(data[3]);

        int num_courses = std::stoi(data[4]);
        for (int i=0; i<num_courses; ++i)
        {
            std::string course_and_periods = data[5+i];
            std::size_t delim_pos = course_and_periods.find(";");
            std::string course = course_and_periods.substr(0, delim_pos);
            std::string periods = course_and_periods.substr(delim_pos+1);
            student.add_course(course, std::stoi(periods));
        }



        student.print();
        students->push_back(student);

        // Go to next line
        std::getline(stream, line);
    }

    return students;
}

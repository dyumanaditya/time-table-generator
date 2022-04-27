#include "time-table-generator/student.h"

#include <iostream>

Student::Student()
{
}

Student::~Student()
{
}

void Student::set_name(std::string name)
{
    Student::name = name;
}

void Student::set_phone(std::string phone)
{
    Student::phone = phone;
}

void Student::set_email(std::string email)
{
    Student::email = email;
}

void Student::set_section(Sections section)
{
    Student::section = section;
}

void Student::add_course(std::string course_name, std::string teacher_name, int periods)
{
    Student::courses.push_back(std::tuple<std::string, std::string, int>(course_name, teacher_name, periods));
}


void Student::print()
{
    std::cout << "Contact Details:" << std::endl;
    std::cout << name << std::endl;
    std::cout << email << std::endl;
    std::cout << phone << std::endl;
    switch (section)
    {
    case Sections::K1:
        std::cout << "K1" << std::endl;
        break;
    case Sections::K2:
        std::cout << "K2" << std::endl;
        break;
    case Sections::K3:
        std::cout << "K3" << std::endl;
        break;
    }
    std::cout << "Courses Taking & Number of periods:" << std::endl;
    for (auto course : courses)
    {
        std::cout << course.first << " - " << course.second << std::endl;
    }
}


std::string Student::get_name()
{
    return name;
}

Sections Student::get_section()
{
    return section;
}

std::string Student::get_email()
{
    return email;
}

std::string Student::get_phone()
{
    return phone;
}


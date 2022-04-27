#include "time-table-generator/teacher.h"

#include <iostream>

Teacher::Teacher()
{
}

Teacher::~Teacher()
{
}

void Teacher::set_name(std::string name)
{
    Teacher::name = name;
}

void Teacher::set_phone(std::string phone)
{
    Teacher::phone = phone;
}

void Teacher::set_email(std::string email)
{
    Teacher::email = email;
}

void Teacher::add_free_period(Days day, int period)
{
    free_periods.push_back((day)*7 + period);
}

void Teacher::add_course(std::string course)
{
    courses.push_back(course);
}

void Teacher::add_section(Sections section)
{
    sections.push_back(section);
}

void Teacher::set_num_students(Sections section, int num)
{
    switch (section)
    {
    case Sections::K1:
    {
        num_students_k1 = num;
        break;
    }

    case Sections::K2:
    {
        num_students_k2 = num;
        break;
    }
    case Sections::K3:
    {
        num_students_k3 = num;
        break;
    }
    }
}

void Teacher::print()
{
    std::cout << "Contact Details:" << std::endl;
    std::cout << name << std::endl;
    std::cout << email << std::endl;
    std::cout << phone << std::endl;
    std::cout << "Courses Taking:" << std::endl;
    for (auto course : courses)
    {
        std::cout << course << std::endl;
    }
    std::cout << "Free Periods:" << std::endl;
    for (auto free_period : free_periods)
    {
        std::cout << free_period << ", ";
    }
    std::cout << std::endl << "Sections Taking:" << std::endl;
    for (auto section : sections)
    {
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
    }
}

std::string Teacher::get_name()
{
    return name;
}

std::string Teacher::get_phone()
{
    return phone;
}

std::string Teacher::get_email()
{
    return email;
}

std::vector<int> Teacher::get_free_periods()
{
    return free_periods;
}

int Teacher::get_num_students(Sections section)
{
    switch (section)
    {
    case Sections::K1:
    {
        return num_students_k1;
        break;
    }

    case Sections::K2:
    {
        return num_students_k2;
        break;
    }
    case Sections::K3:
    {
        return num_students_k3;
        break;
    }
    }
}

#include "include/teacher.h"

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

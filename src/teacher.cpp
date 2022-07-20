#include "time-table-generator/teacher.h"

#include <iostream>

Teacher::Teacher()
{
}

Teacher::~Teacher()
{
}

void Teacher::setName(std::string name)
{
    Teacher::name = name;
}

void Teacher::setPhone(std::string phone)
{
    Teacher::phone = phone;
}

void Teacher::setEmail(std::string email)
{
    Teacher::email = email;
}

void Teacher::addFreePeriod(Days day, int period)
{
    free_periods.push_back((day)*7 + period);
}

void Teacher::addCourse(std::string course, bool is_science)
{
    courses.push_back(std::make_pair(course, is_science));
}

void Teacher::addSection(Sections section)
{
    sections.push_back(section);
}

void Teacher::setNumStudents(Sections section, std::string course, int num)
{
    num_students[section][course] = num;
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
        std::cout << course.first << std::endl;
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

std::string Teacher::getName()
{
    return name;
}

std::string Teacher::getPhone()
{
    return phone;
}

std::string Teacher::getEmail()
{
    return email;
}

std::vector<int> Teacher::getFreePeriods()
{
    return free_periods;
}

int Teacher::getNumStudents(Sections section, std::string course)
{
    return num_students[section][course];
}

void Teacher::removeFreePeriod(int period)
{
    free_periods.erase(std::remove(free_periods.begin(), free_periods.end(), period), free_periods.end());
}

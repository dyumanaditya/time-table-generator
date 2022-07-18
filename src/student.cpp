#include "time-table-generator/student.h"

#include <iostream>
#include <algorithm>

Student::Student()
{
    // Add all 42 periods for student being free
    for (int i=1; i<=42; ++i)
    {
        free_periods.push_back(i);
    }
}

Student::~Student()
{
}

void Student::setName(std::string name)
{
    Student::name = name;
}

void Student::setPhone(std::string phone)
{
    Student::phone = phone;
}

void Student::setEmail(std::string email)
{
    Student::email = email;
}

void Student::setSection(Sections section)
{
    Student::section = section;
}

void Student::addCourse(std::string course_name, std::string teacher_name, int periods)
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
    std::cout << "Courses Taking, Name of Teacher & Number of periods:" << std::endl;
    for (auto course : courses)
    {
        std::cout << std::get<0>(course) << " - " << std::get<1>(course) << " - " << std::get<2>(course) << std::endl;
    }
}


std::string Student::getName()
{
    return name;
}

Sections Student::getSection()
{
    return section;
}

std::string Student::getEmail()
{
    return email;
}

std::string Student::getPhone()
{
    return phone;
}

bool Student::isFree(int period)
{
    if (std::find(free_periods.begin(), free_periods.end(), period) != free_periods.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}


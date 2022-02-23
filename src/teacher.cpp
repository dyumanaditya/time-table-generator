#include "include/teacher.h"

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

void Teacher::add_course(Courses course)
{
    courses.push_back(course);
}

void Teacher::add_section(Sections section)
{
    sections.push_back(section);
}

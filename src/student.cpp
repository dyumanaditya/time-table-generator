#include "student.h"

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

void Student::set_section(std::string section)
{
    Student::section = section;
}

void Student::add_course(std::string course_name, int periods)
{
    Student::courses.insert(std::pair<std::string, int>(course_name, periods));
}

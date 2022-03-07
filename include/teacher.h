#ifndef TEACHER_H
#define TEACHER_H
\
#include <string>
#include <vector>

#include "include/days.h"
#include "include/sections.h"

class Teacher
{
public:
    Teacher();
    ~Teacher();

    void set_name(std::string name);
    void set_phone(std::string phone);
    void set_email(std::string email);
    void add_free_period(Days day, int period);
    void add_course(std::string course);
    void add_section(Sections section);
    void print();

private:
    std::string name;
    std::string phone;
    std::string email;
    std::vector<int> free_periods;
    std::vector<std::string> courses;
    std::vector<Sections> sections;
};

#endif // TEACHER_H

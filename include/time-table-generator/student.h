#ifndef STUDENT_H
#define STUDENT_H

#include "time-table-generator/sections.h"

#include <string>
#include <vector>
#include <tuple>

class Student
{
public:
    Student();
    ~Student();

    void set_name(std::string name);
    void set_phone(std::string phone);
    void set_email(std::string email);
    void set_section(Sections section);
    void add_course(std::string course_name, std::string teacher_name, int periods);
    void print();

    Sections get_section();
    std::string get_name();
    std::string get_phone();
    std::string get_email();

    std::vector<std::tuple<std::string, std::string, int> > courses;

private:
    std::string name;
    std::string phone;
    std::string email;
    Sections section;
};

#endif // STUDENT_H

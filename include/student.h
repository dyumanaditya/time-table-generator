#ifndef STUDENT_H
#define STUDENT_H

#include "include/sections.h"

#include <string>
#include <vector>

class Student
{
public:
    Student();
    ~Student();

    void set_name(std::string name);
    void set_phone(std::string phone);
    void set_email(std::string email);
    void set_section(Sections section);
    void add_course(std::string course_name, int periods);
    void print();

private:
    std::string name;
    std::string phone;
    std::string email;
    Sections section;
    std::vector<std::pair<std::string, int> > courses;
};

#endif // STUDENT_H

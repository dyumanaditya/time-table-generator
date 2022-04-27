#ifndef TEACHER_H
#define TEACHER_H
\
#include <string>
#include <vector>

#include "time-table-generator/days.h"
#include "time-table-generator/sections.h"

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
    void set_num_students(Sections section, int num);
    void print();

    std::string get_name();
    std::string get_phone();
    std::string get_email();
    std::vector<int> get_free_periods();
    int get_num_students(Sections section);

private:
    std::string name;
    std::string phone;
    std::string email;
    std::vector<int> free_periods;
    std::vector<std::string> courses;
    std::vector<Sections> sections;
    int num_students_k1;
    int num_students_k2;
    int num_students_k3;
};

#endif // TEACHER_H

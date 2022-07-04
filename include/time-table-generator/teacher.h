#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include <vector>
#include <utility>

#include "time-table-generator/days.h"
#include "time-table-generator/sections.h"

class Teacher
{
public:
    Teacher();
    ~Teacher();

    void setName(std::string name);
    void setPhone(std::string phone);
    void setEmail(std::string email);
    void addFreePeriod(Days day, int period);
    void addCourse(std::string course, bool is_science);
    void addSection(Sections section);
    void setNumStudents(Sections section, int num);
    void print();

    std::string getName();
    std::string getPhone();
    std::string getEmail();
    std::vector<int> getFreePeriods();
    int getNumStudents(Sections section);

    // Vector of courses with name and if science of not
    std::vector<std::pair<std::string, bool> > courses;

private:
    std::string name;
    std::string phone;
    std::string email;
    std::vector<int> free_periods;
    std::vector<Sections> sections;
    int num_students_k1;
    int num_students_k2;
    int num_students_k3;
};

#endif // TEACHER_H

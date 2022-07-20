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

    void setName(std::string name);
    void setPhone(std::string phone);
    void setEmail(std::string email);
    void setSection(Sections section);
    void addCourse(std::string course_name, std::string teacher_name, int periods);
    void print();

    Sections getSection();
    std::string getName();
    std::string getPhone();
    std::string getEmail();

    // Vector containing: Course name, Teacher name, Number of periods
    std::vector<std::tuple<std::string, std::string, int> > courses;

    // Vector containing the students free periods which is initially all 42
    std::vector<int> free_periods;

    // Function to check if student is free in the given period
    bool isFree(int period);

    // Function to fix a class for the student: removes a free period
    void removeFreePeriod(int period);

private:
    std::string name;
    std::string phone;
    std::string email;
    Sections section;
};

#endif // STUDENT_H

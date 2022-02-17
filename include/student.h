#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <map>

class Student
{
public:
    Student();
    ~Student();

    void set_name(std::string name);
    void set_phone(std::string phone);
    void set_email(std::string email);
    void set_section(std::string section);
    void add_course(std::string course_name, int periods);

private:
    std::string name;
    std::string phone;
    std::string email;
    std::string section;
    std::map<std::string, int> courses;

};

#endif // STUDENT_H

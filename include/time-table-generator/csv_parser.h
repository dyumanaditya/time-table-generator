#ifndef CSVPARSER_H
#define CSVPARSER_H

#include <string>
#include <vector>

#include "time-table-generator/student.h"
#include "time-table-generator/teacher.h"

class CSVParser
{
public:
    CSVParser();
    ~CSVParser();

    std::vector<Teacher*> parseTeacherData(std::string teacher_data_path);
    std::vector<Student*> parseStudentData(std::string student_data_path);

private:

    // Format for the csv files (not used in the code yet)
    enum class teacher_csv_data
    {
        Name, Email, Phone, Courses, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, K1, K2, K3
    };

    enum class student_csv_data
    {
        Name, Section, Email, Phone, Number_of_courses, Course_list_start
    };

};

#endif // CSVPARSER_H

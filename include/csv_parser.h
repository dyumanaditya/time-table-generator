#ifndef CSVPARSER_H
#define CSVPARSER_H

#include <string>
#include <vector>

#include "include/student.h"
#include "include/teacher.h"

class CSVParser
{
public:
    CSVParser();
    ~CSVParser();

    std::vector<Teacher>* parse_teacher_data(std::string teacher_data_path);
    std::vector<Student>* parse_student_data(std::string student_data_path);

};

#endif // CSVPARSER_H

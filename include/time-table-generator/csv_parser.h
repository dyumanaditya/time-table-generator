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

};

#endif // CSVPARSER_H

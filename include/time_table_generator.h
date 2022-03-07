#ifndef TIMETABLEGENERATOR_H
#define TIMETABLEGENERATOR_H

#include "include/csv_parser.h"
#include "include/teacher.h"
#include "include/student.h"

#include <string>
#include <vector>

class TimeTableGenerator
{
public:
    TimeTableGenerator(std::string teacher_data_path, std::string student_data_path);
    ~TimeTableGenerator();

    void generateTimeTable();

private:
    CSVParser csv_parser;
    std::vector<Teacher>* teachers;
    std::vector<Student>* students;
};

#endif // TIMETABLEGENERATOR_H

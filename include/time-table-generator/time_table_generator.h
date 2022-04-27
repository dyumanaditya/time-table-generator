#ifndef TIMETABLEGENERATOR_H
#define TIMETABLEGENERATOR_H

#include "time-table-generator/csv_parser.h"
#include "time-table-generator/teacher.h"
#include "time-table-generator/student.h"
#include "time-table-generator/courses.h"

#include <string>
#include <vector>
#include <map>

class TimeTableGenerator
{
public:
    TimeTableGenerator(std::string teacher_data_path, std::string student_data_path);
    ~TimeTableGenerator();

    void generateTimeTable();

private:
    CSVParser csv_parser;
    std::vector<Teacher*> teachers;
    std::vector<Student*> students;

    // Size (42 x # (of teachers in that period))
    std::map<int, Teacher*> teacher_availability;

    // Function to evaluate and populate teacher_availability matrix:
    void set_teacher_availability();
    void sort_teacher_availability();
};

#endif // TIMETABLEGENERATOR_H

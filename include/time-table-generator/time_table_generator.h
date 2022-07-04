#ifndef TIMETABLEGENERATOR_H
#define TIMETABLEGENERATOR_H

#include "time-table-generator/csv_parser.h"
#include "time-table-generator/teacher.h"
#include "time-table-generator/student.h"
#include "time-table-generator/courses.h"
#include "time-table-generator/class.h"
#include "time-table-generator/sections.h"

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

    // Set of all classes
    std::vector<Class> classes;

    // Map of all potential classes in a particular period
    std::map<int, std::vector<Class>> class_matrix;

    // Size (42 x # (of teachers in that period))
    std::map<int, std::vector<Teacher*>> teacher_availability;

    // Function to evaluate and populate class matrix based on teacher free periods:
    void populateClassMatrix();

    // Function to sort the class_matrix based on the metrics
    void sortClassMatrix();

    // Function to initialize all classes
    void initClasses();

    // Function to set the num_students_section varaible
    void setNumStudentsSection();
};

#endif // TIMETABLEGENERATOR_H

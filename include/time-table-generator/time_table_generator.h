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
    std::map<int, std::vector<Class*>> class_matrix;

    // Size (42 x # (of teachers in that period))
    std::map<int, std::vector<Teacher*>> teacher_availability;

    // Time table contains the classes that have been fixed: period number -> vector of classes
    std::map<int, std::vector<Class*>> time_table;

    // Vector containing the periods we have not yet selected for algo
    std::vector<int> periods;

    // Function to evaluate and populate class matrix based on teacher free periods:
    void populateClassMatrix();

    // Function to sort the class_matrix based on the metrics
    void sortClassMatrix();

    // Function to initialize all classes
    void initClasses();

    // Function to set the num_students_section varaible
    void setNumStudentsSection();

    // Function to fill up the periods from 1-42 again
    void fillPeriods();

    // Function to generate random number in some range
    int generateRandomInt(int lower, int upper);

    // Function to get the random period
    int generateRandomPeriod();

    // Function to remove the classes which have metric 0 because that means nobody is taking the class
    void removeRedundantClasses();

    // Function to fix a certain class. Returns true if successful, otherwise false (all students should be free)
    bool fixClass(int period, int class_position);

    // Function to check if the program has completed and if all periods have been fixed
    bool programCompleted();

    // Function to get get period given a number from 1-42. Example 1 -> Monday 1st
    std::string getPeriodFromNumber(int period);

    // Function to print time table
    void printTimetable();
};

#endif // TIMETABLEGENERATOR_H

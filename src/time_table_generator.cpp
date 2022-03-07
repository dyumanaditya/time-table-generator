#include "include/time_table_generator.h"

TimeTableGenerator::TimeTableGenerator(std::string teacher_data_path, std::string student_data_path)
{
    teachers = csv_parser.parse_teacher_data(teacher_data_path);
    students = csv_parser.parse_student_data(student_data_path);
}

TimeTableGenerator::~TimeTableGenerator()
{
}


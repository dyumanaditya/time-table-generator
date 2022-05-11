#ifndef CLASS_H
#define CLASS_H

#include "time-table-generator/teacher.h"
#include "time-table-generator/student.h"
#include "time-table-generator/sections.h"

#include <vector>
#include <map>
#include <string>


class Class
{
public:
    Class();
    ~Class();

    std::string course;
    Teacher* teacher;
    bool science;

    // The maximum number of periods that a student has requested from a section
    std::map<Sections, int> max_num_periods;

    std::map<Sections, std::vector<Student*>> students;
};

#endif // CLASS_H

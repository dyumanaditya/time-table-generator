#include <time-table-generator/utils.h>
#include <time-table-generator/courses.h>

#include <algorithm>

bool utils::isScience(std::string course)
{
    if (fixed_period_courses.contains(course))
    {
        return true;
    }
    else
    {
        return false;
    }
}

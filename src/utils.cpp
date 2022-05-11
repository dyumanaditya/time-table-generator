#include <time-table-generator/utils.h>
#include <time-table-generator/courses.h>

#include <algorithm>

bool utils::isScience(std::string course)
{
    if (std::find(fixed_period_courses.begin(), fixed_period_courses.end(), course) != fixed_period_courses.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}

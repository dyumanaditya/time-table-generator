#include "time-table-generator/class.h"

#include <iostream>


Class::Class()
{
    max_num_periods[Sections::K1] = 0;
    max_num_periods[Sections::K2] = 0;
    max_num_periods[Sections::K3] = 0;
    k1_fixed = false;
    k2_fixed = false;
    k3_fixed = false;
}

Class::~Class()
{
}

void Class::print()
{
    std::cout << "CLASS: " << course << std::endl;
    std::cout << "Teacher: " << teacher->getName() << std::endl;
    std::cout << "Metric: " << metric << std::endl << std::endl;
}

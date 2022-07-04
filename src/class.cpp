#include "time-table-generator/class.h"

#include <iostream>


Class::Class()
{
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

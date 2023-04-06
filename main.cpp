#include <iostream>
#include <string>
#include "wheel.h"

int main()
{
    Wheel one(30);

    Wheel two(25);
    one.setRpm(2500);
    two.setRpm(4000);
    std::cout << one.operator<(two) << std::endl;

    return 0;
}
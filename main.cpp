#include <iostream>
#include <string>
#include "wheel.h"

int main()
{
    Wheel testWheel(20);
    testWheel.getAngle();
    std::cout << testWheel.getAngle() << " " << testWheel.getRpm() << std::endl;
    return 0;
}
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "wheel.h"

class Car
{
    enum class Color
    {
        Red,
        Blue,
        White,
        Black
    };

private:
    Color color;
    int weight;
    std::string model;
    double liniarVelocity;
    double angularVelocity;
    std::shared_ptr<Wheel> wheel;

public:
    bool setSpeed(double speed)
    {
    }
};
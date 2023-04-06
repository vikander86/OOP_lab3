#include <iostream>

class Wheel
{
private:
    double radius;
    double rpm;
    double angle;
    double pressure;

public:
    Wheel(double radius) : radius(radius), rpm(0), angle(0), pressure(0) {}

    bool setRpm(double newRpm)
    {
        if (newRpm >= 0 && newRpm <= 10000)
        {
            this->rpm = newRpm;
            return true;
        }
        else
        {
            return false;
        }
    }
    double getRpm()
    {
        return rpm;
    }
    bool setAngle(double newAngle)
    {
        if (newAngle >= 0 && newAngle <= 360)
        {
            this->angle = newAngle;
            return true;
        }
        else
        {
            return false;
        }
    }
    double getAngle()
    {
        return angle;
    }
};
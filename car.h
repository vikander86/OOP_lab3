#pragma once
#include <string>
#include "wheel.h"
#include <math.h>
class Car
{
public:
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
    Wheel *flwheel;
    Wheel *frwheel;
    Wheel *rlwheel;
    Wheel *rrwheel;

public:
    // default constructer
    Car() : color(Color::Red), weight(0), model(""), liniarVelocity(0), angularVelocity(0),
            flwheel(new Wheel(0)), frwheel(new Wheel(0)), rlwheel(new Wheel(0)), rrwheel(new Wheel(0))
    {
        std::cout << "Creating default car" << std::endl;
    }

    // copy constructer
    Car(const Car &other)
        : angularVelocity(other.angularVelocity), liniarVelocity(other.liniarVelocity), color(other.color),
          weight(other.weight), model(other.model)
    {
        flwheel = new Wheel(*(other.flwheel));
        frwheel = new Wheel(*(other.frwheel));
        rlwheel = new Wheel(*(other.rlwheel));
        rrwheel = new Wheel(*(other.rrwheel));
        std::cout << "Creating copy, with copy constructor of car model: " << other.model << std::endl;
    }

    // desctructor
    ~Car()
    {
        delete flwheel;
        delete frwheel;
        delete rlwheel;
        delete rrwheel;
        std::cout << "Deleting model: " << model << std::endl;
    }

    // assigment constructor
    Car &operator=(const Car &other)
    {
        if (this != &other)
        {
            delete flwheel;
            delete frwheel;
            delete rlwheel;
            delete rrwheel;

            angularVelocity = other.angularVelocity;
            liniarVelocity = other.liniarVelocity;
            color = other.color;
            weight = other.weight;
            model = other.model;

            flwheel = new Wheel(*(other.flwheel));
            frwheel = new Wheel(*(other.frwheel));
            rlwheel = new Wheel(*(other.rlwheel));
            rrwheel = new Wheel(*(other.rrwheel));
            std::cout << "Copying car with assigment operator of car model: " << other.model << std::endl;
        }
        return *this;
    }

    // move constructor
    Car(Car &&other) noexcept
        : color(other.color), weight(other.weight), model(std::move(other.model)), liniarVelocity(other.liniarVelocity), angularVelocity(other.angularVelocity),
          flwheel(other.flwheel), frwheel(other.frwheel), rlwheel(other.rlwheel), rrwheel(other.rrwheel)
    {
        other.flwheel = nullptr;
        other.frwheel = nullptr;
        other.rlwheel = nullptr;
        other.rrwheel = nullptr;
        std::cout << "Invoking move constructor! Moving car model: " << model << std::endl;
    }

    // move assignment operator
    Car &operator=(Car &&other) noexcept
    {
        if (this != &other)
        {
            delete flwheel;
            delete frwheel;
            delete rlwheel;
            delete rrwheel;

            color = other.color;
            weight = other.weight;
            model = std::move(other.model);
            liniarVelocity = other.liniarVelocity;
            angularVelocity = other.angularVelocity;
            flwheel = other.flwheel;
            frwheel = other.frwheel;
            rlwheel = other.rlwheel;
            rrwheel = other.rrwheel;

            other.flwheel = nullptr;
            other.frwheel = nullptr;
            other.rlwheel = nullptr;
            other.rrwheel = nullptr;
            std::cout << "Invoking MoveAssigmentOperator! Moving car model: " << model << std::endl;
        }
        return *this;
    }

    // none default constructor
    Car(Color color)
        : color(color), angularVelocity(0), liniarVelocity(0), weight(0), model(""),
          flwheel(nullptr), frwheel(nullptr), rlwheel(nullptr), rrwheel(nullptr)
    {
        std::cout << "Creating car with non-default constructor." << std::endl;
    }

    void setModelName(std::string modelName)
    {
        model = modelName;
    }

    std::string getModelName() const
    {
        return model;
    }

    void getColor()
    {
        switch (color)
        {
        case Color::Red:
            std::cout << "Car is Red" << std::endl;
            break;
        case Color::White:
            std::cout << "Car is White" << std::endl;
            break;
        case Color::Black:
            std::cout << "Car is Black" << std::endl;
            break;
        case Color::Blue:
            std::cout << "Car is blue" << std::endl;
            break;
        default:
            break;
        }
    }

    void setWeight(double weight)
    {
        this->weight = weight;
    }

    double getWeight()
    {
        return weight;
    }

    void setSpeed()
    {
        this->liniarVelocity = this->flwheel->getRpm() * 2 * M_PI * this->flwheel->radius;
    }

    bool setTurningAngle(double angle)
    {
        if (angle >= 0 && angle <= 10000)
        {
            this->angularVelocity = angle;
            return true;
        }
        else
        {
            return false;
        }
    }
};
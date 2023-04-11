#include <iostream>
#include <string>
#include "wheel.h"
#include "pump.h"
#include "car.h"

int main()
{
    // default
    // creates a car with the default member variables specified in the car class
    Car carOne;
    carOne.setModelName("BatMobile");
    // before the instantion of the object, it's clear to see that the values are very random
    // and as soon as we step into our Car Class, it modifies our variables to that which I set as default

    // copy constructor
    // creates a deep copy of carOne, with the member variable values of that of carOne
    Car carTwo(carOne);
    carTwo.setModelName("CatMobile");
    // Same as carOne, with the instantion of the object, it's clear to see that the values are very random
    // and as soon as we step into our copy constructor, it copies the values of our carOne
    // we have to create new Wheel objects and copy the values from the original wheels

    // copy assignment operator
    // creates a copy of carOne using the assigment operator
    Car carThree;
    carThree = carTwo;
    carThree.setModelName("PinguinMobile");
    // the assignment operator works similiar to the copy constructor in that it creates a deep copy of our carOne

    // non-default
    // creates a car with specified color.
    Car carFour(Car::Color::White);
    carFour.setModelName("JokerMobile");

    // move constructor
    // to ensure invokation of the move constructor, we can make use of std::move to make sure the move constructor is invoked
    Car carFive(std::move(carFour));
    // the values stored in our carFour are moved to carFive, and the pointers in carFour are set to null
    // carFour still exists in memory, but for us to use it again successfully we would have to re-initialise it.

    // move assigment operator
    // to en invokation of the move constructor, we make use of std::move to make sure the move assigment operator is invoked.
    carFour = std::move(carOne);
    // the values stored in our carTwo are moved to carFour

    return 0;
}
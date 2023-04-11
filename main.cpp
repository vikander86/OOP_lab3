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
    carOne.getColor();
    // before the instantion of the object, it's clear to see that the values are very random
    // and as soon as we step into our Car Class, it modifies our variables to that which I set as default

    // copy constructor
    // creates a deep copy of carOne, with the member variable values of that of carOne
    Car carTwo(carOne);
    carTwo.setModelName("CatMobile");
    // Same as carOne, with the instantion of the object, it's clear to see that the values are very random
    // and as soon as we step into our copy constructor, it copies the values of our carOne
    // we also have to delete our pointers to our wheels, as the shallow copy will effectively not work
    // so we have to update the pointers by deference

    // copy assigment
    // creates a copy of carOne using the assigment operator
    Car carThree;
    carThree = carTwo;
    // the assignment operator works similiar to the copy constructor in that
    // it creates a deep copy of our carOne

    Car carFour(Car::Color::White);
    carFour.getColor();

    return 0;
}
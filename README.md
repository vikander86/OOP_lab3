# OOP_lab3

## Exercise 1

Initialized a new Git Repo.

---

## Exercise 2

Created a Wheel class with the provided information

Data Members:

- double radius;
- double rpm;
- double angle;
- double pressure;

Member Functions:

- Non-default constructor to create a Wheel with radius;
- Getter and setter functions for rpm, return bool from setter;
- Getter and setter functions for angle, return bool from setter;
- Getter for radius;

Created the setter function for RPM to take in a value between 0 and 10000
Created the setter function for ANGLE to take in a value between 0 and 40

---

## Exercise 3

Created a new Pump class with a setPressure function, that takes a Wheel object and a double value for pressure
as an argument.

Use the pump class to set the pressure in the wheel.

### Problemsolving:

I initially thought the function had to be the friend, not the actually class! So I tried to make the function a friend in the Wheel class which gave me several complications, I then create a function outside my class to change the pressure of the wheel and used the pump class to call this function! This created a lot of unneccesarry code when I found out I could just friend the actually class :/

---

## Exercise 4

Defined six comparision operators (==, !=, <, >, <=, >=) in the Wheel class that can be used to comprae the current speed of two different wheel objects by using radius and rpm!

### Problemsolving:

I first tackled this problem with using an enum class that had members "EqualTo","NotEqualTo", etc etc.
Then used a switch case that took the enum member and performed the comparison.

This was working just fine, but the use of the operator call made the code alot more readiable and accessible.

---

## Exercise 5

Created a car class with the following members and member functions

Data Members:

- Color color;
- int weight;
- string model;
- double linearVelocity;
- double angularVelocity;
- Wheel \*flWheel;
- Wheel \*frWheel;
- Wheel \*rlWheel;
- Wheel \*rrWheel;

Member Functions:

- bool setSpeed(double speed);
- bool setTurningAngle(double angle);

Created three car objects with the default constructor, copyconstructor and the copy assignment operator

### Problemsolving:

Doing the debugging I got several segmentationfaults, and it was clear that copying was an issue.
It was clear that a shallow copy does not work and the constructor could not simply copy the pointer values. As if the current object I copied went out of scope and got deleted, the pointers to their wheels also got destroyed! Meaning that i would have a copy car that brought on segmentation faults.

To adress this I implemented a deep copy constructor instead, which creates new wheels and instantiated them with the values of the original wheels.

---

## Exercise 6

Added a non-default constructor to the car class that creates a new car with a given color.
Further added the required getter and setter functions to create a complete Car.

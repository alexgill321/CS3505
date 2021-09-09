/*
Alexander Gill

CS3505

Assignment 2: Classes, Facades, and Makefiles

September 14, 2021

This file is the implementation for the SpiralPDF Class. It includes functions for setting up a Spiral,
getting x, y, and letter angle objects, and incrementing the spiral for the next character placement.
*/

#define _USE_MATH_DEFINES
#include <cmath>
#include "Spiral.h"

//Default Constructor
Spiral::Spiral(){
	//Declares starting variables that make the spiral look pretty clean
	X = 210;
	Y = 300;
	Angle = 180;
	Radius = 50;
}

//Constructor with user inputs as the initial values.
Spiral::Spiral(double centerX, double centerY, double intAngle, double intRadius){
	//Assigning initial values from the user to the new object
	X = centerX;
	Y = centerY;
	Angle = intAngle;
	Radius = intRadius;
}

//The following functions just return the current x and y positions and angle of the spiral.
double Spiral::getTextX(){
	return posX;
}

double Spiral::getTextY(){
	return posY;
}

double Spiral::getLetterAngle(){
	return rad1;
}

//This function calculates the angles and positions of the spiral at its current point, based on
// the angle and the circle radius.
void Spiral::calculate(){
	//Converting from degrees to radians
	rad1 = (Angle - 90) / 180 * M_PI;
	rad2 = Angle / 180 * M_PI;
	// Calulating position
	posX = X + cos(rad2) * Radius;
    posY = Y + sin(rad2) * Radius;
}
//The following functions are iterators for the Spiral, they calculate and store the
//necessary values and then increase the spiral by one iteration.
Spiral& Spiral::operator++(){
    //Iterating the angle and radius once so the next character is in a different location
    Angle -= 10; // change the angle around the circle
    Radius += 0.75; //Change the radius of the circle, continuing the spiral

    //Returning a pointer to the current 
    return *this;
}



Spiral Spiral::operator++(int){
	//Creating a temporary copy of the current Spiral object
	Spiral temp(*this);
    //Iterating the angle and radius once so the next character is in a different location
    ++(*this);

    //returning the copy of the spiral object after modification
    return temp;
}


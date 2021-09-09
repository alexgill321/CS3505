/*
Alexander Gill

CS3505

Assignment 2: Classes, Facades, and Makefiles

September 14, 2021

This file is the interface for the Spiral class. It includes functions definitions
 and class objects, and lets the compiler know to look out for the class functions when called.
*/

//Defining the spiral header function
#ifndef SPIRAL_H
#define SPIRAL_H

class Spiral{
	//Private variables for Spiral:
	//X = Center horizontal postion of the spiral
	//Y = Center vertical postion of the spiral
	//Angle = Current angle of the spiral
	//Radius = Current Radius of the spiral
	//posX = X position based on the spirals current angle and radius 
	//posY = Y position based on the spirals current angle and radius
	//rad1 = Angle of the spiral at posx and posy, in radians
	//rad2 = Angle of the spiral in radians.
	private:
		double X,Y,Angle, Radius, posX, posY, rad1, rad2;
	public:
		//Declarations for all of the spiral functions, so the compiler can search for these in spiral.cpp
		Spiral();
		Spiral(double centerX, double centerY, double intAngle, double intRadius);
		double getTextX();
		double getTextY();
		double getLetterAngle();
		void calculate();
		Spiral& operator++();
		Spiral operator++(int);
};

#endif
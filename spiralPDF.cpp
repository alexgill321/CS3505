/*
Alexander Gill

CS3505

Assignment 2: Classes, Facades, and Makefiles

September 14, 2021

This is the test file that takes in the text from the compiler to be written to the pdf, and
calls the correct functions from the HaruPDF and Spiral classes to write the given text to a pdf.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include "Spiral.h"
#include "HaruPDF.h"

int main (int argc, char **argv)
{
	//Declaring the variable to hold the text for the spiral. 256 characters should be sufficient
	//for a standard page.
	char SAMP_TXT[256];
	// Check for the compiler arguments to ensure some text was entered, if not, an error is given,
	//and the code exits
	if (argc > 1){
    	strcpy(SAMP_TXT, argv[1]);
    }
    else{
    	std::cout << "ERROR: No text was given." << std::endl;
    	return 0;
    }

    //Creating a filename based off of the compiler name + ".pdf"
    char fname[256];
    strcpy (fname, argv[0]);
    strcat (fname, ".pdf");

    //Creating a new page and spiral object
    HaruPDF myPage;
    Spiral mySpiral;
    float x,y,rad;
    // Place characters one at a time on the page.
    mySpiral.calculate();
    for (int i = 0; i < strlen (SAMP_TXT); i++) {
    	//Usings Spiral class getter functions to retrieve the spirals current position and angle
    	x = mySpiral.getTextX();
    	y = mySpiral.getTextY();
    	rad = mySpiral.getLetterAngle();
    	//Writing out a character to the page
       	myPage.Write(rad,x,y,SAMP_TXT[i]);
       	//Incrementing the Spiral to its next position
       	++mySpiral;
       	//Calculating and updating new spiral position and angles from incremented values
    	mySpiral.calculate();
    }
    //After all the text is written to the page, this function is called to save to a .pdf file
    myPage.Save(fname);

    //Closing the HaruPDF object, so it can no longer be modified.
    myPage.Close();
}




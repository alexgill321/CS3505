/*
Alexander Gill

CS3505

Assignment 2: Classes, Facades, and Makefiles

September 14, 2021

This file is the interface for the HaruPDF Class. It includes functions definitions
 and class objects, and lets the compiler know to look out for the class functions when called.
*/

//Defining HARUPDF.h, if not already defined.
#ifndef HARUPDF_H
#define HARUPDF_H
#include "hpdf.h"

class HaruPDF {
	// Private variables for the HaruPDF class
	private:
		HPDF_Doc  pdf;
		HPDF_Page page;
		HPDF_Font font;
	public:
		// Constructor declaration for HaruPDF
		HaruPDF();
		// Declarations for the write save and close functions.
		void Write(float rad, float x, float y, char print_char);
		void Save(const char* fname);
		void Close();
}; 

#endif
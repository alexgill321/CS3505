/*
Alexander Gill

CS3505

Assignment 2: Classes, Facades, and Makefiles

September 14, 2021

This file is the implementation for the HaruPDF Class. It includes functions for setting up a pdf,
writing a character to a pdf, saving, and closing the file.
*/

#include "HaruPDF.h"
#include "hpdf.h"
#include <math.h>

// This function does all of the initializing for the page, I made it so the user doesn't have to modify
//any variables to get it to create a page.
HaruPDF::HaruPDF(){
	pdf = HPDF_New (NULL, NULL);
    /* add a new page object. */
    page = HPDF_AddPage (pdf);
    HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);
	// print_grid  (pdf, page);
    HPDF_Page_SetTextLeading (page, 20);
    HPDF_Page_SetGrayStroke (page, 0);
    HPDF_Page_BeginText (page);
    font = HPDF_GetFont (pdf, "Courier-Bold", NULL);
    HPDF_Page_SetFontAndSize (page, font, 15);
}

//This function takes in a position and angle, and prints a character with those specifications
void HaruPDF::Write(float rad, float x, float y, char print_char){
	//Modifying the variables to fit HPDF's requirements
	char buf[2];
	HPDF_Page_SetTextMatrix(page, cos(rad), sin(rad), -sin(rad), cos(rad), x, y);
	buf[0] = print_char; // The character to display
    buf[1] = 0;
    // This command prints the character out on the page
    HPDF_Page_ShowText (page, buf);
}

//This function just takes a filename and saves the pdf to that file
void HaruPDF::Save(const char* fname){
	HPDF_SaveToFile (pdf, fname);
}

//This function closes the HaruPDF object and frees the pdf.
void HaruPDF::Close(){
	HPDF_Page_EndText (page);
	HPDF_Free (pdf);
}
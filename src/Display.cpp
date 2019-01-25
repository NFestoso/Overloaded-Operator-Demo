/***************************************************************
Filename:			Display.cpp
Version:			1.0
Author:				Nathan Festoso
Student #:			040825359
Course name/number:	C++ Programming CST8219
Lab section:		302
Assignment #:		2
Assignment name:	Animation Project in C++ using STL Container Classes
					and Overloaded Operators
Due date:			Dec 9, 2017
Submission date:	Dec 9, 2017
Professor:			Andrew Tyler
Purpose:			Frame display information
***************************************************************/

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

#include <iostream>
#include <windows.h>
#include "Display.h"

/***************************************************************
Function name:		Display
Purpose:			Overloaded constructor
In parameters:		int x - pixel_x
					int y - pixel_y
					int duration - Time to display
					char* name - Name of display
Out parameters:		Display object
Version:			1.0
Author:				Nathan Festoso
***************************************************************/
Display::Display(int x, int y, int duration, char* name) {
	pixel_x = x;
	pixel_y = y;
	this->duration = duration;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

/***************************************************************
Function name:		Display
Purpose:			Copy constructor
In parameters:		const Display& d - Display object to be copied
Out parameters:		Display object
Version:			1.0
Author:				Nathan Festoso
***************************************************************/
Display::Display(const Display& d) {
	pixel_x = d.pixel_x;
	pixel_y = d.pixel_y;
	duration = d.duration;
	name = new char[strlen(d.name) + 1];
	strcpy(name, d.name);
}

/***************************************************************
Function name:		~Display
Purpose:			Deallocate Display memory
In parameters:		-
Out parameters:		-
Version:			1.0
Author:				Nathan Festoso
***************************************************************/
Display::~Display() {
	delete[]name;
}

/***************************************************************
Function name:		operator<<
Purpose:			Console output Display and wait time
In parameters:		ostream& os - Output stream
					Display& d - Display to print and count
Out parameters:		ostream& - Output stream
Version:			1.0
Author:				Nathan Festoso
***************************************************************/
ostream& operator<<(ostream& os, Display& d) {
	// Display info
	os << "pixel_x = " << d.pixel_x << "; ";
	os << "pixel_y = " << d.pixel_y << "; ";
	os << "duration = " << d.duration << endl;

	// Count
	os << "\t" <<"Counting the seconds for this Display: ";
	for (int i = 0; i <= d.duration; i++) {
		os << i << ", ";
		Sleep(1000);
	}
	os << endl;
	return os;
}

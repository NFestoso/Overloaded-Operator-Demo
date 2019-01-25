/***************************************************************
Filename:			Frame.cpp
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
Purpose:			Animation Frame to hold display information and time
***************************************************************/

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include "Display.h"
#include "Frame.h"

/***************************************************************
Function name:		operator+
Purpose:			Concatination
In parameters:		Frame& f - Frame to be concatinated to this
Out parameters:		Frame - New concatinated frame object
Version:			1.0
Author:				Nathan Festoso
***************************************************************/
Frame Frame::operator+(Frame& f) {
	string new_name;
	vector<Display> new_displays;

	// Concatinate new name
	new_name = fileName + "_" + f.fileName;

	// Combine Displays from each Frame
	new_displays = displays;
	for (unsigned int i = 0; i < f.displays.size(); i++) {
		new_displays.push_back(f.displays[i]);
	}
	
	// Create new Frame
	Frame new_f(new_name, new_displays);
	return new_f;
}

/***************************************************************
Function name:		operator<<
Purpose:			Console output Frame
In parameters:		ostream& os - Output stream
					Frame& f - Frame to display
Out parameters:		ostream& - Output stream
Version:			1.0
Author:				Nathan Festoso
***************************************************************/
ostream& operator<<(ostream& os, Frame& f) {
	// Print Frame info
	os << "\tfileName = " << f.fileName << endl;
	
	// Print Displays
	for (unsigned int i = 0; i < f.displays.size(); i++) {
		os << "\tDisplay #" << i << ":\t";
		os << "\t" << f.displays[i];
	}
	return os;
}

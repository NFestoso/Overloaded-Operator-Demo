/***************************************************************
Filename:			Animation.cpp
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
Purpose:			Holds and manages list of Frames
***************************************************************/

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

#include <string>
#include <iostream>
#include <forward_list>
#include <vector>
#include <iterator>
#include "Display.h"
#include "Frame.h"
#include "Animation.h"

/***************************************************************
Function name:		InsertFrame
Purpose:			Inserts new frames into forward_list at specified
					location after the second
In parameters:		-
Out parameters:		-
Version:			1.0
Author:				Nathan Festoso
***************************************************************/
void Animation::InsertFrame() {
	vector<Display> displays;
	string fileName;
	char tempName[25];
	int num_display, x, y, duration, index;

	// Get filename
	cout << "Insert a Frame in the Animation" << endl;
	cout << "Please enter the Frame filename: ";
	cin >> fileName;
	
	// Get number of displays
	cout << endl << "Enter the Frames display (dimensions and duration)" << endl;
	cout << "Please enter the number of Displays: "; 
	cin >> num_display;

	// Set vector size
	displays.reserve(num_display);
	
	// Get each display
	for (int i = 0; i < num_display; i++) {
		cout << "Please enter pixel X for Display #" << i << " pixel_x: ";
		cin >> x;
		cout<< "Please enter pixel Y for Display #" << i << " pixel_y: ";
		cin >> y;
		cout<< "Please enter the duration sec for this Display: ";
		cin >> duration;
		cout<< "Please enter the name for this Display: ";
		cin >> tempName;
		
		// Create and add Display
		displays.push_back(Display(x, y, duration, tempName));
	}

	if (frames.empty()) {
		// First frame in animation
		cout << "This is the first frame in the list" << endl;
		frames.push_front(Frame(fileName, displays));
	}
	else {
		// Insert frame at specified index
		forward_list<Frame>::iterator start = frames.begin();
		forward_list<Frame>::iterator end = frames.end();

		// Get index to add frame
		if (distance(start, end) < 2) {
			// Add second frame to front without prompt
			frames.push_front(Frame(fileName, displays));
		}
		else {
			// User specifies location to add frame
			cout << "There are " << distance(start, end)+1 << " frames in list" << endl;
			cout << "Please specify the position, between 0" << " and " << distance(start, end)-1 << " to insert after: ";
			cin >> index;
			
			// Insert into list
			forward_list<Frame>::iterator insert = frames.begin();
			// Incrememnt iterator to index
			for (int i = 0; i < index; i++, insert++);
			// Insert frame
			frames.insert_after(insert, Frame(fileName, displays));
		}
		cout << endl; 
	}
	
}

/***************************************************************
Function name:		DeleteFrames
Purpose:			Removes all Frames in Animation
In parameters:		-
Out parameters:		-
Version:			1.0
Author:				Nathan Festoso
***************************************************************/
void Animation::DeleteFrames() {
	frames.clear();
}

/***************************************************************
Function name:		operator[]
Purpose:			Enable index access to Frames
In parameters:		unsigned int index - Frame location in list
Out parameters:		Frame&
Version:			1.0
Author:				Nathan Festoso
***************************************************************/
Frame& Animation::operator[](unsigned int index) {
	forward_list<Frame>::iterator it;
	unsigned int i = 0;
	// Get frame at index
	for (it = frames.begin(); it != frames.end(); it++, i++) {
		if (i == index)
			return *it;
	}
	return *it;
}

/***************************************************************
Function name:		operator+=
Purpose:			Enable Frame concatination
In parameters:		Frame& f - Frame object
Out parameters:		-
Version:			1.0
Author:				Nathan Festoso
***************************************************************/
void Animation::operator+=(Frame& f) {
	frames.push_front(f);
}

/***************************************************************
Function name:		operator<<
Purpose:			Console output Animation
In parameters:		ostream& os - output stream
					Animation& A - Animation object
Out parameters:		ostream& - Output stream
Version:			1.0
Author:				Nathan Festoso
***************************************************************/
ostream& operator<<(ostream &os, Animation &A) {
	os << "Animation " << A.name << endl;
	os << "Run the Animation" << endl;
	
	// Print Frames
	for (int i = 0; i < distance(A.frames.begin(), A.frames.end()); i++) {
		os << "Frame #" << i << ":" << endl;
		os << A[i];
	}
	os << "Output finished" << endl;
	return os;
}  
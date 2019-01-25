// Display.h
#pragma once

class Display 
{
	int pixel_x;
	int pixel_y;
	int duration;
	char* name;	
public:
	Display(int x, int y, int duration, char* name);
	Display(const Display&);
	~Display();
	friend ostream& operator<<(ostream&, Display&);
};

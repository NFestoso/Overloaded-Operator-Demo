//Animation.h
#pragma once

class Animation 
{
	string name;
	forward_list<Frame> frames;
public:
	Animation(string s): name(s){}
	void InsertFrame();
	void DeleteFrames();
	void Concatenate() // inline
	{
		cout << "Concatenating two Frames" << endl;
		int index1{ -1 }, index2{ -1 }; // same as int index1 = -1, index2 = -1;
		Animation& A{ *this };		// same as Animation& A = *this;
		int count{ distance(frames.begin(),frames.end()) };//same as int count = distance(frames.begin(),frames.end());
		do {
			cout << "Please enter valid indexes of the two Frames to concatenate (0 to " << count - 1 << ")" << endl;
			cin >> index1 >> index2;
		} while ((index1<0 || index1>count - 1) || (index2<0 || index2>count - 1));

		A += A[index1] + A[index2];
	}
	Frame& operator[](unsigned int);
	void operator+=(Frame&);
	friend ostream& operator<<(ostream& , Animation&);
};

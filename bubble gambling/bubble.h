#pragma once
#include <time.h>
#include <algorithm>
#include <iostream>

class bubble
{
	friend std::ostream& operator<<(std::ostream &os, const bubble &b);

private:
	char posX;
	int posY;
	int value;
	bool popped;
	char bubbleType;

public:
	//constructor
	bubble(char x, int y, int val);
	~bubble();

	//get-methods
	char getPositionX();
	int getPositionY();
	int getValue();
	bool getPopped();

	//set-methods
	void setPopped(bool pop);

};


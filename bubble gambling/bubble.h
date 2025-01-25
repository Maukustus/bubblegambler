#pragma once
class bubble
{
private:
	char posX;
	int posY;
	int value;
public:
	bubble(char x, int y, int val);
	char getPositionX();
	int getPositionY();
	int getValue();

};


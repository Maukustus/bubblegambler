#include "bubble.h"

bubble::bubble(char x, int y, int val){
	int temp = rand() % 2;
	posX = x;
	posY = y;
	value = val;
	popped = false;

	switch (temp) {
	case 0:
		bubbleType = 'O';
		break;
	case 1:
		bubbleType = 'o';
		break;
	default:
		bubbleType = 'E';
		break;
	}
}

bubble::~bubble(){
}

char bubble::getPositionX() {
	return posX;
}

int bubble::getPositionY() {
	return posY;
}

int bubble::getValue() {
	return value;
}

bool bubble::getPopped() {
	return popped;
}

void bubble::setPopped(bool pop){
	popped = pop;
}

std::ostream& operator<<(std::ostream& os, const bubble& b)
{
	if (!b.popped) {
		os << b.bubbleType;
	}
	else {
		os << '*';
	}
	return os;
}

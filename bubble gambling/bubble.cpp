#include "bubble.h"

bubble::bubble(char x, int y, int val){
	posX = x;
	posY = y;
	value = val;
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

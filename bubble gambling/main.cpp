#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

#include "bubble.h"

void showBubbles(std::vector<std::vector<bubble>>& bubbles);
void generateBubbles(std::vector<std::vector<bubble>>& bubbles);
void popBubbles(std::vector<std::vector<bubble>>& bubbles, int column, int row);


int main() {
	srand(time(0));
	std::vector< std::vector<bubble>> bubbles;

	generateBubbles(bubbles);
	showBubbles(bubbles);
	char column = 'A';
	int row = 1;

	int columnNum = column - 64;

	popBubbles(bubbles, columnNum, row);

	return 0;
}

void showBubbles(std::vector<std::vector<bubble>>& bubbles) {
	//draws the alphabet grid
	std::cout << ' ';
	for (int i = 'A'; i <= 'L'; i++) {
		std::cout << ' ' << char(i);
	}

	std::cout << std::endl;

	for (size_t y = 0; y < bubbles.size(); y++) {
		std::cout << y + 1;

		const std::vector<bubble> row = bubbles[y];

		for (size_t x = 0; x < row.size(); x++) {
			std::cout << ' ' << row[x];
		}
		std::cout << std::endl;
	}
}

void generateBubbles(std::vector<std::vector<bubble>>& bubbles) {
	for (int y = 0; y <= 7; y++) {
		std::vector<bubble> tempVector;

		for (int x = 'A'; x <= 'L'; x++) {
			bubble tempBubble((char)x, y, rand() % 100 - 50);
			//tempBubble.setPopped(true);

			tempVector.push_back(tempBubble);
		}
		bubbles.push_back(tempVector);
	}
}

void popBubbles(std::vector<std::vector<bubble>>& bubbles, int column, int row) {
	 
}
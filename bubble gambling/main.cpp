#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

#include "bubble.h"

void showBubbles(std::vector<std::vector<bubble>>& bubbles);
void generateBubbles(std::vector<std::vector<bubble>>& bubbles);
void popBubbles(std::vector<std::vector<bubble>>& bubbles, int column, int row);


int main() {
	int tries = 5;

	srand(time(0));
	std::vector<std::vector<bubble>> bubbles;

	generateBubbles(bubbles);
	//bubbles[5][6].setPopped(true);
	showBubbles(bubbles);
	do {
		char column = 'A';
		int row = 1;
		std::cout << "Tries left: " << tries << std::endl;

		std::cout << "Which column? ";
		std::cin >> column;

		std::cout << "Which row? ";
		std::cin >> row;

		int columnNum = column - 64;

		if (!bubbles[row - 1][columnNum - 1].getPopped()) {
			popBubbles(bubbles, columnNum, row);
			tries--;
		}
		else {
			std::cout << "Bubble already popped! Try another one!" << std::endl;
		}
		showBubbles(bubbles);
	} while (tries > 0);

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
	std::cout << "Popping bubble on: " << std::endl << "Column: " << char(column + 64) << std::endl
		<< "Row: " << row << std::endl;
	bubbles[row - 1][column - 1].setPopped(true);
	
	std::cout << std::endl;

}
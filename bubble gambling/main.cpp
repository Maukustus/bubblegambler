#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

#include "bubble.h"

void showBubbles(std::vector<std::vector<bubble>>& bubbles);
void generateBubbles(std::vector<std::vector<bubble>>& bubbles);
void popBubbles(std::vector<std::vector<bubble>>& bubbles, int column, int row);


int main() {
	std::cout << "Hello! Welcome to bubble gambling! We hope you have fun!\nPop a bubble from any row and column, and see if you get any points!\nPoints range from -5 to 10" << std::endl;
	
	int tries = 10;
	int score = 0;

	srand(time(0));
	std::vector<std::vector<bubble>> bubbles;

	generateBubbles(bubbles);
	//bubbles[5][6].setPopped(true);
	showBubbles(bubbles);

	do {
		char column = 'A';
		int row = 1;
		std::cout << "Tries left: " << tries << std::endl;

		std::cout << "Which column & row? ";
		std::cin >> column;
		std::cin >> row;
		column = toupper(column);
		int columnNum = column - 64;
		

		if ((columnNum > 0 && columnNum < 13) && (row > 0 && row < 9)) {
			if (!bubbles[row - 1][columnNum - 1].getPopped()) {
				popBubbles(bubbles, columnNum, row);
				score += bubbles[row - 1][columnNum - 1].getValue();
				tries--;
				std::cout << "Score: " << score << std::endl;
				std::cout << std::endl;
			}
			else {
				std::cout << "Bubble already popped! Try another one!" << std::endl;
			}
		}
		else {
			std::cout << "Column and/or row does not exist, try again!" << std::endl;
		}
		
		showBubbles(bubbles);
	} while (tries > 0);

	std::cout << "Total score: " << score << std::endl;

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
			bubble tempBubble((char)x, y, rand() % 16 - 5);
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
	
	std::cout << "POP! Bubble's value was: " << bubbles[row - 1][column - 1].getValue() << std::endl;

}
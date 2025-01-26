//sorry to anyone who has to see this sourcecode
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <string>

#include "bubble.h"
//#include "player.h"

void showBubbles(std::vector<std::vector<bubble>>& bubbles);
void generateBubbles(std::vector<std::vector<bubble>>& bubbles);
void popBubbles(std::vector<std::vector<bubble>>& bubbles, int column, int row);
void playGame(std::vector<std::pair<std::string, int>>& scores);
void viewScores(std::vector<std::pair<std::string, int>> scores);
void loadScores(std::vector<std::pair<std::string, int>>& scores);
void saveScores(std::vector<std::pair<std::string, int>>& scores);
void deleteScores(std::vector<std::pair<std::string, int>>& scores);


int main() {
	srand(time(0));

	bool playing = true;

	std::vector<std::pair<std::string, int>> scores;

	loadScores(scores);

	int choice = 0;

	while (playing) {
		std::cout << "Choose what you want to do: \n[1] Play the game\n[2] View scores\n[3] Delete all scores\n[0] Save & exit" << std::endl;
		std::cin >> choice;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clears so that std::cin can be run again.

		switch (choice) {
		case 0:
			saveScores(scores);
			std::cout << "Bye!" << std::endl;
			playing = false;
			break;
		case 1:
			playGame(scores);
			break;
		case 2:
			viewScores(scores);
			break;
		case 3:
			deleteScores(scores);
			break;
		default:
			std::cout << "invalid input" << std::endl;
			break;
		}
	}

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

void playGame(std::vector<std::pair<std::string, int>>& scores) {
	std::string playerName;
	std::cout << "Hello! Welcome to bubble gambling! We hope you have fun!\nPop a bubble from any row and column, and see if you get any points!\nPoints range from -5 to 10, and you have 10 tries to get as many points as possible!\nFirst off, can you tell us your name?" << std::endl;
	std::cin >> playerName;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clears so that std::cin can be run again.

	std::cout << "Hi there, " << playerName << std::endl;

	int tries = 10;
	int score = 0;

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
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clears so that std::cin can be run again.

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
				std::cout << "That bubble is already popped! Try another one!" << std::endl;
			}
		}
		else {
			std::cout << "That column and/or row does not exist, try again!" << std::endl;
		}

		showBubbles(bubbles);
	} while (tries > 0);

	std::cout << playerName << ", your final score is: " << score << std::endl;
	scores.push_back(std::pair<std::string, int>(playerName, score));
}

void viewScores(std::vector<std::pair<std::string, int>> scores) {
	if (!scores.empty()) {
		std::vector<std::pair<std::string, int>>::iterator iter;

		sort(scores.begin(), scores.end(),
			[](std::pair<std::string, int> a, std::pair<std::string, int> b) {
				return a.second > b.second;
			});//custom lambda function to sort by second of pair, i think it works???
		std::cout << "\nScores:\n";

		for (iter = scores.begin(); iter != scores.end(); ++iter)
		{
			std::cout << iter->first << ", " << iter->second << std::endl;
		}
	}
	else {
		std::cout << "No scores found\n" << std::endl;
	}

}

void loadScores(std::vector<std::pair<std::string, int>>& scores) {
	int n;
	int score;
	std::string name;

	std::ifstream savefile("scores.save", std::ios::binary | std::ios::in);

	if (savefile) {
		while (savefile.peek() != EOF) {
			savefile.read((char*)&n, sizeof(int));
			char* tmpName = new char[n + 1];
			tmpName[n] = '\0';

			savefile.read(tmpName, n);

			name = tmpName;

			savefile.read((char*)&score, sizeof(int));

			delete[] tmpName;

			scores.push_back(std::pair<std::string, int>(name, score));
		}
		savefile.close();
	}
	else {
		std::cout << "Error while loading scores!" << std::endl;
	}

}

void saveScores(std::vector<std::pair<std::string, int>>& scores) {
	if (scores.empty()) {
		std::cout << "No scores to save!" << std::endl;
		return;
	}

	std::cout << "Saving scores...." << std::endl;

	std::ofstream savefile("scores.save", std::ios::binary | std::ios::out);

	if (savefile) {
		std::vector<std::pair<std::string, int>>::iterator iter;

		for (iter = scores.begin(); iter != scores.end(); iter++) {
			std::string name = iter->first;
			int nameSize = name.size();
			savefile.write((char*)&nameSize, sizeof(int));
			savefile.write(name.c_str(), nameSize);
			savefile.write((char*)&(iter->second), sizeof(int));
		}

		savefile.close();

		std::cout << "Scores saved!" << std::endl;
	}
	else {
		std::cout << "Error while saving scores!" << std::endl;
	}

}

void deleteScores(std::vector<std::pair<std::string, int>>& scores) {
	scores.clear();
	std::ofstream savefile("scores.save", std::ios::binary | std::ios::out);
	std::cout << "Scores deleted" << std::endl;
}
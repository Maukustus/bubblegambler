#pragma once
#include <string>

class player
{
private:
	std::string name;
	int score;
public:
	player(std::string n);
	~player();
	void setScore(int s);
	int getScore();
	std::string getName();
};


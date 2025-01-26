#include "player.h"

player::player(std::string n)
{
	name = n;
}

player::~player()
{
}

void player::setScore(int s)
{
	score = s;
}

int player::getScore()
{
	return score;
}

std::string player::getName()
{
	return name;
}

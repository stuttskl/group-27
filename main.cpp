/******************************************************************************
** Program name: main.cpp
** Authors: April Castaneda, Victoria Fisher, Katie Stutts
** Date: 06.20.2019
** Description: Main function that runs the game.
******************************************************************************/
#include <cstdlib>	// Header file needed to use srand
#include <ctime>	// Header file needed to use time

#include "GameEngine.hpp"

int main()
{
	unsigned seed;	// Random generator seed

	// Uses time function to get a seed valude for srand
	seed = time(0);
	srand(seed);

	// Create Game and run game
	GameEngine game;
	game.runGame();

	return 0;
}

	

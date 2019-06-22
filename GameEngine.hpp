/******************************************************************************
** Program name: GameEngine.hpp
** Author: April Castaneda, Victoria Fisher, Katie Stutts
** Date: 06.20.2019
** Description: GameEngine class specification file.
******************************************************************************/
#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <queue>
using std::queue;

#include <stack>
using std::stack;

#include <vector>
using std::vector;

#include <utility>
using std::swap;

#include <iomanip>
using std::setw;
using std::left;
/*
#include <ctime>
using std::time;

#include <cstdlib>
using std::rand;
using std::srand;
*/
#include "Card.hpp"

#include "Ascii.hpp"

//#include "Menu.hpp"

int INIT_CARDS=150;		// Initial card count
int START_TURNS=12;	    // Number turns start at
int INIT_HAND=7;		    // Initial card count in hand

// Game Engine Class declaration
class GameEngine
{
	private:
		int turns,
			choice;
		bool hasWon = false;
		Card** deck;	// Initial deck
        Card * card;
		vector <Card*> hand;	// Player's hand
		vector <Card*> table;	// Cards on table
		queue <Card*> pile;	// Cards to draw from
		stack <Card*> discard;	// Discarded cards
	public:
		// Constructor
		GameEngine();

		// Destructor
		~GameEngine();

		// Setters
		void setTurns(int turns);
		void setChoice(int choice);
		void setWon(bool won);

		// Getters
		int getTurns();
		int getChoice();
		bool getWon();

		// Function to create cards
    void createDeck();
    void createInventionDeck();
    void createPopDeck();
    void createHistoryDeck();
    void createVideoGamesDeck();
    void createCompSciDeck();

		// Function that shuffles deck
		void shuffleDeck();

		// Function to deal hand
		void dealHand();

		// Function to create pile
		void createPile();
		
		// Function to run Game	
		void runGame();

		// Function that draws card from pile
		Card* drawPile(int);

		// Function that adds card to table at position
		void addTable(Card*, int);

		// Function for user to press Enter
		void pressEnter();

		// Functions that plays hand or cards on table
		Card* playHand();
		Card* playTable(Card*);

		// Functions that validate integer input
		bool validateInput(string, int, unsigned);
 	
		// Functions that displays title and rules
		void displayTitle();
		void displayRules();

		// Function that displays hand
		void displayHand();

		// Function that displays table cards
		void displayTable();

		// Function that displays deck -- testing function
		void displayDeck();

		// Function that displays pile -- testing function
		void displayPile();
};
#endif

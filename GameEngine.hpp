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

using std::swap;

#include "Card.hpp"

//#include "Menu.hpp"

const int INIT_CARDS=150;		// Initial card count
const int START_TURNS=20;	// Number turns start at
const int INIT_HAND=15;		// Initial card count in hand -- should be 15 -- 2 for testing

// Game Engine Class declaration
class GameEngine
{
	private:
		int turns;
		bool hasWon = false;
		Card** deck;	// Initial deck
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
		void setWon(bool won);

		// Getters
		int getTurns();
		bool getWon();

		// Function to create menu
		void createMenus();

		// Function to create cards
		void createDeck();
        void createInventionDeck();
        void createHistoryDeck();
        void createCompSciDeck();
        void createVideoGameDeck();
        void createPopDeck();

		// Function that shuffles deck
		void shuffleDeck();

		// Function to deal hand
		void dealHand();

		// Function to create pile
		void createPile();
		
		// Function to run Game	
		void runGame();

		// Function that draws card from pile
		Card* drawPile();

		// Function that adds card to table at position
		void addTable(Card*, int);
		
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

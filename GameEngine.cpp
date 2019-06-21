/******************************************************************************
** Program name: GameEngine.cpp
** Author: April Castaneda, Victoria Fisher, Katie Stutts
** Date: 06.20.2019
** Description: GameEngine class implementation file.
******************************************************************************/
#include "GameEngine.hpp"

/******************************************************************************
** Description: Constructor
******************************************************************************/
GameEngine::GameEngine()
{
	// First, set variables
	setTurns(START_TURNS);	
	setWon(false);

	// Next, create deck
	createDeck();

	// Display deck at first
	displayDeck();

	// Next, shuffle deck
	shuffleDeck();

	// Next, deal hand
	dealHand();

	// Next, create pile from leftover deck
	createPile();
}

/******************************************************************************
** Description: Destructor
******************************************************************************/
GameEngine::~GameEngine()
{
	// Delete deck here
	// Delete hand here
	// Delete table here
	// Delete pile here
	// Delete discard here
}

/******************************************************************************
** Description: Setters
******************************************************************************/
void GameEngine::setTurns(int turns)
{
	this->turns = turns;
}

void GameEngine::setWon(bool won)
{
	this->won = won;
}

/******************************************************************************
** Description: Getters
******************************************************************************/
int GameEngine::getTurns()
{
	return turns;
}

bool GameEngine::getWon()
{
	return won;
}

/******************************************************************************
** Description: Function that creates deck of cards.
******************************************************************************/
void GameEngine::createDeck()
{
	deck = new Card* [INIT_CARDS];

	// Initialize all to NULL
	for(int i = 0; i < INIT_CARDS; i++)
	{
		deck[i] = NULL;
	}

	// Create specific cards
	deck[0] = new Card(2009, 0, "Pop Culture", "Lady Gaga's debut single \"Just Dance\" reached #1 on the Billboard Hot 100.");
	deck[1] = new Card(1994, 1, "Pop Culture", "\"Friends\", an American television sitcom, first aired on NBC.");
	deck[2] = new Card(1992, 2, "Pop Culture", "Radiohead, an English rock band, released their debut single \"Creep\"");
	deck[3] = new Card(2002, 3, "Pop Culture", "Detroit took Hollywood when \"8 Mile\", a film starring Eminem, premiered.");
	deck[4] = new Card(2012, 4, "Pop Culture", "Disney acquired Lucasfilm and gained ownership to Star Wars."); 
}

/******************************************************************************
** Description: Function that shuffles deck of cards.
******************************************************************************/
void GameEngine::shuffleDeck()
{
	for(int i = 0; i < INIT_CARDS; i++)
	{
		// Random for remaining positions
		int r = i + (rand() % (INIT_CARDS - i));

		// Swap card at current position with card at rand position
		swap(deck[i], deck[r]);
	}
}

/******************************************************************************
** Description: Function that deals hand.
******************************************************************************/
void GameEngine::dealHand()
{
	// Adds first INIT_HAND# of cards from deck into hand
	for(int i = 0; i < INIT_HAND; i++)
	{
		hand.push_back(deck[i]);
	}
}

/******************************************************************************
** Description: Function that creates pile from deck -- after hand has been 
**		dealt.
******************************************************************************/
void GameEngine::createPile()
{
	for(int i = INIT_HAND; i < INIT_CARDS; i++)
	{
		pile.push(deck[i]);
	} 
}

/******************************************************************************
** Description: Function to run game
******************************************************************************/
void GameEngine::runGame()
{
	// Test display deck
	cout << "Deck: " << endl;
	displayDeck();

	// Test display hand
	cout << "Hand: " << endl;
	displayHand();

	// Test display pile
	cout << "Pile: " << endl;
	displayPile();
}
	
/******************************************************************************
** Description: Function that displays deck - for testing
******************************************************************************/
void GameEngine::displayDeck()
{
	for(int i = 0; i < INIT_CARDS; i++)
	{
		cout << i+1 << ". ";
		deck[i]->displayCard();
		cout << endl;
	}
	cout << endl;
}

/******************************************************************************
** Description: Function that displays hand
******************************************************************************/
void GameEngine::displayHand()
{
	for(unsigned i = 0; i < hand.size(); i++)
	{
		cout << i+1 << ". ";
		hand[i]->displayCard();
		cout << endl;
	}
	cout << endl;
}

/******************************************************************************
** Description: Function that displays pile.
******************************************************************************/
void GameEngine::displayPile()
{
	int i = 1; 	// Pile card counter

	while(!pile.empty())
	{
		// Store front of pile in temp Card
		Card *temp = pile.front();

		// Display temp card
		cout << i << ". ";
		temp->displayCard();
		cout << endl;

		// Increment counter
		i++;

		// Pop off front
		pile.pop();
	}
}


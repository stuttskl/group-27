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

	// Display deck at first -- for testing
	cout << "Deck before shuffle: " << endl;
	displayDeck();

	// Next, shuffle deck
	shuffleDeck();

	// Next, deal hand
	dealHand();

	// Next, create pile from leftover deck
	createPile();

	// Next, create Menus
//	createMenus();
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
** Description: Function that creates menus.
******************************************************************************/
/*void GameEngine::createMenus()
{
	handMenu = new Menu(
}
*/
/******************************************************************************
** Description: Function to run game
******************************************************************************/
void GameEngine::runGame()
{
	// Test display deck
	cout << "Deck: " << endl;
	displayDeck();

	// First, display game title and rules
	// Need to be implemented -- not written yet
	displayTitle();	
	displayRules();

	// Next, display hand -- basic implementation for nwo
	cout << "Hand: " << endl;
	displayHand();

	// Next, draw card from pile, add to table, and display table
	Card *drawn = drawPile();
	addTable(drawn, 0); // Adds drawn card at position 0
	cout << endl << "Cards on the table: " << endl;
	displayTable();	

	// Next, ask user which card they would like to play from hand 
}

/******************************************************************************
** Description: Function that draws from pile.
******************************************************************************/
Card* GameEngine::drawPile()
{
	// Store card on top of pile
	Card *top = pile.front();
	Card *copy = new Card(*top);
	
	// Display temp card
	cout << "Card drawn from pile reads:" << endl;
	top->displayCard();
	cout << endl;

	// Delete front of pile
	pile.pop();

	// Return stored card
	return copy;
}

/******************************************************************************
** Description: Function that adds card to cards on table at position.
******************************************************************************/
void GameEngine::addTable(Card* inCard, int pos)
{
	// If no cards yet on table
	if(table.empty())
	{
		table.push_back(inCard);
	}
	else	// If there are cards already, use position
	{
		// Create iterator pointing to position
		auto itPos = table.begin() + pos;

		// Insert card at position
		table.insert(itPos, inCard);
	}
}

/******************************************************************************
** Description: Function that displays game title.
******************************************************************************/
void GameEngine::displayTitle()
{
}

/******************************************************************************
** Description: Function that displays game rules.
******************************************************************************/
void GameEngine::displayRules()
{
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
** Description: Function that displays table
******************************************************************************/
void GameEngine::displayTable()
{
	for(unsigned i = 0; i < table.size(); i++)
	{
		cout << i+1 << ". ";
		table[i]->displayCard();
		cout << endl;
	}
	cout << endl;
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


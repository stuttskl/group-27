/******************************************************************************
** Program name: Card.hpp
** Author: April Castaneda, Victoria Fisher, Katie STutts
** Date: 06.20.2019
** Description: Card.hpp is the Card class specification file. (Node)
******************************************************************************/
#ifndef CARD_HPP
#define CARD_HPP

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

// Card class declaration (Node)
class Card{
	protected:
		int year,
			cardNum,
			cardPlace;
		string category,
			description;
		Card *left,
			*right;
	public:
		Card(int year=0, int cardNum=0, string category="", string description="");
		Card(const Card&);

		// Setters
		void setYear(int);
		void setCardNum(int);
		void setCardPlace(int);
		void setCategory(string);
		void setDescription(string);
		void setLeft(Card*);
		void setRight(Card*);

		// Getters
		int getYear();
		int getCardNum();
		int getCardPlace();
		string getCategory();
		string getDescription();
		Card* getLeft();
		Card* getRight();

		// Displays card
		void displayCard();	// Displays card description
};
#endif

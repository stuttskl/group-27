/******************************************************************************
** Program name: Card.cpp
** Author: April Castaneda, Victoria Fisher, Katie Stutts
** Date: 06.20.2019
** Description: Card.cpp is the Card class implementation file.
******************************************************************************/
#include "Card.hpp"

/******************************************************************************
** Description: Constructor
******************************************************************************/
Card::Card(int year, int cardNum, string category, string description)
{
	setYear(year);
	setCardNum(cardNum);
	setCardPlace(0);
	setCategory(category);
	setDescription(description);
	setLeft(NULL);
	setRight(NULL);
}

/******************************************************************************
** Description: Copy Constructor
******************************************************************************/
Card::Card(const Card &old_obj)
{
	setYear(old_obj.year);
	setCardNum(old_obj.cardNum);
	setCardPlace(old_obj.cardPlace);
	setCategory(old_obj.category);
	setDescription(old_obj.description);
	setLeft(old_obj.left);
	setRight(old_obj.right);
}

/******************************************************************************
** Description: Setters
******************************************************************************/
void Card::setYear(int year)
{
	this->year = year;
}

void Card::setCardNum(int cardNum)
{
	this->cardNum = cardNum;
}

void Card::setCardPlace(int cardPlace)
{
	this->cardPlace = cardPlace;
}

void Card::setCategory(string category)
{
	this->category = category;
}

void Card::setDescription(string description)
{
	this->description = description;
}

void Card::setLeft(Card* left)
{
	this->left = left;
}

void Card::setRight(Card* right)
{
	this->right = right;
}

/******************************************************************************
** Description: Getters
******************************************************************************/
int Card::getYear()
{
	return year;
}

int Card::getCardNum()
{
	return cardNum;
}

int Card::getCardPlace()
{
	return cardPlace;
}

string Card::getCategory()
{
	return category;
}

string Card::getDescription()
{
	return description;
}

Card* Card::getLeft()
{
	return left;
}

Card* Card::getRight()
{
	return right;
}

/******************************************************************************
** Description: Function that displays Card description
******************************************************************************/
void Card::displayCard()
{
	cout << description;
}

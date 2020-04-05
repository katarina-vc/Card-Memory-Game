/*
* Author:		Katarina Capalbo
* Date:			2/5/2018
* Assignment:	C++ Advanced Project 1
*
* Description: Card.cpp defines the functions of class Card. Every card object is automatically set as
*              false. A card object should look like:
*			   +---+
*			   | * |
*			   +---+
*/

#include <iostream>
#include <string>
#include "Card.h"
#include "MemoryGame.h"

using namespace std;

Card::Card()
{
	isUp = false;
}

Card::~Card()
{
}

void Card::setFront(char c) // set what is on the front of the card
{
	this->front = c;
}

char Card::getFront()	// get what is on the front of the card
{
	return front;
}

void Card::setBack(char c)	// set what is on the back of the card ( * )
{
	this->back = c;
}

void Card::printCardTopBottom()	// prints +---+ (helpful for printing multiple cards)
{
	cout << "+---+";
}

void Card::print() 		// prints | X | where X is the front or back of the card
{
	cout << "| ";
	if (isCardUp())
	{
		cout << front; 
	}
	
	if(isCardUp() == false)
	{
		cout << back;
	}
	cout << " |";
}

bool Card::isCardUp()		// is the card currently face up
{
	// 0 equals false, 1 equals true
	// false = * = back ,,, true = num = front 

	if (isUp == true)
	{
		return true; // front of the card is showing a number
	}
	else if (isUp == false)
	{
		return false; // back of the card is showing *
	}
}

void Card::turnUp()			// put card so front is up
{
	if (isCardUp() == false)
	{
		isUp = true;
	}
}

void Card::turnDown()		// put card so front is down
{
	if (isCardUp() == true)
	{
		isUp = false;
	}
}
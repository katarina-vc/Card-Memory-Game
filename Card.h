/*
* Author:		Katarina Capalbo
* Date:			2/5/2018
* Assignment:	C++ Advanced Project 1
*
* Description: Card.h, creates a single card.
*
*/

#pragma once

class Card
{
private:
	char front;					// character on front of card
	char back;					// character on back of card
	bool isUp;					// is card currently face up or down

public:
	Card(void);
	~Card(void);

	void setFront(char c);		// set what is on the front of the card
	char getFront();			// get what is on the front of the card 
	void setBack(char c);		// set what is on the back of the card

	void printCardTopBottom();	// prints +---+ (helpful for printing multiple cards)
	void print();			// prints | X | where X is the front or back of the card

	bool isCardUp();		// is the card currently face up
	void turnUp();			// put card so front is up
	void turnDown();		// put card so front is down
};


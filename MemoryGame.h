/*
* Author:		Katarina Capalbo
* Date:			2/5/2018
* Assignment:	C++ Advanced Project 1
*
* Description: MemoryGame.h creates an array of objects of class Card. Utilizes fuctions and card objects
*			   to create a game out of a 'deck' of card objects. 
*
*/

#pragma once
#include "Card.h"

class MemoryGame
{
private:
	static const int MAXDECK = 4;		// card deck is MAXDECK x MAXDECK cards
	static const int MAXGUESSES = 15;	// max number of guesses before lose game 

	Card cards[MAXDECK][MAXDECK];	// the cards
	int numGuesses;			// how many guesses have been made
	int numMatches;			// how many matches have been found so far
	int firstRow;				// row of first card turned over
	int firstCol;				// column of first card turned over
	int secondRow;				// row of second card turned over
	int secondCol;				// column of second card turned over

	void getCard(int &row, int &col);	// prompt the user for card to turn over and turn it over

public:
	MemoryGame(void);
	~MemoryGame(void);

	static enum status { WIN, LOSE, CONTINUE };	// used for current status of the game  (static)

	void resetGame(bool randomShuffle);

	// put random pairs in MAXDECK x MAXDECK matrix
	// place them all face down, reset guess and match counter

	void printBoard();	// print the 4x4 card matrix to the screen
	status getStatus();	// return the current state of the game
	void getFirstCard();	// prompt the user for the first card to turn over and turn it over
	void getSecondCard();	// prompt the user for the second card to turn over and turn it over
	bool cardsMatch();	// return true if the 2 cards that are face up are a match
	void endTurn();		// turn cards over if it wasn't a match, leave up if it is a match
	int numGuessesMade();	// return how many total guesses the player has made

};


/*
* Author:		Katarina Capalbo
* Date:			2/5/2018
* Assignment:	C++ Advanced Project 1
*
* Description: MemoryGame.cpp defines functions of class MemoryGame. Creates card object
*			   and initializes it into a deck (array) of cards.
*			    
*
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include "MemoryGame.h"
#include "Card.h"
#include <time.h>  

using namespace std;

MemoryGame::MemoryGame(void)
{
}
MemoryGame::~MemoryGame(void)
{
}

void MemoryGame::resetGame(bool randomShuffle)
{

// RESET MATCHES AND GUESSES TO 0
	numMatches = 0;
	numGuesses = 0;

// INITIALIZE THE BACK OF THE CARD TO '*'
	for (int i = 0; i < MAXDECK; i++)
	{
		for (int n = 0; n < MAXDECK; n++)
		{
			cards[i][n].setBack('*');
		}
	}

// INITIALIZE THE FRONT OF THE CARD
	int num = 48;
	for (int k = 0; k < MAXDECK; k++)
		{
			for (int i = 0; i < MAXDECK; i++)
			{
				if ((i % 2) == 0)
				{
					num++;
					cards[k][i].setFront(static_cast<char>(num));
				}
				else
				{

					cards[k][i].setFront(static_cast<char>(num));

				}
			}
		}

// SHUFFLE THE DECK
	if (randomShuffle == true)
		{
			srand(time(NULL));

			for (int k = 0; k < MAXDECK; k++)
			{
				for (int i = 0; i < MAXDECK; i++)
				{
					int randRow = rand() % MAXDECK;
					int randCol = rand() % MAXDECK;

					int randRow2 = rand() % MAXDECK;
					int randCol2 = rand() % MAXDECK;

					Card temp;

					temp = cards[randRow][randCol];
					cards[randRow][randCol] = cards[randRow2][randCol2];
					cards[randRow2][randCol2] = temp;
				}
			}
		}
	
}

void MemoryGame::printBoard()	// print the 4x4 card matrix to the screen
{
	cout << endl;
	for (int j = 0; j < MAXDECK; j++) // PRINTS TOP LAYER OF A CARD
	{
		for (int i = 0; i < MAXDECK; i++)
		{
			cards[j][i].printCardTopBottom();
		}

		cout << endl;

		for (int i = 0; i < MAXDECK; i++) // PRINTS CONTENTS OF A CARD
		{
			cards[j][i].print();
		}

		cout << endl;

		for (int i = 0; i < MAXDECK; i++) // PRINTS BOTTOM LAYER OF A CARD
		{
			cards[j][i].printCardTopBottom();
		}
		
		cout << endl;
	}
} 

MemoryGame::status MemoryGame::getStatus()	// return the current state of the game
{
// DETERMINE HOW MANY MATCHES THEIR WILL BE IN THE DECK
	int matches;
	matches = (MAXDECK * MAXDECK) / 2;

// IF USER HAS NOT USED UP THEIR GUESSES OR FOUND ALL THE MATCHES CONTINUE
	while((numGuessesMade() < MAXGUESSES) && (numMatches != matches))
	{
		return CONTINUE;
	}

// IF USER HAS FOUND ALL THE MATCHES THEN RETURN WIN
	 while(numMatches == matches)
	{
		return WIN;
	}

// IF USER HAS USED UP ALL THE GUESSES THEN RETURN LOSE
	while(numGuessesMade() >= MAXGUESSES)
	{
		return LOSE;
	}
}

void MemoryGame::getFirstCard()	// prompt the user for the first card to turn over and turn it over
{
	cout << "Row Column? ";
	cin >> firstRow >> firstCol;

// CHECK FOR INVALID ROW OR COLUMN
	while ((firstRow < 1) || (firstCol < 1) || (firstRow > MAXDECK) || (firstCol > MAXDECK))
	{
		cout << endl << "Invalid row and/or column" << endl;
		cout << "Row Column? ";
		cin >> firstRow >> firstCol;
	}

// CHECK TO MAKE SURE THE USER ISNT PROMPTING FOR A CARD THAT IS ALREADY TURNED UP
	while (cards[firstRow - 1][firstCol - 1].isCardUp() == true)
	{
		cout << endl << "Card is already face up" << endl;
		cout << "Row Column? ";
		cin >> firstRow >> firstCol;
	}

	getCard(firstRow, firstCol);
}

void MemoryGame::getSecondCard()	// prompt the user for the second card to turn over and turn it over
{
	cout << "Row Column? ";
	cin >> secondRow >> secondCol;

// CHECK FOR INVALID ROW OR COLUMN
	while ((secondRow < 1) || (secondCol < 1) || (secondRow > MAXDECK) || (secondRow > MAXDECK))
	{
		cout << endl << "Invalid row and/or column" << endl;
		cout << "Row Column? ";
		cin >> secondRow >> secondCol;
	}

// CHECK TO MAKE SURE THE USER ISNT PROMPTING FOR A CARD THAT IS ALREADY TURNED UP
	while (cards[secondRow - 1][secondCol - 1].isCardUp() == true)
	{
		cout << endl << "Card is already face up" << endl;
		cout << "Row Column? ";
		cin >> secondRow >> secondCol;
	}

	getCard(secondRow, secondCol);
}

bool MemoryGame::cardsMatch()	// return true if the 2 cards that are face up are a match 
{
	if (cards[firstRow - 1][firstCol - 1].getFront() == cards[secondRow - 1][secondCol - 1].getFront())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void MemoryGame::endTurn()		// turn cards over if it wasn't a match, leave up if it is a match
{
	if (cardsMatch() == true)
	{
		numMatches++;
		numGuesses++;
		cout << "You made a match!" << endl;
	}

	if (cardsMatch() == false)
	{
		cards[firstRow - 1][firstCol - 1].turnDown();

		cards[secondRow - 1][secondCol - 1].turnDown();

		numGuesses++;
		
		cout << "Try again" << endl;
	}

	cout << endl;
}

int MemoryGame::numGuessesMade()	// return how many total guesses the player has made
{
	return numGuesses;
}

void MemoryGame::getCard(int &row, int &col)	// turn over card and print board
{
	cards[row - 1][col - 1].turnUp();

	printBoard();
}

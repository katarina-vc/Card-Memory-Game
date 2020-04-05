/*
* Author:		Katarina Capalbo
* Date:			2/5/2018
* Assignment:	C++ Advanced Project 1
*
* Description: Play.cpp contains main(). Creates an object of class MemoryGame. 
*			   Brings user through the card matching game and determines output for
*			   a win or a loss.
*
*/

#include <iostream>
#include <string>
#include "MemoryGame.h"
#include "Card.h"

using namespace std;

int main() {

// DECLARATIONS
	MemoryGame game; 
	char shuffle;

// PROMPT USER FOR A RANDOM SHUFFLE
	cout << "Random Shuffle (y/n)? ";
	cin >> shuffle;

	if (shuffle == 'y')
	{
		game.resetGame(true);
	}

	if (shuffle == 'n')
	{
		game.resetGame(false);
	}

// GAMEPLAY
	while (game.getStatus() == MemoryGame::CONTINUE)
	{
		game.printBoard();
		game.getFirstCard();
		game.getSecondCard();
		game.endTurn();
	}

// WIN OUTPUT
	if (game.getStatus() == MemoryGame::WIN)
	{
		cout << endl << "You won with " << game.numGuessesMade() << " guesses!" << endl;
	}

// LOSE OUTPUT
	if (game.getStatus() == MemoryGame::LOSE)
	{
		cout << endl << "You lost!" << endl;
	}

	system("PAUSE");
	return 0;
}
// FindTheGold.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>     
#include <time.h>   
#include <iomanip> //Had trouble displaying array, had to research ways online to display a 2-D array, found this
// This will help with the setw function that will be used to display the array
using namespace std;   

const int NUM_ROWS = 8;
const int NUM_COLS = 8;
const int NUM_LIVES = 5;
const int ITEMS_TO_BURY = 5;
const int PLACED_BOMB = 1;
//for the gold, bomb, and the number of lives within the game board

void initBoard(char board[NUM_ROWS][NUM_COLS]); //initializing the board
void printGame(char board[NUM_ROWS][NUM_COLS]);
void hideTreasures(char board[NUM_ROWS][NUM_COLS]); 
void gameRules(); 
void guessLocations(char board[NUM_ROWS][NUM_COLS]); 



int main()
{
	// The actual array
	char board[NUM_ROWS][NUM_COLS];
	char answer;
	do
	{
		initBoard(board);
		printGame(board);
		hideTreasures(board);
		gameRules();
		guessLocations(board);
		
		cout << endl;
		cout << "Play Again? Enter 'y' ";
		cin >> answer;
	} while (answer == 'Y' || answer == 'y'); //allowing the user to play again at the end of game

	return 0;
}
	

void initBoard(char board[NUM_ROWS][NUM_COLS])
{
	int row, col;

	for (row = 0; row < NUM_ROWS; row++)
	{
		for (col = 0; col < NUM_COLS; col++)
		{
			board[row][col] = '?';
		}
	}
}

void printGame(char board[NUM_ROWS][NUM_COLS])
{
	int row, col;
	cout << endl;
	cout << " ";
	for (col = 0; col < NUM_COLS; col++)
		cout << setw(4) << col + 1;
	cout << endl;
	cout << " " << " -------------------------------------- " << endl;
	//displaying the rows of the array

	for (row = 0; row < NUM_ROWS; row++)
	{
		cout << " " << row + 1 << " | "; //displaying borders of the board
		for (col = 0; col < NUM_COLS; col++)
		{
			cout << setw(4) << board[row][col]; //the 4 in the setw sets the stream size
		}
		cout << endl;
	}
	cout << " " << " -------------------------------------- " << endl;
}

void hideTreasures(char board[NUM_ROWS][NUM_COLS]) 
{
	int gold = 0;
	int x, y;
	int bomb = 0;
	srand(time(NULL));

	// Hiding treasure randomly on the boardd

	for (gold = 0; gold < ITEMS_TO_BURY; gold++)
	{
		x = rand() % NUM_ROWS;
		y = rand() % NUM_COLS;
		board[x][y] = 'G';
	}  // end of for loop

	for (bomb = 0; bomb < PLACED_BOMB; bomb++)
	{
		x = rand() % NUM_ROWS;
		y = rand() % NUM_COLS;
		board[x][y] = 'B';
	}
}
		void gameRules() //rule board to display at the start of the game
		{
			cout << endl;
			cout << "*****" << " ************************* " << "*****" << endl;
			cout << "*********" << " Try to Find Gold " << "**********" << endl;
			cout << "*********" << " You have 5 Guesses" << "*********" << endl;
			cout << "**********" << " 5 pieces of gold " << "*********" << endl;
			cout << "*************" << " and 1 bomb " << "************" << endl;
			cout << "*************" << " Good Luck! " << "************" << endl;
			cout << "*****" << " ************************* " << "*****" << endl;
			cout << endl;
		}
	
		void guessLocations(char board[NUM_ROWS][NUM_COLS])
		{
			// Allow user to keep guessing where the treasure is hidden
			int rowGuessed, colGuessed;
			int guessesLeft = NUM_LIVES;
			int points = 0; 

			while (guessesLeft > 0)
			{
				cout << "Enter X Coordinate: 1-" << NUM_COLS << ": ";
				cin >> rowGuessed;
				cout << "Enter Y Coordinate: 1-" << NUM_ROWS << ": ";
				cin >> colGuessed;

				// Check whether any treasure is buried where the user guessed
				if (board[rowGuessed][colGuessed] == 'G')
				{
					cout << "You Found GOLD!";
					board[rowGuessed][colGuessed] = 'F';
					points = points + 1;
					guessesLeft--;
					cout << "\t" << " You have " << guessesLeft << " guesses left " << endl;
					cout << endl;
					continue;
				}
				else if (board[rowGuessed][colGuessed] == 'B')
				{
					cout << endl;
					guessesLeft = 0;
					cout << " You found a Bomb... " << "The game is over " << endl;
					break;
				}
				else
				cout << "Uh ohh.. No gold there ";
				guessesLeft--;
				cout << "\t" << "You have " << guessesLeft << " guesses left " << endl;
			}


			cout << "You earned " << points << " points " << endl;
			cout << "Better luck next time " << endl;
			cout << " If you wish to keep playing the next baord will display " << endl;
			cout << endl;

			cout << " ";
			for (colGuessed = 0; colGuessed < NUM_COLS; colGuessed++)
			cout << setw(4) << colGuessed + 1;
			cout << endl;
			cout << " " << " -------------------------------------- " << endl;

			for (rowGuessed = 0; rowGuessed < NUM_ROWS; rowGuessed++)
			{
				cout << " " << rowGuessed << + 1 << " | ";
				for (colGuessed = 0; colGuessed < NUM_COLS; colGuessed++)
				{
					cout << setw(4) << board[rowGuessed][colGuessed];
				}
				cout << endl;
			}
			cout << " " << " -------------------------------------- " << endl;
		}
			

		
			

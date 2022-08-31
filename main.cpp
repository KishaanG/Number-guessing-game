/*

	Author: Kishaan Gidda

	Description: Guessing game with ten guesses mentioning if the user's guess is closer, further or the same distance as their previous guess. 

	Last modified: 10 June, 2022.

*/

#include <iostream>
#include <time.h>
#include <cmath>
using namespace std;

/// =========== Prototypes ===========

int randNumGenerator(int, int);
void guessInterface();
bool evaluateGuess(int, int, int, int &, int &);
void keyToContinue();
int checkRepeat();

/// =========== Definitions ===========

void keyToContinue()
{
	cin.ignore();
	cout << "Type any key to continue..." << endl;
	getchar();
	return;
}

int randNumGenerator(int highestNum, int lowestNum)
{
	int randNum = 0;
	srand (time(NULL));
	randNum = rand() % highestNum + lowestNum; /// This generates a random number. 
	return randNum;
}

void guessInterface()
{
	int randNum = randNumGenerator(50, 1);
	int userGuess = 0;
	int oldDist = 0;
	int currentDist = 0;
	bool gameWin = false;
	for(int i = 0; i < 10 and gameWin == false; i++) /// A for loop that runs for the ten guesses the user has and while the user hasn't won the game. 
	{
		do
		{
			cout << "What number would you like to guess between 1 and 50 inclusive?\n(Guess " << i+1 << ")" << endl;
			cin >> userGuess;
			if(userGuess > 50 || userGuess < 1)
			{ /// Checks for invalid answers and gives an error message. 
				cout << "Please enter a number between and including 1 and 50." << endl;
				keyToContinue();
				system("clear");
			}
		}while(userGuess > 50 || userGuess < 1); /// Loops while the user gives an invalid guess.

		gameWin = evaluateGuess(userGuess, randNum, i, oldDist, currentDist);
	}
	if(gameWin == false)
	{
		cout << "You ran out of guesses. The answer was " << randNum << "." << endl;	
	}
	return;
}

bool evaluateGuess(int userGuess, int targetNum, int counter, int & oldDist, int & currentDist)
{
	bool gameWin = false;
	if(userGuess == targetNum)
	{/// Display a message if the user won.
		system("clear");
		cout << "You won!!! You got the number in " << counter + 1 << " guesses. " << endl;
		gameWin =  true;
	}
	else
	{
		if(counter == 0)
		{/// If it is the user's first guess, I tell them their geuss was incorrect because there is no previous guess to base a message on. 
			currentDist = abs(userGuess - targetNum); /// This will get the distance between the user's guess and the number they're trying to guess. 
			cout << "Your guess is wrong." << endl;
			keyToContinue();
			system("clear");
		}
		else
		{
			oldDist = currentDist; /// This makes the previous currentDist, the oldDist.
			currentDist = abs(userGuess - targetNum); /// This sets the new currentDist. 
			if(currentDist < oldDist)
			{ /// If the distance between the numbers is smaller than the previous distance, the guess is closer.
				cout << "Your guess is closer than your previous." << endl;
				keyToContinue();
				system("clear");
			}
			else if(currentDist == oldDist)
			{ /// If the distance between the numbers is the same as the previous distance, the guess is the same distance away as the previous.
				cout << "Your guess is the same distance as your last guess." << endl;
				keyToContinue();
				system("clear");
			}
			else if(currentDist > oldDist)
			{ /// If the distance between the numbers is larger than the previous distance, the guess is further.
				cout << "Your guess is further than your previous guess." << endl;
				keyToContinue();
				system("clear");
			}
		}
	}
	if(gameWin)
	{
		return true;
	}
	else return false;
}

int checkRepeat()
{
	int userRepeat = 0;
	do
	{
		cout << "Would you like to play again with a new number?\n1. Yes\n2. No" << endl;
		cin >> userRepeat; /// Checks if the user wants to play again. 
		if(userRepeat > 2 || userRepeat < 1)
		{/// This validates the number they typed in.
			cout << "Type either 1 or 2." << endl;
			keyToContinue();
			system("clear");
		}
	}while(userRepeat > 2 || userRepeat < 1);
	return userRepeat;
}

int main()
{
	int userRepeat = 0;
	do
	{
		guessInterface();	
		userRepeat = checkRepeat();
		system("clear");
	}while(userRepeat == 1);/// This will repeat the game while the user wants to repeat it. 
	return 0;
}

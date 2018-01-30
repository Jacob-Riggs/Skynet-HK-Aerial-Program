// skynetAI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0))); //random number generator

	int secretNumber = rand() % 100 + 1; //random number between 1 and 64
	int tries = 0;
	int guess;
	cout << "\tWelcome to Skynet\n\n";

	do {
		cout << "Enter a guess: ";
		cin >> guess;
		++tries;

		if (guess > secretNumber) { // conditional that says your guess is too high
			cout << "Too high!\n\n";
		}
		else if (guess < secretNumber) { // conditional that says your guess is too low
			cout << "Too low!\n\n";
		}
		else {
			cout << "\nThat's it! You got it in " << tries << "guesses!\n"; // conditional that says your guess was correct
		}
	} while (guess != secretNumber); // loops the game so that you can keep guessing until correct

	return 0;


}


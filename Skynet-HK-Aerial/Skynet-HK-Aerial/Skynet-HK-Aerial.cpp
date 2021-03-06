// skynetAI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	//generate the enemy location
	cout << "Generate random enemy in 8x8 grid..." << endl;
	srand(time(0));

	int searchGridHighNumber = 64; //sets the highest number the drone can search through
	int searchGridLowNumber = 1; //sets the lowest number the drone ca search through
	int enemyLocation = rand() % searchGridHighNumber + searchGridLowNumber; //generates the enemy location somewhere between the two numbers

	cout << "Skynet software initializing";

	int targetLocationPredictionCounter = 0; //sets the counter for how many pings it takes to find the enemy to 0
	bool targetFound = false; //sets the boolean for finding the enemy to false so the while loop works

	while (targetFound == false) { //the while loop states that as long as the enemy isn't found it will keep reiterating until it does
		int targetLocationPredicition = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber; //based on the high and low points, the program gets a number to check
		targetLocationPredictionCounter++; //adds 1 to the prediction counter so that we know how many pings it took

		cout << "============================================================================" << endl;
		cout << "Skynet HK-Aerial Radar seding out ping #" << targetLocationPredictionCounter << endl;

		if (targetLocationPredicition > enemyLocation) { //states what will happen if the prediction was higher than the enemy's location
			searchGridHighNumber = targetLocationPredicition - 1; //this chops off all the numbers higher than the prediciton so that they aren't checked again
			cout << "The prediciton of " << targetLocationPredicition << " was higher than the actual location. ";
			cout << "The new searchGridHighNumber = " << searchGridHighNumber << endl;
		}
		else if (targetLocationPredicition < enemyLocation) { //states what will happen if the prediction was lower than the enemy's location
			searchGridLowNumber = targetLocationPredicition + 1; //this chops off all the numbers lower than the prediction so that they aren't checked again
			cout << "The prediciton of " << targetLocationPredicition << " was lower than the actual location. ";
			cout << "The new searchGridLowNumber = " << searchGridLowNumber << endl;
		}
		else if (targetLocationPredicition = enemyLocation) { //states what will happen if the prediction was correct on the enemy's location
			cout << "Enemy hiding at location #" << enemyLocation << endl;
			cout << "Target was found at location #" << targetLocationPredicition << endl;
			cout << "Skynet HK-Aerial Software took " << targetLocationPredictionCounter << " predicitons to find the target.";
			targetFound = true; //sets the targetFound to true so that the while loop will end
		}
		else { //states what will happen if something were to go wrong with the program
			cout << "System malfunctioned." << endl;
			cout << "Send in unit for repair" << endl;
			targetFound = true; //sets targetFound to true so that the application will end and not run continously.
		}
	}
	system("pause");
	return 0;
}


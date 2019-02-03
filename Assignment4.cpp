#include <iostream>
//This is needed for generating a random number
#include <ctime>
#include <string>
using namespace std;

int main() {
	//Introducing the program 
	system("Title Skynet HK-Aerial Software");
	cout << "Skynet HK-Aerial Software" << endl;
	cout << "Generating Random enemy location on an 8x8 grid...." << endl;

	//Variables
	int binarySearchGridHighNumber = 64;
	int binarySearchGridLowNumber = 1;
	int linearSearchGridLowNumber = 1;

	// The counters for the formulas
	int binaryTargetLocationPredictionCounter = 0;
	int humanTargetLocationPredictionCounter = 0;
	int linearTargetLocationPredictionCounter = 0;
	int randomTargetLocationPredictionCounter = 0;

	//Generating a random number from 1 - 64
	srand(time(0));

	//Setting the enemy position 
	int enemyLocation = rand() % 64 + 1;


	//Conditions needed for the functions 
	bool humanSearch = false;
	bool binarySearch = false;
	bool linearSearch = false;
	bool randomSearch = false;
	bool continueGame = false;

	// Human Search
	
	if (humanSearch == false) {
		int humanGuess;

		cout << "Choose a number between 1 - 64.\nIf you manage to guess right, the rest of the software will be unlocked.\nGood Luck!" << endl;
		cin >> humanGuess;
		while (humanGuess != enemyLocation) {
			cout << "Wrong Number! Try Again." << endl;
			if (humanGuess > enemyLocation) {
				cout << "Hint: The enemy is hiding in a sector lower than what you guessed" << endl;
				humanTargetLocationPredictionCounter++;
			}
			if (humanGuess < enemyLocation) {
				cout << "Hint: The enemy is hiding in a sector higher than what you guessed" << endl;
				humanTargetLocationPredictionCounter++;
			}
			cin >> humanGuess;
		}
		if (humanGuess == enemyLocation) {
			cout << "Nice Job! You guess the correct number. It only took you " << humanTargetLocationPredictionCounter << " tries." << endl;
			humanSearch = true;
			continueGame = true;
		}
	}
	while (continueGame == true) {

		//Linear Search
		cout << "The enemy as you now know was located at location #" << enemyLocation << " on an 8x8 grid with 64 sectors.\n" << endl;
		cout << "Initializing Skynet HK-Aerial Software (Linear Search)......" << endl;
		system("pause");
		while (linearSearch == false) {
			int linearSearchAlgorithm = linearSearchGridLowNumber++;
			cout << linearSearchAlgorithm << endl;
			linearTargetLocationPredictionCounter++;
			cout << "===" << endl;
			if (linearSearchGridLowNumber == enemyLocation) {
				cout << "Enemy was found in location: " << enemyLocation << " using linear search algorithm." << endl;
				cout << "Skynet HK-Aerial Software took " << linearTargetLocationPredictionCounter << " predictions to find the enemy location\non a grid size of 8x8 using a linear search algorithm\n" << endl;
				linearSearch = true;
			}
		}

		// Random Search
		cout << "Initializing Skynet HK-Aerial Software (Random Search)......" << endl;
		system("pause");
		while (randomSearch == false) {
			int randomSearchAlgorithm = rand() % 64 + 1;
			cout << randomSearchAlgorithm << endl;
			randomTargetLocationPredictionCounter++;
			cout << "===" << endl;
			if (randomSearchAlgorithm == enemyLocation) {
				cout << "Enemy was found in location: " << enemyLocation << " using random search algorithm." << endl;
				cout << "Skynet HK-Aerial Software took " << randomTargetLocationPredictionCounter << " predictions to find the enemy location\non a grid size of 8x8 using a random search algorithm\n" << endl;
				randomSearch = true;
			}

		}

		// Binary Search
		cout << "Initializing Skynet HK-Aerial Software (Binary Search)......" << endl;
		system("pause");
		while (binarySearch == false) {
			//Software selecting target location prediction in flyover hunt for enemy. (Thank you for this Mr. Hinton!)
			int targetLocationPrediction = ((binarySearchGridHighNumber - binarySearchGridLowNumber) / 2) + binarySearchGridLowNumber; //Binary search Algorithm  
			// Increases with each iteration 
			binaryTargetLocationPredictionCounter++;
			cout << "====================================================================================" << endl;


			//If the number the computer guessed is higher than the enemy position, this function will run
			if (targetLocationPrediction > enemyLocation) {
				cout << "Skynet HK-Aerial Radar sending out ping #" << binaryTargetLocationPredictionCounter << ":" << endl;
				// New high number guess
				binarySearchGridHighNumber = targetLocationPrediction - 1;
				cout << "The target location prediction of " << targetLocationPrediction << " was higher than the actual enemy location of " << enemyLocation << endl;
				cout << "The new searchGridHighNumber = " << binarySearchGridHighNumber << endl;
			}
			//If the number the computer guessed is lower than the enemy position, this function will run
			else if (targetLocationPrediction < enemyLocation) {
				cout << "Skynet HK-Aerial Radar sending out ping #" << binaryTargetLocationPredictionCounter << ":" << endl;
				// New low number guess
				binarySearchGridLowNumber = targetLocationPrediction + 1;
				cout << "The target location prediction of " << targetLocationPrediction << " was lower than the actual enemy location of " << enemyLocation << endl;
				cout << "The new searchGridLowNumber = " << binarySearchGridLowNumber << endl;
			}
			// If the number the compuer guessed is the enemy's location, this function will run
			else if (targetLocationPrediction == enemyLocation) {
				cout << "Enemy was hiding at location #" << enemyLocation << endl;
				cout << "Target was found at location #" << targetLocationPrediction << endl;
				cout << "Skynet HK-Aerial Software took " << binaryTargetLocationPredictionCounter << " predictions to find the enemy location\non a grid size of 8x8 using a binary search algorithm" << endl;
				//Stops the while loop
				binarySearch = true;
				continueGame = false;
				system("pause");
			}
		}
		if (continueGame == false) {
			cout << "************************************************************************************************************************" << endl;
			cout << "*************************************************SCOREBOARD*************************************************************" << endl; 
			cout << "************************************************************************************************************************" << endl;
			cout << "It took the human " << humanTargetLocationPredictionCounter << " tries to guess the correct number" << endl;
			cout << "It took the linear algorithrm search " << linearTargetLocationPredictionCounter << " tries to guess the correct number" << endl;
			cout << "It took the random algorithrm search " << randomTargetLocationPredictionCounter << " tries to guess the correct number" << endl;
			cout << "It took the binary algorithrm search " << binaryTargetLocationPredictionCounter << " tries to guess the correct number" << endl;
		}
	}
	system("pause");
	return 0;
}
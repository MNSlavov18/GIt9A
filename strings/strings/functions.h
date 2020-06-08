#pragma once
#include <iostream> //cin, cout
#include<stdio.h> //NULL
#include<string>    //String
#include<stdlib.h>  //srand, rand
#include<time.h>    //time
#include"data.h"
using namespace std;
int getRandNumber(int lowerNumber, int upperNumber)
{
	int randNumber;
	/* initialize random seed: */
	srand(time(NULL));

	randNumber = rand() % upperNumber + lowerNumber;
	return randNumber;
}

WORD randomWord()
{
	int randIndex;
	randIndex = getRandNumber(0, 3);
	WORD  generatedWord = words[randIndex];
	return generatedWord;
}
bool Menu()
{
	WORD word1;
	int roundsCount, correct = 0, wrong = 0;
	string difficulty;
	cout << "How many rounds do you wish to play: ";
	cin >> roundsCount;
	for (int i = 0; i < roundsCount; i++)
	{
		bool difficultyCheck = false;
		do
		{
			/*If the user failed to input the difficulty correctly
			 they'll be forced to do so again.*/
			if (difficultyCheck == true) cout << "Put in a valid option!!!" << endl;
			cout << "What difficulty would you like to play on(easy, medium, hard):";
			cin >> difficulty;
			difficultyCheck = true;
		}
		/*This checks if the user inpuutted the difficulty correctly*/
		while (difficulty != "easy" && difficulty != "medium" && difficulty != "hard");


		word1 = randomWord();
		cout << "The word is " << word1.name << endl;
		cout << "The topic is " << word1.topic << endl;
		return false;
	}
}
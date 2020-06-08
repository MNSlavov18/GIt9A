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

string wordChanger(string difficulty, string word)
{
	int hiddenLetters, availableleSpace = word.size();
	if (difficulty == "easy")
	{
		hiddenLetters = 3;
	}
	else if (difficulty == "medium")
	{
		hiddenLetters = 4;
	}
	else if (difficulty == "hard")
	{
		hiddenLetters = 5;
	}
	while (hiddenLetters > 0 && availableleSpace > 1)
	{
		int delIndex = getRandNumber(0, word.size() - 1);
		if (word[delIndex] != '_')
		{
			word[delIndex] = '_';
			availableleSpace--;
			hiddenLetters--;

		}
	}
	return word;
}
void Menu()
{
	WORD selectedWord;
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


		selectedWord = randomWord();
		cout << "The word is " << wordChanger(difficulty, selectedWord.name) << endl;
		cout << "The topic is " << selectedWord.topic << endl;
	}
}
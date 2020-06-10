#pragma once
#include <iostream> //cin, cout
#include<stdio.h> //NULL
#include<string>    //String
#include<stdlib.h>  //srand, rand
#include<time.h>    //time
#include<ctype.h>	///tolower
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
		int delIndex = getRandNumber(1, word.size() - 1);
		if (word[delIndex] != '_')
		{
			word[delIndex] = '_';
			availableleSpace--;
			hiddenLetters--;

		}
	}
	return word;
}
void checkWord(string word, string correctWord)
{
	bool guessedWord = false;
	while (1)
	{
		cout << "Please, guess a letter from the word you're guessing:";
		char letter;
		cin >> letter;
		//makes the letter that you search for lowercase
		letter = tolower(letter);
		if (correctWord.find(letter) != string::npos)
		{
			
			for (int i = 0; i < correctWord.size(); i++)
			{
				cout << correctWord[i] << " " << letter << endl;
				if (correctWord[i] == letter)
				{
					word[i] = letter;
					if (word == correctWord)
					{
						cout << "Congratulations! You guessed the whole word!" << endl;
						guessedWord = true;
						break;
					}
					else
					{
						cout << "Correct!" << endl;
						break;
					}
				}


			}
		}
		else
		{
			cout << "The word doesn't have that letter. Please try again:" << endl;
		}
		/*You exit the loop if you have guessed the word*/
		if (guessedWord == true) break;
		cout << "The word is " << word << endl;
	}
	
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
		string changedString= wordChanger(difficulty, selectedWord.name);
		cout << "The word is " << changedString << endl;
		cout << "The topic is " << selectedWord.topic << endl;
		checkWord(changedString,selectedWord.name);
	}
}
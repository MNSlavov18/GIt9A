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
	randIndex = getRandNumber(0, arraySize - 1);
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
	string strikes ;
	while (1)
	{
		cout << "Please, guess a letter or the whole word: ";
		char letter;
		string guess;
		bool replaced = false;
		bool failedGame = false;
		cin >> guess;
		// If the user inputted a letter
		if (guess.size() == 1) letter = guess[0];
		// If the user inputted the correct word
		else if (guess == correctWord)
		{
				cout << "Congratulations! You guessed the whole word!" << endl;
				break;
		}
		//If the user inputted something other than a letter or the correct word
		else
		{
			cout << "Your guess is incorrect." << endl;
			strikes += "X";
			cout << "strikes: " << strikes << endl;
			continue;
		}

		//makes the letter that you search for lowercase
		letter = tolower(letter);
		if (correctWord.find(letter) != string::npos)
		{

			for (int i = 0; i < correctWord.size(); i++)
			{
				if (correctWord[i] == letter)
				{
					word[i] = letter;
					if (word == correctWord)
					{
						cout << "Congratulations! You guessed the whole word!" << endl;
						guessedWord = true;
						break;
					}
					else if (replaced == false)
					{
						cout << "Correct!" << endl;
						replaced = true;
					}
				}


			}
		}
		else
		{
			cout << "The word doesn't have that letter. Please try again." << endl;
			strikes += "X";
			
		}
		/*You exit the loop if you have guessed the word*/
		if (guessedWord == true) break;
		
	}
}

bool isValid(int number)
{
	if (number <= 0 || number > 15)
	{
		cout << "Put in a valid option!!!" << endl;
		return false;
	}
	return true;
}
string difficultyInput()
{
	string difficulty;
	bool valid = true;
	do
	{
		/*If the user failed to input the difficulty correctly
		 they'll be forced to do so again.*/
		if (valid == false) cout << "Put in a valid option!!!" << endl;
		cout << "What difficulty would you like to play on(easy, medium, hard): ";
		cin >> difficulty;
		valid = false;
	}
	/*This checks if the user inpuutted the difficulty correctly*/
	while (difficulty != "easy" && difficulty != "medium" && difficulty != "hard");
	return difficulty;
}
void Menu()
{
	WORD selectedWord;
	int roundsCount, correct = 0, wrong = 0;
	bool valid = false;
	string difficulty;
	while (valid == false)
	{
		cout << "How many rounds do you want to play (1-15): ";
		cin >> roundsCount;
		valid = isValid(roundsCount);
	}
	for (int i = 0; i < roundsCount; i++)
	{
		difficulty = difficultyInput();

		selectedWord = randomWord();

		string changedString = wordChanger(difficulty, selectedWord.name);
		cout << "The word is " << changedString << endl;
		cout << "The topic is " << selectedWord.topic << endl;
		checkWord(changedString, selectedWord.name);
	}
	cout << "You won!" << endl;
}
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

bool strikeCheck(string& strikes)
{
	strikes += "X";
	cout << "strikes: " << strikes << endl;
	if (strikes.size() == 3)
	{
		cout << "You lost." << endl;
		return false;
	}
	return true;
}

int isLetterInWord(string correctWord, string& strikes,  string& word, char letter, bool *lettersGuessed)
{
	bool strikeResult;
	if (correctWord.find(letter) != string::npos && lettersGuessed[letter-'a'+1]==0)
	{
		lettersGuessed[letter - 'a' + 1] = 1;
		bool replaced = false;
		for (int i = 0; i < correctWord.size(); i++)
		{
			if (correctWord[i] == letter)
			{
				word[i] = letter;
				if (word == correctWord)
				{
					cout << "Congratulations! You guessed the whole word!" << endl;
					return 1;
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
		strikeResult = strikeCheck(strikes);
		if (strikeResult == false) return 2;
		if (lettersGuessed[letter - 'a' + 1] == 1) cout << "You've already tried to guess that letter." << endl;
		else cout << "The word doesn't have that letter. Please try again." << endl;
	}
	cout << "The word is " << word << endl;
	return 3;
}

string toLowerCase(string str1)
{
	for (int i = 0; i < str1.size(); i++)
	{
		str1[i] = tolower(str1[i]);
	}
	return str1;
}

bool checkWord(string word, string correctWord)
{
	string strikes = "";
	bool lettersGuessed[27] = {0};
	int letterInWordResult;
	while (1)
	{
		char letter;
		bool strikeResult;
		bool replaced = false;

		string guess;
		cout << "Please, guess a letter or the whole word: ";
		cin >> guess;
		// If the user inputted a letter
		if (guess.size() == 1) letter = guess[0];
		// If the user inputted the correct word
		else if (toLowerCase(guess) == toLowerCase(correctWord))
		{
			cout << "Congratulations! You guessed the whole word!" << endl;
			return true;
		}
		//If the user inputted something other than a letter or the correct word
		else
		{
			cout << "Your guess is incorrect." << endl;
			strikeResult = strikeCheck(strikes);
			if (strikeResult == false) return false;
			continue;
		}
		//makes the letter that you search for lowercase
		letter = tolower(letter);
		letterInWordResult = isLetterInWord(correctWord, strikes, word, letter, lettersGuessed);
		if (letterInWordResult == 1) return true;
		else if (letterInWordResult == 2) return false;
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
	bool valid = false, winLose;
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
		winLose = checkWord(changedString, selectedWord.name);
		//The program ends if you get 3 strikes
		
		if (winLose == false) break;
	}
	if (winLose == true) cout << "You won!" << endl;
}
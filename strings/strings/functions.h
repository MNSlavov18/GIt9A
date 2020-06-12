#pragma once
#include <iostream> //cin, cout
#include<stdio.h> //NULL
#include<string>    //String
#include<stdlib.h>  //srand, rand
#include<time.h>    //time
#include<ctype.h>	///tolower
#include"data.h"
using namespace std;

//function that generates numbers for generating words
int getRandNumber(int lowerNumber, int upperNumber)
{
	int randNumber;
	/* initialize random seed: */
	srand(time(NULL));

	randNumber = rand() % upperNumber + lowerNumber;
	return randNumber;
}

//structure that generates words
WORD randomWord()
{
	int randIndex;
	//varaiable that asigns the function to generate random word
	randIndex = getRandNumber(0, arraySize - 1);
	WORD  generatedWord = words[randIndex];
	return generatedWord;
}

//function that asks the user what difficulty to be the game
string wordChanger(string difficulty, string word)
{
	int hiddenLetters, availableleSpace = word.size();
	if (difficulty == "easy")
	{
		//variable that hid 3 letters because the level is easy
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
	//converts random letters into free spaces h
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


//function that output strike if you input wrong letter
bool strikeCheck(string& strikes)
{
	strikes += "X";
	cout << "strikes: " << strikes << endl;
	//if you get wrong 3 times you loose
	if (strikes.size() == 3)
	{
		cout << "You lost." << endl;
		return false;
	}
	return true;
}

//function that checks if the user guessed right a letter or the whole word
int isLetterInWord(string correctWord, string& strikes,  string& word, char letter, bool *lettersGuessed)
{
	bool strikeResult;
	//if statement that finds 
	if (correctWord.find(letter) != string::npos && lettersGuessed[letter-'a'+1]==0)
	{
		lettersGuessed[letter - 'a' + 1] = 1;
		bool replaced = false;
		for (int i = 0; i < correctWord.size(); i++)
		{
			//if statement that checks if the letter is in the word
			if (correctWord[i] == letter)
			{
				word[i] = letter;
				//if statement that checks if the word is right
				if (word == correctWord)
				{
					cout << "Congratulations! You guessed the whole word!" << endl;
					//if tyou guessed the whole word returns 1
					return 1;
				}
				//if statement that outputs message if you guess a letter right
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
		//it increase the strike if you put the same letter twice
		strikeResult = strikeCheck(strikes);
		if (strikeResult == false) /*if the user's answer is wrong returns 2*/ return 2;
		//if statement that outputs a message if you put the same letter twice or more
		if (lettersGuessed[letter - 'a' + 1] == 1) cout << "You've already tried to guess that letter." << endl;
		else cout << "The word doesn't have that letter. Please try again." << endl;
	}
	cout << "The word is " << word << endl;
	//if you guessed only a letter returns 3
	return 3;
}

//function that converts all letters to lower case
string toLowerCase(string str1)
{
	for (int i = 0; i < str1.size(); i++)
	{
		str1[i] = tolower(str1[i]);
	}
	return str1;
}

//function that checks if the world you put is correct
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

//function that outputs a message if the rounds are more than 15 and less than 1
bool isValid(int number)
{
	if (number <= 0 || number > 15)
	{
		cout << "Put in a valid option!!!" << endl;
		return false;
	}
	return true;
}

//function that make you choose the difficulty you want
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

//menu
void Menu()
{
	WORD selectedWord;
	int roundsCount, correct = 0, wrong = 0;
	bool valid = false, winLose;
	string difficulty;
	//while that outputs a message
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
		//output the word that you have to guess
		cout << "The word is " << changedString << endl;
		//output the topic of the word you have to guess
		cout << "The topic is " << selectedWord.topic << endl;
		winLose = checkWord(changedString, selectedWord.name);
		//The program ends if you get 3 strikes
		
		if (winLose == false) break;
	}
	//if statement that if you guess all the words outputs a message
	if (winLose == true) cout << "You won!" << endl;
}
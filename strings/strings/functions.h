#pragma once
#include <iostream> //cin, cout
#include<stdio.h> //NULL
#include<string>    //String
#include<stdlib.h>  //srand, rand
#include<time.h>    //time
#include"data.h"
using namespace std;
int getRandNumber(int lowerNumber,int upperNumber)
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
	randIndex = getRandNumber(0, 4);
	WORD  word1 = words[randIndex];
	return word1;
}
void Menu(string str, int option)
{
	WORD word1;
	int roundsCount,correct=0,wrong=0;
	cout << "How many rounds do you wish to play: ";
	cin >> roundsCount;
	for (int i = 0; i < roundsCount; i++)
	{
		word1 = randomWord();
		cout << "The word is " << word1.name << endl;
		cout << "The topic is " << word1.topic << endl;
	}
}
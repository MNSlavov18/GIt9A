#pragma once
#include <iostream> //cin, cout
#include<stdio.h> //NULL
#include<string>    //String
#include<stdlib.h>  //srand, rand
#include<time.h>    //time
using namespace std;
struct WORD
{
	string name;
	string topic;
};

//the random word's that are 
WORD words[30] = {
	 {"sunflower","flowers"},
	 {"Australia","countries"},
	 {"Bulgaria","countries"},
	 {"France","countries"},
	{"cucumber", "vegetable"},
	{"watermelon", "fruit"},
	{"blueberry", "fruit"},
	{"strawberry", "fruit"},
	{"builder", "profession"},
	{"doctor", "profession"},
	{"waiter", "profession"},
	{"onion", "vegetable"},
	{"cauliflower", "vegetable"},
	{"broccoli", "vegetable"},
	{"Estonia", "countries"},
	{"Germany", "countries"},
	{"Portugal", "countries"},
	{"Switzerland", "countries"},
	{"Norway", "countries"},
	{"lasagna", "food"},
	{"spaghetti", "food"},
	{"hamburger", "food"},
	{"seafood", "food"},
	{"milkshake", "drink"},
	{"lemonade", "drink"},
	{"coffee", "drink"},
    {"football", "sport"},
    {"basketball", "sport"},
    {"swimming", "sport"},
    {"volleyball", "sport"},
   

};
int arraySize = 29;
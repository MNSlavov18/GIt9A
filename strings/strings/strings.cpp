#include <iostream> //cin, cout
#include<stdio.h> //NULL
#include<string>    //string
#include<stdlib.h>  //srand, rand
#include<time.h>    //time
#include"data.h"
#include"functions.h"
using namespace std;
int main()
{
    bool result;
    while (1)
    {
        result = Menu();
        return result;
    }
    return 0;
}
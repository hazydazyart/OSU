/******************************************************
 * ** Author: Megan Conley
 * ** Date: 10/10/2013
 * ** Description: Lab 3
 * ** Input: none
 * ** Output: Three random numbers generated from the current time
 * ******************************************************/


#include <iostream>
#include <stdlib.h> //srand, rand
#include <ctime> //time
using std::cout;
using std::cin;
using std::endl;

int main()
{
	/*Original program only included declaring the variables and setting them equal to rand() values. However, per the C++ Reference library, rand() requires a seed so that random values change each time the program is run. */

	//initialize the random number generator by creating an arbitrary seed based on the current time (code from en.cppreference.com/w/cpp/numeric/random/srand 
	srand(std::time(0));

	//declare the three variables to have the random numbers assigned to
	int v1, v2, v3;
	
	v1 = rand() % 100; // v1 is between 0 and 99
	v2 = rand() % 100 + 1; //v2 is between 1 and 100
	v3 = rand() % 30 + 1985; //v3 is between 1985 and 2014

	//print out these values
	cout<< v1 << endl;
	cout<< v2 << endl;
	cout<< v3 << endl;

	return 0;
}


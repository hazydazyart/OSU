/******************************************************
 * ** Author: Megan Conley
 * ** Date: 10/10/2013
 * ** Description: Lab 3
 * ** Input: User inputs integer
 * ** Output: Statements based on user input integer
 * ******************************************************/


#include <iostream>

using std::cout; //with this I do not have to type std::
using std::cin; //with this I do not have to type std::
using std::endl; //with this I do not have to type std::

int main()
{
	//creates variable to store input
	int input = 0;

	//explain what kind of input we are looking for and get input
	cout<< "Please enter a number from 1 to 3: ";
	cin>> input;

	//print output based on the value of the input
	/*
 	* notice that the code that runs from a conditional statement (such as an if statement) does not *need* braces, but it will only execute the first line below
 	* it without the braces, which means that you can include braces so that the whole "block" of code (inside the braces) executes.
 	*/

	if(input == 1) {
		cout<< "You entered the number 1, perhaps the loneliest number."<< endl;
	}
	else if(input == 2){
		cout<< "You entered the number 2, perhaps the lonliest number sice the number one." << endl;
	}
	else if(input == 3){
		cout<< "You entered the number 3, making it the third wheel." << endl;
	}
	else {
		cout<< "You entered some invalid input, next time try to enter some valid input." << endl;
	}

	return 0;

}



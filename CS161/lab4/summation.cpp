/******************************************************
 * ** Author: Megan Conley
 * ** Date: 10/14/2013
 * ** Description: Lab 4
 * ** Input: An int to sum over the function x^5 + 10
 * ** Output: Calculated the summation of a mathematical function
 * ******************************************************/


#include <iostream>
#include <math.h> // pow

using std::cout;
using std::endl;
using std::cin;

int main()
{
	//Initialize a variable to keep a running total
	int total;

	//Initialize a variable int where the  user wants the summation to stop
	int input;

	//Define the maximum value to be accepted as input
	//Trial and error testing found that 47 is the maximum value that will not result in overflow
	int maxInput = 47;

	//Initialize boolean for use during check to see if user wants to run the program again
	//Set it to true first so the program runs at least once
	bool runAgain = true;

	//Check if the user would like to run the program multiple times
	//As runAgain is already set to true, there is no need to add any logic operators
	while(runAgain) {

		//Ask user for input
		cout<< "What value would you like to stop the sum over the fucntion x^5 + 10?" <<endl;
		cin>> input;

		//Check if input is valid, and if not, request input again
		while (input < 1 || input > maxInput) {
			cout<< "That number is invalid. ";
			cout<< "Please enter a number between 1 and " << maxInput <<endl;
			cin>> input;
		}

		for (int i = 1; i <= input; i++) {
			total += pow(i, 5) + 10;
			cout<< "Total is increasing by " << pow(i, 5) + 10 << endl;
		}

		//Print the result of the for loop
		cout<< "The total sum over i from 1 to " << input << " is " << total << endl;

		//Check if the user would like to use program again
		cout<< "Would you like to try another value to sum up to?" <<endl;
		//Initialize an int for user's answer
		int runAgainTest;

		cout<< "Enter 0 for no or 1 for yes." <<endl;
		cin>> runAgainTest;
	
		//Check if user gave valid input for runAgain
		while(runAgainTest < 0 || runAgainTest > 1) {
			cout<< "That number is invalid."<< endl;
			cout<< "Enter 0 for no or 1 for yes." <<endl;
			cin>> runAgainTest;
		}

		if(runAgainTest == 1) {
			runAgain = true;
		} else {
			runAgain = false;
		}
	}
	return 0;
}

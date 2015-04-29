/********************************************************************* 
 * ** Program Filename: conleyme_assn_2-1.cpp
 * ** Author: Megan Conley
 * ** Date: 1/19/2014
 * ** Description: Assignment 2: Chapter 18, Project 2
 * ** Input: An integer between 1-10
 * ** Output: A statement keeping track of how many times a 
 * recursive function has been called, then an error message
 * once the user-input depth was reached.
 * *********************************************************************/

#include <iostream>

int user_input();
void recursive_func(int input, int count);

int main() {

	int count = 1;

	int input = user_input();

	recursive_func(input, count);

	return 0;
}

/********************************************************************* 
 * ** Function: int user_input
 * ** Description: Takes user input, checks if valid, and returns a valid
 * input
 * ** Parameters: None
 * ** Pre-Conditions: None
 * ** Post-Conditions: Returns an int
 * *********************************************************************/ 

int user_input() {
	int input;
	std::cout << "Please input an integer between 1 and 10: ";
	std::cin >> input;
	while(!std::cin || input > 10 || input < 1) {
		std::cin.clear();              //clear the cin error state
                std::cin.ignore(9999, '\n');            //discard characters in stream
		std::cout << "Invalid input. Please input an integer between 1 and 10: ";
		std::cin >> input;
	}	

	return input;
}

/********************************************************************* 
 * ** Function: void recursive_func
 * ** Description: Calls itself until it hits the user-input depth,
 * then throws an exception.
 * ** Parameters: int input, int count
 * ** Pre-Conditions: input and count are valid ints
 * ** Post-Conditions: Ends by throwing an exception
 * *********************************************************************/ 

void recursive_func(int input, int count) {
       try {
                if (count != input) {
                        std::cout << "Function has been called " << count << " times." << std::endl;
			count++;
                        recursive_func(input, count);
                } else {
			throw input;
                }
        }
	catch (int count) {
		if (count == input) {
			std::cout << "Error: Depth of " << count << " reached." << std::endl;
		}
	}
}


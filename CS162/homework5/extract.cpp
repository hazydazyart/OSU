/********************************************************************* 
 * ** Program Filename: extract.cpp
 * ** Author: Megan Conley
 * ** Date: 2/8/2013
 * ** Description: Assignment 5
 * ** Input: User input string
 * ** Output: Integer value extracted from string
 * *********************************************************************/ 

#include<iostream>
#include<string>
#include<sstream>

int test_input();
bool int_found(std::stringstream& ss, int& found);
void get_input(std::stringstream& ss);

int main() {

        std::stringstream ss;
        int value = 0;

        value = test_input();

        std::cout << "The integer is: " << value << std::endl;

        return 0;
}

 
/********************************************************************* 
 * ** Function: int test_input
 * ** Description: Calls functions to get input and verify input, returning
 * an int once valid input is entered.
 * ** Parameters: None
 * ** Pre-Conditions: None
 * ** Post-Conditions: Returns an int
 * *********************************************************************/

int test_input() {

        std::stringstream ss;
        int value;
	bool found;
	
	get_input(ss);
	
	found = int_found(ss, value);

        while (!found) {
                std::cout << "No integer found. Please try again." << std::endl;
		ss.str(""); // clear stringstream
		ss.clear(); // reset any flags
		get_input(ss);
		found = int_found(ss, value);
	} 
	return value;
}

 
/********************************************************************* 
 * ** Function: bool int_found
 * ** Description: Tests string for int using stringstream, returing
 * true if found
 * ** Parameters: Stringstream object, int (as reference) 
 * ** Pre-Conditions: Stringstream has had input; input is space-
 * delineated
 * ** Post-Conditions: If int is found, sets int parameter equal to
 * the found int; if not found, returns true.
 * *********************************************************************/

bool int_found(std::stringstream& ss, int& found) {

	std::string temp;
        while(std::getline(ss, temp,' ')) {
                if(std::stringstream(temp)>>found) {
                        return true;
                }
        }

        return false;
}
 
/********************************************************************* 
 * ** Function: void get_input
 * ** Description: Prompts user for string input using getline
 * ** Parameters: Stringstream object
 * ** Pre-Conditions: None
 * ** Post-Conditions: String is written to stringstream
 * *********************************************************************/

void get_input(std::stringstream& ss) {

        std::string input;
        std::cout << "Enter an integer: ";
        std::getline (std::cin, input);
        ss << input;
}


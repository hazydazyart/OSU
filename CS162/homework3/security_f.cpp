/********************************************************************* 
 * ** Program Filename: security_f.cpp
 * ** Author: Megan Conley
 * ** Date: 1/26/2014
 * ** Description: Implementation file for security.cpp
 * ** Input: n/a
 * ** Output: n/a
 * *********************************************************************/ 

#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include "security_h.h"

/********************************************************************* 
 * ** Function: void print_vector
 * ** Description: Prints contents of vector to console
 * ** Parameters: Vector
 * ** Pre-Conditions: Vector exists and has at least one value
 * ** Post-Conditions: Vector is printed to console
 * *********************************************************************/ 


void print_vector(std::vector<std::string> &names) {
       for(std::vector<std::string>::iterator i = names.begin(); i != names.end(); i++) {
                std::cout << *i << " ";
        }
        std::cout << std::endl;
}

/********************************************************************* 
 * ** Function: void add_name
 * ** Description: Prompts user for a string, adds that string to a
 * vector
 * ** Parameters: Vector
 * ** Pre-Conditions: Vector exists
 * ** Post-Conditions: Vector contains user input string
 * *********************************************************************/ 


void add_name(std::vector<std::string> &names) {
        std::string input = "";

        std::cout << "Please enter the name of the visitor: ";
        std::cin >> input;

        names.push_back(input);

        std::cout << input << " added to visitor's log." << std::endl;
}

/********************************************************************* 
 * ** Function: void delete_name
 * ** Description: Prompts user for string, searches vector for string,
 * and erases if string is found
 * ** Parameters: Vector
 * ** Pre-Conditions: Vector is initialized and has at least one string
 * ** Post-Conditions: If user input string is located, it is erased
 * from vector
 * *********************************************************************/ 


void delete_name(std::vector<std::string> &names) {
        std::string input = "";
        std::cout << "Please enter a name to delete: ";
        std::cin >> input;

        for(std::vector<std::string>::iterator i = names.begin(); i != names.end(); i++) {
                if (*i == input) {
                        i = names.erase(i);
                }
        }

        std::cout << input << " erased from visitor's log." << std::endl;
}

/********************************************************************* 
 * ** Function: int get_input
 * ** Description: Displays option menu and prompts user for int
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: Returns an int
 * *********************************************************************/ 


int get_input() {
        int input;

        std::cout << "Options:" << std::endl;
        std::cout << "1. Add name to log" << std::endl;
        std::cout << "2. Delete name from log" << std::endl;
        std::cout << "3. View log" << std::endl;
        std::cout << "4. Exit" << std::endl;

        std::cin >> input;

        while(!std::cin || input < 0 || input > 4) {
                std::cin.clear();
                std::cin.ignore(9999, '\n');
                std::cout << "Please enter a number between 1 and 4: ";
                std::cin >> input;
        }
        return input;
}

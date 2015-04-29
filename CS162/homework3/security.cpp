/********************************************************************* 
 * ** Program Filename: security.cpp
 * ** Author: Megan Conley
 * ** Date: 1/26/2014
 * ** Description: Assignment 3, project 2
 * ** Input: Strings, ints
 * ** Output: Gives user options to store strings in a vector,
 * delete from the vector, or print contents of vector
 * *********************************************************************/ 

#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include "security_h.h"

int main() {

	// Initialize the vector
	std::vector<std::string> names;

	// Add a name, as the program may not function
	// if there isn't at least one string in the
	// vector
	add_name(names);

	int option = 0;

	while (option != 4) {
		
		option = get_input();

		if (option == 1) {
			add_name(names);
		} else if (option == 2) {
			delete_name(names);
		} else if (option == 3) {
			print_vector(names);
		} else {
			return 0;
		}
	}
	return 0;
}


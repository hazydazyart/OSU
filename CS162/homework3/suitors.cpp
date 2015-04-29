
/********************************************************************* 
 * ** Program Filename: conleyme_assn_3-3.cpp
 * ** Author: Megan Conley
 * ** Date: 1/24/2014
 * ** Description: Assignment 3, project 3
 * ** Input: An int
 * ** Output: Fills a vector with ints 1 through the user input int,
 * prints it, then removes every third number until 1 remains.
 * *********************************************************************/ 

#include <iostream>
#include <vector>
#include <iterator>
#include "suitors_h.h"

int main() {

	std::vector<int> suitors;

	int total = get_total();

	// Fill the vectors with 1 through user's input int
	for (int i = 1; i <= total; i++) {
		suitors.push_back(i);
	}

	print_vector(suitors);

	int count = 0;

	find_last(suitors, count);

	std::cout << "To marry the princess, you should stand in position " << suitors.front();
	std::cout << " when there are " << total << " suitors in line." << std::endl;

	return 0;
}

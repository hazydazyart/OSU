

/********************************************************************* 
 * ** Program Filename: suitors_f.cpp
 * ** Author: Megan Conley
 * ** Date: 1/26/2014
 * ** Description: Implementation file for suitors.cpp
 * ** Input: n/a
 * ** Output: n/a
 * *********************************************************************/ 

#include <iostream>
#include <vector>
#include <iterator>
#include "suitors_h.h"

/*********************************************************************
 * ** Function: get_total
 * ** Description: Explains the situation, prompts the user for a
 *  valid int, and returns it
 * ** Parameters: n/a
 * ** Pre-Conditions: None
 * ** Post-Conditions: Int is returned
 * *********************************************************************/

int get_total() {

        int total;

        std::cout << "The beautiful princess Eve will eliminate " << std::endl;
        std::cout << "every third suitor until one remains. This " << std::endl;
        std::cout << "program will calculate which position in line " << std::endl;
        std::cout << "will allow you to marry the princess." << std::endl;

        std::cout << "How many suitors are there? ";
        std::cin >> total;

        while(!std::cin || total < 1) { // There should be at least one person in line.
                std::cin.clear();
                std::cin.ignore(9999, '\n');
                std::cout << "Please enter a positive integer. ";
                std::cin >> total;
        }

        return total;
}

/*********************************************************************
 * ** Function: print_vector(vector)
 * ** Description: Prints the contents of a vector
 * ** Parameters: a vector
 * ** Pre-Conditions: Vector that is passed as parameter has at least
 * one element
 * ** Post-Conditions: Vector is printed
 * *********************************************************************/

void print_vector(std::vector<int> &suitors) {

        for(std::vector<int>::iterator i = suitors.begin(); i != suitors.end(); i++) {
                std::cout << *i << " ";
        }
        std::cout << std::endl;
}

/*********************************************************************
 * ** Function: find_last(vector, int)
 * ** Description: Deletes every third element of the vector, printing
 * at every step, until 1 int remains
 * ** Parameters: Vector, int
 * ** Pre-Conditions: Vector contains at least 1 int, separate int for
 * second parameter is valid
 * ** Post-Conditions: Vector passed as reference contains only one
 * int
 * *********************************************************************/

void find_last(std::vector<int> &suitors, int count) {

        for(std::vector<int>::iterator i = suitors.begin(); suitors.size() > 1; i++) {
                if (i == suitors.end()) { // if it hits the end, wrap around
                        i = suitors.begin();
                }
                if (++count == 3) { // increment the count each time
                        i = suitors.erase(i); // once it hits 3, erase
                        --i; // move the iterator back one
                        count = 0; // reset the count
                        print_vector(suitors); // print the current svector
                }
        }
}

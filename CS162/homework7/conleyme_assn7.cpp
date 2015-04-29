/********************************************************************* 
 * ** Program Filename: conleyme_assn7
 * ** Author: Megan Conley
 * ** Date: 2/24/2014
 * ** Description: Assigment 7 implementation
 * ** Input: none
 * ** Output: 2d char array representing a cellular automata
 * *********************************************************************/

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<vector>
#include<iterator>
#include<string>
#include"organism.h"

void print(char array[][20]);
void moveAnts(char step[][20], std::vector<Ant>& colony);
void moveDoodlebugs(char step[][20], std::vector<Doodlebug>& bugs, std::vector<Ant>& colony);

int main() {

	srand(time(NULL));

	char step[20][20];

	for(int i = 0; i < 20; i++) {
		for(int j = 0; j < 20; j++) {
			step[i][j] = '.';
		}
	}

	std::vector<Ant> colony;
	std::vector<Doodlebug> bugs;

	for(int i = 0; i < 100; i++) {
		Ant test(step);
		colony.push_back(test);
	}

	for(int i = 0; i < 5; i++) {
		Doodlebug temp(step);
		bugs.push_back(temp);
	}

	std::string input = "y";

	while(input == "y" || input == "Y") {
		print(step);
		moveDoodlebugs(step, bugs, colony);
		moveAnts(step, colony);
		std::cout << "Press y to continue, anything else to quit: ";
		std::getline(std::cin, input);
	}
		
	
	return 0;
}

/********************************************************************* 
 * ** Function: print
 * ** Description: Prints the current state of the 2d char array
 * ** Parameters: 2d char array
 * ** Pre-Conditions: 2d char array has been initialized
 * ** Post-Conditions: 2d char array is printed to console
 * *********************************************************************/ 

void print(char array[][20]) {
        for(int i = 0; i < 20; i++) {
                for(int j = 0; j < 20; j++) {
                        std::cout << array[i][j];
                }
                std::cout << std::endl;
        }
	std::cout << std::endl;
}

/********************************************************************* 
 * ** Function: moveAnts
 * ** Description: Calls Ant class member functions for all objects in
 * Ant array in the order of one time step - first they move, and if
 * condiditons are met, breed
 * ** Parameters: 2d char array, Ant vector
 * ** Pre-Conditions: 2d char array and Ant vector have been intialized
 * ** Post-Conditions: 2d char array updated with movement of Ant objects,
 * new Ant objects added to vector if applicable
 * *********************************************************************/ 

void moveAnts(char step[][20], std::vector<Ant>& colony) {
	// Rather than add to a vector already being iterated over,
	// create a temporary vector to store the newly added objects
	std::vector<Ant> nextGen;
        for(std::size_t i = 0; i < colony.size(); ++i) {
		if(!colony[i].isDead()) {
	                colony[i].move(step, 'O');
        	        colony[i].breed(step, nextGen);
		}
        }

	// Merge the newly added objects to original vector
        for(std::vector<Ant>::iterator i = nextGen.begin(); i != nextGen.end(); ++i) {
                colony.push_back(*i);
        }
}

/********************************************************************* 
 * ** Function: moveDoodlebugs
 * ** Description: Calls the member functions of Doodlebugs in order
 * of how they should occur in each time step - eat, breed, or die depending
 * on if the conditions for each are met.
 * ** Parameters: 2d char array, Doodlebug vector, Ant vector
 * ** Pre-Conditions: All parameters have been initialized; Doodlebug vector
 * contains at least one object
 * ** Post-Conditions: 2d char array updated with movement of Doodlebug
 * objects, new Doodlebugs added to vector if applicable, Ant/Doodlebug objects
 * removed from array/vectors if applicable
 * *********************************************************************/ 

void moveDoodlebugs(char step[][20], std::vector<Doodlebug>& bugs, std::vector<Ant>& colony) {
        std::vector<Doodlebug> nextGen;
        for(std::size_t i = 0; i < bugs.size(); ++i) {
		if(!bugs[i].isDead()) {
        	        bugs[i].eat(step, colony);
                	bugs[i].breed(step, nextGen);
			bugs[i].die(step);
		}
        }
        for(std::vector<Doodlebug>::iterator i = nextGen.begin(); i != nextGen.end(); ++i) {
                bugs.push_back(*i);
        }
}

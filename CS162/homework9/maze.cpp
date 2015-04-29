/********************************************************************* 
 * ** Program Filename: maze.cpp
 * ** Author: Megan Conley
 * ** Date: 3/14/2014
 * ** Description: Assignment 9
 * ** Input: Directions as char to navigate a maze
 * ** Output: Current location in maze; list of rooms already visited if
 * requested
 * *********************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

class MazeNode {

public:

/********************************************************************* 
 * ** Function: MazeNode constructors/deconstructor
 * ** Description: Default and non-default constructor and deconstructor
 * for MazeNode class objects
 * ** Parameters: Non-default cosntructor take a char and a string
 * ** Pre-Conditions: None
 * ** Post-Conditions: Constructs/deconstructs MazeNode object
 * *********************************************************************/

	MazeNode() {}
	MazeNode(char theLoc, std::string theChoices) {
		this->location = theLoc;
		this->choices = theChoices;
	}

	~MazeNode() {}

/********************************************************************* 
 * ** Function: getLocation
 * ** Description: Accessor function for location variable
 * ** Parameters: None
 * ** Pre-Conditions: Object exists and location has been set to some value
 * ** Post-Conditions: Returns location as a char
 * *********************************************************************/

	char getLocation() {
		return this->location;
	}

/********************************************************************* 
 * ** Function: getChoices
 * ** Description: Accessor function for choices variable
 * ** Parameters: None
 * ** Pre-Conditions: Object exists and choices has been set to some value
 * ** Post-Conditions: Returns choices as a string
 * *********************************************************************/

	std::string getChoices() {
		return this->choices;
	}

/********************************************************************* 
 * ** Function: getLink
 * ** Description: Overloaded function - default returns MazeNode object;
 * function with int parameter returns one of up to four MazeNode objects
 * ** Parameters: none/int
 * ** Pre-Conditions: Object exists and has at least one link variable set
 * to equal another object
 * ** Post-Conditions: Returns MazeNode object
 * *********************************************************************/

	MazeNode* getLink() {
		return this->link;
	}
	MazeNode* getLink(int theLink) {
		if(theLink == 1) {
			return this->link;
		}
                if(theLink == 2) {
                        return this->link2;
                }
                if(theLink == 3) {
                        return this->link3;
                }
                if(theLink == 4) {
                        return this->link4;
                }
	}

/********************************************************************* 
 * ** Function: setLocation
 * ** Description: Mutator function for location variable
 * ** Parameters: Char
 * ** Pre-Conditions: Object exists
 * ** Post-Conditions: Location set to parameter value
 * *********************************************************************/

	void setLocation(char theLoc) {
		this->location = theLoc;
	}

/*********************************************************************
 * ** Function: setChoices
 * ** Description: Mutator function for choices variable
 * ** Parameters: String
 * ** Pre-Conditions: Object exists
 * ** Post-Conditions: Choices set to parameter value
 * *********************************************************************/

	void setChoices(std::string theChoices) {
		this->choices = theChoices;
	}

/********************************************************************* 
 * ** Function: setLink
 * ** Description: Overloaded function sets up to four MazeNode variables
 * equal to the parameter, depending on how many links are needed
 * ** Parameters: 1-4 MazeNode objects
 * ** Pre-Conditions: Object exists and objects passed as parameter exist
 * ** Post-Conditions: link/link2/link3/link4 set to parameter values
 * *********************************************************************/

	void setLink(MazeNode* p) {
		this->link = p;
	}
        void setLink(MazeNode* p, MazeNode* p2) {
                this->link = p;
		this->link2 = p2;
        }
        void setLink(MazeNode* p, MazeNode* p2, MazeNode* p3) {
                this->link = p;
		this->link2 = p2;
		this->link3 = p3;
        }
        void setLink(MazeNode* p, MazeNode* p2, MazeNode* p3, MazeNode* p4) {
                this->link = p;
		this->link2 = p2;
		this->link3 = p3;
		this->link4 = p4;
        }

/********************************************************************* 
 * ** Function: printNode
 * ** Description: Prints information about MazeNode object
 * ** Parameters: None
 * ** Pre-Conditions: Object exists and location/choices have been
 * initialized
 * ** Post-Conditions: Prints information to console
 * *********************************************************************/

	void printNode() {
        	std::cout << "You are in room " << this->getLocation()
	                  << " of a maze of twisty little passages, "
                  	  << "all alike." << std::endl;
        	std::cout << "You can go "
			  << this->getChoices() << std::endl;
	}


private:
	char location;
	std::string choices;
	MazeNode* link;
	MazeNode* link2;
	MazeNode* link3;
	MazeNode* link4;
};

/********************************************************************* 
 * ** Function: buildMaze
 * ** Description: Initializes MazeNode objects and sets links between
 * them in a list
 * ** Parameters: None 
 * ** Pre-Conditions: None
 * ** Post-Conditions: Returns the "head" MazeNode object
 * *********************************************************************/

MazeNode* buildMaze() { 

	MazeNode *head = new MazeNode('A', "east or south.");

        MazeNode *E = new MazeNode('E', "south or north.");

        MazeNode *I = new MazeNode('I',"north.");

        MazeNode *B = new MazeNode('B', "west or south.");

	MazeNode *J = new MazeNode('J', "west.");
	
	MazeNode *F = new MazeNode('F', "north or east.");

	MazeNode *G = new MazeNode('G', "north, east, west, or south.");

	MazeNode *K = new MazeNode('K', "north.");

	MazeNode *C = new MazeNode('C', "south or east");	
	
	MazeNode *D = new MazeNode('D', "west.");

	MazeNode *H = new MazeNode('H', "south or west.");

	MazeNode *L = new MazeNode('L', "north");

	head->setLink(E, B);
	E->setLink(head, I);
	I->setLink(E, J);
	J->setLink(I);
	B->setLink(head, F);
	F->setLink(B, G);
	G->setLink(F, C, K, H);
	D->setLink(C);
	C->setLink(G, D);
	H->setLink(G, L);
	K->setLink(G);
	L->setLink(H);

	return head;
}

/********************************************************************* 
 * ** Function: breadcrumbs
 * ** Description: Prints a list of rooms visited in reverse order and
 * prompts user for input for next direction
 * ** Parameters: std::stack<char>
 * ** Pre-Conditions: Stack passed as parameter has at least one value
 * ** Post-Conditions: Returns a string
 * *********************************************************************/

std::string breadcrumbs(std::stack<char> st) {

        std::stack<char> temp = st;
        std::string input;

        std::cout << "You have been through rooms: " << std::endl;

        while(!temp.empty()) {
                std::cout << temp.top() << " ";
                temp.pop();
        }

	std::cout << std::endl;

        std::cout << "Choose a direction. ";
        std::cin >> input;

        return input;
}

/********************************************************************* 
 * ** Function: getInput
 * ** Description: Prompts user for input; calls breadcrumbs function if
 * first input is "C"
 * ** Parameters: std::stack<char>
 * ** Pre-Conditions: Stack contains at least one value if input is "C"
 * ** Post-Conditions: Returns user input as a string 
 * *********************************************************************/

std::string getInput(std::stack<char> st) {

	std::string input;
	
	std::cout << "Choose a direction or enter C to see " << std::endl;
	std::cout << "the list of rooms to return to the beginning. ";
	std::cin >> input;

	if(input == "C") {
		input = breadcrumbs(st);
	}

	return input;
}
/********************************************************************* 
 * ** Function: reverseStack
 * ** Description: Reverses stack of chars to show user which rooms they
 * visted in order during the maze
 * ** Parameters: Two std::stack<char>
 * ** Pre-Conditions: First stack parameter has at least one value
 * ** Post-Conditions: Prints reversed stack
 * *********************************************************************/

void reverseStack(std::stack<char> st, std::stack<char> rev) {

	while(!st.empty()) {
		rev.push(st.top());
		st.pop();
	}

	std::cout << "During the maze, you passed through rooms:" << std::endl;

	while(!rev.empty()) {
		std::cout << rev.top() << " ";
		rev.pop();
	}

	std::cout << std::endl;
}

/********************************************************************* 
 * ** Function: deleteList
 * ** Description: Deletes the linked list
 * ** Parameters: MazeNode pointer as reference
 * ** Pre-Conditions: Linked list exists
 * ** Post-Conditions: Deletes all nodes in the linked list
 * *********************************************************************/

/*
void deleteList(MazeNode*& head) {
	MazeNode* current = head;
	MazeNode* temp = current;

	temp = current->getLink(1);
	temp = temp->getLink(2);
	temp = temp->getLink(2);
	current = temp->getLink();
	delete temp;
	
	MazeNode* temp2 = current;
	current = current->getLink(1);
	delete temp2;

	MazeNode* temp3 = current;
	current = current->getLink(1);
	delete temp3;

        MazeNode* temp4 = current;
	current = current->getLink(2);
	delete temp4;

	MazeNode* temp5 = current;
	current = current->getLink(2);
	delete temp5;

	current = current->getLink(2);
	MazeNode* temp6 = current->getLink(2);
	delete temp6;

	MazeNode* temp7 = current;
	current = current->getLink(1);
	delete temp7;

	MazeNode* temp8 = current->getLink(3);
	delete temp8;

	current = current->getLink(4);
	MazeNode* temp9 = current->getLink(2);
	delete temp9;

	delete current;
}
*/

int main() {

	bool solved = false;
	std::string input;
	std::stack<char> crumbs; // rooms visited in reverse
	std::stack<char> rooms; // stack to be reversed in the end

	MazeNode *head = buildMaze(); // Initialize nodes and list

	MazeNode *conductor; // Initialize object to traverse the list
	conductor = head; // Set it equal to the first node

	/* For each room entered, push the current location into the crumbs stack.
 	* then prompt for input. If input is "C", print the stack. Otherwise,
 	* set the conductor equal to the appropriate node. */

	while(!solved) {
		if(conductor->getLocation() == 'A') {
			crumbs.push('A');
			conductor->printNode();
			input = getInput(crumbs);
/*
			while((input != "E") || (input != "S")) {
				std::cout << "Invalid choice." << std::endl;
				std::cin >> input;
			}
*/
			if(input == "E") {
				conductor = conductor->getLink(2);
			} else {
				conductor = conductor->getLink(1);
			}
		}
		if(conductor->getLocation() == 'E') {
			crumbs.push('E');
			conductor->printNode();
			input = getInput(crumbs);
/*
                        while(input != "N" || input != "S") {
                                std::cout << "Invalid choice." << std::endl;
                                input = getInput(crumbs);
                        }
*/
			if(input == "N") {
				conductor = conductor->getLink(1);
			} else {
				conductor = conductor->getLink(2);
			}
		}
		if(conductor->getLocation() == 'I') {
			crumbs.push('I');
			conductor->printNode();
                        input = getInput(crumbs);
/*
                        while(input != "N" || input != "E") {
                                std::cout << "Invalid choice." << std::endl;
                                input = getInput(crumbs);
                        }
*/
			if(input == "N") {
				conductor = conductor->getLink(1);
			} else {
				conductor = conductor->getLink(2);
			}
		}
		if(conductor->getLocation() == 'J') {
			crumbs.push('J');
			conductor->printNode();
                        input = getInput(crumbs);
/*
                        if(input != "E") {
                                std::cout << "But thou must." << std::endl;
                        }
*/
			conductor = conductor->getLink();
		}
		if(conductor->getLocation() == 'B') {
			crumbs.push('B');
			conductor->printNode();
                        input = getInput(crumbs);
/*
                        while(input != "W" || input != "S") {
                                std::cout << "Invalid choice." << std::endl;
                                input = getInput(crumbs);
                        }
*/
			if(input == "W") {
				conductor = conductor->getLink(1);
			} else {
				conductor = conductor->getLink(2);
			}
		}
		if(conductor->getLocation() == 'F') {
			crumbs.push('F');
			conductor->printNode();
                        input = getInput(crumbs);
/*
                        while(input != "E" || input != "N") {
                                std::cout << "Invalid choice." << std::endl;
                                input = getInput(crumbs);
                        }
*/
			if(input == "N") {
				conductor = conductor->getLink(1);
			} else {	
				conductor = conductor->getLink(2);
			}
		}
		if(conductor->getLocation() == 'G') {
			crumbs.push('G');
			conductor->printNode();
                        input = getInput(crumbs);
/*
                        while(input != "E" || input != "S" || input != "N" || input != "W") {
                                std::cout << "Invalid choice." << std::endl;
                                input = getInput(crumbs);
                        }
*/
			if(input == "W") {
				conductor = conductor->getLink(1);
			} else if(input == "N") {
				conductor = conductor->getLink(2);
			} else if(input == "S") {
				conductor = conductor->getLink(3);
			} else {
				conductor = conductor->getLink(4);
			}
		}
		if(conductor->getLocation() == 'C') {
			crumbs.push('C');
			conductor->printNode();
                        input = getInput(crumbs);
/*
                        while(input != "E" || input != "S") {
                                std::cout << "Invalid choice." << std::endl;
                                input = getInput(crumbs);
                        }
*/
			if(input == "S") {
				conductor = conductor->getLink(1);
			} else {
				conductor = conductor->getLink(2);
			}
		}
		if(conductor->getLocation() == 'D') {
			crumbs.push('D');
			conductor->printNode();
			input = getInput(crumbs);
/*
			if(input != "W") {
				std::cout << "But thou must." << std::endl;
			}
*/
			conductor = conductor->getLink();
		}
		if(conductor->getLocation() == 'K') {
			crumbs.push('K');
			conductor->printNode();
			input = getInput(crumbs);
/*
			if(input != "N") {
				std::cout << "But thou must." << std::endl;
			}
*/
			conductor = conductor->getLink();
		}
		if(conductor->getLocation() == 'H') {
			crumbs.push('H');
			conductor->printNode();
                        input = getInput(crumbs);
/*
                        while(input != "W" || input != "S") {
                                std::cout << "Invalid choice." << std::endl;
                                input = getInput(crumbs);
                        }
*/
			if(input == "W") {
				conductor = conductor->getLink(1);
			} else { 
				conductor = conductor->getLink(2);
			}
		}
		if(conductor->getLocation() == 'L') {
			crumbs.push('L');
			std::cout << "You have reached room L." << std::endl;
			solved = true; // Exit while loop
		}

	}

	std::cout << "You have escaped the maze!" << std::endl;
	reverseStack(crumbs, rooms); // Print reversed stack

//	deleteList(head);

	return 0;
}

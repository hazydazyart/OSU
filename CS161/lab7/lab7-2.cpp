/******************************************************
 * ** Author: Megan Conley
 * ** Date: 11/9/2013
 * ** Description: Lab 7, part 2
 * ** Input: Command line arguments - two commands and two ints
 * ** Output: The user's inputs as ints
 * ******************************************************/

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int getInt();
bool isInt(int argc, char* argv[]);

int main(int argc, char* argv[]) {
	int f, s;
	
	// If user does not enter any arguments, this section prompts user for both values.
	if (argc == 1) {
		cout << "Please enter an integer value for the first input." << endl;
		f = getInt();

		cout << "Please enter an integer value for the second input." << endl;
		s = getInt();
		
		cout << "First value = " << f << endl;
		cout << "Second value = " << s << endl;

		return 0;

	// If user only inputs one correct command, it checks if the value associated
	// with the command is valid and prompts again if not, then asks for the 
	// command not input by the user.
	} else if(argc == 3) {
		if(strcmp(argv[1],"-f") == 0) { // For the case that the user only used the command "-f"
			if (isInt(2, argv)) { // If the input is a valid integer
                        	f = atoi(argv[2]); // Convert the value to an int and assign it to variable f
                        } else { // If not a valid integer, prompt until one is received
	                        cout << "Please enter an integer value for the first input." << endl;
				f = getInt();
                        }

                        cout << "Please enter an integer value for the second input." << endl; // Prompt user for "-s" value
                        s = getInt();

			cout << "First value = " << f << endl;
			cout << "Second value = " << s << endl;
			return 0;
		} else if(strcmp(argv[1],"-s") == 0) { // For the case that the user only used the command "-s"
			if (isInt(2, argv)) {
				s = atoi(argv[2]);
			} else {
				cout << "Please enter an integer value for the second input." << endl;
				s = getInt();
			}
			cout << "Please enter an integer value for the first input." << endl;
			f = getInt();
		}

	// In the case that the user input both commands correctly, it checks both
	// values to see if they are valid integers, and prompts the user to input
	// a value again it is valid if an integer is not entered.
	} else if(argc == 5) {
		for (int i = 1; i < argc; i++) {
			if (strcmp(argv[i], "-f") == 0) {
				if (isInt((i + 1), argv)) {
					f = atoi(argv[i + 1]);
				} else {
					cout << "Please enter an integer value for the first input." << endl;
					f = getInt();
				}			 
			} else if (strcmp(argv[i], "-s") == 0) {
                                if (isInt((i + 1), argv)) {
                                        s = atoi(argv[i + 1]);
                                } else {
                                        cout << "Please enter an integer value for the second input." << endl;
                                      	s = getInt();
                                }
			}
		}

        cout << "First value = " << f << endl;
        cout << "Second value = " << s << endl;

	// If user inputs commands in wrong order, does not include valid arguments,
	// or if there are more than 5 arguments, inform user how to use program.
        } else {
                cout << "USAGE: " << argv[0] << " [-f <number>] [-s <number>]" << endl;
                return 0;
	}
	return 0;	
}

//This function gets input from user and continues to prompt
//them to get a valid integer if one is not input.
int getInt() {
	int value;
        cin >> value;
        while(!cin){                                            //enter loop if cin is not an int
        	cin.clear();                                    //clear the cin error state
                cin.ignore(9999, '\n');                                         //discard characters in stream
                cout << "Please enter an integer." << endl;
                cin >> value;
	}	
	return value;
}

//This function runs through the string provided by the user
//to check if it is a valid integer.
bool isInt(int argc, char* argv[]) {
	bool isInt;
        for (int j = 0; j < strlen(argv[argc]); j++) {  //For loop runs through each char in the array at argc
                if (isdigit(argv[argc][j])) { 	// Checks to see if char is an integer
			isInt = true;
        	} else {
			isInt = false; // If there is ever a non-integer character, exit loop and return false
			return isInt;
		}
	}
	return isInt;
	
}


//a program to print something using repetition

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{

	int input = -1;

	//explain what kind of input we are looking for and get input
	cout<< "What would you like to do today?" << endl;
	cout<< "[1] Sing \"99 bugs reported to squash!\" (really fast!)" << endl;
	cout<< "[-1] Quit this nonsense!" << endl;
	cin>> input;

	//Perform an action pased on the input above
	if(input == 1) {
		cout<< "Oh!" << endl;
		for(int verse = 99; verse > 0; --verse) {
			cout<< "There are " << verse << " bugs reported to squash, ";
			cout<< verse << " bugs to squash!" << endl;
			cout<< "You fix one up, and test it around, " << (verse - 1) << " bugs to squash!" << endl;
		}
		cout<< "then you quit, but you forgot to commit, leaving you back at 99 bugs to squash!" << endl;
	} else if(input == -1) {
		cout<< "You have entered -1, we will now stop asking you questions." << endl;
	} else {
		cout<< "You entered some invalid input, next time try to enter some valid input."<<endl;
	}
		//mostly blank line... to keep things separated (makes the program a bit more readable)
	cout<< endl;
	cout<< "Thanks for participating, now returning." << endl;
	return 0;
}


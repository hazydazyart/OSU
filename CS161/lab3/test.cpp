/******************************************************
 * ** Author: Megan Conley
 * ** Date: 10/10/2013
 * ** Description: Lab 3
 * ** Input: User inputs 1 or 0 to answer true or false question
 * ** Output: Output depends on user input: for 1, it's "I love vi!"
 * ** For 0, it's "You hate vi!?"
 * ** For all other input, output is "Please enter either 1 or 0."
 * ******************************************************/


#include <iostream>

int main()
{
	int userInput;
	std::cout<< "Do you like vi? 1 - True, 0 - false: "<< std::endl;
	std::cin>> userInput;
	if (userInput == 1){
		std::cout<< "You love vi!" << std::endl;
	}
	else if(userInput == 0) {
		std::cout<<"You hate vi!?" << std::endl;
	}
	else
	{
		std::cout<<"Please enter either 1 or 0." << std::endl;
	}

	return 0;
}

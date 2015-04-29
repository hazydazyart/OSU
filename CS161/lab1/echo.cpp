/******************************************************
 **** Author: Megan Conley
 **** Date: 10/2/2013
 **** Description: Lab 1
 **** Input: An int
 **** Output: An int entered by the user
 ********************************************************/


#include <iostream>

int main()
{
	int input_value; //a "variable" that will hold a value of "type" "int",  which can hold whole values
        std::cout<< "Please enter a number to be printed: "; //tell the user what they should be doing
	std::cin >> input_value; //get the value from the user
	std::cout<< "You entered: " << input_value <<std::endl; //indicate what is being printed and print it

	return 0;
}


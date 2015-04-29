/******************************************************
 * ** Author: Megan Conley
 * ** Date: 11/2/2013
 * ** Description: Lab 6
 * ** Input: User chooses two ints to be used in the functions
 * ** Output: Either the two ints added together or multiplied
 * ******************************************************/

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int add_it(int first, int second);
int add_rec(int first, int second);
int mult_it(int first, int second);
int mult_rec(int first, int second, int third);

int main() {

	//Initialize variables
	int operand1, operand2, operand3;

	cout<< "This program adds two numbers." <<endl;
	cout<< "Please enter the first number: ";
	cin>> operand1;
	cout<< "Please enter the second number: ";
	cin>> operand2;

	//First output uses interative function
	cout<< "Using the interative function, the sum is ";
	cout<< add_it(operand1, operand2) << endl;

	//Second output uses recursive function
	cout<< "Using the recursive function, the sum is ";
	cout<< add_rec(operand1, operand2) << endl;

	//Third output is the two ints multiplied using iterative function
	cout<< "Using the interative function, the product is ";
	cout<< mult_it(operand1, operand2) << endl;
	
	//Fourth output is the two ints multiplied using recursive function
	cout<< "Using the recursive function, the product is ";
	cout<< mult_rec(operand1, operand2, operand1) << endl;

	return 0;

}

//This function adds two ints together iteratively
int add_it(int first, int second) {
	int result = first;
	for (int current = 0; current < second; ++current) {
		result++;
	}
	return result;
}

//This function adds two ints together recursively
int add_rec(int first, int second) {
	if(second <= 0) {
		return first;
	} else {
		return add_rec(++first, --second);
	}
}

//This function multiplies two ints iteratively without using the
//multiplication operand
int mult_it(int first, int second) {
	int result = first;
	for (int current = 1; current < second; ++current) {
		//Instead of multiplying, the result increased
		//by the original int each time the for loop runs
		first += result;
	}
	
	return first;
}

//This funciton multiplies two ints recursively
//It takes an extra parameter to keep the first
//input the same; if I tried to use the method
//above, it would keep updating both the first
//and third ints, rather than keep the third
//the same in order to keep increasing by the original
//int.
int mult_rec(int first, int second, int third) {
	if(second <= 1) {
		return first;
	} else {
		return mult_rec(first+=third, --second, third);
	}
}

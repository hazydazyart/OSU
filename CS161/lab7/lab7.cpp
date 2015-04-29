/******************************************************
 * ** Author: Megan Conley
 * ** Date: 11/9/2013
 * ** Description: Lab 7, part 1
 * ** Input: n/a
 * ** Output: Addresses/values of pointers
 * ******************************************************/

#include <iostream>

using std::cout;
using std::endl;

int main() {

	//Declare all pointers and define variables
	double *d;
	double **dp;
	double d1, d2, d3;
	d1 = 7.8;
	d2 = 10.0;
	d3 = .009;

	//Prints out the address of *d and **dp
	//to compare to the addresses of the variables
	//below.
	cout << "The address of *d is " << &d << endl;
	cout << "The address of **dp is " << &dp << endl;

	//This section prints the address and value using pointer d.
	//It will point to each variable in turn.
	d = &d1;
	cout << "The address of d1 is " << d << " and its value";
	cout << " is " << *d << endl;

	d = &d2;
        cout << "The address of d2 is " << d << " and its value";
        cout << " is " << *d << endl;

	d = &d3;
        cout << "The address of d3 is " << d << " and its value";
        cout << " is " << *d << endl;

	//Set dp equal to the address of d
	dp = &d;

	//Since dp points to d, the address of the variables are now
	//the address of d, unlike above, where they were set to
	//their own addresses
        cout << "The address of d1 is " << dp << " and its value";
        cout << " is " << d1 << endl;
        cout << "The address of d2 is " << dp << " and its value";
        cout << " is " << d2 << endl;
        cout << "The address of d3 is " << dp << " and its value";
        cout << " is " << d3 << endl;

	return 0;

}


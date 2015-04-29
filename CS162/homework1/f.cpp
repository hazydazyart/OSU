/********************************************************************* 
 * ** Program Filename: f.cpp
 * ** Author: Megan Conley
 * ** Date: 1/10/2014
 * ** Description: Implementation file for f.cpp
 * Part of Homework 1, #1
 * ** Input: none
 * ** Output: Prints a notification that this is function f,
 * then prints the sum of the two parameter ints
 * The interface for void f{} is in the header file f.h.
 * *********************************************************************/ 

#include <iostream>
#include "f.h" /* The header file contains the declaration of f() */

namespace A {

/********************************************************************* 
 * ** Function: void f
 * ** Description: Prints a statement describing the function
 * then prints the sum of the two parameters
 * ** Parameters: int a, int b
 * ** Pre-Conditions: n/a
 * ** Post-Conditions: n/a
 * *********************************************************************/ 

	void f(int a, int b) {
		std::cout << "Function F called: Adding " << a << " + " << b << std::endl;
		std::cout << a + b << std::endl;
	}
}

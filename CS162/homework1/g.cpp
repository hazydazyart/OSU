/*********************************************************************
 * ** Program Filename: g.cpp
 * ** Author: Megan Conley
 * ** Date: 1/10/2014
 * ** Description: Implementation file for g.cpp
 * Part of Homework 1, #1
 * ** Input: none
 * ** Output: Prints a notification that this is function g,
 * then prints the difference of the two parameter ints
 * The interface for void f{} is in the header file g.h.
 * *********************************************************************/

#include <iostream>
#include "g.h" /* Header file contains the declaration of function g */

namespace A {

/********************************************************************* 
 ** Function: void g
 ** Description: Prints a declaration that it is function g then
 * prints the difference of the two parameters
 ** Parameters: int a, int b
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/ 

        void g(int a, int b) {
                std::cout << "Function G called: Subtracting " << a << " - " << b << std::endl;
                std::cout << a - b << std::endl;
        }
}



/********************************************************************* 
 * ** Program Filename: main.cpp
 * ** Author: Megan Conley
 * ** Date: 1/10/2014
 * ** Description: Homework 1, #1
 * ** Input: none
 * ** Output: The output of the functions f(int, int) and g(int, int)
 * as defined in the header and implementation files
 *********************************************************************/ 

#include <iostream>
#include "f.h" 
#include "g.h"

/* At first I #included f.cpp and g.cpp, the implementation files, but
 * got an "already defined" error.
 * I realized that it defined them in the headers, so as long as the
 * implementation was included when compiled, it would still work
 * without it explicitly in the main program. */

int main() {
	
	using namespace A;

	/* Both functions require two ints; picked 
 	 * two at random just for demonstration. */
	f(10, 7);

	g(10, 7);

	return 0;
}

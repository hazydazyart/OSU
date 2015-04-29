/********************************************************************* 
 * ** Program Filename: fibonacci.cpp
 * ** Author: Megan Conley
 * ** Date: 3/9/2014
 * ** Description: Lab 4
 * ** Input: Int
 * ** Output: The nth number in the fibonacci sequence, where n is
 * the user's input.
 * *********************************************************************/

#include<iostream>
#include<time.h>
#include<iomanip>

/********************************************************************* 
 * ** Function: rec_fib
 * ** Description: Computes fibonacci sequence up to the parameter
 * by recursion
 * ** Parameters: Int
 * ** Pre-Conditions: Valid value passed as parameter 
 * ** Post-Conditions: Returns an int
 * *********************************************************************/

int rec_fib(int input) {
	
	if(input <= 1) {
		return input;
	} else {
		return (rec_fib(input - 1) + rec_fib(input - 2));
	}
}

/********************************************************************* 
 * ** Function: it_fib
 * ** Description: Computes fibonacci sequence up to parameter
 * iteratively.
 * ** Parameters: Int
 * ** Pre-Conditions: Valid value passed as parameter 
 * ** Post-Conditions: Returns an int
 * *********************************************************************/

int it_fib(int input) {

	int temp_a = 0;
	int temp_b = 1;
	int temp_c;

	if(input == 0) {
		return temp_a;
	}

	for(int i = 2; i <= input; i++) {
		temp_c = temp_a + temp_b;
		temp_a = temp_b;
		temp_b = temp_c;
	}

	return temp_b;
} 

/********************************************************************* 
 * ** Function: array_fib
 * ** Description: Calculates fibonacci sequence up to input, storing
 * values in an array
 * ** Parameters: int, int array
 * ** Pre-Conditions: Valid values are passed as parameters
 * ** Post-Conditions: Returns an int
 * *********************************************************************/

int array_fib(int input, int array[]) {

	if(input <= 1) {
		return input;
	}
	if(array[input] != -1) { // array is initialized to be filled with -1
		return array[input];
	}
	array[input] = array_fib((input - 1), array) + 
			array_fib((input - 2), array);
}

int main() {
	
	int in;

	std::cout << "Enter a positive integer: ";
	std::cin >> in;

	while(!std::cin || in < 0) {
		std::cin.clear();
		std::cin.ignore(9999, '\n');
		std::cout << "Error. Enter a positive integer: ";
		std::cin >> in;
	}

	// Create an array for array_fib function
        int array[in+1];
        for(int i = 0; i <= in; i++) {
                array[i] = -1;
        }

	clock_t t;
	t = clock();

	std::cout << std::setprecision(10) << std::fixed;

	std::cout << "Calculated recursively: " << rec_fib(in) << std::endl;
	t = clock() - t;
	std::cout << "This calculation took " << ((float)t)/CLOCKS_PER_SEC
			<< " seconds." << std::endl;

	t = clock();
	std::cout << "Calculated iteratively: " << it_fib(in) << std::endl;
        t = clock() - t;
        std::cout << "This calculation took " << ((float)t)/CLOCKS_PER_SEC
                        << " seconds." << std::endl;

        t = clock();
	std::cout << "Using an array: " << array_fib(in, array) << std::endl;
        t = clock() - t;
        std::cout << "This calculation took " << ((float)t)/CLOCKS_PER_SEC
                        << " seconds." << std::endl;

	return 0;
}

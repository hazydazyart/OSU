/********************************************************************* 
 * ** Program Filename: conleyme_assn1_3-4.cpp
 * ** Author: Megan Conley
 * ** Date: 1/7/2014
 * ** Description: Assignment #1, 3-4
 * ** Input: None
 * ** Output: Prints the three arrays - one filled with 4s, one filled
 * with 6s, and one that is the product of both.
 * It then outputs the sum of all products of array_1 and array_2
 * that are divisible by 3 or 5 and less than 1000.
 * Finally, it prints out the three arrays for reference.
 * *********************************************************************/ 

#include <iostream> // cout, endl

void fill_array_1(int array_1[10][10]);
void fill_array_2(int array_2[10][10]);
void fill_array_3(int array_3[10][10]);
void multiply(int array_1[10][10], int array_2[10][10], int array_3[10][10]);
void sum(int array_3[10][10]);
void print_array(int array[10][10]);

/* With all of the print statements within the functions,
 * main becomes a streamlined summary of the process.
 */

int main() {

	//Initialize the three arrays
	int array_1[10][10];
	int array_2[10][10];
	int array_3[10][10];

	//Populate the arrays with integers
	fill_array_1(array_1);
	fill_array_2(array_2);
	fill_array_3(array_3);
	
	//Multiply array_1 by array_2 and store the products in array_3
	multiply(array_1, array_2, array_3);
	
	//Add the values in array_3 that are divisible by 3 or 5 and <1000
	sum(array_3);

	//Print the three arrays
	print_array(array_1);
	print_array(array_2);
	print_array(array_3);

	return 0;
}

 
/********************************************************************* 
 * ** Function: void fill_array_1
 * ** Description: Sets the value of all ints in array_1 to 4
 * ** Parameters: int array_1[10][10]
 * ** Pre-Conditions: n/a
 * ** Post-Conditions: n/a
 * ** Comments: No particular reason for this number, just picked one
 *  * to test.
 * *********************************************************************/	

void fill_array_1(int array_1[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			array_1[i][j] = 4;
		}
	}
}

/*********************************************************************
 * ** Function: void fill_array_2
 * ** Description: Sets the value of all ints in array_2 to 6
 * ** Parameters: int array_2[10][10]
 * ** Pre-Conditions: n/a
 * ** Post-Conditions: n/a
 * ** Comments: No particular reason for this number, just picked one
 * to test.
 * *********************************************************************/


void fill_array_2(int array_2[10][10]) {
        for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                        array_2[i][j] = 6;
                }
        }
}

/*********************************************************************
 * ** Function: void fill_array_3
 * ** Description: Sets the value of all ints in array_3 to 0
 * ** Parameters: int array_3[10][10]
 * ** Pre-Conditions: n/a
 * ** Post-Conditions: n/a
 * ** Comments: Originally I did not have array_3 set to anything
 * and it caused an error in the output; I realized I had to initialize
 * the values before I could alter them in the multiplication function.
 * *********************************************************************/


void fill_array_3(int array_3[10][10]) {
        for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                        array_3[i][j] = 0;
                }
        }
}

/*********************************************************************
 * ** Function: void multiply
 * ** Description: Performs a matrix multiplication of array_1 and array_2 
 * and stores the products in array_3
 * ** Parameters: int array_1[10][10], int array_2[10][10], int array_3[10][10]
 * ** Pre-Conditions: n/a
 * ** Post-Conditions: n/a
 * ** Comments: I used this page to help refresh my memory on how to
 * multiply matrices: http://www.mathsisfun.com/algebra/matrix-multiplying.html
 * *********************************************************************/


void multiply(int array_1[10][10], int array_2[10][10], int array_3[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				array_3[i][j] += array_1[i][k] * array_2[k][i];
			}
		}
	}
}

/*********************************************************************
 * ** Function: void sum
 * ** Description: Checks if the values in array_3 are divisible by 3 or 5
 * and is less than 1000, and adds it to the running sum if it is
 * ** Parameters: int array_3[10][10]
 * ** Pre-Conditions: n/a
 * ** Post-Conditions: n/a
 * ** Comments: I used this page to check that the output was correct:
 * http://www.bluebit.gr/matrix-calculator/multiply.aspx
 * *********************************************************************/

void sum(int array_3[10][10]) {

	int sum = 0; // initializing sum for running count in for loop

	for (int i = 0; i < 10; i ++) {
		for (int j = 0; j < 10; j++) {
			if ((array_3[i][j] % 3 == 0 || array_3[i][j] % 5 == 0) && array_3[i][j] <= 1000) {
			//	std::cout << "Adding " << array_3[i][j] << std::endl; // This line was used for testing
				sum += array_3[i][j];
			}
		}
	}
	
	std::cout << "The sum is " << sum << std::endl;
}

/*********************************************************************
 * ** Function: void print_array
 * ** Description: Prints out any 10x10 array
 * ** Parameters: any 10x10 array
 * ** Pre-Conditions: n/a
 * ** Post-Conditions: n/a
 * ** Comments: This could be easily coded to print any array by adding
 * additional parameters for the dimensions, but since this program
 * only deals with 10x10 arrays I decided to hard code it just for ease
 * and consistency.
 * *********************************************************************/

void print_array(int array[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			std::cout << array[i][j] << " ";
		}
	std::cout << std::endl;
	}

	std::cout << std::endl;
}

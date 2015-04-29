/********************************************************************* 
 * ** Program Filename: template3.cpp
 * ** Author: Megan Conley
 * ** Date: 3/1/2014
 * ** Description: Assignment 8.3
 * ** Input: none
 * ** Output: Arrays of various primitive types sorted using an insertion
 * sort template
 * *********************************************************************/

#include<iostream>
#include<iomanip>

/********************************************************************* 
 * ** Function: sort
 * ** Description: Template for insertion sort that prints the array
 * at each stage of sorting
 * ** Parameters: array, int
 * ** Pre-Conditions: array is initialized with at least 2 values 
 * ** Post-Conditions: Array is sorted and printed to console
 * *********************************************************************/ 

template <class T1>
void sort(T1 a[], int length) {
	int j;
	T1 temp;

	for(int i = 1; i < length; i++) {
		j = i;
		while(j > 0 && a[j] < a[j-1]) {
			temp = a[j];
			a[j] = a[j-1];
			a[j-1] = temp;
			j--;
		}
		print(a, length);
	}
}

/********************************************************************* 
 * ** Function: print
 * ** Description: Template to print arrays of any variable type
 * ** Parameters: Array, int
 * ** Pre-Conditions: Array is initialized with at least 1 value
 * ** Post-Conditions: Array is printed to console
 * *********************************************************************/ 

template <class T1>
void print(T1 a[], int length) {

	std::cout << "Sorting: ";
	for(int i = 0; i < length; i++) {
		std::cout << " " << std::setprecision(4) << a[i];
	}
	std::cout << std::endl;
}

int main() {

	// Sort an int array
	int array[5] = {5,4,3,2,1};
	sort(array, 5);

	// Sort a double array
	double array_d[5] = {5.2, 4.3, 3.4, 2.5, 1.8};
	sort(array_d, 5);

	// Sort a char array
	char array_c[5] = {'e','d','c','b','a'};
	sort(array_c, 5);
	
	return 0;
}

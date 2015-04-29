/********************************************************************* 
 * ** Program Filename: median.cpp
 * ** Author: Megan Conley
 * ** Date: 2/8/2014
 * ** Description: Assignment 5
 * ** Input: File which contains ints
 * ** Output: 1st, 2nd, and 3rd quartiles of the input list of ints
 * *********************************************************************/

#include<iostream>
#include<string>
#include<fstream>

float find_quartile(int arr[], int index);

int main() {

	std::ifstream ifs;

	ifs.open("input.txt");

	int count = 0;
	int temp; // Variable to hold values from file to be insert into an array

	ifs >> temp;

	// Counts how many ints are in the input file
	while(!ifs.eof()) {
		count++;
		ifs >> temp;
	}
	std::cout << std::endl;

        ifs.close(); // Close the file
        ifs.clear(); // Clear the eof flag

	//If no ints are found, exits program
	if (count == 0) {
		std::cout << "Error: no ints found in file." << std::endl;
		return 0;
	}

	int arr[count];

	ifs.open("input.txt");

	// Fills an array with the contents of the input file
	for (int i = 0; i < count; i++) {
		ifs >> temp;
		arr[i] = temp;
	}

	ifs.close();

	std::cout << "There are " << count << " numbers in this file." << std::endl;
	std::cout << "Contents of file: ";

        for (int i = 0; i < count; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	// Computes the three quartiles
	float q1 = find_quartile(arr, (count/4.0));
        float median = find_quartile(arr, (count/2.0));
	float q3 = find_quartile(arr, (count/1.25));

	std::cout << "First quartile: " << q1 << std::endl;
        std::cout << "Second quartile: " << median << std::endl;
	std::cout << "Third quartile: " << q3 << std::endl;

	return 0;
}

/********************************************************************* 
 * ** Function: float find_quartile
 * ** Description: Finds the specified quartile from an array
 * ** Parameters: Array of ints, one int to specify the quartile
 * ** Pre-Conditions: Array of ints contains at least one int
 * ** Post-Conditions: Returns the specified quartile value
 * *********************************************************************/ 


float find_quartile(int arr[], int index) {
	float quartile;

        if (index % 2 == 0) {
                quartile = (arr[index] + arr[index-1])/2.0;
        } else {
               quartile = arr[index];
        }

	return quartile;
}


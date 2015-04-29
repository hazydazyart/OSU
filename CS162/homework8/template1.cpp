/********************************************************************* 
 * ** Program Filename: template1.cpp
 * ** Author: Megan Conley
 * ** Date: 3/1/2014
 * ** Description: Assignment 8.1
 * ** Input: Int
 * ** Output: Location of int in array if found; error message if not
 * *********************************************************************/ 

#include<iostream>
const int ARRAY_SIZE = 10;

/********************************************************************* 
 * ** Function: search
 * ** Description: Searches a sorted array for a specified input
 * ** Parameters: array and four variables of the same type; one bool
 * ** Pre-Conditions: Array has been sorted from lowest to highest
 * ** Post-Conditions: Sets bool parameter to true if key is fond
 * *********************************************************************/ 

template <class T1>
void search(const T1 a[], int lowEnd, int highEnd, T1 key,
		bool& found, int& location) {

	int first = lowEnd;
	int last = highEnd;
	int mid;

	found = false;
	while ((first <= last) && !(found)) {
		mid = (first + last)/2;
		if (key == a[mid]) {
			found = true;
			location = mid;
		} else if (key < a[mid]) {
			last = mid - 1;
		} else if (key > a[mid]) {
			first = mid + 1;
		}
	}
}

int main() {

	int a[ARRAY_SIZE]; // testing int in search template function
	const int finalIndex = ARRAY_SIZE - 1;
	int key = 0;
	int location = 0;
	bool found;

	for (int i = 0; i < ARRAY_SIZE; ++i) {
		a[i] = i;
	}

	std::cout << "Enter number to be located: ";
	std::cin >> key;
	search(a, 0, finalIndex, key, found, location);

	if(found) {
		std::cout << key << " is in index location "
			<< location << std::endl;
	} else {
		std::cout << key << " is not in the array." << std::endl;
	}

        return 0;
}

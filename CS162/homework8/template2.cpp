/*********************************************************************
 * ** Program Filename: template1.cpp
 * ** Author: Megan Conley
 * ** Date: 3/1/2014
 * ** Description: Assignment 8.2
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
void search(const T1 a[], int first, int last,
		T1 key, bool& found, int& location) {

	int mid;
	if(first > last) {
		found = false;
	} else {
		mid = (first + last) /2;
		if (key == a[mid]) {
			found = true;
			location = mid;
		} else if (key < a[mid]) {
			search(a, first, mid - 1, key, found, location);
		} else if (key > a[mid]) {
			search(a, mid + 1, last, key, found, location);
		}
	}
}

int main() {

        int a[ARRAY_SIZE]; // testing with int, though this could be any primitive type
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

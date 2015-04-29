/********************************************************************* 
 * ** Program Filename: conleyme_assn_2-2.cpp
 * ** Author: Megan Conley
 * ** Date: 1/19/2014
 * ** Description: Chapter 18, Project 4
 * ** Input: none
 * ** Output: Product IDs that correspond to the product names passed
 * as parameters. Throws an exception if the product name is not found
 * in the product name array.
 * *********************************************************************/ 

#include <iostream>
#include <string>
#include <stdlib.h>

int getProductID( int ids[], std::string names[],
        int numProducts, std::string target);

int main() { // Sample code to test the getProductID function

        int productIds[] = {4, 5, 8, 10, 13};
        std::string products[] = {"computer","flash drive",
       	        "mouse","printer","camera"};

        std::cout << getProductID(productIds, products, 5, "mouse") << std::endl;
        std::cout << getProductID(productIds, products, 5, "camera") << std::endl;
        std::cout << getProductID(productIds, products, 5, "laptop") << std::endl;

        return 0;
}

/********************************************************************* 
 * ** Function: int getProductID
 * ** Description: Returns the value that corresponds with the position
 * in the array of the product name. Throws an exception if product name
 * is not found.
 * ** Parameters: int ids[], std::string names[], int numProducts,
 * std::string target
 * ** Pre-Conditions: The two arrays passed to the function have the same
 * length 
 * ** Post-Conditions: Product ID value is returned
 * *********************************************************************/ 

int getProductID( int ids[], std::string names[],
	int numProducts, std::string target) {
	
	try {
		for (int i=0; i < numProducts; i++) {
			if (names[i] == target) {
				return ids[i];
			}		
		}
	
		throw target;
	
	}
	catch (std::string x) {	
		std::cout << "Error: " << x << " not found." << std::endl;
		exit(0);
	}
}	


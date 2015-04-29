/********************************************************************* 
 * ** Program Filename: list.cpp
 * ** Author: Megan Conley
 * ** Date: 2/8/2014
 * ** Description: Assignment 5
 * ** Input: Two files which contain ints
 * ** Output: Third file with sorted contents from first two files
 * *********************************************************************/

#include<iostream>
#include<fstream>
#include<vector>
#include<iterator>
#include<algorithm>

void sort(std::ifstream& ifs, std::ofstream& ofs, std::ifstream& ifs2);

int main() {

        std::ifstream ifs;
	std::ifstream ifs2;
        std::ofstream ofs;

        ifs.open("num1.txt");
	ifs2.open("num2.txt");
	ofs.open("output.txt");

	sort(ifs, ofs, ifs2);

        return 0;
}

/********************************************************************* 
 * ** Function: void sort
 * ** Description: Reads ints from two input files, sorts them in
 * ascending order, and write the sorted list to another file
 * ** Parameters: Two ifstreams, one ofstream
 * ** Pre-Conditions: Two files exist and have at least one int
 * ** Post-Conditions: Third file with sorted list of numbers is created
 * *********************************************************************/ 


void sort(std::ifstream& ifs, std::ofstream& ofs, std::ifstream& ifs2) {
	int temp;
	std::vector<int> list;

        ifs >> temp;

        while (!ifs.eof()) {
                list.push_back(temp);
                if (!ifs) break;	// Prevents the last number from being read twice
                ifs >> temp;
        }

	ifs.close();	// Files are closed as soon as they are not needed

        ifs2 >> temp;

        while (!ifs2.eof()) {
                list.push_back(temp);
                if (!ifs2) break;
                ifs2 >> temp;
        }

	ifs2.close();

	std::cout << "Unsorted list: ";

        for (std::vector<int>::iterator i = list.begin(); i != list.end(); i++) {
                std::cout << *i << " ";
        }

        std::cout << std::endl;

        std::sort(list.begin(), list.end());

	std::cout << "Sorted list: ";

        for (std::vector<int>::iterator i = list.begin(); i != list.end(); i++) {
                std::cout << *i << " ";
		ofs << *i << " ";
        }
        std::cout << std::endl;

	std::cout << "Sorted list printed to output.txt." << std::endl;

	ofs.close();

}

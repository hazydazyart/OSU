/********************************************************************* 
 * ** Program Filename: tag.cpp
 * ** Author: Megan Conley
 * ** Date: 1/31/2014
 * ** Description: Lab 3
 * ** Input: Int - length of vector; strings - names to fill vector
 * ** Output: Member of vector that is "It" - whoever is the last name
 * as it cycles through the vector of names for as many times as there
 * are words in the rhyme.
 * *********************************************************************/ 

#include<vector>
#include<iostream>
#include<iterator>
#include<string>

void print_vector(std::vector<std::string> &v);
int get_total(std::vector<std::string> &rhyme);
void find_it(std::vector<std::string> &tag, int count, std::string& it, std::vector<std::string> &rhyme);

int main() {

	 
        std::vector<std::string> tag;
	std::vector<std::string> rhyme = {"Eeny,", "meeny,", "miny,", "moe,", "Catch", "a", "tiger", "by", "the", "toe.", "If", "he", "hollers,", "let", "him", "go,", "Eeny,", "meeny,", "miny,", "moe."}; 
 
        int total = get_total(rhyme); 
	std::string name = "";
	std::string it = "";
 
	// Enters as many names as user specified in get_total(rhyme)
        for (int i = 1; i <= total; i++) {
		std::cout << "Please enter a name: ";
		std::cin >> name;
                tag.push_back(name);
        }
 
        print_vector(tag); // print the list of names
	std::cout << std::endl;
	print_vector(rhyme); // print the rhyme
	std::cout << std::endl;
 
        int count = 0; 
        find_it(tag, count, it, rhyme); // find the name that is "it"
 
        std::cout << it << " is it!" << std::endl; // print the name
      
        return 0;
}

/********************************************************************* 
 * ** Function: find_it
 * ** Description: Finds which name is it in the vector of strings
 * ** Parameters: 2 string vectors, 1 int, 1 string
 * ** Pre-Conditions: Both string vectors have at least one value,
 * int parameter has a value
 * ** Post-Conditions: Sets string parameter to name that is "it."
 * *********************************************************************/ 

void find_it(std::vector<std::string> &tag, int count, std::string& it, std::vector<std::string> &rhyme) {
 
        for(std::vector<std::string>::iterator i = tag.begin(); count <= 20; i++) {
                if (i == tag.end()) { // if it hits the end, wrap around
                        i = tag.begin();
                }
                if (++count == 20) { // 20 words in the rhyme means it iterates through 20 names
                        it = *i;
		}		
        }
}

/********************************************************************* 
 * ** Function: print_vector
 * ** Description: Prints contects of a string vector
 * ** Parameters: String vector
 * ** Pre-Conditions: String vector has at least one value
 * ** Post-Conditions: String vector is printed to console
 * *********************************************************************/ 

void print_vector(std::vector<std::string> &v) {
 
        for(std::vector<std::string>::iterator i = v.begin(); i != v.end(); i++) {
                std::cout << *i << " ";
        }
        std::cout << std::endl;
}

/********************************************************************* 
 * ** Function: get_total
 * ** Description: Prints the rhyme and prompts user until valid int
 * is entered
 * ** Parameters: String vector
 * ** Pre-Conditions: String vector is initialized 
 * ** Post-Conditions: Returns an int
 * *********************************************************************/ 

int get_total(std::vector<std::string> &rhyme) {
 
        int total;
 
        std::cout << "This program will tell you who is it out of a list " << std::endl;
std::cout << "of names you enter, based on this rhyme: " << std::endl;
 
print_vector(rhyme);
 
        std::cout << "How many people in line are there? ";
        std::cin >> total;
 
        while(!std::cin || total < 1) { // There should be at least one person in line.
                std::cin.clear();
                std::cin.ignore(9999, '\n');
                std::cout << "Please enter a positive integer. ";
                std::cin >> total;
        }
 
        return total;
}

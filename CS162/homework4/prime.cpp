/********************************************************************* 
 * ** Program Filename: prime.cpp
 * ** Author: Megan Conley
 * ** Date: 1/31/2014
 * ** Description: Homework 4, assignment 3
 * ** Input: n/a
 * ** Output: Either the next closest prime number or closest previous
 * prime number, when overloaded operators ++ or -- are callsed
 * *********************************************************************/ 


#include<iostream>
#include<stdio.h>
#include<math.h>

class Prime {

	public:

/********************************************************************* 
 * ** Function: Prime class constructors/destructors
 * ** Description: Constructors - either provides default argument or
 * takes one parameter to set the value of int num. Destructor alos
 * defined.
 * ** Parameters: 0, 1 int
 * ** Pre-Conditions: n/a
 * ** Post-Conditions: n/a
 * *********************************************************************/ 


	Prime() {
		num = 0;
	}

	Prime(int input) {
		num = input;
	}

	~Prime() {};

	Prime& operator++();
	Prime& operator++(int ignored);
	Prime& operator--();
	Prime& operator--(int ignored);
        friend std::ostream& operator<<(std::ostream& os, const Prime& p);

	private:

	int num;
};

int next_prime(int num);
int prev_prime(int num);
bool prime(int x);
int check_input();

int main() {

	int choice = 0;

        std::cout << "Please enter a number to begin: ";
        int prime = check_input();
	Prime test(prime);
	Prime test2(prime);

	std::cout << "Next closest prime using prefix ++: " << ++test << std::endl;
	std::cout << "Next closest prime using postfix ++: " << test++ << std::endl;
        std::cout << "Previous closest prime using prefix --: " << --test2 << std::endl;
        std::cout << "Previous closest prime using postfix --: " << test2-- << std::endl;

	return 0;

}

/********************************************************************* 
 * ** Function: int check_input
 * ** Description: Prompts user for input until valid int value is
 * entered.
 * ** Parameters: none
 * ** Pre-Conditions: none 
 * ** Post-Conditions: returns an int
 * *********************************************************************/ 


int check_input() {

	int input;
        std::cin >> input;
        while(!std::cin || input < 0) {
               std::cin.clear();
               std::cin.ignore(9999, '\n');
               std::cout << "Please enter a positive integer: ";
               std::cin >> input;
        }

	return input;
}

/********************************************************************* 
 * ** Function: bool prime
 * ** Description: Takes an int as a parameter and checks if it is
 * prime. Returns true if prime, false if not.
 * ** Parameters: One int
 * ** Pre-Conditions: n/a
 * ** Post-Conditions: bool variable is set to true or false
 * *********************************************************************/ 


bool prime(int x) {

        for (int i = 2; i <= (x/2); i++) {
                if (x % i == 0) {
                        return false;
                }
        }
	return true;
}

/********************************************************************* 
 * ** Function: int next_prime
 * ** Description: Finds the next closest prime number to the int
 * passed as a parameter and returns it.
 * ** Parameters: One int
 * ** Pre-Conditions: Function bool prime is working
 * ** Post-Conditions: Returns next closest prime
 * *********************************************************************/ 


int next_prime(int num) {

        if(prime(num)) {
                num++;
        }

        while(!prime(num)) {
                num++;
        }

	return num;
}

/********************************************************************* 
 * ** Function: int prev_prime
 * ** Description: Finds the closest previous prime number to the
 * int passed as a parameter and returns it.
 * ** Parameters: One int
 * ** Pre-Conditions: Function bool prime is working
 * ** Post-Conditions: Returns closest previous prime integer
 * *********************************************************************/ 

int prev_prime(int num) {

        if(prime(num)) {
                num--;
        }

        while(!prime(num)) {
                num--;
        }

        return num;
}

/********************************************************************* 
 * ** Function: operator++
 * ** Description: Overloads the operator ++ to return the next closest
 * prime number (prefix)
 * ** Parameters: n/a
 * ** Pre-Conditions: Prime class object exists and is initialized to
 * some value 
 * ** Post-Conditions: Prime class object value updated to next
 * closest prime
 * *********************************************************************/ 

Prime& Prime::operator++() {
        this->num = next_prime(num);
        return *this;
}

/*********************************************************************
 * ** Function: operator++
 * ** Description: Overloads the operator ++ to return the next closest
 * prime number (postfix)
 * ** Parameters: n/a
 * ** Pre-Conditions: Prime class object exists and is initialized to
 * some value
 * ** Post-Conditions: Prime class object value updated to next
 * closest prime
 * *********************************************************************/

Prime& Prime::operator++(int ignored) {
    	this->num = next_prime(num);
	return *this;
}

/*********************************************************************
 * ** Function: operator--
 * ** Description: Overloads the operator -- to return the closest
 * previous prime number (postfix)
 * ** Parameters: n/a
 * ** Pre-Conditions: Prime class object exists and is initialized to
 * some value
 * ** Post-Conditions: Prime class object value updated to previous
 * closest prime
 * *********************************************************************/

Prime& Prime::operator--() {
	this->num = prev_prime(num);
	return *this;
}

/*********************************************************************
 *  ** Function: operator--
 * ** Description: Overloads the operator -- to return the closest
 * previous prime number (prefix)
 * ** Parameters: n/a
 * ** Pre-Conditions: Prime class object exists and is initialized to
 * some value
 * ** Post-Conditions: Prime class object value updated to previous
 * closest prime
 * *********************************************************************/

Prime& Prime::operator--(int ignored) {
	this->num = prev_prime(num);
	return *this;
}

/********************************************************************* 
 * ** Function: operator <<
 * ** Description: Overloads operator << to print value of an object
 * of the Prime class.
 * ** Parameters: ostream, Prime object
 * ** Pre-Conditions: Prime object has been initialized to some value
 * ** Post-Conditions: Prime object variable num is printed to console.
 * *********************************************************************/ 


std::ostream& operator<<(std::ostream& os, const Prime& p) {
	os << p.num;
	return os;
}

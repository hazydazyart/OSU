/********************************************************************* 
 * ** Program Filename: employee.cpp
 * ** Author: Megan Conley
 * ** Date: 2/15/2014
 * ** Description: Implementation file for Employee class
 * ** Input: n/a
 * ** Output: n/a
 * *********************************************************************/ 


#include<string>
#include<cstdlib>
#include<iostream>
#include "employee.h"

/********************************************************************* 
 * ** Function: Employee constructor
 * ** Description: Default constructor
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: Creates Employee object
 * *********************************************************************/ 

Employee::Employee() {
	name = "No name yet";
	ssn = "No ssn yet";
	netPay = 0;
}

/********************************************************************* 
 * ** Function: Employee constructor
 * ** Description: Constructor
 * ** Parameters: two strings
 * ** Pre-Conditions: none
 * ** Post-Conditions: Creates Employee object usings parameters to set
 * variable values.
 * *********************************************************************/ 

Employee::Employee(const std::string& theName, const std::string& theNumber) {
	name = theName;
	ssn = theNumber;
	netPay = 0;
}

/********************************************************************* 
 * ** Function: getName, getSsn, getNetPay
 * ** Description: Accessor function for private variables
 * ** Parameters: none
 * ** Pre-Conditions: Object exists
 * ** Post-Conditions: Returns values for respective variables
 * *********************************************************************/ 

std::string Employee::getName() const {
	return name;
}

std::string Employee::getSsn() const {
	return ssn;
}

double Employee::getNetPay() const {
	return netPay;
}

/********************************************************************* 
 * ** Function: setName, setSsn, setNetPay
 * ** Description: Mutator functions for private variables
 * ** Parameters: String, string, double
 * ** Pre-Conditions: Object exists
 * ** Post-Conditions: Object variables set to values passed as 
 * parameters.
 * *********************************************************************/ 

void Employee::setName(const std::string& newName) {
	name = newName;
}

void Employee::setSsn(const std::string& newSsn) {
	ssn = newSsn;
}

void Employee::setNetPay(double newNetPay) {
	netPay = newNetPay;
}

/********************************************************************* 
 * ** Function: printCheck
 * ** Description: Prints error message, since Employee objects will not
 * be used.
 * ** Parameters: None
 * ** Pre-Conditions: none
 * ** Post-Conditions: Prints error message
 * *********************************************************************/ 

void Employee::printCheck() const {
	std::cout << "\nERROR: printCheck FUNCTION CALLED FOR AN \n"
	     << "UNDIFFERENTIATED EMPLOYEE. Aborting the program.\n"
	     << "Check with the author of the program about this bug.\n";
	exit(1);
}

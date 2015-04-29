
/********************************************************************* 
 * ** Program Filename: salariedemployee.cpp
 * ** Author: Megan Conley (Walter Savitch, technically)
 * ** Date: 2/15/2014
 * ** Description: Implementation file for SalariedEmployee class
 * ** Input: none
 * ** Output: none
 * *********************************************************************/ 

#include<iostream>
#include <string>
#include "salariedemployee.h"
#include"employee.cpp"

/********************************************************************* 
 * ** Function: SalariedEmployee
 * ** Description: Default constructor
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: Creates SalariedEmployee object with default values
 * *********************************************************************/

SalariedEmployee::SalariedEmployee() {
	Employee();
	salary = 0;
}

/********************************************************************* 
 * ** Function: SalariedEmployee
 * ** Description: Constructor
 * ** Parameters: two strings, one double
 * ** Pre-Conditions: none
 * ** Post-Conditions: Creates SalariedEmployee object initialized to
 * values passed as parameters
 * *********************************************************************/

SalariedEmployee::SalariedEmployee(const std::string& theName, const std::string& theNumber,
					double theWeeklyPay) {
	Employee(theName, theNumber);
	salary = theWeeklyPay;
}

/********************************************************************* 
 * ** Function: getSalary
 * ** Description: Accessor function for salary variable
 * ** Parameters: none
 * ** Pre-Conditions: SalariedEmployee object exists, salary has been
 * initialized
 * ** Post-Conditions: returns salary as double
 * *********************************************************************/

double SalariedEmployee::getSalary() const {
	return salary;
}

/********************************************************************* 
 * ** Function: setSalary
 * ** Description: Mutator function for salary variable
 * ** Parameters: none
 * ** Pre-Conditions: SalariedEmployee object exists
 * ** Post-Conditions: SalariedEmployee salary variable set to parameter
 * *********************************************************************/

void SalariedEmployee::setSalary(double newSalary) {
	salary = newSalary;
}

/********************************************************************* 
 * ** Function: printCheck
 * ** Description: SalariedEmployee printCheck override
 * ** Parameters: none
 * ** Pre-Conditions: SalariedEmployee exists, and at least its name,
 * salary, and ssn variables are set to some value
 * ** Post-Conditions: Prints "pay stub"
 * *********************************************************************/

void SalariedEmployee::printCheck() {
	setNetPay(salary);
	std::cout << "\n________________________________________________\n";
	std::cout << "Pay to the order of " << getName() << std::endl;
	std::cout << "The sum of " << getNetPay() << " Dollars\n";
	std::cout << "_________________________________________________\n";
	std::cout << "Check Stub NOT NEGOTIABLE \n";
	std::cout << "Employee Number: " << getSsn() << std::endl;
	std::cout << "Salaried Employee. Regular Pay: "
	     << salary << std::endl;
	std::cout << "_________________________________________________\n";
}


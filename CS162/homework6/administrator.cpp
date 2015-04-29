/********************************************************************* 
 * ** Program Filename: administrator.cpp
 * ** Author: Megan Conley
 * ** Date: 2/15/2014
 * ** Description: Implementation file for Administrator class
 * ** Input: none
 * ** Output: none
 * *********************************************************************/ 


#include<iostream>
#include<string>
#include"administator.h"

/********************************************************************* 
 * ** Function: Administrator constructor
 * ** Description: Default constructor
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: Creates object with default values
 * *********************************************************************/ 

Administrator::Administrator() {
	SalariedEmployee();
	this->area = "Area of responsibility not set.";
	this->supervisor = "Supervisor name not set.";
	this->title = "Title not set.";
}

/********************************************************************* 
 * ** Function: Administrator constructor
 * ** Description: Non-default constructor
 * ** Parameters: 5 strings, 1 double
 * ** Pre-Conditions: None
 * ** Post-Conditions: Creates Administrator object with all variable set
 * to parameters
 * *********************************************************************/ 

Administrator::Administrator(const std::string& theName, const std::string& theSsn,
                        	double theSalary, std::string& theArea, std::string& theSuper,
				std::string& theTitle) {
	SalariedEmployee(theName, theSsn, theSalary);
	this->area = theArea;
	this->supervisor = theSuper;
	this->title = theTitle;
}

//Administrator deconstructor
Administrator::~Administrator() {}


/********************************************************************* 
 * ** Functions: getArea, getSuper, getTitle
 * ** Description: Accessor functions for private variables
 * ** Parameters: None
 * ** Pre-Conditions: Administrator object exists and variables have been
 * set to some value
 * ** Post-Conditions: Returns respective variables as strings
 * *********************************************************************/ 

std::string Administrator::getArea() {
	return area;
}

std::string Administrator::getSuper() {
	return supervisor;
}

std::string Administrator::getTitle() {
	return title;
}

/********************************************************************* 
 * ** Function: setArea, setSuper, setTitle
 * ** Description: Mutators for Administrator class variables
 * ** Parameters: Each takes 1 string
 * ** Pre-Conditions: Administrator object exists
 * ** Post-Conditions: Respective variables of Administrator object set
 * to the parameter
 * *********************************************************************/ 

void Administrator::setArea(const std::string& theArea) {
	area = theArea;
}

void Administrator::setSuper(const std::string& theSuper) {
	supervisor = theSuper;
}

void Administrator::setTitle(const std::string& theTitle) {
	title = theTitle;
}

/********************************************************************* 
 * ** Function: setInfo
 * ** Description: Prompts user for input and changes the value of
 * the Administrator object variables using the mutators above and from
 * the parent class.
 * ** Parameters: None
 * ** Pre-Conditions: Administrator object exists
 * ** Post-Conditions: Administrator object variables set to user input
 * *********************************************************************/ 

void Administrator::setInfo() {

        std::string name;
        std::string title;
        std::string ssn;
        std::string super;
        std::string area;
        double salary;

        std::cout << "Enter administrator's name: ";
        std::getline(std::cin, name);
        setName(name);
        std::cout << "Enter " << getName() << "'s title: ";
        std::getline(std::cin, title);
        setTitle(title);
        std::cout << "Enter " << getName() << "'s employee #: ";
        std::getline(std::cin, ssn);
        setSsn(ssn);
        std::cout << "Enter " << getName() << "'s area of responsibility: ";
        std::getline(std::cin, area);
        setArea(area);
        std::cout << "Enter " << getName() << "'s supervisor: ";
        std::getline(std::cin, super);
        setSuper(super);
        std::cout << "Enter " << getName() << "'s salary: ";
        std::cin >> salary;
        
        setSalary(salary);
}

/********************************************************************* 
 * ** Function: print
 * ** Description: Prints values for Administrator class object
 * ** Parameters: None
 * ** Pre-Conditions: Administrator object exists
 * ** Post-Conditions: Values for object printed to console
 * *********************************************************************/ 

void Administrator::print() {
	std::cout << "Name: " << this->name << std::endl;
        std::cout << "Employee number: " << this->ssn << std::endl;
        std::cout << "Salary: " << this->salary << std::endl;
        std::cout << "Title: " << this->title << std::endl;
        std::cout << "Area of responsibility: " << this->area << std::endl;
        std::cout << "Supervisor's name: " << this->supervisor << std::endl;
}

/********************************************************************* 
 * ** Function: printCheck()
 * ** Description: Administrator class override for parent class
 * printCheck function
 * ** Parameters: None
 * ** Pre-Conditions: Administrator object exists and at least name,
 * salary, and ssn variables have been initialized
 * ** Post-Conditions: Prints name/salary/ssn in a "pay stub"
 * *********************************************************************/ 

void Administrator::printCheck() {
        std::cout << "\n________________________________________________\n";
        std::cout << "Pay to the order of " << getName() << std::endl;
        std::cout << "The sum of " << salary << " Dollars\n";
        std::cout << "_________________________________________________\n";
        std::cout << "Check Stub NOT NEGOTIABLE \n";
        std::cout << "Employee Number: " << getSsn() << std::endl;
        std::cout << "Administrator. Regular Pay: "
             << salary << std::endl;
        std::cout << "_________________________________________________\n";
}

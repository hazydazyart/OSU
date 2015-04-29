

/********************************************************************* 
 * ** Program Filename: salariedemployee.h
 * ** Author: Megan Conley
 * ** Date: 2/15/2014
 * ** Description: Header file for salaried employee class
 * ** Input: n/a
 * ** Output: n/a
 * *********************************************************************/ 

#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include<string>
#include "employee.h"

class SalariedEmployee : public Employee {

public:
	SalariedEmployee();
	SalariedEmployee(const std::string& theName, const std::string& theSsn,
				double theWeeklySalary);
	double getSalary() const;
	void setSalary(double newSalary);
	void printCheck();

protected:
	double salary;
};

#endif // SALARIED EMPLOYEE_H

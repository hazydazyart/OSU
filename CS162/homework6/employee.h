/********************************************************************* 
 * ** Program Filename: employee.h
 * ** Author: Megan Conley
 * ** Date: 2/15/2014 
 * ** Description: Header file for employee.cpp
 * ** Input: n/a
 * ** Output: n/a
 * *********************************************************************/ 


#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<string>

class Employee {

public:
	Employee();
	Employee(const std::string& theName, const std::string& theSsn);
	std::string getName() const;
	std::string getSsn() const;
	double getNetPay() const;
	void setName(const std::string& newName);
	void setSsn(const std::string& newSsn);
	void setNetPay(double newNetPay);
	void printCheck() const;

protected:
	std::string name;
	std::string ssn;
	double netPay;
};

#endif // EMPLOYEE_H

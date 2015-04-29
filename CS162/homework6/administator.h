
/********************************************************************* 
 * ** Program Filename: administator.h
 * ** Author: Megan Conley
 * ** Date: 2/15/2014 
 * ** Description: Administrator class header file
 * ** Input: n/a
 * ** Output: n/a
 * *********************************************************************/ 

#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include<string>
#include"salariedemployee.cpp"

class Administrator : public SalariedEmployee {

public:
	Administrator();
	Administrator(const std::string& theName, const std::string& theSsn,
                                double theSalary, std::string& theArea, std::string& theSuper,
                                std::string& theTitle);
	std::string getArea();
	std::string getSuper();
	std::string getTitle();
	void setArea(const std::string& theArea);
	void setSuper(const std::string& theSuper);
	void setTitle(const std::string& theTitle);
	void setInfo();
	void print();
	void printCheck();
	~Administrator();

private:
	std::string title;
	std::string area;
	std::string supervisor;
};

#endif

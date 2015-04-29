/********************************************************************* 
 * ** Program Filename: admin.cpp
 * ** Author: Megan Conley
 * ** Date: 2/15/2014
 * ** Description: Assignment 6.1
 * ** Input: User inputs values when prompted to set all Administrator 
 * object  variables.
 * ** Output: Prints values for all Administrator object variables and
 * contents of the printCheck() function.
 * *********************************************************************/ 

#include<iostream>
#include<string>
#include"administrator.cpp"

int main() {

	Administrator admin;

	admin.setInfo();

	admin.print();

	admin.printCheck();

	return 0;
}

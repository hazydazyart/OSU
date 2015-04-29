/********************************************************************* 
 * ** Program Filename: vector2d.cpp
 * ** Author: Megan Conley
 * ** Date: 2/1/2014
 * ** Description: Assignment 4, project 2
 * ** Input: n/a
 * ** Output: Dot product of a 2D vector
 * *********************************************************************/

#include<iostream>
#include<vector>
#include<iterator>

class Vector2D {
 
public:
 
/********************************************************************* 
 * ** Function: Vector2D constructors
 * ** Description: Initialize a Vector2D object with either user's input
 * ints or initializes them to 1 if none are given. The constructor
 * with one parameter is reserved for the dot product.
 * ** Parameters: 2 ints, 1 int, or none
 * ** Pre-Conditions: n/a
 * ** Post-Conditions: Vector2D object is initialized
 * *********************************************************************/ 

	Vector2D(int x_input, int y_input) {
		x = x_input;
		y = y_input;
	}
 
	Vector2D() {
		x = 1;
		y = 1;
	}

	Vector2D (int input) {
		x = input;
		y = 1;
	}
 
	~Vector2D() {}
 
/********************************************************************* 
 * ** Function: Vector2D accessors
 * ** Description: Accessor functions for the two private variables
 * in this class.
 * ** Parameters: None
 * ** Pre-Conditions: Vector2D object has been initialized
 * ** Post-Conditions: Returns int value for that object
 * *********************************************************************/ 

	int get_x() {
		return x;
	}
 
	int get_y() {
		return y;
	}
 
/********************************************************************* 
 * ** Function: Vector2D mutators
 * ** Description: Mutator functions for the class, allows change of
 * variable values
 * ** Parameters: 1 int
 * ** Pre-Conditions: Vector2D object has been initialized
 * ** Post-Conditions: Vector2D object value for private variables
 * is set to parameter value
 * *********************************************************************/ 

	void set_x(int input) {
		x = input;
	}
 
	void set_y(int input) {
		y = input;
	}

/********************************************************************* 
 * ** Function: operator *
 * ** Description: Overloads operator * to return the dot product of
 * two Vector2D objects
 * ** Parameters: Vector 2D object
 * ** Pre-Conditions: Two objects have been initialized
 * ** Post-Conditions: Returns an object whose x value is the
 * dot product.
 * *********************************************************************/ 

	const Vector2D operator*(const Vector2D& B) {
		return Vector2D((this->x * B.x) + (this->y * B.y));
	}
 
private:

	int x;
	int y;
 
};
 
int main() {
 
	Vector2D A(3, 4);
	Vector2D B(2, 5);
 
	std::cout << "Vector A(x = 3, y = 4), Vector B(x = 2, y = 5)" << std::endl;
	std::cout << "A * B = ";

	Vector2D C = A*B;

	std::cout << C.get_x() << std::endl;
 
 
	return 0;
 
}

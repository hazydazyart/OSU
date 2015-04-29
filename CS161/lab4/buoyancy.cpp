/******************************************************
 * ** Author: Megan Conley
 * ** Date: 10/14/2013
 * ** Description: Lab 4
 * ** Input: Weight and radius of a sphere
 * ** Output: Whether a sphere will float or not
 * ******************************************************/


#include <iostream>
#include <math.h> //pow, M_PI

//Defines the specific weight of water
#define WATER_WEIGHT 62.4;

using std::cout;
using std::cin;

int main() 
{
	//Variables needed to calculate buoyancy
	float radius, bforce, volume, weight;

	//Prompt user for weight and radius of sphere
	cout<< "Please enter the weight (lbs): ";
	cin>> weight;

	cout<< "Please enter the radius: ";
	cin>> radius;

	//Calculate the volume and buoyancy force
	volume = 4.0/3.0 * M_PI * pow(radius, 3);
	bforce = volume * WATER_WEIGHT;

	//Determine if the sphere will sink or float
	if (bforce >= weight) {
		cout<< "The sphere will float!\n";
	} else {
		cout<< "The sphere will sink!\n";
	}
	
	return 0;
}

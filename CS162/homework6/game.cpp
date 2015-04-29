/********************************************************************* 
 * ** Program Filename: game.cpp
 * ** Author: Megan Conley
 * ** Date: 2/15/2014
 * ** Description: Assignment 6.2
 * ** Input: none
 * ** Output: Values for object variables created from Creature.cpp
 * implementation file, and 5 calculations of the getDamage function
 * for each.
 * *********************************************************************/ 

#include"creature.cpp"
#include<iostream>
#include <time.h>
#include <stdlib.h>

int main() {

	srand(time(NULL)); // Initialize random seed for getDamage() function

	// Construct objects
	Human bob(10, 10);
	Elf bill(10, 15);
	Balrog joe(15, 8);
	Cyberdemon robo(25, 20);	

	// Initialize a damage variable for each object
	int damage;
	int damage2;
	int damage3;
	int damage4;


	// Prints object species, HP, and Str, then calculates damage 5 times
	// for each object

	std::cout << bob.getSpecies() << " attacks!" << std::endl;
	std::cout << "HP: " << bob.getHP() << " STR: " << bob.getStr() << std::endl;
	for(int i = 0; i < 5; i++) {
		damage = bob.getDamage();
	}

        std::cout << bill.getSpecies() << " attacks!" << std::endl;
        std::cout << "HP: " << bill.getHP() << " STR: " << bill.getStr() << std::endl;
        for(int i = 0; i < 5; i++) {
                damage2 = bill.getDamage();
        }

        std::cout << joe.getSpecies() << " attacks!" << std::endl;
        std::cout << "HP: " << joe.getHP() << " STR: " << joe.getStr() << std::endl;
        for(int i = 0; i < 5; i++) {
                damage3 = joe.getDamage();
        }

        std::cout << robo.getSpecies() << " attacks!" << std::endl;
        std::cout << "HP: " << robo.getHP() << " STR: " << robo.getStr() << std::endl;
        for(int i = 0; i < 5; i++) {
                damage4 = robo.getDamage();
        }


	return 0;
}

/********************************************************************* 
 * ** Program Filename: creature.cpp
 * ** Author: Megan Conley
 * ** Date: 2/15/2014
 * ** Description: Implementation for creature.h
 * ** Input: n/a
 * ** Output: n/a
 * *********************************************************************/ 

#include<string>
#include<stdlib.h>
#include<iostream>
#include"creature.h"

/********************************************************************* 
 * ** Function: Creature constructor
 * ** Description: Default constructor for Creature class; will not
 * actually be used.
 * ** Parameters: n/a
 * ** Pre-Conditions: n/a
 * ** Post-Conditions: Constructs a Creature object
 * *********************************************************************/ 

Creature::Creature() {
        this->str = 1;
        this->hp = 1;
}

/*********************************************************************
 * ** Function: Creature constructor
 * ** Description: Constructor
 * ** Parameters: two ints
 * ** Pre-Conditions: n/a
 * ** Post-Conditions: Constructs a Creature object
 * *********************************************************************/

Creature::Creature(int itsHp, int itsStr) {
	this->hp = itsHp;
	this->str = itsStr;
}
/*
********************************************************************* 
 * ** Function: getSpecies()
 * ** Description: Returns an error message, as this class will not
 * be used to create objects
 * ** Parameters: none
 * ** Pre-Conditions: An object has been initialized
 * ** Post-Conditions: Returns string
 * *********************************************************************

std::string Creature::getSpecies() {
        return "Species not set";
}
*/
/********************************************************************* 
 * ** Function: getDamage()
 * ** Description: Calculates damage between 1 and objects str value
 * ** Parameters: none
 * ** Pre-Conditions: Object exists and has str => 1
 * ** Post-Conditions: Returns random int
 * *********************************************************************/ 

int Creature::getDamage() {
        int damage = (rand() % str) + 1;
        return damage;
}

/********************************************************************* 
 * ** Function: setHP
 * ** Description: Allows protected HP variable to be changed
 * ** Parameters: Int
 * ** Pre-Conditions: Object exists 
 * ** Post-Conditions: Object's HP value set to parameter
 * *********************************************************************/ 

void Creature::setHP(int itsHP) {
	hp = itsHP;
}

/********************************************************************* 
 * ** Function: getHP
 * ** Description: Returns HP value for object
 * ** Parameters: none
 * ** Pre-Conditions: Object exists
 * ** Post-Conditions: Returns HP as int
 * *********************************************************************/ 

int Creature::getHP() {
	return hp;
}

/********************************************************************* 
 * ** Function: setStr
 * ** Description: Allows protected Str variable to be changed
 * ** Parameters: Int
 * ** Pre-Conditions: Object exists 
 * ** Post-Conditions: Object's Str variable set to parameter
 * *********************************************************************/ 

void Creature::setStr(int itsStr) {
	str = itsStr;
}

/********************************************************************* 
 * ** Function: getStr
 * ** Description: Accessor function for protected Str variable
 * ** Parameters: none
 * ** Pre-Conditions: Object exists
 * ** Post-Conditions: Returns Str value as int
 * *********************************************************************/ 

int Creature::getStr() {
	return str;
}

// Creature class destructor
Creature::~Creature() {}

/*********************************************************************
 * ** Function: Human constructor
 * ** Description: Default constructor
 * ** Parameters: none
 * ** Pre-Conditions: n/a
 * ** Post-Conditions: Human object created with default values
 * *********************************************************************/

Human::Human() {
	this->hp = 1;
	this->str = 1;
}

/********************************************************************* 
 * ** Function: Human constructor
 * ** Description: Constructs a Human class object
 * ** Parameters: two ints
 * ** Pre-Conditions: n/a
 * ** Post-Conditions: Human object created with HP and STR set by parameters.
 * *********************************************************************/ 

Human::Human(int itsHp, int itsStr) {
	this->hp = itsHp;
	this->str = itsStr;
}

/********************************************************************* 
 * ** Function: getSpecies
 * ** Description: getSpecies override for Human class
 * ** Parameters: none
 * ** Pre-Conditions: Human object exists
 * ** Post-Conditions: returns "Human"
 * *********************************************************************/ 

std::string Human::getSpecies() {
	return "Human";
}

int Human::getDamage() {
	int damage = Creature::getDamage();
        std::cout << getSpecies() << " attacks for " <<
                damage << " points!" << std::endl;
	return damage;
}

// Human deconstructor
Human::~Human() {}

/********************************************************************* 
 * ** Function: Elf default constructor
 * ** Description: Creates an Elf class object with default values
 * ** Parameters: none
 * ** Pre-Conditions: n/a 
 * ** Post-Conditions: Creates Elf object with type set to "Elf" and
 * HP and STR set to 1.
 * *********************************************************************/ 

Elf::Elf() {
       	this->hp = 1;
	this->str = 1;
}

/********************************************************************* 
 * ** Function: Elf constructor
 * ** Description: Creates Elf class object
 * ** Parameters: two ints
 * ** Pre-Conditions: n/a
 * ** Post-Conditions: Creates Elf class object with HP and STR to the parameters.
 * *********************************************************************/ 

Elf::Elf(int itsHp, int itsStr) {
	this->hp = itsHp;
	this->str = itsStr;
}

/********************************************************************* 
 * ** Function: getSpecies
 * ** Description: getSpecies override for Elf class
 * ** Parameters: none
 * ** Pre-Conditions: Elf object exists
 * ** Post-Conditions: returns "Elf"
 * *********************************************************************/ 

std::string Elf::getSpecies() {
	return "Elf";
}

// Elf deconstructor
Elf::~Elf() {}

/********************************************************************* 
 * ** Function: getDamage()
 * ** Description: Override of parent class getDamage function
 * ** Parameters: none
 * ** Pre-Conditions: Elf object exists
 * ** Post-Conditions: Returns results of parent class getDamage() plus
 * Elf class bonus damage (10% of double attack)
 * *********************************************************************/
 
int Elf::getDamage() {
	int damage = Creature::getDamage();
        std::cout << getSpecies() << " attacks for " <<
                damage << " points!" << std::endl;
        if (rand() % 10 == 0) {
                std::cout << "Magical attack inflicts " << damage <<
                " additional damage points!" << std::endl;
                damage = damage * 2;
        }
        return damage;
}

/********************************************************************* 
 * ** Function: Demon constructor
 * ** Description: Creates Demon object by calling parent constructor;
 * will not be used, because it exists to pass functions to child classes
 * only
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: Creates Demon class object
 * *********************************************************************/ 

Demon::Demon() {
	this->hp = 1;
	this->str = 1;
}

// Demon deconstructor
Demon::~Demon() {}

/********************************************************************* 
 * ** Function: getDamage()
 * ** Description: Demon class override for getDamage()
 * ** Parameters: none
 * ** Pre-Conditions: Demon class (or child of Demon class) object exists
 * ** Post-Conditions: Returns parent class damage plus less than 5% chance
 * for 50 extra.
 * *********************************************************************/ 

int Demon::getDamage() {
	int damage;
        if ((rand() % 100) < 5) {
                damage = 50;
                std::cout << "Demonic attack inflicts 50 additional "
                << " damage points!" << std::endl;
        }
	return damage;
}

/********************************************************************* 
 * ** Function: Balrog constructor
 * ** Description: Default constructor for Balrog class
 * ** Parameters: none
 * ** Pre-Conditions: n/a
 * ** Post-Conditions: Creates Balrog class object with default values
 * *********************************************************************/ 

Balrog::Balrog() {
        this->hp = 1;
	this->str = 1;
}

/********************************************************************* 
 * ** Function: Balrog constructor
 * ** Description: Constructs Balrog class object
 * ** Parameters: two ints
 * ** Pre-Conditions: n/a
 * ** Post-Conditions: Creates Balrog class object with HP and STR set to parameters
 * *********************************************************************/ 

Balrog::Balrog(int itsHp, int itsStr) {
        this->hp = itsHp;
	this->str = itsStr;
}

/********************************************************************* 
 * ** Function: getSpecies
 * ** Description: getSpecies override for Balrog class
 * ** Parameters: none
 * ** Pre-Conditions: Balrog object exists
 * ** Post-Conditions: returns "Balrog"
 * *********************************************************************/ 

std::string Balrog::getSpecies() {
	return "Balrog";
}

// Balrog Constructor
Balrog::~Balrog() {}

/********************************************************************* 
 * ** Function: getDamage()
 * ** Description: Balrog class getDamage override
 * ** Parameters: none
 * ** Pre-Conditions: Balrog class object exists
 * ** Post-Conditions: Calls both parent and base class getDamage functions
 * to make class bonus of double damage.
 * *********************************************************************/ 

int Balrog::getDamage() {
	int damage = Creature::getDamage();
	int damage2 = Creature::getDamage();
        std::cout << getSpecies() << " attacks for " <<
                damage << " points!" << std::endl;
        std::cout << "Balrog speed attack inflicts " << damage2 <<
        " additional damage points!" << std::endl;
	int damage3 = Demon::getDamage();
	return damage+damage2+damage3;
}

/********************************************************************* 
 * ** Function: Cyberdemon constructor
 * ** Description: Cyberdemon default constructor
 * ** Parameters: none
 * ** Pre-Conditions: n/a
 * ** Post-Conditions: Creates Cyberdemon object with default values
 * *********************************************************************/ 

Cyberdemon::Cyberdemon() {
	this->hp = 1;
	this->str = 1;
}

/********************************************************************* 
 * ** Function: Cyberdemon constructor
 * ** Description: Cyberdemon constructor
 * ** Parameters: two ints
 * ** Pre-Conditions: none
 * ** Post-Conditions: Creates Cyberdemon object with type set to default
 * and HP and STR set to parameters
 * *********************************************************************/ 

Cyberdemon::Cyberdemon(int itsHp, int itsStr) {
	this->hp = itsHp;
	this->str = itsStr;
}

/********************************************************************* 
 * ** Function: getSpeceies()
 * ** Description: getSpecies override for Cyberdemon class
 * ** Parameters: none
 * ** Pre-Conditions: Cyberdemon object exists
 * ** Post-Conditions: returns "Cyberdemon"
 * *********************************************************************/ 

std::string Cyberdemon::getSpecies() {
	return "Cyberdemon";
}

/********************************************************************* 
 * ** Function: getDamage()
 * ** Description: Cyberdemon class override of getDamage
 * ** Parameters: none
 * ** Pre-Conditions: Cyberdemon object exists
 * ** Post-Conditions: Returns base class damage plus parent class damage
 * *********************************************************************/ 

int Cyberdemon::getDamage() {
	int damage = Creature::getDamage();
        std::cout << getSpecies() << " attacks for " <<
                damage << " points!" << std::endl;
	int damage2 = Demon::getDamage();
	return damage+damage2;
}

//Cyberdemon deconstructor
Cyberdemon::~Cyberdemon() {}


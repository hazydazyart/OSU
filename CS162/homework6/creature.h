/********************************************************************* 
 * ** Program Filename: creature.h
 * ** Author: Megan Conley
 * ** Date: 2/15/2014
 * ** Description: Header file for Creature.cpp
 * ** Input: n/a
 * ** Output: n/a
 * *********************************************************************/ 


#ifndef CREATURE_H
#define CREATURE_H

#include<string>

class Creature {

public:
	Creature();
	Creature(int itsHp, int itsStr);
	~Creature();
	int getDamage();
	int getStr();
	int getHP();
	std::string getSpecies();
	void setHP(int itsHP);
	void setStr(int itsStr);

protected:

	int hp;
	int str;
};

class Human : public Creature {

public:
        Human();
        Human(int itsHp, int itsStr);
	int getDamage();
	std::string getSpecies();
        ~Human();
};

class Elf : public Creature {

public:
        Elf();
        Elf(int itsHp, int itsStr);
	std::string getSpecies();
        ~Elf();
        int getDamage();
};

class Demon : public Creature {

public:
        Demon();
        ~Demon();
        int getDamage();
};

class Balrog : public Demon {

public:
        Balrog();
        Balrog(int itsHp, int itsStr);
	std::string getSpecies();
        ~Balrog();
        int getDamage();
};

class Cyberdemon : public Demon {

public:
        Cyberdemon();
        Cyberdemon(int itsHp, int itsStr);
	std::string getSpecies();
	int getDamage();
        ~Cyberdemon();
};

#endif

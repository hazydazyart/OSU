#ifndef ELF_H
#define ELF_H

#include<string>
#include<stdlib.h>
#include"creature.cpp"

class Elf : public Creature {

public:
	Elf();
	Elf(int itsHp, int itsStr);
	~Elf();
	int getDamage();
};

#endif

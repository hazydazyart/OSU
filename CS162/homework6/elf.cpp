
#include<string>
#include<stdlib.h>
#include<iostream>
#include"elf.h"

Elf::Elf() {
	type = "Elf";
	hp = 1;
	str = 1;
}

Elf::Elf(int itsHp, int itsStr) {
	type = "Elf";
	hp = itsHp;
	str = itsStr;
}

Elf::~Elf() {}

int getDamage() {
	damage = Creature::getDamage();
	if (rand() % 10 == 0) {
		std::cout << "Magical attack inflicts " << damage <<
		" additional damage points!" << std::endl;
		damage = damage * 2;
	}
	return damage;
}

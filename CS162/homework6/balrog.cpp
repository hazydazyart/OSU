
#include<iostream>
#include<string>
#include"balrog.h"

Balrog::Balrog() {
	type = "Balrog";
	hp = 1;
	str = 1;
}

Balrog::Balrog(int itsHp, int itsStr) {
	type = "Balrog";
	hp = itsHp;
	str = itsStr;
}

Balrog::~Balrog() {}

int getDamage() {
	int damage = Demon::getDamage();
	int damage2 = Creature::getDamage();
	std::cout << "Balrog speed attack inflicts " << damage2 <<
	" additional damage points!" << std::endl;
	damage += damage2;
	return damage;
}

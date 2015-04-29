
#include<string>
#include<stdlib.h>
#include"demon.h"

Demon::Demon() {
	type = "Demon";
	hp = 1;
	str = 1;
}

Demon::~Demon() {}

int getDamage() {
	int damage = Creature::getDamage();
	if ((rand() % 100) < 5) {
		damage += 50;
		std::cout << "Demonic attack inflicts 50 additional "
		<< " damage points!" << std::endl;
	}
}


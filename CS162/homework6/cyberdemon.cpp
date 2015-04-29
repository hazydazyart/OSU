
#include<string>
#include"cyberdemon.h"

Cyberdemon::Cyberdemon() {
	type = "Cyberdemon";
	hp = 1;
	str = 1;
}

Cyberdemon::Cyberdemon(int itsHp, int itsStr) {
	type = "Cyberdemon";
	hp = itsHp;
	str = itsStr;
}

Cyberdemon::~Cyberdemon() {}


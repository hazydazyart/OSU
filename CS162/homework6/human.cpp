
#include<string>
#include"human.h"

Human::Human() {
	type = "Human";
	hp = 1;
	str = 1;
}

Human::Human(int itsHp, int itsStr) {
	type = "Human";
	hp = itsHp;
	str = itsStr;
}

Human::~Human() {}



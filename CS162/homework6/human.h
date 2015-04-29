
#ifndef HUMAN_H
#define HUMAN_H

#include<string>
#include"creature.cpp"

class Human : public Creature {

public:
	Human();
	Human(int itsHp, int itsStr);
	~Human();
};

#endif

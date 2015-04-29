
#include<string>
#include"demon.cpp"

class Balrog : public Demon {

public:
	Balrog();
	Balrog(int itsHp, int itsStr);
	~Balrog();
	int getDamage();
};

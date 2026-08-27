#pragma once
#include "Enemy.h"
class Boss : public Enemy
{
public:
	//Constructor
	Boss(std::string name, int hp, int attack);
	//Destructor
	~Boss();
	//Getter
	int getHP();
	int getATK();
	//Setter
	void setHP(int newHP);
	void setATK(int newATK);

	void ObobjibName();
	void BobmijName();
	void JimbobName();
};

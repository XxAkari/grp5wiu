#pragma once
#include "Enemy.h"
class Boss : public Enemy
{
	//Constructor
	Boss();

	//Destructor
	~Boss();

	//Getter
	int getHP();
	int getATK();

	//Setter
	void setHP(int newHP);
	void setATK(int newATK);

public:
	



};

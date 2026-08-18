#pragma once
#include "Character.h"
class Enemy : public Character
{
	int hp;
	int attack;


public:
	//Constructor
	Enemy();

	//Destructor 
	~Enemy();

	//getter
	int getHP();
	int getATK();

	//setter
	void setHP(int newHP);
	void setATK(int newAttack);

};


#pragma once
#include <string>
#include "Character.h"

class Enemy : public Character {
public:

	//constructor
	Enemy(std::string name, int hp, int attack);

	//attack function
	void atk(Character& target);

	//enemy names
	void BombjiName();
	void BomjibName();
	void MobijName();

	void printEnemyName();
};

#pragma once
#include <string>
#include "Character.h"
class Enemy : public Character {
public:
	Enemy(std::string name, int hp, int maxHp, int attack);
	Enemy(std::string name, int hp, int attack);            

	void atk(Character& target);
};
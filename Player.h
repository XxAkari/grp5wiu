#pragma once
#include "Character.h"

class Player : public Character {
public:
	std::string name;
	int hp;
	int atk;

	Player(std::string name, int hp, int attack);
};
 
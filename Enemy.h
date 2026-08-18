#pragma once
#include <string>
#include "Character.h"

class Enemy : public Character {
public:
	Enemy(std::string name, int hp, int attack);
};

class Boss : public Enemy {
public:
	Boss(std::string name, int hp, int attack);
};
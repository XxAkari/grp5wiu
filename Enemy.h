#pragma once
#include <string>
#include "Character.h"

class Enemy : public Character {
public:
	Enemy(std::string name, int hp, int atk);
};

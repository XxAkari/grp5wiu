#pragma once
#include "Character.h"

// TEMPORARY placeholder Enemy class, just so combat can be tested with
class Enemy : public Character {
public:
	Enemy(std::string name, int hp, int attack);

	// makes this enemy hit target for its own attack stat
	void attack(Character& target);
};

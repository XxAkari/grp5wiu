#pragma once
#include "Character.h"

class Player : public Character {
public:
	Player(std::string name, int hp, int attack);
};

class Fairy : public Player {
public:
	Fairy(std::string name);
};

class Witch : public Player {
public:
	Witch(std::string name);
};

class Assassin : public Player {
public:
	Assassin(std::string name);
};

#pragma once
#include <string>

class Character {
public:
	Character() = default;
	Character(std::string name, int hp, int attack);

	bool isAlive();
	void takeDamage(int amount);
	int getAttack();
	std::string getName();
	int getHp();
	int getMaxHp();
	void setHp();
	void setAttack();

protected:
	std::string name;
	int hp;
	int maxHp;
	int attack;
};
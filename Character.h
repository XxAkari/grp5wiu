#pragma once
#include <string>

class Character {
public:
	Character();

	Character(std::string name, int hp, int attack);

	bool isAlive();
	void takeDamage(int amount);
	int getAttack();
	std::string getName();
	int getHp();
	int getMaxHp();

	void setAttack(int atk);
	void setHeaalth(int health);
	void setMaxHP(int maxHP);

	void addHp(int hp);
	void addMaxHP(int hp);
	void addAttack(int atk);

private:
	std::string name;
	int hp;
	int maxHp;
	int atk;
};

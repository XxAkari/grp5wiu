#pragma once
#include <string>

class Character {
public:
	Character();
	Character(std::string name, int hp, int maxhp, int attack);

	bool isAlive();
	void takeDamage(int amount);
	int getAttack();
	std::string getName();
	int getHp();
	int getMaxHp();

	void setAttack(int atk);
	void setHealth(int health);
	void setMaxHP(int maxHP);

	void addAttack(int atk);
	void addHp(int hp);
	void addMaxHP(int hp);

private:
	std::string name;
	int hp;
	int maxHp;
	int attack;
};

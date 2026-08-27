#include "Boss.h"
#include <iostream>

Boss::Boss(std::string name, int hp, int attack)
	: Enemy(name, hp, attack) {
}

Boss::~Boss() {
}

int Boss::getHP() {
	return getHp(); // reuses Character's existing getHp()
}

int Boss::getATK() {
	return getAttack(); // reuses Character's existing getAttack()
}

void Boss::setHP(int newHP) {
	int diff = newHP - getHp();
	takeDamage(-diff);
}

void Boss::setATK(int newATK) {
}


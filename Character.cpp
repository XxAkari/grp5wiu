#include "Character.h"

Character::Character() {}

Character::Character(std::string name, int hp, int attack)
	: name(name), hp(hp), maxHp(hp), attack(attack) {
};

bool Character::isAlive() {
	return hp > 0;
}

void Character::takeDamage(int amount) {
	hp -= amount;
	if (hp < 0) hp = 0;
}

int Character::getAttack() {
	return attack;
}

std::string Character::getName() {
	return name;
}

int Character::getHp() {
	return hp;
}

int Character::getMaxHp() {
	return maxHp;
}

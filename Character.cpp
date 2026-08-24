#include "Character.h"

Character::Character() {}

Character::Character(std::string name, int hp, int maxhp, int attack)
	: name(name), hp(hp), maxHp(hp), attack(attack) {
};

bool Character::isAlive() {
	return hp > 0;
}

void Character::setAttack(int atk) {
	attack = atk;
}

void Character::setHealth(int health) {
	hp = health;
}

void Character::setMaxHP(int maxHP) {
	maxHp = maxHP;
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

void Character::addHp(int hp) {
	this->hp += hp;
}

void Character::addMaxHP(int hp) {
	maxHp += hp;
}

void Character::addAttack(int atk) {
	attack += atk;
}

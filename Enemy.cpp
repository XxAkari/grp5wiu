#include "Enemy.h"

Enemy::Enemy(std::string name, int hp, int maxHp, int attack)
	: Character(name, hp, maxHp, attack) {
}

Enemy::Enemy(std::string name, int hp, int attack)
	: Character(name, hp, attack) {
}

void Enemy::atk(Character& target) {
	target.takeDamage(getAttack());
}
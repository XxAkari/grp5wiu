#include "Enemy.h"

Enemy::Enemy(std::string name, int hp, int attack)
	: Character(name, hp, attack) {
}

void Enemy::attack(Character& target) {
	target.takeDamage(getAttack());
}

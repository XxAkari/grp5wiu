#include "Enemy.h"
#include <iostream>

Enemy::Enemy(std::string name, int hp, int attack)
    : Character(name, hp, attack) {
}

void Enemy::atk(Character& target) {
    target.takeDamage(getAttack());
}

// will be printed when we fave the enemies (to show who we're fighting
void Enemy::BombjiName() {
	std::cout << R"(
||||. .||||. |\    /| ||||.   ||| |||||
|   | |    | | \  / | |   |     |   |  
|   | |    | |  \/  | |   |     |   |  
||||. |    | |      | ||||.     |   |  
|   | |    | |      | |   | \   |   |  
|   | |    | |      | |   |  \  |   |  
||||. .||||. |      | ||||.   \\/ |||||)" << std::endl;
	};

void Enemy::BomjibName() {
	std::cout << R"(
||||. .||||. |\    /|    ||| ||||| ||||. 
|   | |    | | \  / |     |   |    |   |
|   | |    | |  \/  |     |   |    |   |
||||. |    | |      |     |   |    ||||.
|   | |    | |      | \   |   |    |   |
|   | |    | |      |  \  |   |    |   |
||||. .||||. |      |   \\/  ||||| ||||.)" << std::endl;
};

void Enemy::MobijName() {
	std::cout << R"(
|\    /| .||||. ||||.  |||||    |||
| \  / | |    | |   |    |       |
|  \/  | |    | |   |    |       |
|      | |    | ||||.    |       |
|      | |    | |   |    |   \   |
|      | |    | |   |    |    \  |
|      | .||||. ||||.  |||||   \\/)" << std::endl;
};
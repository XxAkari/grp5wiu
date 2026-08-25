#include "Enemy.h"
#include <iostream>

Enemy::Enemy(std::string name, int hp, int attack)
	: Character(name, hp, attack) {}

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

void Enemy::ObobjibName() {
    std::cout << R"(
.||||. ||||. .||||. ||||.    ||| ||||| ||||. 
|    | |   | |    | |   |     |    |   |   |
|    | |   | |    | |   |     |    |   |   |
|    | ||||. |    | ||||.     |    |   ||||.
|    | |   | |    | |   | \   |    |   |   |
|    | |   | |    | |   |  \  |    |   |   |
.||||. ||||. .||||. ||||.   \\/  ||||| ||||.)" << std::endl;
};

void Enemy::BobmijName() {
    std::cout << R"(
||||. .||||. ||||. |\    /| |||||    |||
|   | |    | |   | | \  / |   |       |
|   | |    | |   | |  \/  |   |       |
||||. |    | ||||. |      |   |       |
|   | |    | |   | |      |   |   \   |
|   | |    | |   | |      |   |    \  |
||||. .||||. ||||. |      | |||||   \\/)" << std::endl;
};

void Enemy::JimbobName() {
    std::cout << R"(
   ||| ||||| |\    /| ||||. .||||. ||||. 
    |    |   | \  / | |   | |    | |   |
    |    |   |  \/  | |   | |    | |   |
    |    |   |      | ||||. |    | ||||.
\   |    |   |      | |   | |    | |   |
 \  |    |   |      | |   | |    | |   |
  \\/  ||||| |      | ||||. .||||. ||||.)" << std::endl;
};

void Enemy::printEnemyName()
{
    if (getName() == "Bombji")
    {
        BombjiName();
    }
    else if (getName() == "Bomjib")
    {
        BomjibName();
    }
    else if (getName() == "Mobij")
    {
        MobijName();
    }

    else if (getName() == "Obobjib")
    {
        ObobjibName();
    }
    else if (getName() == "Bobmij")
    {
        BobmijName();
    }
    else if (getName() == "Jimbob")
    {
        JimbobName();
    }
    else
    {
        std::cout << getName() << std::endl;
    }
};

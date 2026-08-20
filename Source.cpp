#include <iostream>
#include <conio.h>
#include <vector>
#include "World.h"
#include "Character.h"
#include "Enemy.h"
#include "Dialogue.h"
#include "Combat.h"

int main() {
	srand(static_cast<unsigned int>(time(0)));

	Dialogue d;
	std::cout << "The Jimbob Paradox" << std::endl;
	World world;
	std::cout << "After stealing a sandwich from your roommate, you fall through a portal and arrive in a new world. You're confused, stuck in a new place with no clear way out." << std::endl;
	std::string name = world.namingUI(); // you could probably replace std::string name here with the name var saved in player class
	bool isActive = false;
	std::string plyClass = world.playerClassUI();
	int hp = 0, attack = 0;
	if (plyClass != "null") {
		isActive = true;
		if (plyClass == "Fairy") {
			hp = 100; // mockup values, change later	
			attack = 5;
		}
		else if (plyClass == "Witch") {
			hp = 25, attack = 10;
		}
		else if (plyClass == "Assassin") {
			hp = 67, attack = 20;
		}
	}

	Character player1(name, hp, attack); // just change player1 if you dont like its name
	// remind me to change this to Player player1 later when player class is added
	Character* playerPtr = &player1;

	std::vector<Enemy> enemies = {
		Enemy("Enemy", 10, 1),
		Enemy("Enemy", 15, 3),
		Enemy("Boss", 25, 5)
	};

	bool inCombat = false;
	char keyPressed;
	// homescreen
	while (isActive) {
		system("cls");
		Enemy& currentEnemy = enemies[world.getCurrentLevel()];

		if (inCombat) {
			world.printCombatUI(player1.getName(), player1.getHp(), player1.getAttack(), currentEnemy.getHp(), currentEnemy.getAttack(), world.getCredits()); // same with this
			keyPressed = _getch();
			if (keyPressed == 'x')
			{
				currentEnemy.takeDamage(player1.getAttack());
			}

			// enemy attacks back, but only if it's still alive
			if (currentEnemy.isAlive()) currentEnemy.attack(player1);

			if (player1.getHp() <= 0) {
				system("cls");
				std::cout << "You were defeated..." << std::endl;
				isActive = false;
			}
			else if (currentEnemy.getHp() <= 0) {
				system("cls");
				world.printCombatUI(player1.getName(), player1.getHp(), player1.getAttack(), currentEnemy.getHp(), currentEnemy.getAttack(), world.getCredits()); // same with this
				std::cout << "You killed " << currentEnemy.getName() << "!" << std::endl;
				world.earnCredits(currentEnemy.getName());
				std::cout << "Press [E] to continue" << std::endl;
				keyPressed = _getch();
				if (keyPressed == 'e') {
					int nextLevel = world.changeLevel();
					if (nextLevel >= (int)enemies.size()) {
						system("cls");
						std::cout << "You defeated every enemy! You win!" << std::endl;
						isActive = false;
					}
					else {
						inCombat = false;
					}
				}
			}

		}


		else {
			d.printDialogue(world.getCurrentLevel(), playerPtr->getName());
			std::cout << "Press any key to continue..." << std::endl;
			keyPressed = _getch();
			inCombat = true;
		}

		//logic: kill enemy
		// enemy.getName(); after death to find out what type it is
		// then i throw it into earnCredits()
		// ????????????
	};

	return 0;
}

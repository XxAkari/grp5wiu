#include <iostream>
#include <conio.h>
#include "World.h"
#include "Character.h"
#include "Enemy.h"
#include "Dialogue.h"

int main() {
	srand(static_cast<unsigned int>(time(0)));
	Dialogue d;
	World world;
	std::cout << "The Jimbob Paradox" << std::endl;
	std::cout << "After stealing a sandwich from your roommate, you fall through a portal and arrive in a new world." << std::endl;
	std::cout << "You're confused, stuck in a new place with no clear way out." << std::endl;
	std::string name = world.namingUI(); // you could probably replace std::string name here with the name var saved in player class
	int hp = 0, attack = 0, maxHP = 0;
	Character player1(name, hp, maxHP, attack); // just change player1 if you dont like its name
	// remind me to change this to Player player1 later when player class is added
	Character* playerPtr = &player1;
	world.playerClassUI(playerPtr);

	Character enemy1("Enemy", 10, 10, 1);
	bool isActive = true;
	bool inCombat = false;
	bool enemyIsAlive = false;
	bool inShop = false;
	char keyPressed = _getch();
	// homescreen
	while (isActive) {
		while (inCombat) {
			system("cls");
			if (player1.getHp() <= 0) {
				world.printDeathScreen();
				isActive = false;
				inCombat = false;
			}
			else if (enemyIsAlive) {
				world.printCombatUI(player1, enemy1); // same with this
				keyPressed = _getch();
				if (keyPressed == 'x') {
					enemy1.takeDamage(2);
					if (enemy1.getHp() <= 0) enemyIsAlive = false;
				}
			}
			else {
				if (!inShop) {
					while (keyPressed != 'e') {
						system("cls");
						std::cout << "You killed an enemy!" << std::endl;
						std::cout << "Press [E] to continue" << std::endl;
						keyPressed = _getch();
					}
					inShop = true;
					world.earnCredits(enemy1.getName());
					bool a = false;
					while (inShop) {
						while (!a) {
							system("cls");
							world.printShopUI(playerPtr);
							std::cout << "Press [E] to confirm / any other key to return." << std::endl;
							keyPressed = _getch();
							a = (keyPressed == 'e');
						}
						if (keyPressed == 'e') {
							keyPressed = d.printEndDialogue(world.getCurrentLevel(), player1.getName());
							while (keyPressed != 'e') keyPressed = d.printEndDialogue(world.getCurrentLevel(), player1.getName());
							inShop = false;
							inCombat = false;
							world.changeLevel();
						}
					}
				}
			}
		}

		if (world.getCurrentLevel() <= 8) {
			keyPressed = d.printDialogue(world.getCurrentLevel(), player1.getName());
			if (keyPressed == 'e') inCombat = true,enemyIsAlive = true;
			else if (keyPressed == '8') world.cheatCode(playerPtr);
		}
		else {
			world.printWinScreen();
			isActive = false;
		}
	};

	return 0;
}

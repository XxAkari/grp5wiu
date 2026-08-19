#include <iostream>
#include <conio.h>
#include "World.h"
#include "Character.h"
#include "Enemy.h"
#include "Dialogue.h"

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

	Character enemy1("Enemy", 10, 1);

	bool inCombat = false;
	char keyPressed = _getch();
	// homescreen
	while (isActive) {
		system("cls");
		if (inCombat) {
			world.printCombatUI(player1.getName(), player1.getHp(), player1.getAttack(), enemy1.getHp(), enemy1.getAttack(), world.getCredits()); // same with this
			keyPressed = _getch();
			if (keyPressed == 'x') enemy1.takeDamage(2);
			if (enemy1.getHp() <= 0) {
				system("cls");
				world.printCombatUI(player1.getName(), player1.getHp(), player1.getAttack(), enemy1.getHp(), enemy1.getAttack(), world.getCredits()); // same with this
				std::cout << "You killed " << enemy1.getName() << "!" << std::endl;
				std::cout << "Press [E] to continue" << std::endl;
				keyPressed = _getch();
				if (keyPressed == 'e') inCombat = false;
			}

		}
	

		else {
			world.earnCredits(enemy1.getName());
			d.loadDialogue(playerPtr->getName());
			d.printDialogue();
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

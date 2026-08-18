#include <iostream>
#include <conio.h>
#include "World.h"
#include "Character.h"
#include "Enemy.h"

int main() {
	srand(static_cast<unsigned int>(time(0)));

	std::cout << "The Jimbob Paradox" << std::endl;
	World world;
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
	system("cls");

	Character player1(name, hp, attack); // just change player1 if you dont like its name
										// remind me to change this to Player player1 later when player class is added
					
	Character enemy1("Enemy", 10, 1);
	// homescreen
	while (isActive) {
		world.printCombatUI(player1.getName(), player1.getHp(), player1.getAttack(), enemy1.getHp(), 1, world.getCredits()); // same with this
		char keyPressed = _getch();
		system("cls");

		if (keyPressed == 'x') enemy1.takeDamage(20);
		if (enemy1.getHp() <= 0) world.earnCredits(enemy1.getName());

		//logic: kill enemy
		// enemy.getName(); after death to find out what type it is
		// then i throw it into earnCredits()
		// ????????????
	};

	return 0;
}
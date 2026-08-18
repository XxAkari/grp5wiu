#include <iostream>
#include <conio.h>
#include "World.h"
#include "Character.h"

int main() {
	std::cout << "The Jimbob Paradox" << std::endl;
	World world;
	std::string name = world.namingUI(); // you could probably replace std::string name here with the name var saved in player class
	bool isActive = false;
	std::string plyClass = world.playerClassUI();
	std::cout << plyClass << std::endl;
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
			hp = 50, attack = 20;
		}
	}
	// system("cls");

	Character player1(name, hp, attack); // just change player1 if you dont like its name

	// homescreen
	while (isActive) {
		world.printCombatUI(player1.getName(), player1.getHp(), player1.getAttack(), 1, 1); // same with this
		char keyPressed = _getch();
		system("cls");
	};

	return 0;
}
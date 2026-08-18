#include <iostream>
#include <conio.h>
#include "World.h"

int main() {
	std::cout << "The Jimbob Paradox" << std::endl;
	World world;
	std::string name = world.namingUI(); // you could probably replace std::string name here with the name var saved in player class
	bool isActive = false;
	if (world.playerClassUI() != "null") isActive = true;
	system("cls");

	// homescreen
	while (isActive) {
		world.printCombatUI(name); // same with this
		char keyPressed = _getch();
		system("cls");
	};

	return 0;
}
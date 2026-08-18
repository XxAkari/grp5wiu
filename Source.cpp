#include <iostream>
#include <conio.h>
#include "World.h"

int main() {
	std::cout << "The Jimbob Paradox" << std::endl;
	World world;
	world.namingUI();
	bool isActive = false;
	if (world.playerClassUI() != "null") isActive = true;

	// homescreen
	while (isActive) {
		world.printCombatUI();
		char keyPressed = _getch();
		system("cls");
	};

	return 0;
}
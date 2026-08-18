#include "World.h"
#include <iostream>	
#include <conio.h>

World::World() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			grid[i][j] = '.';
		}
	}
};

std::string World::namingUI() {
	std::cout << "Name Your Character: ";
	std::string playerName;
	std::cin >> playerName;
	std::cout << "hello " << playerName << std::endl;
	return playerName;
}

std::string World::playerClassUI() {
	std::cout << "1: Fairy -- Low Attack, High HP" << std::endl;
	std::cout << "2: Witch -- Medium Attack, Low HP" << std::endl;
	std::cout << "3: Assassin -- High Attack, Medium HP" << std::endl;
	std::cout << "Choose A Class: ";
	char keypressed;
	std::cin >> keypressed;
	std::string chosenClass = "null";
	switch (keypressed) {
	case '1':
		chosenClass = "Fairy";
		break;
	case '2':
		chosenClass = "Witch";
		break;
	case '3':
		chosenClass = "Assassin";
		break;
	default:
		std::cout << "Invalid Class!" << std::endl;
	}
	std::cout << "You chose " << chosenClass << "!" << std::endl;
	return chosenClass;
}

void World::printCombatUI(std::string playerName, int pHp, int pAtk, int eHp, int eAtk){
	std::cout << "The Jimbob Paradox" << std::endl;
	std::cout << playerName << " Health: " << pHp << std::endl;
	std::cout << "Attack: " << pAtk << std::endl;
	std::cout << std::endl;
	std::cout <<"Enemy Health: " << eHp << std::endl; 
	std::cout << "Attack: " << eAtk << std::endl;

	grid[6][7] = 'x'; // dw about this im just test running
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			std::cout << grid[i][j] << ' ';
		}
		std::cout << std::endl;
	}

}
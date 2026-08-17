#include "World.h"
#include "Character.h"
#include <iostream>	
#include <conio.h>

World::World() {

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
	std::string chosenClass;
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
	}
	std::cout << "You chose " << chosenClass << "!" << std::endl;
	return chosenClass;
}

void World::printStartUI() {
	namingUI();
	playerClassUI();
}
#include "World.h"
#include "Dialogue.h"
#include "Enemy.h"
#include <iostream>	
#include <conio.h>

World::World() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			grid[i][j] = '.';
		}
	}
	currentLevel = 0;
	credits = 0;
};

int World::getCredits() {
	return credits;
}

int World::getCurrentLevel() {
	return currentLevel;
}

std::string World::namingUI() {
	std::cout << "Name Your Character: ";
	std::string playerName;
	std::cin >> playerName;
	std::cout << "Hello " << playerName << std::endl;
	std::cout << "Press any key to continue";
	return playerName;
}


std::string World::playerClassUI() {
	std::string cardname[3] = { "Fairy", "Witch", "Assassin" };
	std::string carddesc[3] = { "placeholder 1", "placeholder 2", "placeholder 3" };
	int cardatk[3] = {5, 10, 20};
	int cardhp[3] = {100, 25, 67};
	bool chosen = false;
	int cardCount = 0;

	while (!chosen) {
		char newKey = _getch();
		switch (newKey) {
		case 'z':
			cardCount--;
			if (cardCount < 0) cardCount = 2;
			break;
		case 'x':
			cardCount++;
			if (cardCount > 2) cardCount = 0;
			break;
		case 'c':
			chosen = true;
			break;
		}
		system("cls");
		std::cout << "The Jimbob Paradox" << std::endl;
		std::cout << "[ Class Selection ]" << std::endl;
		std::cout << "Class: " << cardname[cardCount] << std::endl;
		std::cout << "Desc: " << carddesc[cardCount] << std::endl;
		std::cout << "Attack: " << cardatk[cardCount] << std::endl;
		std::cout << "Health: " << cardhp[cardCount] << std::endl;
		std::cout << "[Z] Previous / [X] Next / [C] Choose" << std::endl;
	}

	std::string chosenClass = "null";
	switch (cardCount) {
	case 0:
		chosenClass = "Fairy";
		break;
	case 1:
		chosenClass = "Witch";
		break;
	case 2:
		chosenClass = "Assassin";
		break;
	default:
		std::cout << "Invalid Class!" << std::endl;
	}
	std::cout << "You chose " << chosenClass << "!" << std::endl;
	std::cout << "Press any key to continue..." << std::endl;
	return chosenClass;
}

void World::printCombatUI(std::string playerName, int pHp, int pAtk, int eHp, int eAtk, int creds){
	std::cout << "The Jimbob Paradox" << std::endl;
	std::cout << "Credits: " << creds << std::endl;
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

void World::earnCredits(std::string enemyType) {
	if (enemyType == "Enemy") creditsRewarded = rand() % 7 + 5;
	else if (enemyType == "Boss") creditsRewarded = rand() % 5 + 10;
	credits += creditsRewarded;
}
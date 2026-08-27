#include "World.h"
#include "Dialogue.h"
#include "Character.h"
#include "Enemy.h"
#include <iostream>	
#include <conio.h>

World::World() {
	creditsRewarded = 0;
	currentLevel = 0;
	credits = 0;
	playerClass = "null";
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


void World::playerClassUI(Character* player) {
	std::string cardname[3] = { "Fairy", "Witch", "Assassin" };
	std::string carddesc[3] = { "placeholder 1", "placeholder 2", "placeholder 3" };
	int cardatk[3] = { 5, 10, 20 };
	int cardhp[3] = { 100, 25, 67 };
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
	if (chosenClass != "null") {
		player->setHealth(cardhp[cardCount]);
		player->setMaxHP(cardhp[cardCount]);
		player->setAttack(cardatk[cardCount]);
		playerClass = chosenClass; // remembered here since Character has no "class" field - Combat needs this for gimmicks
		std::cout << "You chose " << chosenClass << "!" << std::endl;
		std::cout << "Press any key to continue..." << std::endl;
	}
}

std::string World::getPlayerClass() {
	return playerClass;
}

void printHp(Character& c) {
	std::cout << "HP [";
	int i = 0;
	for (; i < int((c.getHp() / float(c.getMaxHp())) * 10); i++) {
		std::cout << (char)254u;
	}
	for (int j = 0; j < 10 - i; j++) {
		std::cout << ' ';
	}
	std::cout << "] " << c.getHp() << '/' << c.getMaxHp() << std::endl;
}

void World::printHP(Character& c) {
	printHp(c); // same bar-drawing logic, just exposed as a member per the header
}

void World::printStats(Character& c) {
	std::cout << std::endl;
	std::cout << '[' << c.getName() << ']' << std::endl;
	printHp(c);
	std::cout << "Attack: " << c.getAttack() << std::endl;
	std::cout << std::endl;
}

void World::printCombatUI(Character& p, Enemy& e) {
	std::cout << "The Jimbob Paradox" << std::endl;
	std::cout << "Credits: " << credits << std::endl;
	printStats(p);
	std::cout << "===============================" << std::endl;
	printStats(e);
	printEnemyName(e);
	std::cout << std::endl;
	std::cout << std::endl;
}

void World::earnCredits(std::string enemyType) {
	bool isEnemy = (enemyType == "Bombji") || (enemyType == "Bomjib") || (enemyType == "Mobij");
	bool isBoss = (enemyType == "Obobjib") || (enemyType == "Bobmij") || (enemyType == "Jimbob");
	if (isEnemy) creditsRewarded = rand() % 7 + 5;
	else if (isBoss) creditsRewarded = rand() % 5 + 10;
	credits += creditsRewarded;
}

void World::changeLevel() {
	currentLevel++;
}

void World::shopASCIIprint() {
	std::cout << R"(
    <<<<<<<<<<< SHOP >>>>>>>>>>>
    ____________________________
   /                            \
  |\___/ \___/ \___/ \___/ \___/ |
  |  __________________          |
  |  |                |    ____  |
  |  |                |   | __ | |
  |  |________________|   ||__|| |
  |                       |   o| |
  |_______________________|____|_|
	)" << std::endl;
}

void World::printShopUI(Character* player) {
	std::string item[3] = { "Vitality", "Damage", "Shield" };
	std::string desc[3] = { "Increases max health by 20.","Increases damage by 3.","Decreases damage taken by 5." };
	int itemCount = 0;
	bool proceed = false;
	bool affordable = true;
	char keypressed = '\0';
	while (proceed == false) {
		system("cls");
		std::cout << "The Jimbob Paradox" << std::endl;
		std::cout << "Credits: " << credits << std::endl;
		shopASCIIprint();
		std::cout << "[ Items In Stock ]" << std::endl;
		std::cout << "Item: " << item[itemCount] << std::endl;
		std::cout << "Description: " << desc[itemCount] << std::endl;
		std::cout << "Cost: 10" << std::endl;
		std::cout << std::endl;
		std::cout << "[Z] View Previous / [X] View Next / [E] Skip Shop" << std::endl;;
		for (int i = 0; i < 3; i++) {
			std::cout << " [" << i + 1 << "] Buy " << item[i];
		}
		std::cout << std::endl;
		if (!affordable) std::cout << "Not enough credits!" << std::endl;
		keypressed = _getch();
		switch (keypressed) {
		case 'z':
			itemCount--;
			if (itemCount < 0) itemCount = 2;
			affordable = true;
			break;
		case 'x':
			itemCount++;
			if (itemCount > 2) itemCount = 0;
			affordable = true;
			break;
		case 'e':
			proceed = true;
			break;
		case '1':
			if (credits >= 10) {
				std::cout << "You bought " << item[0] << std::endl;
				credits -= 10;
				std::cout << "Press any key to continue" << std::endl;
				keypressed = _getch();
				player->addMaxHP(20);
			}
			else affordable = false;
			break;
		case '2':
			if (credits >= 10) {
				std::cout << "You bought " << item[1] << std::endl;
				credits -= 10;
				std::cout << "Press any key to continue" << std::endl;
				keypressed = _getch();
				player->addAttack(3);
			}
			else affordable = false;
			break;
		case '3':
			if (credits >= 10) {
				std::cout << "You bought " << item[2] << std::endl;
				credits -= 10;
				std::cout << "Press any key to continue" << std::endl;
				keypressed = _getch();
				// player defense up
			}
			else affordable = false;
			break;
		}
	}
}


void World::BombjiName() {
	std::cout << R"(
||||. .||||. |\    /| ||||.   ||| |||||
|   | |    | | \  / | |   |     |   |  
|   | |    | |  \/  | |   |     |   |  
||||. |    | |      | ||||.     |   |  
|   | |    | |      | |   | \   |   |  
|   | |    | |      | |   |  \  |   |  
||||. .||||. |      | ||||.   \\/ |||||)" << std::endl;
};

void World::BomjibName() {
	std::cout << R"(
||||. .||||. |\    /|    ||| ||||| ||||. 
|   | |    | | \  / |     |   |    |   |
|   | |    | |  \/  |     |   |    |   |
||||. |    | |      |     |   |    ||||.
|   | |    | |      | \   |   |    |   |
|   | |    | |      |  \  |   |    |   |
||||. .||||. |      |   \\/  ||||| ||||.)" << std::endl;
};

void World::MobijName() {
	std::cout << R"(
|\    /| .||||. ||||.  |||||    |||
| \  / | |    | |   |    |       |
|  \/  | |    | |   |    |       |
|      | |    | ||||.    |       |
|      | |    | |   |    |   \   |
|      | |    | |   |    |    \  |
|      | .||||. ||||.  |||||   \\/)" << std::endl;
};

void World::ObobjibName() {
	std::cout << R"(
.||||. ||||. .||||. ||||.    ||| ||||| ||||. 
|    | |   | |    | |   |     |    |   |   |
|    | |   | |    | |   |     |    |   |   |
|    | ||||. |    | ||||.     |    |   ||||.
|    | |   | |    | |   | \   |    |   |   |
|    | |   | |    | |   |  \  |    |   |   |
.||||. ||||. .||||. ||||.   \\/  ||||| ||||.)" << std::endl;
};

void World::BobmijName() {
	std::cout << R"(
||||. .||||. ||||. |\    /| |||||    |||
|   | |    | |   | | \  / |   |       |
|   | |    | |   | |  \/  |   |       |
||||. |    | ||||. |      |   |       |
|   | |    | |   | |      |   |   \   |
|   | |    | |   | |      |   |    \  |
||||. .||||. ||||. |      | |||||   \\/)" << std::endl;
};

void World::JimbobName() {
	std::cout << R"(
   ||| ||||| |\    /| ||||. .||||. ||||. 
    |    |   | \  / | |   | |    | |   |
    |    |   |  \/  | |   | |    | |   |
    |    |   |      | ||||. |    | ||||.
\   |    |   |      | |   | |    | |   |
 \  |    |   |      | |   | |    | |   |
  \\/  ||||| |      | ||||. .||||. ||||.)" << std::endl;
};

void World::printEnemyName(Enemy& e) {
	if (e.getName() == "Bombji") BombjiName();
	else if (e.getName() == "Bomjib") BomjibName();
	else if (e.getName() == "Mobij") MobijName();
	else if (e.getName() == "Obobjib") ObobjibName();
	else if (e.getName() == "Bobmij") BobmijName();
	else if (e.getName() == "Jimbob") JimbobName();
}



void World::printWinScreen() {
	system("cls");
	// final winscreen here
	std::cout << "You win!" << std::endl;
	std::cout << "Press any key to quit" << std::endl;
	int e = _getch();
}

void World::printDeathScreen() {
	std::cout << "You died..." << std::endl;
}

void World::cheatCode(Character* player) {
	system("cls");
	std::cout << "Cheat code enabled!" << std::endl;
	std::cout << "Type 8 to reset input." << std::endl;
	bool cheat = true;
	char keyp = '\0';
	std::string cheatcode = "";
	while (cheat) {
		keyp = _getch();
		std::cout << keyp;
		if (cheatcode.length() > 8) {
			std::cout << std::endl;
			std::cout << "Warning: Too many characters inputted. Type [clear] to clear input: ";
			std::string resp;
			std::cin >> resp;
			if (resp == "clear") cheatcode.clear(), std::cout << "Input has been cleared." << std::endl;
		}
		else {
			cheatcode += keyp;
			if (cheatcode == "kms") {
				std::cout << std::endl;
				player->setHealth(0);
				std::cout << "Player health is now 0." << std::endl;
				cheatcode.clear();
			}
			else if (cheatcode == "skip") {
				std::cout << std::endl;
				std::cout << "Choose the level you want to skip to (0-9) and press [Enter] to confirm: ";
				int lvl;
				std::cin >> lvl;
				if (lvl <= 9 && lvl >= 0) {
					currentLevel = lvl;
					std::cout << "Current Level: " << currentLevel << std::endl;
				}
				else std::cout << "Invalid output!" << std::endl;
				cheatcode.clear();
			}
			else if (cheatcode == "rich") {
				std::cout << std::endl;
				credits += 9999;
				std::cout << "Credits: " << credits << std::endl;
				cheatcode.clear();
			}
			else if (cheatcode == "sethp") {
				std::cout << std::endl;
				int h;
				std::cout << "Set Health: ";
				std::cin >> h;
				player->setHealth(h);
				std::cout << "Health set to " << h << std::endl;
				cheatcode.clear();
			}
			else if (cheatcode == "clear") {
				std::cout << std::endl;
				std::cout << "Input cleared!" << std::endl;
				cheatcode.clear();
			}
			else if (cheatcode == "quit") {
				std::cout << std::endl;
				std::cout << "Cheatcode has been disabled." << std::endl;
				std::cout << "Press [E] to return." << std::endl;
				char x = _getch();
				if (x == 'e') cheat = false;
				cheatcode.clear();
			}
		}
	}
}

#include <iostream>
#include <conio.h>
#include "World.h"
#include "Character.h"
#include "Enemy.h"
#include "Boss.h"
#include "Dialogue.h"
#include "Combat.h"

// each level's enemy is its own named object - no vector, no array.
Enemy levelEnemy0("Mobij", 10, 3);
Enemy levelEnemy1("Bombji", 15, 4);
Enemy levelEnemy2("Bomjib", 20, 5);
Boss finalBoss("Jimbob", 40, 8); // the final fight

const int TOTAL_LEVELS = 4; // 3 regular enemies + 1 boss

Character& getCurrentEnemy(int level) {
	switch (level) {
	case 0: {
		return levelEnemy0;
	}
	case 1: {
		return levelEnemy1;
	}
	case 2: {
		return levelEnemy2;
	}
	case 3: {
		return finalBoss;
	}
	default: {
		return finalBoss;
	}
	}
}

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
			hp = 100; // mockup values can change later	
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

	bool inCombat = false;
	char keyPressed;
	Combat* activeCombat = nullptr; // persists for the whole fight
	int turnCounter = 0;

	// homescreen
	while (isActive) {
		system("cls");
		Character& currentEnemy = getCurrentEnemy(world.getCurrentLevel());

		if (inCombat) {
			// build the Combat object ONCE per fight, the first time we enter combat
			if (activeCombat == nullptr) {
				activeCombat = new Combat(player1, currentEnemy, plyClass);
				turnCounter = 0;
			}

			// tick any lingering DoTs 
			// at the start of the round, same as before
			activeCombat->tickDotEffects();

			if (currentEnemy.isAlive() && player1.isAlive()) {
				// build the status block shown under "-- Status --" in the combat UI
				std::string statusEffects;
				if (activeCombat->getWitchDotTurnsLeft() > 0) {
					statusEffects += currentEnemy.getName() + " cursed: " + std::to_string(activeCombat->getWitchDotTurnsLeft()) + " turn(s) left\n";
				}
				if (activeCombat->getEnemyDotTurnsLeft() > 0) {
					statusEffects += "You are afflicted: " + std::to_string(activeCombat->getEnemyDotTurnsLeft()) + " turn(s) left\n";
				}
				if (plyClass == "Fairy") {
					int untilHeal = activeCombat->getTurnsUntilFairyHeal();
					statusEffects += "Next Fairy heal in: " + std::to_string(untilHeal) + " turn(s)\n";
				}

				world.printCombatUI(player1.getName(), player1.getHp(), player1.getAttack(), currentEnemy.getHp(), currentEnemy.getAttack(), world.getCredits(), turnCounter, statusEffects);
				keyPressed = _getch();

				if (keyPressed == 'x' || keyPressed == 'X') {
					currentEnemy.takeDamage(player1.getAttack());
					activeCombat->applyGimmick(); // Witch curse / Fairy heal, if applies
					turnCounter++;

					std::cout << "Press any key to continue..." << std::endl;
					_getch();

					// enemy attacks back, but only if it survived the hit above
					if (currentEnemy.isAlive()) {
						system("cls");
						activeCombat->doEnemyTurn();
						std::cout << "Press any key to continue..." << std::endl;
						_getch();
					}
				}
			}

			if (player1.getHp() <= 0) {
				system("cls");
				std::cout << "You were defeated..." << std::endl;
				isActive = false;
				delete activeCombat;
				activeCombat = nullptr;
			}
			else if (currentEnemy.getHp() <= 0) {
				system("cls");
				std::cout << "You killed " << currentEnemy.getName() << "!" << std::endl;
				std::cout << "Press [E] to confirm" << std::endl;
				keyPressed = _getch();
				if (keyPressed == 'e' || keyPressed == 'E') {
					system("cls");
					world.earnCredits(currentEnemy.getName());
					world.printShopUI();

					d.printEndDialogue(world.getCurrentLevel(), player1.getName());

					delete activeCombat; 
					activeCombat = nullptr;

					std::cout << "Press [E] to continue" << std::endl;
					keyPressed = _getch();
					if (keyPressed == 'e' || keyPressed == 'E') {
						int nextLevel = world.changeLevel();
						if (nextLevel >= TOTAL_LEVELS) {
							system("cls");
							std::cout << "You defeated every enemy! You win!" << std::endl;
							isActive = false;
						}
						else {
							inCombat = false;
						}
					}
				}
			}
		}
		else {
			d.printDialogue(world.getCurrentLevel(), playerPtr->getName());
			std::cout << "Press any key to continue..." << std::endl;
			keyPressed = _getch();
			inCombat = true;
		}
	};

	delete activeCombat; // safety net in case the loop exits mid-fight

	return 0;
}

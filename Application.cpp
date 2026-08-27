#include "Application.h"
#include <iostream>
#include <conio.h>
#include "World.h"
#include "Character.h"
#include "Enemy.h"
#include "Boss.h"
#include "Dialogue.h"
#include "Combat.h"

// each enemy/boss appearance is its own named object
// grouped by level ,, since some levels now have more than one wave.

// Level 0: tutorial fight against Bobmij 
Boss bobmijTutorial("Bombji", 5, 2); //

//  Level 1: Mobij 
Enemy mobij1("Mobij", 15, 3);

// Level 2: Obobjib summons Mobij first, then fights you himself 
Enemy mobij2("Mobij", 15, 3);
Boss obobjib2("Obobjib", 20, 5);

// Level 3: Bombji 
Enemy bombji3("Bombji", 16, 4);
Enemy mobij3("Mobij", 16, 3);

// Level 4 (one): Mobij and Bombji both return
Enemy mobij4a("Mobij", 18, 4);
Enemy bombji4a("Bombji", 17, 5);

//  Level 4 (two): Bobmij turns on you 
Boss bobmijBoss("Bobmij", 50, 10);

//  Level 5 (one): Jimbob, first appearance 
Enemy bombji5a("Bombji", 20, 9);
Enemy mobij5a("Mobij", 20, 8);

//  Level 5 (two): "familiar faces" - Bomjib 
Enemy bomjib5b("Bomjib", 20, 10);
Enemy mobij5b("Mobij", 25, 9);

// Level 5 (three): the real final fight 
Boss jimbobFinal("Jimbob", 75, 12);

const int TOTAL_LEVELS = 9;
const int MAX_WAVES = 2;

// nullptr >> "no wave here" for levels with fewer than MAX_WAVES fights.

Enemy* levelWaves[TOTAL_LEVELS][MAX_WAVES] = {
	{ &bobmijTutorial, nullptr },     // level 0
	{ &mobij1,         nullptr },     // level 1
	{ &mobij2,         &obobjib2 },   // level 2
	{ &bombji3,        &mobij3 },     // level 3
	{ &mobij4a,        &bombji4a },   // level 4 
	{ &bobmijBoss,     nullptr },     // level 4 
	{ &bombji5a,       &mobij5a },     // level 5 
	{ &bomjib5b,       &mobij5b },     // level 5 
	{ &jimbobFinal,    nullptr },     // level 5 
};

Enemy* getWaveEnemy(int level, int wave) {
	if (level < 0 || level >= TOTAL_LEVELS) return nullptr;
	if (wave < 0 || wave >= MAX_WAVES) return nullptr;
	return levelWaves[level][wave];
}

int Application::Game() {
	srand(static_cast<unsigned int>(time(0)));

	Dialogue d;
	std::cout << "The Jimbob Paradox" << std::endl;
	World world;
	std::cout << "After stealing a sandwich from your roommate, you fall through a portal and arrive in a new world. You're confused, stuck in a new place with no clear way out." << std::endl;

	std::string name = world.namingUI();

	// construct with placeholderstats -
	// playerClassUI() below overwrites hp/maxHp/attack once a class is chosen
	Character player1(name, 0, 0);
	Character* playerPtr = &player1;

	world.playerClassUI(&player1);
	std::string plyClass = world.getPlayerClass();
	bool isActive = (plyClass != "null");

	bool inCombat = false;
	bool inShop = false;
	char keyPressed;
	Combat* activeCombat = nullptr; // persists for the whole fight
	int turnCounter = 0;
	int currentWave = 0; // which wave within the current level we're on

	// homescreen
	while (isActive) {
		system("cls");
		Enemy* currentEnemyPtr = getWaveEnemy(world.getCurrentLevel(), currentWave);
		if (currentEnemyPtr == nullptr) {
			// s
			std::cout << "No enemy configured for this level/wave - stopping here." << std::endl;
			break;
		}
		Enemy& currentEnemy = *currentEnemyPtr;

		if (inCombat) {
			// build the Combat object ONCE per figh the first time we enter combat
			if (activeCombat == nullptr) {
				activeCombat = new Combat(player1, currentEnemy, plyClass);
				turnCounter = 0;
			}

			// tick any lingering DoTs at the start of the round
			activeCombat->tickDotEffects();

			if (currentEnemy.isAlive() && player1.isAlive()) {
				world.printCombatUI(player1, currentEnemy);

				std::cout << "Turn: " << turnCounter << std::endl;
				if (activeCombat->getWitchDotTurnsLeft() > 0) {
					std::cout << currentEnemy.getName() << " cursed: " << activeCombat->getWitchDotTurnsLeft() << " turn(s) left" << std::endl;
				}
				if (activeCombat->getEnemyDotTurnsLeft() > 0) {
					std::cout << "You are afflicted: " << activeCombat->getEnemyDotTurnsLeft() << " turn(s) left" << std::endl;
				}
				if (plyClass == "Fairy") {
					std::cout << "Next Fairy heal in: " << activeCombat->getTurnsUntilFairyHeal() << " turn(s)" << std::endl;
				}

				char requiredKey = 'A' + rand() % 26;
				std::cout << "Quick! Press \033[31m[" << requiredKey << "]\033[0m to attack!" << std::endl;

				keyPressed = _getch();

				char pressedUpper = keyPressed;
				if (pressedUpper >= 'a' && pressedUpper <= 'z') {
					pressedUpper = pressedUpper - 'a' + 'A';
				}
				if (pressedUpper == requiredKey) {
					currentEnemy.takeDamage(player1.getAttack());
					activeCombat->applyGimmick(); // Witch curse / Fairy heal, if applicable
					turnCounter++;
					std::cout << "Direct hit!" << std::endl;
				}
				else {
					std::cout << "You fumbled the attack and missed!" << std::endl;
				}

				std::cout << "Press any key to continue..." << std::endl;
				_getch();

				if (currentEnemy.isAlive()) {
					system("cls");
					activeCombat->doEnemyTurn();
					std::cout << "Press any key to continue..." << std::endl;
					_getch();
				}
			}

			if (player1.getHp() <= 0) {
				system("cls");
				world.printDeathScreen();
				isActive = false;
				delete activeCombat;
				activeCombat = nullptr;
			}
			else if (currentEnemy.getHp() <= 0) {
				system("cls");
				std::cout << "You defeated " << currentEnemy.getName() << "!" << std::endl;
				std::cout << "Press \033[36m[E]\033[0m to confirm" << std::endl;
				keyPressed = _getch();
				if (keyPressed == 'e' || keyPressed == 'E') {
					world.earnCredits(currentEnemy.getName());
					delete activeCombat;
					activeCombat = nullptr;

					Enemy* nextWave = getWaveEnemy(world.getCurrentLevel(), currentWave + 1);
					if (nextWave != nullptr) {
						// more enemies in this same level ,, no shop/dialogue yet
						currentWave++;
						system("cls");
						std::cout << "Another enemy appears!" << std::endl;
						std::cout << "Press any key to continue..." << std::endl;
						_getch();
						// inCombat stays true ,, next loop picks up nextWave automatically
					}
					else {
						if (!inShop) {
							while (keyPressed != 'e') {
								system("cls");
								std::cout << "You killed an enemy!" << std::endl;
								std::cout << "Press \033[36m[E]\033[0m to continue" << std::endl;
								keyPressed = _getch();
							}
							inShop = true;
							bool a = false;
							while (inShop) {
								while (!a) {
									system("cls");
									world.printShopUI(playerPtr);
									std::cout << "Press \033[36m[E]\033[0m to confirm / any other key to return." << std::endl;
									keyPressed = _getch();
									a = (keyPressed == 'e');
								}
								if (keyPressed == 'e') {
									keyPressed = d.printEndDialogue(world.getCurrentLevel(), player1.getName());
									while (keyPressed != 'e') keyPressed = d.printEndDialogue(world.getCurrentLevel(), player1.getName());
									inShop = false;
									inCombat = false;

									currentWave = 0; //reset to first wave of level

									world.changeLevel();
								}
							}
						}
					}
				}
			}
		}
		if (inCombat == false) {
			if (world.getCurrentLevel() <= 8) {
				keyPressed = d.printDialogue(world.getCurrentLevel(), player1.getName());
				if (keyPressed == 'e') inCombat = true;
				else if (keyPressed == '8') world.cheatCode(playerPtr);
			}
			else {
				world.printWinScreen();
				isActive = false;
			}
		}
	};

	delete activeCombat; // safety net in case the loop exits mid-fight

	return 0;
}

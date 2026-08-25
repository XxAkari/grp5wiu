#include <string>
#include "Character.h"

#pragma once
class World
{
private: 
	// char grid[10][10];
	int currentLevel;
	int credits;
	int creditsRewarded;

public:
	World();
	int getCredits(); // accessor to credits value, not the earning one
	int getCurrentLevel();
	void changeLevel(); // level increment
	std::string namingUI();
	void playerClassUI(Character* player);
	void earnCredits(std::string enemyType);	
	void printHP(Character& c);
	void printCombatUI(Character& p, Character& e);
	void shopASCIIprint();
	void printShopUI(Character* player);
	void printWinScreen();
	void printDeathScreen();
	
	void cheatCode(Character* player);
};


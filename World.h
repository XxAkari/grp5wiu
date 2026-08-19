#include <string>

#pragma once
class World
{
private: 
	char grid[10][10];
	int currentLevel;
	int credits;
	int creditsRewarded;

public:
	World();
	int getCredits(); // accessor to credits value, not the earning one
	int getCurrentLevel();
	std::string namingUI();
	std::string playerClassUI();

	void earnCredits(std::string enemyType);
	void printCombatUI(std::string playerName, int pHp, int pAtk, int eHp, int eAtk, int creds);
};


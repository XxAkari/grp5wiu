#include <string>

#pragma once
class World
{
private: 
	char grid[10][10];
	int credits;
	int creditsRewarded;
	int curLevel; // current level

public:
	World();
	int getCurrentLevel();
	int changeLevel(); // level increment
	int getCredits(); // accessor to credits value, not the earning one
	std::string namingUI();
	std::string playerClassUI();

	void earnCredits(std::string enemyType);
	void printCombatUI(std::string playerName, int pHp, int pAtk, int eHp, int eAtk, int creds);
};


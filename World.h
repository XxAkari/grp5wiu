#include <string>
#pragma once
class World
{
private:
	int currentLevel;
	int credits;
	int creditsRewarded;
public:
	World();
	int getCredits(); // accessor to credits value
	int getCurrentLevel();
	int changeLevel(); // level increment
	std::string namingUI();
	std::string playerClassUI();
	void earnCredits(std::string enemyType);
	void printCombatUI(std::string playerName, int pHp, int pAtk, int eHp, int eAtk, int creds, int turnCounter, std::string statusEffects);
	void shopASCIIprint();
	void printShopUI();
};

#include <string>
#include "Character.h"
#include "Enemy.h"

#pragma once
class World
{
private:
	int currentLevel;
	int credits;
	int creditsRewarded;
	std::string playerClass;

public:
	World();
	int getCredits(); // accessor to credits value, not the earning one
	int getCurrentLevel();
	void changeLevel(); // level increment
	std::string namingUI();
	void playerClassUI(Character* player);
	std::string getPlayerClass(); // Fairy/Witch/Assassin, set after playerClassUI() runs
	void earnCredits(std::string enemyType);
	void printHP(Character& c);
	void printStats(Character& c);
	void printCombatUI(Character& p, Enemy& e);
	void shopASCIIprint();
	void printShopUI(Character* player);
	void printWinScreen();
	void printDeathScreen();

	void BombjiName();
	void BomjibName();
	void MobijName();

	void ObobjibName();
	void BobmijName();
	void JimbobName();

	void printEnemyName(Enemy& e);

	void cheatCode(Character* player);
};
#pragma once
#include "Character.h"
#include <string>

class Combat {
public:
	// pClassName should be "Fairy", "Witch", "Assassin", or "" for no gimmick
	Combat(Character& player, Character& enemy, std::string pClassName = "");

	// Runs the full turn-based battle loop.
	// Returns true if the player wins (enemy defeated),
	// false if the player dies or flees.
	bool runCombat();

private:
	Character& player;
	Character& enemy;
	std::string pClassName;

	// enemy gimmick flags, worked out from enemy.getName() in the constructor:
	//   isExplodeEnemy - Bombji / boss Bobmij: attack deals bonus "explosion" damage
	//   isDotEnemy     - Bomjib / Jimbob: attack also applies a 3-turn DoT to the player
	bool isExplodeEnemy;
	bool isDotEnemy;

	// gimmick state trackers
	int witchDotTurnsLeft;   // DoT ticking on the enemy, from Witch's attack
	int enemyDotTurnsLeft;   // DoT ticking on the player, from Bomjib/Jimbob
	int fairyTurnCounter;    // player turns taken since last Fairy heal

	int getEnemyAttackDamage(); // handles the explode gimmick's bonus damage
	void healCharacter(Character& target, int amount); // caps at maxHp, no heal() on Character yet

	void printStatus();
	void tickDotEffects();     // applies + decrements any active DoTs at the start of a round
	bool doPlayerTurn();       // returns false if the player chose to flee
	void doEnemyTurn();
};
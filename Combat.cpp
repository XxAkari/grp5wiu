#include "Combat.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <algorithm>

namespace {
	// gimmick constants
	const int WITCH_DOT_DMG = 3;
	const int WITCH_DOT_DURATION = 3;
	const int ENEMY_DOT_DMG = 3;
	const int ENEMY_DOT_DURATION = 3;
	const int FAIRY_HEAL_AMT = 20;
	const int FAIRY_HEAL_INTERVAL = 3;
	const int ASSASSIN_DODGE_CHANCE = 25; // out of 100
	const int BOMBJI_EXPLOSION_DMG = 1;
}

Combat::Combat(Character& player, Character& enemy, std::string pClassName)
	: player(player), enemy(enemy), pClassName(pClassName),
	witchDotTurnsLeft(0), enemyDotTurnsLeft(0), fairyTurnCounter(0) {

	std::string name = enemy.getName();
	isExplodeEnemy = (name == "Bombji" || name == "Bobmij");
	isDotEnemy = (name == "Bomjib" || name == "Jimbob");
	// Mobij, Obobij, or anything else -> both flags stay false, plain attack only
}

int Combat::getEnemyAttackDamage() {
	if (isExplodeEnemy) {
		// Bombjis atk isn't what it actually hits for
		// Boss Bobmij doesnt have a separate number yet,
		// so it just uses its own ATK stat until thats filled in.
		if (enemy.getName() == "Bombji") return BOMBJI_EXPLOSION_DMG;
		return enemy.getAttack();
	}
	return enemy.getAttack();
}

void Combat::healCharacter(Character& target, int amount) {
	// Character has no heal so reuse takeDamage() with a negative amount
	// manually capped so we never overheal past maxHp
	int missing = target.getMaxHp() - target.getHp();
	int healAmount = std::min(amount, missing);
	if (healAmount > 0) {
		target.takeDamage(-healAmount);
	}
}

void Combat::tickDotEffects() {
	if (witchDotTurnsLeft > 0 && enemy.isAlive()) {
		enemy.takeDamage(WITCH_DOT_DMG);
		witchDotTurnsLeft--;
		std::cout << enemy.getName() << " takes " << WITCH_DOT_DMG
			<< " curse damage! (" << witchDotTurnsLeft << " turns left)" << std::endl;
	}

	if (enemyDotTurnsLeft > 0 && player.isAlive()) {
		player.takeDamage(ENEMY_DOT_DMG);
		enemyDotTurnsLeft--;
		std::cout << player.getName() << " takes " << ENEMY_DOT_DMG
			<< " lingering damage! (" << enemyDotTurnsLeft << " turns left)" << std::endl;
	}
}

bool Combat::doPlayerTurn() {
	char key = _getch();
	system("cls");

	if (key == 'x' || key == 'X') {
		int dmg = player.getAttack();
		enemy.takeDamage(dmg);
		std::cout << player.getName() << " attacks " << enemy.getName()
			<< " for " << dmg << " damage!" << std::endl;

		if (pClassName == "Witch") {
			witchDotTurnsLeft = WITCH_DOT_DURATION;
			std::cout << enemy.getName() << " is cursed! (" << WITCH_DOT_DMG
				<< " dmg/turn for " << WITCH_DOT_DURATION << " turns)" << std::endl;
		}

		fairyTurnCounter++;
		if (pClassName == "Fairy" && fairyTurnCounter % FAIRY_HEAL_INTERVAL == 0) {
			healCharacter(player, FAIRY_HEAL_AMT);
			std::cout << player.getName() << " heals for " << FAIRY_HEAL_AMT
				<< " HP!" << std::endl;
		}

		return true;
	}
	else if (key == 'c' || key == 'C') {
		std::cout << player.getName() << " flees the battle!" << std::endl;
		return false;
	}

	std::cout << "..." << std::endl;
	return true;
}

void Combat::doEnemyTurn() {
	if (!enemy.isAlive()) return;

	if (pClassName == "Assassin" && (rand() % 100) < ASSASSIN_DODGE_CHANCE) {
		std::cout << player.getName() << " dodges " << enemy.getName() << "'s attack!" << std::endl;
		return; // dodged attack deals no damage and doesn't apply the DoT gimmick
	}

	int dmg = getEnemyAttackDamage();
	player.takeDamage(dmg);
	std::cout << enemy.getName() << " attacks " << player.getName()
		<< " for " << dmg << " damage!" << std::endl;

	if (isDotEnemy) {
		enemyDotTurnsLeft = ENEMY_DOT_DURATION;
		std::cout << player.getName() << " is afflicted! (" << ENEMY_DOT_DMG
			<< " dmg/turn for " << ENEMY_DOT_DURATION << " turns)" << std::endl;
	}
}

bool Combat::runCombat() {
	std::cout << "A wild " << enemy.getName() << " appears!" << std::endl;

	while (player.isAlive() && enemy.isAlive()) {
		tickDotEffects();

		if (!enemy.isAlive()) {
			std::cout << enemy.getName() << " succumbs to the curse!" << std::endl;
			return true;
		}
		if (!player.isAlive()) {
			std::cout << player.getName() << " has fallen..." << std::endl;
			return false;
		}

		bool stillFighting = doPlayerTurn();
		if (!stillFighting) return false; // fled

		if (!enemy.isAlive()) {
			std::cout << enemy.getName() << " has been defeated!" << std::endl;
			return true;
		}

		doEnemyTurn();

		if (!player.isAlive()) {
			std::cout << player.getName() << " has fallen..." << std::endl;
			return false;
		}

		std::cout << "Press any key to continue..." << std::endl;
		_getch();
		system("cls");
	}

	return !player.isAlive() ? false : true;
}

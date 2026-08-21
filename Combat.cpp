#include "Combat.h"
#include <iostream>
#include <conio.h>
#include <algorithm>


const int WITCH_DOT_DMG = 3;
const int WITCH_DOT_DURATION = 3;
const int ENEMY_DOT_DMG = 3;
const int ENEMY_DOT_DURATION = 3;
const int FAIRY_HEAL_AMT = 20;
const int ASSASSIN_DODGE_CHANCE = 25; // out of 100
const int BOMBJI_EXPLOSION_DMG = 1;

Combat::Combat(Character& player, Character& enemy, std::string plClassName)
	: player(player), enemy(enemy), pClassName(plClassName),
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
		std::cout << enemy.getName() << " takes " << WITCH_DOT_DMG<< " curse damage! (" << witchDotTurnsLeft << " turns left)" << std::endl;
	}

	if (enemyDotTurnsLeft > 0 && player.isAlive()) {
		player.takeDamage(ENEMY_DOT_DMG);
		enemyDotTurnsLeft--;
		std::cout << player.getName() << " takes " << ENEMY_DOT_DMG<< " lingering damage! (" << enemyDotTurnsLeft << " turns left)" << std::endl;
	}
}

void Combat::applyGimmick()
{
	// Count one player turn
	fairyTurnCounter++;
	// Fairy: heal 20 HP every 3 turns
	if (pClassName == "Fairy" && fairyTurnCounter == 3)
	{
		healCharacter(player, FAIRY_HEAL_AMT);

		std::cout << "FAIRY GIMMICK ACTIVATED!" << std::endl;
		std::cout << player.getName()<< " heals for "<< FAIRY_HEAL_AMT<< " HP!" << std::endl;

		fairyTurnCounter = 0;
	}

	// Witch: apply 3-turn DoT
	if (pClassName == "Witch")
	{
		witchDotTurnsLeft = WITCH_DOT_DURATION;

		std::cout << "WITCH GIMMICK ACTIVATED!" << std::endl;
		std::cout << enemy.getName()<< " is cursed! ("<< WITCH_DOT_DMG<< " dmg/turn for "<< WITCH_DOT_DURATION<< " turns)" << std::endl;
	}
}

void Combat::doEnemyTurn() {
	if (!enemy.isAlive()) return;

	if (pClassName == "Assassin" && (rand() % 100) < ASSASSIN_DODGE_CHANCE) {
		std::cout << player.getName() << " dodges " << enemy.getName() << "'s attack!" << std::endl;
		return; // dodged attack deals no damage and doesn't apply the DoT gimmick
	}

	int dmg = getEnemyAttackDamage();
	player.takeDamage(dmg);
	std::cout << enemy.getName() << " attacks " << player.getName()<< " for " << dmg << " damage!" << std::endl;

	if (isDotEnemy) {
		enemyDotTurnsLeft = ENEMY_DOT_DURATION;
		std::cout << player.getName() << " is afflicted! (" << ENEMY_DOT_DMG<< " dmg/turn for " << ENEMY_DOT_DURATION << " turns)" << std::endl;
	}
}
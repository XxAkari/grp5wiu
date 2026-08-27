#include "Combat.h"
#include <iostream>
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
	const int BOMBJI_EXPLOSION_DMG = 12;
}

Combat::Combat(Character& player, Character& enemy, std::string pClassName)
	: player(player), enemy(enemy), pClassName(pClassName),
	witchDotTurnsLeft(0), enemyDotTurnsLeft(0), explosionCooldown(0), fairyTurnCounter(0) {

	std::string name = enemy.getName();
	isExplodeEnemy = (name == "Bombji" || name == "Bobmij");
	isDotEnemy = (name == "Bomjib" || name == "Jimbob");

}

int Combat::getEnemyAttackDamage() {
	if (isExplodeEnemy) {
		if (enemy.getName() == "Bombji") return BOMBJI_EXPLOSION_DMG;
		return enemy.getAttack();
	}
	return enemy.getAttack();
}

void Combat::healCharacter(Character& target, int amount) {
	// Character has no heal so reuse takeDamage() with a negative amount
	int missing = target.getMaxHp() - target.getHp();
	int healAmount = std::min(amount, missing);
	if (healAmount > 0) {
		target.takeDamage(-healAmount);
	}
}

void Combat::explodeASCII() {
	std::cout << R"(
                        =**++*+:                            
           :-:        .#@@%###*%*.                          
             .=*+-:.  +@@#=-#%%##+:=*#-     .               
                :+%@#+*%=   -+-=+*#%@@%+*#%%@%+-            
              .:..-#*-.=    :   ..  -#*++#%%%##%*-          
         .--==-==+*#*=              .     .+##%##%-         
              :*###+.                       .-#%%#*         
             .=%%%*                            #%#+         
              *%%%%.                          =*##          
              :###%*.:                       :*#+           
                -=*+##.                     .*#*:           
                :::=+%%-.                  =#%#++-.         
                   -+=#*+=+*-  .-:.:::+**::%++-=-:..        
                    -===..-#+-+**+=+=-+*%%+-==-  .          
                          ++**:===+*++==-.    :             
                          *-+-                              
                          + .                               
                          :)" << std::endl;
}

// Called from Source.cpp right after the player's attack damage has already

void Combat::applyGimmick() {
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

void Combat::doEnemyTurn() {
	if (!enemy.isAlive()) return;

	if (pClassName == "Assassin" && (rand() % 100) < ASSASSIN_DODGE_CHANCE) {
		std::cout << player.getName() << " dodges " << enemy.getName() << "'s attack!" << std::endl;
		return; // dodged attack deals no damage and doesn't apply the DoT gimmick
	}

	if (isExplodeEnemy) {
		explodeASCII();
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

int Combat::getWitchDotTurnsLeft() const {
	return witchDotTurnsLeft;
}

int Combat::getEnemyDotTurnsLeft() const {
	return enemyDotTurnsLeft;
}

int Combat::getTurnsUntilFairyHeal() const {
	if (pClassName != "Fairy") return -1; // not applicable for this class
	int remainder = fairyTurnCounter % FAIRY_HEAL_INTERVAL;
	return (remainder == 0) ? 0 : (FAIRY_HEAL_INTERVAL - remainder);
}
#pragma once
#include "Character.h"
#include <string>
class Combat {
public:
    Combat(Character& player, Character& enemy, std::string pClassName = "");
    void applyGimmick();
    void tickDotEffects();
    void doEnemyTurn();
    void explodeASCII();

    int getWitchDotTurnsLeft() const;   // curse ticking on the enemy
    int getEnemyDotTurnsLeft() const;   // DoT ticking on the player
    int getTurnsUntilFairyHeal() const; // 0 means "heals next attack"
private:
    Character& player;
    Character& enemy;
    std::string pClassName;
    bool isExplodeEnemy;
    bool isDotEnemy;

    int witchDotTurnsLeft;   // DoT ticking on the enemy, from Witch's attack
    int enemyDotTurnsLeft;   // DoT ticking on the player, from Bomjib/Jimbob
    int explosionCooldown;
    int fairyTurnCounter;    // player turns taken since last Fairy heal
    int getEnemyAttackDamage();
    void healCharacter(Character& target, int amount); // caps at maxHp, no heal() on Character yet
};

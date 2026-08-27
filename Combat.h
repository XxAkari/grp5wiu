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

    int getWitchDotTurnsLeft() const;
    int getEnemyDotTurnsLeft() const;
    int getTurnsUntilFairyHeal() const;
private:
    Character& player;
    Character& enemy;
    std::string pClassName;
    bool isExplodeEnemy;
    bool isDotEnemy;
    int witchDotTurnsLeft;
    int enemyDotTurnsLeft;
    int explosionCooldown;
    int fairyTurnCounter;
    int getEnemyAttackDamage();
    void healCharacter(Character& target, int amount);
};
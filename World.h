#pragma once
#include <string>
#include "Player.h" 
class World {
private:
    char grid[10][10];       
    int credits;             
    int curLevel;
    int creditsRewarded;
    Player* player;        

public:
    World();   // Constructor
    ~World();  // Destructor

    void startGame();

    int getCredits();// accesor  to credits value, not the earning one 
    int getCurrentLevel(); // level increment 
    int changeLevel(); 

    std::string namingUI();
    std::string playerClassUI();

    void printCombatUI(std::string playerName, int pHp, int pAtk, int eHp, int eAtk, int creds);
    void earnCredits(std::string enemyType);
};

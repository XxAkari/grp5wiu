#pragma once
#include "World.h"
#include <string>

class Character :
    public World
{
private:
    std::string name;
    int playerClass;

public:
    Character();
    void setPlayerName(std::string playerName);
};  


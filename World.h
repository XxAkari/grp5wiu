#include <string>

#pragma once
class World
{
private: 
	char grid[10][10];

public:
	World();
	std::string namingUI();
	std::string playerClassUI();

	void printCombatUI(std::string playerName);
};


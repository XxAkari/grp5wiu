#include <string>

#pragma once
class World
{
private: 


public:
	World();
	std::string namingUI();
	std::string playerClassUI();

	void printCombatUI();
	void printDialogueUI();
	void printStartUI();

	void printGrid();
};


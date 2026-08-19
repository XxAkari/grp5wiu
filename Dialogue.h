#include <string>
#include "Character.h"

#pragma once
class Dialogue
{
private:
	// logic: every levels line of dialogue split and put as indiv elements of an array
	// quote -> level dialogue array -> overall dialogue array
	// then ptr pointing to the level dialogue array
	// then array these ptrs (????)
	// so like
	// std::string array = {"12", "34", "56"}
	// then i ptr to the array????

	int curLevel; // current level
	std::string L0dialogue[6];
	std::string* L0Ptr;

public:
	Dialogue();
	int changeLevel(int level); // level increment
	void printDialogue();
	void loadDialogue(std::string name);
};


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

	void (Dialogue::*dialogue[9])(std::string name);
	void (Dialogue::*endDialogue[9])(std::string name);


public:
	Dialogue();

	void printUI();
	void printDialogue(int level, std::string name);
	void printEndDialogue(int level, std::string name);

	void printL0Dialogue(std::string name);
	void printL1Dialogue(std::string name);
	void printL2Dialogue(std::string name);
	void printL3Dialogue(std::string name);
	void printL4oneDialogue(std::string name);
	void printL4twoDialogue(std::string name);
	void printL5oneDialogue(std::string name);
	void printL5twoDialogue(std::string name);
	void printL5threeDialogue(std::string name);


	void printL0EDialogue(std::string name);
	void printL1EDialogue(std::string name);
	void printL2EDialogue(std::string name);
	void printL3EDialogue(std::string name);
	void printL4oneEDialogue(std::string name);
	void printL4twoEDialogue(std::string name);
	void printL5oneEDialogue(std::string name);
	void printL5twoEDialogue(std::string name);
	void printL5threeEDialogue(std::string name);

	void bombASCII();
};


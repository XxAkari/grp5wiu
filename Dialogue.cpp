#include "Dialogue.h"
#include "Character.h"
#include <iostream>

Dialogue::Dialogue() {
	curLevel = 0;

	for (int i = 0; i < 4; i++) {
		L0dialogue[i] = "null";
	}

	L0Ptr = L0dialogue;
}

int Dialogue::changeLevel(int level) {
	level++;
	return level;
}

void Dialogue::printDialogue() {
	for (int i = 0; i < 6; i++) {
		std::cout << L0dialogue[i] << std::endl;
	}
}

void Dialogue::loadDialogue(std::string name) { // im splitting this from init cause i need the player name which is derived from another class
	L0dialogue[0] = "An unknown figure walks towards you.";
	L0dialogue[1] = "MB: I see youve fallen through the Paradox Portal, " + name;	
	L0dialogue[2] = name + ": Who are you? How do you know my name?";
	L0dialogue[3] = "Bobmij: My apologies, the name's Bobmij, your guide in this world.";
	L0dialogue[4] = "As for how I know you… I’m sure you'll find out during your adventure.";
	L0dialogue[5] = "For now, you're too WEAK!";
}
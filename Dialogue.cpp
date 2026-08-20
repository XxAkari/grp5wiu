#include "Dialogue.h"
#include "Character.h"
#include <iostream>

Dialogue::Dialogue() {

	dialogue[0] = &Dialogue::printL0Dialogue;
	dialogue[1] = &Dialogue::printL1Dialogue;
	dialogue[2] = &Dialogue::printL2Dialogue;
	dialogue[3] = &Dialogue::printL3Dialogue;
	dialogue[4] = &Dialogue::printL4oneDialogue;
	dialogue[5] = &Dialogue::printL4twoDialogue;
	dialogue[6] = &Dialogue::printL5oneDialogue;
	dialogue[7] = &Dialogue::printL5twoDialogue;
	dialogue[8] = &Dialogue::printL5threeDialogue;

	endDialogue[0] = &Dialogue::printL0EDialogue;
	endDialogue[1] = &Dialogue::printL1EDialogue;
	endDialogue[2] = &Dialogue::printL2EDialogue;
	endDialogue[3] = &Dialogue::printL3EDialogue;
	endDialogue[4] = &Dialogue::printL4oneEDialogue;
	endDialogue[5] = &Dialogue::printL4twoEDialogue;
	endDialogue[6] = &Dialogue::printL5oneEDialogue;
	endDialogue[7] = &Dialogue::printL5twoEDialogue;
	endDialogue[8] = &Dialogue::printL5threeEDialogue;
}

//im really trying to push

void Dialogue::printUI() {
	std::cout << "The Jimbob Paradox" << std::endl;
	std::cout << std::endl;
}

void Dialogue::printDialogue(int level, std::string name) {
	printUI();
	(this->*dialogue[level])(name);
}

void Dialogue::printEndDialogue(int level, std::string name) {
	printUI();
	(this->*endDialogue[level])(name);
}

void Dialogue::printL0Dialogue(std::string name) {
	std::cout << "An unknown figure walks towards you." << std::endl;
	std::cout << "???: I see you've fallen through the Paradox Portal, " << name << std::endl;
	std::cout << name << ": Who are you? How do you know my name?" << std::endl;
	std::cout << "Bobmij: My apologies, the name's Bobmij, your guide in this world." << std::endl;
	std::cout << "Bobmij: As for how I know you... I'm sure you'll find out during your adventure." << std::endl;
	std::cout << "Bobmij: For now, you're too WEAK!" << std::endl;
}

void Dialogue::printL0EDialogue(std::string name) {
	std::cout << "BM: Good job, you are now fit to fight the others." << std::endl;
	std::cout << "BM:Stay vigilant, you must save the world." << std::endl;
	std::cout << "(A portal has opened up.)" << std::endl;
	std::cout << "BM: Go through the portal, you will find what you need there." << std::endl;
	std::cout << name << ": But you haven't explained anything!" << std::endl;
	std::cout << name << ": Why must I save this world? Why can't I return?" << std::endl;
	std::cout << "BM: All will be told in due time." << std::endl;
}

void Dialogue::printL1Dialogue(std::string name) {
	std::cout << "(You were dragged through a portal)" << std::endl;
	std::cout << name << ": Where are we? Why are we here?" << std::endl;
	std::cout << "BM: Each time you step into the portal, you will be teleported into a new world." << std::endl;
	std::cout << "BM: The portal will only appear at the right moment." << std::endl;
	std::cout << "BM: Defeat all the enemies." << std::endl;
	std::cout << "BM: I will only step in to help if you really need it." << std::endl;
	std::cout << "BM: The enemy here is a special kind, it-" << std::endl;
	std::cout << "(Bobmij moves aside, as a punch comes flying towards you)" << std::endl;
}

void Dialogue::printL1EDialogue(std::string name) {
	std::cout << "BM: Congrats on defeating your first real enemy." << std::endl;
	std::cout << "BM: As I was saying, the enemy here is called Mobij, and he will follow you around." << std::endl;
	std::cout << name << ": What? Didn't I kill him?" << std::endl;
	std::cout << "BM: Let's go to the next world." << std::endl;
	std::cout << "(A portal opened ahead. Bobmij steps through, pulling you along.)" << std::endl;
}

void Dialogue::printL2Dialogue(std::string name) {
	std::cout << "BM: The enemies change in every world. Some worlds may even have bosses" << std::endl;
	std::cout << "BM: Your job is to clear all of the enemies." << std::endl;
	std::cout << "(A puff of smoke fills the air, before a humanoid figure appears before you.)" << std::endl;
	std::cout << "(He scoffs.)" << std::endl;
	std::cout << "(Bobmij shuffles to your side, whispering:) That guy's name is Obobjib." << std::endl;
	std::cout << "OJ: For a rookie, you sure talk a lot. Come on, show me what you've got!" << std::endl;
	std::cout << "(Obobjib disappears, summoning Mobij.)" << std::endl;
}

void Dialogue::printL2EDialogue(std::string name) {
	std::cout << "OJ: How... did you... defeat me...?" << std::endl;
	std::cout << "(Obobjib collapses.)" << std::endl;
	std::cout << "BM: You've defeated your first boss, well done." << std::endl;
	std::cout << "BM: Unlike regular enemies, bosses like to talk. Obobjib is an example of that." << std::endl;
	std::cout << "(The portal opens before you again.)" << std::endl;
	std::cout << name << ": I still dont understand why-" << std::endl;
	std::cout << "(Bobmij drags you into the portal again.)" << std::endl;
}

void Dialogue::printL3Dialogue(std::string name) {
	std::cout << name <<  ": What was that for?!" << std::endl;
	std::cout << "BM: You should really stop asking so much." << std::endl;
	std::cout << "BM: Anyway, this world's enemy explodes a lot, so.. goodluck!" << std::endl;
	std::cout << name << ": What does that mean?" << std::endl;
	std::cout << "(Ticking is heard from behind, followed by a loud boom.)" << std::endl;
}

void Dialogue::printL3EDialogue(std::string name) {
	std::cout << "(You brush the debris off your clothes.)" << std::endl;
	std::cout << "BM: Killing him was easy, wasn't it?" << std::endl;
	std::cout << name << ": (Grumbling) Easier said than done..." << std::endl;
	std::cout << "(The portal appears again)" << std::endl;
	std::cout << "BM: I'm sure you know the drill by now." << std::endl;
	std::cout << "(You walk in, reluctantly.)" << std::endl;
}


void Dialogue::printL4oneDialogue(std::string name) {
	std::cout << "(You squint at the enemies in the distance.)" << std::endl;
	std::cout << name << ": I swear I've killed both of those enemies before..." << std::endl;
	std::cout << name << ": Didn't you say each world is different?" << std::endl;
	std::cout << "BM: The worlds ARE different, that doesn't mean the enemies can't be the same." << std::endl;
	std::cout << "BM: Hey- Watch out!" << std::endl;
	std::cout << "(Boom.)" << std::endl;
}

void Dialogue::printL4oneEDialogue(std::string name) {
	std::cout << "(The enemies suddenly disappear, seemingly being... recalled by Bobmij?)" << std::endl;
	std::cout << "BM: You sure have grown strong during your time in this world..." << std::endl;
	std::cout << name << ": What is this? I thought you were supposed to be my guide!" << std::endl;
}

void Dialogue::printL4twoDialogue(std::string name) {
	std::cout << "BM: You shouldn't have stolen the sandwich I left in the fridge, " << name << "!" << std::endl;
	std::cout << name << ": I've never even met you before! How could I be your roommate?" << std::endl;
	std::cout << name << ": No wonder the things you tell me sounds so wrong..." << std::endl;
	std::cout << name << ": You were never on my side!" << std::endl;
	std::cout << "BM: HA! It's a little late now, isn't it?" << std::endl;
	std::cout << "BM: Now, you shall pay for taking my sandwich!" << std::endl;
	std::cout << "(The world shatters, fragments spiralling around you both.)" << std::endl;

}

void Dialogue::printL4twoEDialogue(std::string name) {
	std::cout << "(You let out a sigh as you enter the portal.)" << std::endl;
}


void Dialogue::printL5oneDialogue(std::string name) {
	std::cout << "(You glance around to a surprisingly empty surrounding.)" << std::endl;
	std::cout << name << ":  Where are the enemies? Usually I’d see them by now..." << std::endl;
	std::cout << name << ": (muttering) Has Bobmij been telling them of my location?" << std::endl;
	std::cout << "???: Yes, yes he has." << std::endl;
	std::cout << "???: Although all of us know about you and the things you've done." << std::endl;
	std::cout << "JB: Short introduction, the name’s Jimbob, the ‘original’ of all the enemies you've seen so far." << std::endl;
	std::cout << "JB: I assume Bobmij didn't tell you they're all variants of me." << std::endl;
	std::cout << name << ": What? Then why was I brought into this world? I just wanted a sandwich." << std::endl;
	std::cout << "JB: If you win this fight, I'll tell you." << std::endl;
}

void Dialogue::printL5oneEDialogue(std::string name) {
	std::cout << "JB: Yeah. I'm sure that was easy for you, wasn't it?" << std::endl;
	std::cout << "JB: This next one... not anymore." << std::endl;
}

void Dialogue::printL5twoDialogue(std::string name) {
	std::cout << "(Familiar faces emerge, closing in to you.)" << std::endl;
}

void Dialogue::printL5twoEDialogue(std::string name) {
	std::cout << name << ": This has to be the end." << std::endl;
}

void Dialogue::printL5threeDialogue(std::string name) {
	std::cout << "Huh. It seems that you are worthy of fighting me." << std::endl;
	std::cout << "JB: However, you haven't won just yet." << std::endl;
	std::cout << "JB: You ought to try harder than that if you think you can beat me." << std::endl;
}

void Dialogue::printL5threeEDialogue(std::string name) {
	std::cout << "(Jimbob falters, weak on the ground, yet his eyes glimmer with hatred as he looks at you.)" << std::endl;
	std::cout << name << ": I've defeated you!" << std::endl;
	std::cout << name << "Now tell me why I was dragged into this world, and how to get back!" << std::endl;
	std::cout << "JB: This is YOUR world. You made us. You made this place." << std::endl;
	std::cout << name << ": What? That's impossible." << std::endl;
	std::cout << "JB: Haven't you noticed we look similar to you? That's cause we are different versions of YOU." << std::endl;
	std::cout << name << ": No... that's not true!" << std::endl;
	std::cout << name << ": You said YOU were the original!" << std::endl;
	std::cout << "JB: You still don't remember? YOU are the original, Jimbo." << std::endl;
	std::cout << name << "(Jimbo): This can't be true... how- how could	all of this be a dream?" << std::endl;
	std::cout << "JB: You live alone, Jimbo. You stole that sandwich from yourself." << std::endl;
	std::cout << "JB: More precisely, a version of yourself that you imagined." << std::endl;
	std::cout << "Jimbo: Even if that were true, the portal to my house isn't even appearing!" << std::endl;
	std::cout << "JB: Jimbo, you have schizophrenia. This entire world has been a hallucination." << std::endl;
	std::cout << "It's time to wake up." << std::endl;

}
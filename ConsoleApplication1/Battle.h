#include <stdio.h>
#include "Warrior.h"
#include <iostream>

using namespace std;

struct Battle {
	int selector, selectorb, n, i, nWarriors = Warrior::getnumberofWarriors();
	bool validinput;

	void chooseWarriors();
	void chooseWarriorCheck();
	void chooseWarriorCheckSecond();
	static void FightStart(Warrior* warriorA, Warrior* warriorB);
};
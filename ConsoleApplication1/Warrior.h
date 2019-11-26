#pragma once

#include <stdio.h>
#include <random>

using namespace std;

class Warrior {
	double attack;
	double defense;
	static int numberofWarriors;
public:
	string name;
	double health;

	Warrior(string, double, double, double); //constructor
	Warrior(); //default constructor
	~Warrior(); //destructor

	void setWarriorAttributes(string name, double attack, double defense, double health); //method to set a warriors attributes after they have been initialised, with a default constructor for example.
	string getName() { return name; }
	double AttackVal(); //get an attack value for the warrior
	double DefendVal(); //get a defence value for the warrior
	static int getnumberofWarriors() { return numberofWarriors; }
	void DebugString();
};
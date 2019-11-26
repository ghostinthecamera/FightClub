
#include <iostream>
#include <sstream>
#include "Warrior.h"

using namespace std;

int Warrior::numberofWarriors = 0; //initialise this one

Warrior::Warrior() {
	this->name = "Default";
	this->attack = 0;
	this->defense = 0;
	this->health = 0;
}

void Warrior::setWarriorAttributes(string name, double attack, double defense, double health) {
	this->name = name;
	this->attack = attack;
	this->defense = defense;
	this->health = health;
	numberofWarriors++;
}

Warrior::Warrior(string uname, double att, double def, double hp) : name(uname), attack(att), defense(def), health(hp) { numberofWarriors++; }

void Warrior::DebugString() {
	cout << "User created warrior " << this->name << " has an attack of " <<
		this->attack << " a defence of " << this->defense << " and " << this->health << "hp." << "\n";
}

double Warrior::AttackVal() {
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(0.1, 1.0);

	double attackMod = dis(gen);
	return this->attack * attackMod;
}

double Warrior::DefendVal() {
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(0.1, 1.0);

	double defendMod = dis(gen);
	return this->defense * defendMod;
}

Warrior::~Warrior() {
#ifdef DEBUG
	cout << this->name << " has been destroyed" << "\n";
#endif
}

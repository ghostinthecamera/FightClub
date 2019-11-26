#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Warrior.h"
#include "Battle.h"
#include "Main.h"

using namespace std;

Warrior* userwarriors;

int main() {
	inputHandler();
	createWarriors(uWarriorName, uWarriorAttack, uWarriorDefence, uWarriorHealth, numWarriors);
	fightHandler();
	delete[] userwarriors;
	return 0;
}

void inputHandler() {
	int n = 0;

	cout << "How many warriors? (betwween 2 and 5): \n";
	cin >> numWarriors;
	while (!cin) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Not a number. Please enter a number:\n";
		cin >> numWarriors;
	}
	while (numWarriors == 1) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Not enough warriors - need a minimum of two. Please try again: \n";
		cin >> numWarriors;
	}
	if (numWarriors > 5) {
		cout << "Too many warriors. Setting to 5 Warrior maximum" << "\n";
		numWarriors = 5;
	}

	if (numWarriors == 0) {
		cout << "No warriors needed. Exiting.." << "\n";
		exit(0);
	}

	for (n = 0; n < numWarriors; n++) {
		cout << "Name of Warrior " << n + 1 << ":" << "\n";
		cin >> nametempstore;
		uWarriorName.push_back(nametempstore);
		//
		cout << "What is " << uWarriorName[n] << "'s Attack?" << "\n";
		adTempstore = checkInput();
		uWarriorAttack.push_back(adTempstore);
		//
		cout << "What is " << uWarriorName[n] << "'s Defence?" << "\n";
		adTempstore = checkInput();
		uWarriorDefence.push_back(adTempstore);
		//
		cout << "How much health does " << uWarriorName[n] << " have?" << "\n";
		adTempstore = checkInput();
		uWarriorHealth.push_back(adTempstore);
	}
}

void createWarriors(vector<string>& warrNames, vector<double>& warrAttacks, vector<double>& warrDefenses, vector<double>& warrHealth, int& numberWarrs) {
	int n = 0;
	userwarriors = new Warrior[numberWarrs];
	for (n = 0; n < numberWarrs; n++) {
		userwarriors[n].setWarriorAttributes(warrNames[n], warrAttacks[n], warrDefenses[n], warrHealth[n]);
#ifdef DEBUG
		userwarriors[n].DebugString();
#endif
	}
	cout << Warrior::getnumberofWarriors() << " Warriors created" << "\n";
}

double checkInput() {
	cin >> adTempstore;
	while (!cin) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Not a number. Please enter a number:\n";
		cin >> adTempstore;
	}
	return adTempstore;
}

void fightHandler() {
	string fightStatus;
	cout << "Begin Fight? Y/N: ";
	cin >> fightStatus;

	if (fightStatus == "Y" || fightStatus == "y") {
		Battle fight;
		fight.chooseWarriors();
	}
	else if (fightStatus != "Y") {
		cout << "No Fight. Ending.." << "\n";
	}


	cout << "Fight over. Fight Again? Y/N" << "\n";
	cin >> fightStatus;

	if (fightStatus == "Y" || fightStatus == "y") {
		Battle fight;
		fight.chooseWarriors();
	}
	else if (fightStatus != "Y") {
		cout << "No Fight. Ending.." << "\n";
	}
}

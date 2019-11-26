#include "Battle.h"
#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include "Warrior.h"
#include <windows.h>

using namespace std;

extern Warrior* userwarriors;

void Battle::chooseWarriors() {
	Warrior* warrior1 = nullptr;
	Warrior* warrior2 = nullptr;

	if (nWarriors == 2) {
		//        cout << "Select the first warrior to fight from the following" << "\n";
		//        for (n=0; n<nWarriors; n++) {
		//            cout << n << ": " << userwarriors[n].name << "\n";
		//        }
		//        cin.clear();
		//        cin.ignore(INT_MAX, '\n');
		//        cin >> selector;
		//        Battle::chooseWarriorCheck();
		warrior1 = &userwarriors[0];
		warrior2 = &userwarriors[1];
	}
	if (nWarriors > 2) {
		cout << "Select the first warrior to fight from the following" << "\n";
		for (n = 0; n < nWarriors; n++) {
			cout << n << ": " << userwarriors[n].name << "\n";
		}
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> selector;
		Battle::chooseWarriorCheck();
		warrior1 = &userwarriors[selector];
		cout << "Select the second warrior to fight from the following" << "\n";
		selectorb = selector;
		for (n = 0; n < nWarriors; n++) {
			if (n == selectorb) { continue; }
			cout << n << ": " << userwarriors[n].name << "\n";
		}
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> selector;
		Battle::chooseWarriorCheckSecond();
		warrior2 = &userwarriors[selector];
	}
#ifdef DEBUG
	cout << "warrior 1 is " << warrior1->name << "\n";
	cout << "warrior 2 is " << warrior2->name << "\n";
#endif
	Battle::FightStart(warrior1, warrior2);
}

void Battle::chooseWarriorCheck() {
	validinput = false;
	do {
		for (i = 0; i < nWarriors; i++) {
			if (selector == i) {
				validinput = true;
			}
		}
		if (validinput == false) {
			cout << "Not a valid option. Please select from the following:" << "\n";
			for (n = 0; n < nWarriors; n++) {
				cout << n << ": " << userwarriors[n].name << "\n";
			}
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cin >> selector;
		}
	} while (validinput == false);
}

void Battle::chooseWarriorCheckSecond() {
	validinput = false;
	do {
		for (i = 0; i < nWarriors; i++) {
			if (selector == i && selector != selectorb) {
				validinput = true;
			}
		}
		if (validinput == false) {
			cout << "Not a valid option. Please select from the following:" << "\n";
			for (n = 0; n < nWarriors; n++) {
				if (n == selectorb) { continue; }
				cout << n << ": " << userwarriors[n].name << "\n";
			}
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cin >> selector;
		}
	} while (validinput == false);
}

void Battle::FightStart(Warrior* warriorA, Warrior* warriorB) {
	double attackA;
	double attackB;
	double defendA;
	double defendB;
	double healthA = warriorA->health;
	double healthB = warriorB->health;

	cout << "Startng fight between " << warriorA->name << " and " << warriorB->name << "\n";
	while (healthA > 0 && healthB > 0) {
		attackA = warriorA->AttackVal();
		defendB = warriorB->DefendVal();
		if (defendB > attackA) {
			cout << warriorB->name << " successfully defends against " << warriorA->name << "'s attack" << "\n";
		}
		else {
			healthB -= (attackA - defendB);
			healthB = healthB < 0 ? healthB == 0 : healthB;
			cout << warriorA->name << " hits " << warriorB->name << " for " << setprecision(3) << attackA - defendB << "\n";
		}
		defendA = warriorA->DefendVal();
		attackB = warriorB->AttackVal();
		if (defendA > attackB) {
			cout << warriorA->name << " successfully defends against " << warriorB->name << "'s attack" << "\n";
		}
		else {
			healthA -= (attackB - defendA);
			healthA = healthA < 0 ? healthA == 0 : healthA;
			cout << warriorB->name << " hits " << warriorA->name << " for " << setprecision(3) << attackB - defendA << endl;
		}
		cout << warriorA->name << " HP:" << setprecision(3) << healthA << " | " << warriorB->name << " HP:" << setprecision(3) << healthB << "\n\n";
		Sleep(200);
	}
	if (healthA == 0) {
		cout << warriorB->name << " has killed " << warriorA->name << endl;
	}
	else {
		cout << warriorA->name << " has killed " << warriorB->name << endl;
	}

}

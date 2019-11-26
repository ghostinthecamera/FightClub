#include <sstream>
#include <vector>
using namespace std;

//declare vectors and other variables
vector<string> uWarriorName; //vector for names of user warriors
vector<double> uWarriorAttack, uWarriorDefence, uWarriorHealth; //Vectors for attack, defence and health of warriors
int numWarriors;
string nametempstore;
double adTempstore;



//declare functions
void fightHandler();
void inputHandler();
void createWarriors(vector<string>& warrNames, vector<double>& warrAttacks, vector<double>& warrDefenses, vector<double>& warrHealth, int& numberWarrs);
double checkInput();
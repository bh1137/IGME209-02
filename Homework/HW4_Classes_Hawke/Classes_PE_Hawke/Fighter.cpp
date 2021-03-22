#include "Fighter.h"
#include <iostream>
using namespace std;

//default constructor
Fighter::Fighter()
{
	//player default should be called 
	//add deafault weapon skill 
	weaponSkill = "Fracture Force";
}

//parameterized constructor 
Fighter::Fighter(const char* name, int strength, int charisma, int intelligence, const char* weaponSkill) :Player(name, strength, charisma, intelligence)
{
	this->weaponSkill = weaponSkill;
}

//print fighter method 
void Fighter::printFighter()
{
	//call the player print player function 
	Player::printPlayer();

	//add the weapon skill line 
	cout << "Weapon Skill: " << weaponSkill << endl;
}

//destructor 
Fighter:: ~Fighter()
{
	//print statement 
	cout << "Destroying Fighter Object" << endl; 
}

//override the attack function 
void Attack(Player* player)
{
	///ass stuff here
}
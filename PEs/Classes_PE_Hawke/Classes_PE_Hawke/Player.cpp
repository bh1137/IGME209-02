#include "Player.h"
#include <iostream>
using namespace std;

//set the default constuctor 
Player::Player()
{
	name = "Unknown";
	strength = 10;
	charisma = 10;
	intelligence = 10;
}

//set the constructor 
Player::Player(const char* name, int strength, int charisma, int intelligence)
{
	this->name = name;
	this->strength = strength;
	this->charisma = charisma;
	this->intelligence = intelligence;

}

//Print player method
void Player::printPlayer()
{
	cout << "New Player Created:" << endl;
	cout << "Name: " << name << endl;
	cout << "Strength: " << strength << endl;
	cout << "Charisma: " << charisma << endl; 
	cout << "Intelligence: " << intelligence << endl;
}
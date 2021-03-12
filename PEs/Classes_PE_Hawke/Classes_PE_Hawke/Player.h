#pragma once
class Player
{
public: 
	Player();
	Player(const char* name, int strength, int charisma, int intelligence); //the constructor 
	void printPlayer(); //print method


private:
	//set up variables
	const char* name;
	int strength;
	int charisma;
	int intelligence;
};


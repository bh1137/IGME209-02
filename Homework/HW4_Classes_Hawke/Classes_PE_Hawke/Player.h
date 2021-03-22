#pragma once
class Player
{
public: 
	Player();
	Player(const char* name, int strength, int charisma, int intelligence); //the constructor 
	void printPlayer(); //print method
	~Player(); //destructor
	const char* GetName();
	virtual void Attack(Player* player);

private:
	//set up variables
	const char* name;
	int strength;
	int charisma;
	int intelligence;
};


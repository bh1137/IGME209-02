#include "level.h"



//default constructor 
level::level()
{
	levelName = "Disboard";
	levelNumber = 5;
	exitLocationX = 42;
	exitLocationY = 69;	

	//print statement 
	cout << "Construtor being created"<< endl;
}

//constructor 
level::level(string levelName, int levelNumber, int exitLocationX, int exitLocationY)
{
	this->levelName = levelName;
	this->levelNumber = levelNumber;
	this->exitLocationX = exitLocationX;
	this->exitLocationY = exitLocationY;

	//print statement 
	cout << "Constructor being created" << endl;
}

//destructor 
level:: ~level()
{
	//print statemnet 
	cout << "Destructor being initiated"<< endl; 
}

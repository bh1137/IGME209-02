// ConsoleApplication10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

class MovableObject
{
public:
	int xPos;
	int yPos;
	void PrintPos()
	{
		cout << "X:" << xPos << " Y:" << yPos << endl;
	}
};

class Player : public MovableObject
{
public:
	char* name;
	Player()
	{
		cout << "player ctor" << endl;
		name = new char[15];
	}

	~Player()
	{
		cout << "player dtor" << endl;
		delete[] name;
	}
};

class Monster : public MovableObject
{
public:
	int damage;
};

int main()
{
	//Monster *boss = new Monster();
	//Player *pOne = new Player();
	MovableObject *boss = new Monster();
	MovableObject *pOne = new Player();
	Monster *fakeMonster = (Monster*)pOne;

	// add code here
	//print our addresses
	cout << boss << endl;
	cout << pOne << endl;
	cout << fakeMonster << endl;

	//set some values
	boss->xPos = 4;
	boss->yPos = 20;

	pOne->xPos = 6;
	pOne->yPos = 9;

	fakeMonster->xPos = 9;
	fakeMonster->yPos = 13;

	//print 
	boss->PrintPos();
	pOne->PrintPos();
	fakeMonster->PrintPos();

	//to not crash
	fakeMonster = nullptr;

	//#6 player one is now inheriting values from the fake monster instead of having its own value.
	//the values are different for player because it is just inheriting from monster due to being just a movable object
	delete boss;
	delete pOne;
	delete fakeMonster;

	_getch();
    return 0;
}


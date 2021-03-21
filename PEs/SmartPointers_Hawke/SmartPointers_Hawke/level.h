#pragma once
#include <string>
#include <iostream>
using namespace std;

class level
{
public:
	//default constructor 
	level();
	level(string levelName, int levelNumber, int exitLocationX, int exitLocationY);
	~level(); //destructor
private:
	string levelName;
	int levelNumber;
	int exitLocationX;
	int exitLocationY;
	const char* treasure[5] = { "Tommy Gun", "Coffee-Flavored Chewing Gum", "Stand Arrow", "A Potato", "Chunchunmaru" };
};


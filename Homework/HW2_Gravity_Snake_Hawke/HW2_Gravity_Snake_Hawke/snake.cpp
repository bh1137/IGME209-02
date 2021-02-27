//Link to the header
#include <iostream>
#include <Box2D/Box2D.h> //Added Box2D
#include "snake.h"
using namespace std;

//Fields 
int objectsHit = 0;
bool hitTarget = false; 

//snake and target 
b2BodyDef snake;
b2BodyDef target;

//Functions
int randomPosition()
{
	//random number generator for target
	int randomNumber = rand()%11 -5;	
	return randomNumber;
}

void display()
{
	//display player and object position 
	if (hitTarget)
	{
		cout << "Target: " << target.position.x << ", " << target.position.y << " --> Snake: "
			<< snake.position.x << ", " << snake.position.y << " (hit target)"<< endl;
	}
	else
	{
		cout << "Target: " << target.position.x << ", " << target.position.y << " --> Snake: "
			<< snake.position.x << ", " << snake.position.y << endl;
	}
	
}
int main()
{
	//introduce the player to the game 
	cout << "Welcome! Let's play Gravity Snake!" << endl;
	cout << "To control the snake, use the WASD keys!" << endl;

	//declare the gravity and build the world 
	//gravity
	b2Vec2 gravity(0.0f, -9.81f);
	//world with gravity
	b2World world(gravity);

	//implement the snake	
	snake.type = b2_dynamicBody;
	snake.position.Set(5.0f, 5.0f);
	b2Body* body = world.CreateBody(&snake);

	//implement target	
	target.type = b2_staticBody;
	target.position.Set(randomPosition(), randomPosition());
	world.CreateBody(&target);

	//time frames
	float timeStep = 1.0f / 60.0f;
	
	display();
	return 0;
}
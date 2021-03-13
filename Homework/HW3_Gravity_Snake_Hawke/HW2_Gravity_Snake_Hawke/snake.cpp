//Link to the header
#include <iostream>
#include <Box2D/Box2D.h> //Added Box2D
#include "snake.h"	//for the function declarations
#include "conio.h"	//for the keyboard input
using namespace std; // no redundant stds

//Fields 
int objectsHit = 0;
bool IsTargetHit = false; 
bool IsEscHit = false;

//snake and target 
b2BodyDef snake;
b2BodyDef target;

//declare the gravity and build the world 
//gravity
b2Vec2 gravity(0.0f, -1.0f);
//world with gravity
b2World world(gravity);

//fields to make engine run smooth 
float timeStep = 1.0f / 1000.0f;
int32 velocityIterations = 6;
int32 positionIterations = 2;


//Functions
void update()
{
	world.Step(timeStep, velocityIterations, positionIterations);
}

void moveTarget(float& xPos, float& yPos, b2Vec2 targetPosition)
{
	//assign new values
	xPos = (float)randomPosition();
	yPos = (float)randomPosition();

	//to target
	targetPosition.x = xPos;
	targetPosition.y = yPos;
	targetPosition.Set(targetPosition.x, targetPosition.y);

}
int randomPosition()
{
	//random number generator for target
	int randomNumber = rand()%11 -5;	
	return randomNumber;
}

void display(b2Vec2 snakePosition, b2Vec2 targetPosition)
{
	//display player and object position 
	if (IsTargetHit)
	{
		//display message
		printf("Target: %.2f, %.2f --> Snake: %.2f, %.2f (Hit Target)", targetPosition.x, targetPosition.y, snakePosition.x, snakePosition.y);		
		cout << "\n";				
	}
	else
	{
		printf("Target: %.2f, %.2f --> Snake: %.2f, %.2f", targetPosition.x, targetPosition.y, snakePosition.x, snakePosition.y);
		cout << "\n";
	}
	
}

void applyForces(b2Body* snake)
{
	//keyboard hits
	if (_kbhit())
	{
		int ch = _getch();

		//W --> UP
		if (ch == 119)
		{
			b2Vec2 oldPosition = snake->GetPosition();
			snake->ApplyForceToCenter(b2Vec2(oldPosition.x,(oldPosition.y + 3000)), true);
		}
		//A --> LEFT
		else if (ch == 97)
		{
			b2Vec2 oldPosition = snake->GetPosition();
			snake->ApplyForceToCenter(b2Vec2((oldPosition.x - 550), oldPosition.y), true);
			
		}
		//S --> DOWN 
		else if (ch == 115)
		{
			b2Vec2 oldPosition = snake->GetPosition();
			snake->ApplyForceToCenter(b2Vec2(oldPosition.x, (oldPosition.y - 550)), true);
		}
		//D --> RIGHT
		else if (ch == 100)
		{
			b2Vec2 oldPosition = snake->GetPosition();
			snake->ApplyForceToCenter(b2Vec2((oldPosition.x + 550), oldPosition.y), true);
		}
		// ESC --> QUIT
		else if (ch == 27)
		{
			cout << "Good Bye" << endl;
			IsEscHit = true;
		}
		
	}
}

int main()
{
	//introduce the player to the game 
	cout << "Welcome! Let's play Gravity Snake!" << endl;
	cout << "To control the snake, use the WASD keys!" << endl;

	//implement the snake	
	snake.type = b2_dynamicBody;
	snake.position.Set(4.0f, 5.0f);
	b2Body* snakeBody = world.CreateBody(&snake);

	//implement target	
	target.type = b2_staticBody;
	target.position.Set(randomPosition(), randomPosition());
	b2Body* targetBody = world.CreateBody(&target);
	
	//target position (do it before the loop)
	b2Vec2 targetPosition = targetBody->GetPosition();

	//continous loop
	while (objectsHit != 2)
	{
		//ends the game if esc is pressed
		if (IsEscHit)
		{
			return 0;
		}

		//snake position
		b2Vec2 snakePosition = snakeBody->GetPosition();
		

		//update world 
		update();

		//kb detection
		applyForces(snakeBody);
					

		//display it
		display(snakePosition, targetPosition);

		//rounded floats
		double roundSnakeX = round(snakePosition.x);
		double roundSnakeY = round(snakePosition.y);
		double roundTargetX = round(targetPosition.x);
		double roundTargetY = round(targetPosition.y);
		//collision checker 
		if (roundSnakeX == roundTargetX && roundSnakeY == roundTargetY)
		{
			//set bool to true 
			IsTargetHit = true;

			display(snakePosition, targetPosition);

			//set new position for target 
			moveTarget(targetPosition.x, targetPosition.y, targetPosition); 

			
			//set plus 1
			objectsHit++;

			//set back to false
			IsTargetHit = false;
		}
	}
}
	
	
	

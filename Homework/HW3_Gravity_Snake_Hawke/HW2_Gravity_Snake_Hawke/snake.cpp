//Link to the header
#include <iostream>
#include <Box2D/Box2D.h> //Added Box2D
#include "snake.h"	//for the function declarations
#include "conio.h"	//for the keyboard input
using namespace std; // no redundant stds

//for SFML
#define SFML_STATIC
#include<SFML\Window.hpp>
#include<SFML\Graphics.hpp>

//Fields 
int objectsHit = 0;
bool IsTargetHit = false; 
bool IsEscHit = false;
char targetNum[2];
b2Vec2* TargetLocations[];
b2Vec2 currentLocation;

//snake and target 
b2BodyDef snake;
b2Body* snakeBody;
b2BodyDef target;

//declare the gravity and build the world 
//gravity
b2Vec2 gravity(0.0f, -5.0f);
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

//Keyboard input 
void processInput()
{
	//typedef
	ApplyForces W;
	ApplyForces A;
	ApplyForces S;
	ApplyForces D;
	ApplyForces Q;

	W = &ApplyForceUp;
	A = &ApplyForceLeft;
	S = &ApplyForceDown;
	D = &ApplyForceRight;
	Q = &StopMoving;

	//W --> UP
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		(*W)(*snakeBody);
	}
	//A --> LEFT
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		(*A)(*snakeBody);
	}
	//S --> DOWN 
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		(*S)(*snakeBody);
	}
	//D --> RIGHT
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		(*D)(*snakeBody);
	}
	//Q --> STOP MOVING 
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		(*Q)(*snakeBody);
	}
	//Z --> REVERSE GRAVITY
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		ReverseGravity(world);
	}
	//ESC --> QUIT
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		cout << "Good Bye" << endl;
		IsEscHit = true;
	}
}

//moves the player
void ApplyForceUp(b2Body& player)
{
	b2Vec2 oldPosition = player.GetPosition();
	player.ApplyForceToCenter(b2Vec2(oldPosition.x, (oldPosition.y += 2.0)), true);
}

void ApplyForceDown(b2Body& player)
{
	b2Vec2 oldPosition = player.GetPosition();
	player.ApplyForceToCenter(b2Vec2(oldPosition.x, (oldPosition.y -= 2.0)), true);
}

void ApplyForceLeft(b2Body& player)
{
	b2Vec2 oldPosition = player.GetPosition();
	player.ApplyForceToCenter(b2Vec2((oldPosition.x -= 2.0), oldPosition.y), true);
}

void ApplyForceRight(b2Body& player)
{
	b2Vec2 oldPosition = player.GetPosition();
	player.ApplyForceToCenter(b2Vec2((oldPosition.x += 2.0), oldPosition.y), true);
}

void StopMoving(b2Body& player)
{
	b2Vec2 newVel(0,0);
	player.SetLinearVelocity(newVel);
}

void ReverseGravity(b2World& world)
{
	world.SetGravity(-gravity);
}

void setupTarget(int cnt)
{
	const int targNum = cnt + 1;
	//new array
	TargetLocations[targNum];

	//set up the coordinates 
	currentLocation.x = TargetLocations[0]->x;
	currentLocation.y = TargetLocations[0]->y;
}

bool selectNextTarget(int counter)
{	
	//if statement for bool 
	if (TargetLocations[counter] == NULL)
	{
		return false;
	}
	else
	{
		//set up coordinates 
		currentLocation.x = TargetLocations[counter]->x;
		currentLocation.y = TargetLocations[counter]->y;
	}
}
int main()
{
	//introduce the player to the game 
	cout << "Welcome! Let's play Gravity Snake!" << endl;
	cout << "To control the snake, use the WASD keys!" << endl;
	cout << "How many targets would you like (1-10)?  ";
	cin.getline(targetNum, 2);
	cout << endl;

	//if it is digit
	if (!isdigit(targetNum[0]))
	{
		IsEscHit = true;
		cout << "That is not a valid number, try again.";
	}
	
	//is it less than 1 or greater than 10?
	if (targetNum[0] < 1 || targetNum[0] > 10)
	{
		IsEscHit = true;
		cout << "That is not a valid number, try again.";
	}
		
	
	//implement the snake	
	snake.type = b2_dynamicBody;
	snake.position.Set(4.0f, 5.0f);
	snakeBody = world.CreateBody(&snake);

	//implement target	
	target.type = b2_staticBody;
	target.position.Set(randomPosition(), randomPosition());
	b2Body* targetBody = world.CreateBody(&target);
	
	//target position (do it before the loop)
	b2Vec2 targetPosition = targetBody->GetPosition();

	//continous loop
	sf::RenderWindow window(sf::VideoMode(600, 400), "Brandon Hawke window");

	// run the program as long as the window is open
	while (window.isOpen() && objectsHit != 2)
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
		processInput();


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

		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//screen color
		window.clear(sf::Color::Black);

		//shapes   		
		//square
		sf::CircleShape square(50.f, 4);
		square.setFillColor(sf::Color(65, 59, 103));
		square.move(snakePosition.x, snakePosition.y);
		square.rotate(45);
		square.scale(.50, .50);
		window.draw(square);			


		window.display();
	}

	return 0;
}
	
	

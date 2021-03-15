#pragma once
//declare the functions for the homework 

//updates the physical world
void update();

//displays position of target and player
void display(b2Vec2 snakePosition, b2Vec2 targetPosition);

//moves target to new location 
void moveTarget(float& xPos, float& yPos, b2Vec2 targetPosition);

//additional function 
int randomPosition();

//HW3 functions
typedef void (*ApplyForces)(b2Body&); 

void processInput();

//move the player
void ApplyForceUp(b2Body& player);
void ApplyForceDown(b2Body& player);
void ApplyForceLeft(b2Body& player);
void ApplyForceRight(b2Body& player);
void StopMoving(b2Body& player);
void ReverseGravity(b2World& world);

//target functions
void setupTarget(int cnt);
bool selectNextTarget(int counter);

//introduce game to the player
int main();

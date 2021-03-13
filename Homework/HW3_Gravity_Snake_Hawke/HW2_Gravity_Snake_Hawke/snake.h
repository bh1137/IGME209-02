#pragma once
//declare the functions for the homework 

//updates the physical world
void update();

//displays position of target and player
void display(b2Vec2 snakePosition, b2Vec2 targetPosition);

//moves target to new location 
void moveTarget(float& xPos, float& yPos, b2Vec2 targetPosition);

//moves plater
void applyForces(b2Body* snake);

//additional function 
int randomPosition();

//HW3 variables
b2Vec2 TargetLocations[];
b2Vec2 currentLocation;
typedef;

//HW3 functions 

void processInput();

void ApplyForceUp(b2Body& player);

void ApplyForceDown(b2Body& player);

void ApplyForceLeft(b2Body& player);

void ApplyForceRight(b2Body& player);

void StopMoving(b2Body& player);

void ReverseGravity(b2World& world);

bool setupTarget(int cnt);

bool selectNextTarget();

//introduce game to the player
int main();

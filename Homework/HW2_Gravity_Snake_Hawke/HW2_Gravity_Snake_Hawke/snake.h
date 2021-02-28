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

//introduce game to the player
int main();

//additional function 
int randomPosition();
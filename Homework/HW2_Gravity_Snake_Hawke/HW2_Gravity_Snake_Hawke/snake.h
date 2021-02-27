#pragma once
//declare the functions for the homework 

//updates the physical world
void update();

//displays position of target and player
void display();

//moves target to new location 
void applyForces(float& xPos, float& yPos);

//introduce game to the player
int main();

//additional function 
int randomPosition();
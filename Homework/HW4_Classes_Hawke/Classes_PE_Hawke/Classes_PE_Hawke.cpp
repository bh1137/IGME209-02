// Classes_PE_Hawke.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h";
#include "Fighter.h"
using namespace std;

//for memory leaks testing
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
    ///~~~~~~~~~~~~~~ PART 1 ~~~~~~~~~~~~~~~~~~~~~~~~~
    //create a local variable with default constructor  
    Player blank = Player();    
   
    //create a local variable with parameterized constuctor 
    const char* name = "Satou Kazuma";
    int strength = 12;
    int charisma = 40;
    int intelligence = 65;
    Player kazuma = Player(name,strength,charisma,intelligence);    

    //create a variable to the heap default constructor 
    Player* test2 = new Player();

    //create a variable to the heap parameterized constructor 
    Player* jotaro = new Player("Jotaro Kujo", 50, 20, 69);

    //Print out the 4 player classes
    //local default 
    blank.printPlayer();       
    cout << "" << endl; //add some space 

    //local parameterized
    kazuma.printPlayer(); 
    cout << "" << endl; //add some space 

    //heap object default
    test2->printPlayer();
    cout << "" << endl; //add some space 

    //heap object parameterized 
    jotaro->printPlayer();
    cout << "" << endl; //add some space 

    //delete the heap objects
    delete test2;
    delete jotaro;

    ///~~~~~~~~~~~~~~ PART 2 ~~~~~~~~~~~~~~~~~~~~~~~~~
    //create a local fighter with default constructor  
    Fighter fighter1 = Fighter();

    //crete a fighter to the heap paramterized constructor 
    Fighter* rukia = new Fighter("Rukia Kuchiki", 60, 35, 45, "Exorcism");

    //print our the stats
    fighter1.printFighter();
    cout << "" << endl; //add some space
    rukia->printFighter();

    //delete heap objects 
    delete rukia;

    ///~~~~~~~~~~~~~~ PART 3 ~~~~~~~~~~~~~~~~~~~~~~~~~
    //making some space 
    cout << endl;
    cout << endl;
    cout << "Random Anime Tournament..." << endl;
    cout << endl;

    //make ten 10 players (5 players 5 fighters) and put them in an array 
    Player* battlers[10];

    //int for while loop
    int playersLeft = 10;


    //make names array 
    const char* battleNames[10] =
    {
        "Yoshikage Kira",
        "Rukia Kuchiki",
        "Levi Ackerman",
        "Lalatina Dustiness Ford",
        "Centorea Shianus",
        "Stephanie Dola",
        "Dio Brando",
        "Reigen Arataka",
        "Saiki Kusuo",
        "Edelgard Von Hresvelg" 
    };

    //make loop for player generation
    for (int i = 0; i < 10; i++)
    {
        //random generator 
        int ranNumber = rand() & 1;
        
        //make a player
        if (ranNumber == 0)
        {
            Player* player= new Player(battleNames[i], 50, 20, 69);

            //add to array 
            battlers[i] = player;
        }
        else if (ranNumber == 1)
        {
            Fighter* fighter = new Fighter(battleNames[i], 60, 35, 45, "Exorcism");

            //add to array 
            battlers[i] = fighter;
        }
    }

    //make loop for player battle 
    while (playersLeft != 1)
    {        
        //for battle, it will be random 
        int randomAttacker = rand() % 10;
        int randomVictim = rand() % 10;

        // 1. check to see if battler is null 
        if (battlers[randomAttacker] == nullptr)
        {
            //1A. Then reroll
            randomAttacker = rand() % 10;
        }
        //IT IS NOT NULL 
        else
        {
            //2. check to see if victim is null or same as the random attacker
            if (battlers[randomVictim] == nullptr || randomVictim == randomAttacker)
            {
                //2B. Then reroll victim 
                randomVictim = rand() % 10;
            }
            //IT IS ALSO NOT NULL
            else
            {
                //engage battle
                battlers[randomAttacker]->Attack(battlers[randomVictim]);

                //victim becomes null
                battlers[randomVictim] = nullptr;
                
                //subtract from players left 
                playersLeft--;
            }
        }

    }
    
    //finally make a loop that deletes all players
    for (int i = 0; i < 10; i++)
    {
        if (battlers[i] != nullptr)
        {
            battlers[i] = nullptr;
        }
        delete battlers[i];
    }
    _CrtDumpMemoryLeaks(); //memory leak testing 
}



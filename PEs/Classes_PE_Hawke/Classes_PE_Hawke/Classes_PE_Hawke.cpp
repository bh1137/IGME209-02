// Classes_PE_Hawke.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h";
using namespace std;

int main()
{
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

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

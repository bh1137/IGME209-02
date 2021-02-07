// Functions_Hawke.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std; //to stop using std constantly 
#include "functions.h" //added the header to the .cpp file 


int main()
{
    //add reference to PrintName
    PrintName();
}

//function for PE 
//(if put above main, works without header, thus below main to test out the functions.h header
void PrintName()
{
    //print my name 
    cout << "Brandon Hawke!\n";
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

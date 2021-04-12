// RecursionPE_Hawke.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//methods 
int IterationFunction(int seatNumber, const int nepHands, const int omiHands)
{
    int product;
    int finalHands = 0;

    while (seatNumber >= 1)
    {
        product = seatNumber % 2;

        //test for odd or even seat 
        //even
        if (product == 0)
        {
            finalHands += 4;
        }
        else if (product == 1)
        {
            finalHands += 3; 
        }

        seatNumber--;
    }
    return finalHands;
}

int RecursiveFunction(int seatNumber, const int nepHands, const int omiHands)
{
    // even or odd
    int product = seatNumber % 2;

    //if 0
    if (seatNumber < 1)
    {
        return 0;
    }    
    //even 
    if (product == 0)
    {
        return 4 + RecursiveFunction(seatNumber - 1, nepHands, omiHands);
    }
    //odd
    else if (product == 1)
    {
        return 3 + RecursiveFunction(seatNumber - 1, nepHands, omiHands);
    }
}

int FormulaFunction(int seatNumber, const int nepHands, const int omiHands)
{
    //odd and even seats
    int odd = 0;
    int even = 0;
    //for loop to get even and odd seats 
    for (int i = 1; i < seatNumber+1; i++)
    {
        //modulus for even 
        if (i % 2 == 0)
        {
            even++;
        }
        else if (i % 2 == 1)
        {
            odd++;
        }
    }

    //formula 
    return (4 * even) + (3 * odd);
}

int main()
{
    //aliens
    const int NeptunianHands = 4; // even seats
    const int OmicronianHands = 3; //odd seats
        
    //iteration method 
    int iterativeSeats = 10;
    int itHands = IterationFunction(iterativeSeats,NeptunianHands, OmicronianHands);
    cout << itHands << " Hands with " << iterativeSeats << " Seats." << endl;

    //recursive method 
    int recursiveSeats = 15;
    int recHands = RecursiveFunction(recursiveSeats, NeptunianHands, OmicronianHands);
    cout << recHands << " Hands with " << recursiveSeats << " Seats." << endl;

    //formula method 
    int formulaSeats = 50;
    int formHands = FormulaFunction(formulaSeats, NeptunianHands, OmicronianHands);
    cout << formHands << " Hands with " << formulaSeats << " Seats." << endl;
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

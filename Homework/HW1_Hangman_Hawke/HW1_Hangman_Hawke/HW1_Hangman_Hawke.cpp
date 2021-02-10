// HW1_Hangman_Hawke.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include "hangman.h" //link header to the main .ccp

int main()
{  
    //strings for the gallows
    char horizontal[9] = "________";
    char vertical[8] = "|||||||";
    char hangman[9] = "|O|/\\|/\\"; //going down 5 vertical poles

    //declare strings for game 
    //word-to-be-guessed
    char word[10] = "plusultra";
    //correctly guessed letters 
    char correctLetters[10] = "_________";
    //incorrectly guessed letters
    char incorrectLetters[27]= "                          ";
    //guessed letters
    char guessedLetters[2];

    //integer for the guess number limit
    int guessLimit = 8;       

    //Opening to the game 
    cout << "Let's play a game of Hangman!\n";
    cout << "Your word has " << strlen(word);
    cout << " letters in it. Good Luck!\n";
   
    //Show gallows
    ShowGallows(guessLimit, hangman, horizontal, vertical);
    
    //wrong guesses 
    cout << "Wrong Guesses: " << "\n";        

    //correctly guessed 
    cout << "Word to Solve: " << correctLetters << "\n";

    //while loop
    while (guessLimit != 0)
    {        
        //prompt 
        cout << "What letter would you like to guess? ";
        //get answer
        cin.getline(guessedLetters, 2);
        //show guessed letter
        cout << "\nGuess: " << guessedLetters << "\n";

        //show solved...
        //...and lower limit, if applicable
        if (!ShowSolved(word, guessedLetters, correctLetters, incorrectLetters))
        {
            //lower the guess limit
            guessLimit--;

        }        

        //test show gallows        
        ShowGallows(guessLimit, hangman, horizontal, vertical);

        //wrong guesses 
        cout << "Wrong Guesses: ";
        //for loop/if statement 
        for (int i = 0; i < strlen(incorrectLetters); i++)
        {
            if (incorrectLetters[i] != '\0')
            {
                cout << incorrectLetters[i];
            }
        }
        cout << "\n";

        //correctly guessed 
        cout << "Word to Solve: " << correctLetters << "\n";

        //check for game end (winning)
        if (strcmp(correctLetters, "plusultra") == 0)
        {
            cout << "\nCongratulations! You have won the game.\nGAMEOVER...\n";
            break;
        }
        
    }
    
    //game ending message (lost)
    if (guessLimit == 0)
    {
        cout << "\nYou were not able to solve the word in the time. Better luck next time.\nGAMEOVER...\n";
    }
    

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

// FileIO_Hawke.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream> //file IO
#include <string>
using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    //output
    ofstream outFile;
    outFile.open("namegame.txt");

    if (outFile.is_open())
    {
        //name game 
        outFile << "Cranjus McBasketball\n";
        outFile << "Ricktyticky Bobbywobbin\n";
        outFile << "Dr. Shrimp Puerto Rico\n";
        outFile << "Secret Agent Randy Beans\n";
        outFile << "Diddy Doodat\n";
        outFile << "Ja'Crispy Vulcano\n";
        outFile << "Mary Beth BethBeth\n";
        outFile << "Detective Bluto Mindpretzel\n";
        outFile << "Melt Gibsont\n";
        outFile << "High Priestess Gabagool\n";
        outFile << "Holden Afart\n";

        //close
        outFile.close();
    }

    //input
    ifstream inFile("namegame.txt", ios::binary);
    string line;   

    if (inFile.is_open())
    {
        //length
        inFile.seekg(0, ios::end);
        int length = (int)inFile.tellg();
        inFile.seekg(0, ios::beg);

        //array 
        char* fileContents = new char[length + 1];
        inFile.read(fileContents, length);
        fileContents[length] = 0;

        inFile.close();

        //read lines
        for (int i = 0; i < length; i++)
        {
            cout << fileContents[i];
        }
        
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

// C_Strings_Hawke.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
using namespace std; //used to decrease std redundancy 

int main()
{
	//start with declaring and defining the C string name 
	char poppins1[100] = "supercalifraglistic";

	//next find the length of the string
	cout << "There are...";
	cout << strlen(poppins1);
	cout << " letters in the string!\n";

	//now declare and define the second C string name 
	char poppins2[100] = "expialidocious";

	//add a line break space 
	cout << "\n";

	//add poppins2 to poppins1
	strcat_s(poppins1, poppins2);

	//print to the console 
	cout << poppins1;
	cout << "\n";

	//make variables for for loop section 
	int poppinsNum = strlen(poppins1);
	int iNum = 0;

	//for loop to find the # of i's in the poppins string
	for (char letter : poppins1)
	{
		//if statement for the loop
		if (letter == 'i')
		{
			iNum++;
		}
	}
	cout << "\n";
	cout << iNum;
	cout << "\n";
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

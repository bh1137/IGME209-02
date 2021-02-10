#include "hangman.h"
#include <iostream>
using namespace std;



//show gallows
void ShowGallows(int guessLimit, char hangman[], char horizontal[], char vertical[])
{	
	//draw the horizontal bar first 
	cout << horizontal << "\n";
	
	//int variable for vert length 
	int vertLength = strlen(vertical);

	//there are 8 initial guesses
	//guess will be subtracted before this method is called 
	//Zero is game over 
	switch (guessLimit)
	{
		case 8:
		{
			//draw gallows normally			
			//for loop for vertical bar 
			for (int i = 0; i < vertLength; i++)
			{
				//draw...then space
				cout << vertical[i] << "\n";								
			}
			//break
			break;
		}

		case 7:
		{
			//draw one part of the vertical
			cout << vertical[0];

			//draw rope of the hangman 
			cout << "    " << hangman[0] << "\n";

			//draw rest of the vertical 			
			for (int i = 1; i < vertLength; i++)
			{
				//draw...then space
				cout << vertical[i] << "\n";
			}
			//break
			break;
		}

		case 6:
		{
			//draw first part of the vertical
			cout << vertical[0];

			//draw rope of the hangman 
			cout << "    " << hangman[0] << "\n";

			//draw second part of the vertical
			cout << vertical[1];

			//draw head of the hangman 
			cout << "    " << hangman[1] << "\n";

			//draw rest of the vertical 			
			for (int i = 2; i < vertLength; i++)
			{
				//draw...then space
				cout << vertical[i] << "\n";
			}
			//break
			break;
		}

		case 5:
		{
			//draw first part of the vertical
			cout << vertical[0];

			//draw rope of the hangman 
			cout << "    " << hangman[0] << "\n";

			//draw second part of the vertical
			cout << vertical[1];

			//draw head of the hangman 
			cout << "    " << hangman[1] << "\n";

			//draw third part of the vertical
			cout << vertical[2];

			//draw body of the hangman 
			cout << "    " << hangman[2] << "\n";

			//draw rest of the vertical 			
			for (int i = 3; i < vertLength; i++)
			{
				//draw...then space
				cout << vertical[i] << "\n";
			}
			//break
			break;
		}

		case 4:
		{
			//draw first part of the vertical
			cout << vertical[0];

			//draw rope of the hangman 
			cout << "    " << hangman[0] << "\n";

			//draw second part of the vertical
			cout << vertical[1];

			//draw head of the hangman 
			cout << "    " << hangman[1] << "\n";

			//draw third part of the vertical
			cout << vertical[2];

			//draw left arm and body of the hangman 
			cout << "   " << hangman[3] << hangman[2] << "\n";
			

			//draw rest of the vertical 			
			for (int i = 3; i < vertLength; i++)
			{
				//draw...then space
				cout << vertical[i] << "\n";
			}
			//break
			break;
		}

		case 3:
		{
			//draw first part of the vertical
			cout << vertical[0];

			//draw rope of the hangman 
			cout << "    " << hangman[0] << "\n";

			//draw second part of the vertical
			cout << vertical[1];

			//draw head of the hangman 
			cout << "    " << hangman[1] << "\n";

			//draw third part of the vertical
			cout << vertical[2];

			//draw left arm, body, and right arm of the hangman 
			cout << "   " << hangman[3] << hangman[2] << hangman[4] << "\n";


			//draw rest of the vertical 			
			for (int i = 3; i < vertLength; i++)
			{
				//draw...then space
				cout << vertical[i] << "\n";
			}
			//break
			break;
		}

		case 2:
		{
			//draw first part of the vertical
			cout << vertical[0];

			//draw rope of the hangman 
			cout << "    " << hangman[0] << "\n";

			//draw second part of the vertical
			cout << vertical[1];

			//draw head of the hangman 
			cout << "    " << hangman[1] << "\n";

			//draw third part of the vertical
			cout << vertical[2];

			//draw left arm, body, and right arm of the hangman 
			cout << "   " << hangman[3] << hangman[2] << hangman[4] << "\n";

			//draw fourth part of the vertical
			cout << vertical[3];

			//draw waist of the hangman 
			cout << "    " << hangman[5] << "\n";

			//draw rest of the vertical 			
			for (int i = 4; i < vertLength; i++)
			{
				//draw...then space
				cout << vertical[i] << "\n";
			}
			//break
			break;
		}

		case 1:
		{
			//draw first part of the vertical
			cout << vertical[0];

			//draw rope of the hangman 
			cout << "    " << hangman[0] << "\n";

			//draw second part of the vertical
			cout << vertical[1];

			//draw head of the hangman 
			cout << "    " << hangman[1] << "\n";

			//draw third part of the vertical
			cout << vertical[2];

			//draw left arm, body, and right arm of the hangman 
			cout << "   " << hangman[3] << hangman[2] << hangman[4] << "\n";

			//draw fourth part of the vertical
			cout << vertical[3];

			//draw waist of the hangman 
			cout << "    " << hangman[5] << "\n";

			//draw fifth part of the vertical
			cout << vertical[4];

			//draw left leg of the hangaman
			cout << "   " << hangman[6] << "\n";

			//draw rest of the vertical 			
			for (int i = 4; i < vertLength; i++)
			{
				//draw...then space
				cout << vertical[i] << "\n";
			}
			//break
			break;
		}

		case 0:
		{
			//draw first part of the vertical
			cout << vertical[0];

			//draw rope of the hangman 
			cout << "    " << hangman[0] << "\n";

			//draw second part of the vertical
			cout << vertical[1];

			//draw head of the hangman 
			cout << "    " << hangman[1] << "\n";

			//draw third part of the vertical
			cout << vertical[2];

			//draw left arm, body, and right arm of the hangman 
			cout << "   " << hangman[3] << hangman[2] << hangman[4] << "\n";

			//draw fourth part of the vertical
			cout << vertical[3];

			//draw waist of the hangman 
			cout << "    " << hangman[5] << "\n";

			//draw fifth part of the vertical
			cout << vertical[4];

			//draw both legs  of the hangaman
			cout << "   " << hangman[6] << " " << hangman[7] << "\n";

			//draw rest of the vertical 			
			for (int i = 4; i < vertLength; i++)
			{
				//draw...then space
				cout << vertical[i] << "\n";
			}
			//break
			break;
		}

		default:
		{
			cout << "Just here for code to be neat!";
			break;
		}
	}
}

//show solved
bool ShowSolved(char word[], char guesses[], char correctlyguessed[], char incorrectlyguessed[])
{
	//bool for loop
	bool IsNotCorrect = false;

	//check the the guess
	for (int i = 0; i < strlen(guesses); i++)
	{
		//for loop for the word to be guessed 
		for (int j = 0; j < strlen(word); j++)
		{
			//actual if statement to check if the letter is a good guess
			if (guesses[i] == word[j])
			{
				correctlyguessed[j] = guesses[i];
				IsNotCorrect = true;								
			}
		}
	}

	//if no letter is present
	if (!IsNotCorrect)
	{
		for (int i = 0; i < strlen(incorrectlyguessed); i++)
		{		
			//for duplicates
			if (incorrectlyguessed[i] == guesses[0])
			{
				cout << "Sorry, But that letter has already been guessed. Try Again!\n";

				return true; //while still an incorrect guess, this allows second chance to the player
			}
			//for incorrect guesses in general
			if (incorrectlyguessed[i] == ' ')
			{
				//display message 
				cout << "\nSorry, Try Again!\n";

				//add to incorrect array
				incorrectlyguessed[i] = guesses[0];
				
				return false;
			}			
		}
		
	}
	else
	{
		//display correct message
		cout << "\nNice Guess!\n";

		return true;
	}
}

//show solved
//void ShowSolved(char word[], char guesses[], char correctlyguessed[])
//{
//	//bool for loop
//	bool IsNotCorrect = false;
//
//	//check the the guess
//	for (int i = 0; i < strlen(guesses); i++)
//	{
//		//for loop for the word to be guessed 
//		for (int j = 0; j < strlen(word); j++)
//		{
//			//actual if statement to check if the letter is a good guess
//			if (guesses[i] == word[j])
//			{
//				correctlyguessed[j] = guesses[i];
//				IsNotCorrect = true;
//			}
//		}
//	}
//
//	//if no letter is present
//	if (!IsNotCorrect)
//	{
//
//	}
//}
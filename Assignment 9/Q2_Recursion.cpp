//Kalli Bonin
//Question 2 - Guess a Number - Recursion

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

void MakeAGuess(int lowest, int highest, int counter)
{
	int guessed = (lowest+highest)/2;
	char response = ' ';
	
	cout << "Is your number " << guessed << "?" << endl;
	
	cout << "Enter (Y)es, (L)ower, (H)igher: ";
	cin >> response;
	
	//enter two lines
	cout << endl << endl;
	
	switch (response)
		{
			case 'Y':
				cout << "Yay, I correctly guessed your secret number in " 
					 << counter << " guesses!" << endl;
				break;
			case 'L':
				if(lowest >= highest)
				{
					cout << "You are cheating!" << endl;
					break;
				}
				MakeAGuess(lowest, guessed-1, counter+1);
				break;
			case 'H':
				if(lowest >= highest)
				{
					cout << "You are cheating!" << endl;
					break;
				}
				MakeAGuess(guessed+1, highest, counter+1);
				break;
			default: 
				cout << "ERROR: Invalid Response" << endl;
				break;
		}
		
		//if the upper and lower bounds are equal and the response is not yes,
		//the user is not being truthful
		
}

int main()
{  
	cout << "Recursive Guess-A-Number" << endl
		 << "Think of a number which this program will try to guess." <<endl
		 << "Enter the lowest possible number: ";
	
	int lowest = 0;
	cin >> lowest;
	
	int highest = -1;
	while (highest < lowest)
	{
		cout << "Enter the highest possible number: ";
		
		cin >> highest;
		cout << endl;
	}
	
	int counter = 1;
	
	MakeAGuess(lowest, highest, counter);
	
}

/*
	Recursive Guess-A-Number
	Think of a number which this program will try to guess.
	Enter the lowest possible number: 1
	Enter the highest possible number: 100
	
	Is your number 50?
	Enter (Y)es, (L)ower, (H)igher: H
	
	
	Is your number 75?
	Enter (Y)es, (L)ower, (H)igher: H
	
	
	Is your number 88?
	Enter (Y)es, (L)ower, (H)igher: H
	
	
	Is your number 94?
	Enter (Y)es, (L)ower, (H)igher: H
	
	
	Is your number 97?
	Enter (Y)es, (L)ower, (H)igher: H
	
	
	Is your number 99?
	Enter (Y)es, (L)ower, (H)igher: Y
	
	
	Yay, I correctly guessed your secret number in 6 guesses!
	
	--------------------------------
	Process exited after 10.7 seconds with return value 0
	Press any key to continue . . .
*/

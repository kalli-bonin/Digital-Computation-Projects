//Kalli Bonin and Derek Broekhoven
//Question 2 - Guess a Number

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{  
	cout << "Think of a number between 1 and 7. "
		 << "Enter 'ready' when ready to start" << endl;
	
	
	string ready = " ";
	cin >> ready;
	
	if (ready == "ready")
	{
		bool completed = false;
		int guess = 4;
		
		for (int i = 2; i >= 0; i--)
		{
			cout << "Is the number " << guess << "?" << endl;
		
			cout << "Enter y if the guess is correct."  << endl
				 << "Enter h if the computer should guess higher." << endl
				 << "Enter l if the computer should guess lower. ";
			 
			char response = ' ';
			cin >> response;
			
			
			
			if (response == 'y')
			{
				cout << "Your secret number is " << guess;
				completed = true;
				break;
			}
			else if (response == 'h')
				guess += i;
			else if (response == 'l')
				guess -= i;
			else
			{
				cout << "Not a valid response.";
				completed = true;
				break;
			}
					
		}
		
		if (completed == false)
			cout << "User was not truthful.";
	}
	else
		cout << "Not valid confirmation.";
}

/*number guessed correctly in two tries or less

	Think of a number between 1 and 7. Enter 'ready' when ready to start
	ready
	Is the number 4?
	Enter y if the guess is correct.
	Enter h if the computer should guess higher.
	Enter l if the computer should guess lower. h
	Is the number 6?
	Enter y if the guess is correct.
	Enter h if the computer should guess higher.
	Enter l if the computer should guess lower. y
	Your secret number is 6
	--------------------------------
	Process exited after 32.03 seconds with return value 0
	Press any key to continue . . .
*/

/*number guessed correctly onn third try
	
	Think of a number between 1 and 7. Enter 'ready' when ready to start
	ready
	Is the number 4?
	Enter y if the guess is correct.
	Enter h if the computer should guess higher.
	Enter l if the computer should guess lower. h
	Is the number 6?
	Enter y if the guess is correct.
	Enter h if the computer should guess higher.
	Enter l if the computer should guess lower. h
	Is the number 7?
	Enter y if the guess is correct.
	Enter h if the computer should guess higher.
	Enter l if the computer should guess lower. y
	Your secret number is 7
	--------------------------------
	Process exited after 9.759 seconds with return value 0
	Press any key to continue . . .	
*/

/*user is not truthful

	Think of a number between 1 and 7. Enter 'ready' when ready to start
	ready
	Is the number 4?
	Enter y if the guess is correct.
	Enter h if the computer should guess higher.
	Enter l if the computer should guess lower. h
	Is the number 6?
	Enter y if the guess is correct.
	Enter h if the computer should guess higher.
	Enter l if the computer should guess lower. h
	Is the number 7?
	Enter y if the guess is correct.
	Enter h if the computer should guess higher.
	Enter l if the computer should guess lower. h
	User was not truthful.
	--------------------------------
	Process exited after 6.015 seconds with return value 0
	Press any key to continue . . .	
*/

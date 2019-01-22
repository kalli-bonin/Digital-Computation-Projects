//Kalli Bonin and Derek Broekhoven
//Question 1 - Reformat a Number

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{  
	cout << "Input an integer whose magnitude is less than 1,000,000. ";
	
	int input = 0;
	cin >> input;
	
	int output1 = 0, output2 = 1000;
	
	if ( abs(input) / 1000 < 1)
		cout << input;
	
	else if ( abs(input) / 1000000 < 1)
	{
		output1 = input / 1000;
		output2 = input % 1000;
		output2 = abs(output2);
	}
	else
		cout << "Inputted number is too large.";
	
	if (output1 != 0)
	{
		cout << output1 << "," ;
		if (output2 < 10)
			cout << "00" << output2;
		else if (output2 < 100)
			cout << "0" << output2;
		else
			cout << output2;
	}
		
	
	
	return EXIT_SUCCESS;
}

/*
	Input an integer whose magnitude is less than 1,000,000. -1001
	-1,001
	--------------------------------
	Process exited after 2.667 seconds with return value 0
	Press any key to continue . . .
*/

/*
	Input an integer whose magnitude is less than 1,000,000. 4
	4
	--------------------------------
	Process exited after 1.337 seconds with return value 0
	Press any key to continue . . .
*/

/*
	Input an integer whose magnitude is less than 1,000,000. 101200
	101,200
	--------------------------------
	Process exited after 3.529 seconds with return value 0
	Press any key to continue . . .
*/


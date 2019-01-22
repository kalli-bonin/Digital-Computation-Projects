//Kalli Bonin and Brian Chang
//Question 1 - Finding Roots

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{  

	//set lowestVal to much higher than the final answer
	double lowestVal = 100, root = 0;
	
	
	cout << "The roots are ";

	for (double i = -5; i <= 5; i = i+0.0001)
	{
		//calculate the value of the function at i
		double function = (3*pow(i,5) + 11*pow(i,4) + 12*pow(i,3) - 7*i + 5);
		
		//check to see if the value we are at now is closer than our last 
		//lowest value
		if( abs(function) < abs(lowestVal) )
		{
			lowestVal = function;
			root = i;
		}
	}
	
	//output our calculated root
	cout << root << endl;
}

/*
	The roots are -2.09928
	--------------------------------
	Process exited after 0.06724 seconds with return value 0
	Press any key to continue . . .
*/

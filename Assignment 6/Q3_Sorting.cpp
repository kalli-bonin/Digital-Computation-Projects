//Kalli Bonin and Alexander Dineen
//Question 3 - Sorting Three Numbers

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

void swap(float & a, float & b)
{
	float temp = a;
	a = b;
	b = temp;
}


bool sort_three_numbers(float & num_1, float & num_2, float & num_3)
{
	if (num_1 > num_2 && num_2 > num_3)
		return true;
	else
	{
		if(num_2 > num_1)
			swap(num_2, num_1);
		if(num_3 > num_2)
			swap(num_3, num_2);
		if(num_2 > num_1)
			swap(num_2, num_1);
		return false;
	}
}

int main()
{
	cout << "Input three numbers ";
	float num_1 = 0, num_2 = 0, num_3 = 0;
	cin >> num_1 >> num_2 >> num_3;
	
	bool sorted = sort_three_numbers(num_1, num_2, num_3);
	
	if (sorted)
		cout << "Numbers inputted are already sorted" << endl;
	
	cout << num_1 << " > " << num_2 << " > " << num_3 << endl;
}

/*
	Input three numbers 3 8 -1
	8 > 3 > -1
	
	--------------------------------
	Process exited after 3.973 seconds with return value 0
	Press any key to continue . . .

*/

/*


*/

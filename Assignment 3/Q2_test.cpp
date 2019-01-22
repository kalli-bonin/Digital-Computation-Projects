//Kalli Bonin and Brian Chang
//Question 2 - 24-Hour Clock

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{  
	int time1 = -1;
	int min1 = 60;
	
	while ( time1 < 0 || time1 >= 2400 )
	{
		min1 = time1%100;
		while ( min1 > 59 )
		{
			cout << "Enter first time: ";
			cin >> time1;
		}

	}
	
	if (time1 > 0 && time1 < 24 && min1 < 60)
		cout << "valid time";
	

		
}



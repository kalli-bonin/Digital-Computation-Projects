//Kalli Bonin and Brian Chang
//Question 2 - 24-Hour Clock

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{  
	int time1 = -1, time2 = -1;
	
	//check to see if input is a valid time
	while ( time1 < 0 || time1 >= 2400 || time1%100 > 59 )
	{
		cout << "Enter first time: ";
		cin >> time1;
	}
	
	while ( time2 < 0 || time2 >=2400 || time2%100 > 59 ) 
	{
			cout << "Enter second time: ";
			cin >> time2;
	}
	
	//convert 24hour time into hours and mins
	int hour1 = time1/100, hour2 = time2/100;
	int min1 = time1%100, min2 = time2%100;
			
	//calculate the difference in time
	int hoursBetween = hour2 - hour1;
	int minsBetween = min2 - min1;
	
	//check which time comes first and use an "absolute" value function
	if (time1 > time2)
	{
		hoursBetween *= -1;
		minsBetween *= -1;	
	}
	
	//output answer
	cout << "There are " << hoursBetween * 60 + minsBetween
		 << " minutes between the two times.";
}

/*
	Enter first time: 872
	Enter first time: 830
	Enter second time: 466
	Enter second time: 423
	There are 247 minutes between the two times.
	--------------------------------
	Process exited after 20.19 seconds with return value 0
	Press any key to continue . . .
*/

/*
	Enter first time: 1050
	Enter second time: 1120
	There are 30 minutes between the two times.
	--------------------------------
	Process exited after 13.62 seconds with return value 0
	Press any key to continue . . .
*/

/*
	Enter first time: 0000
	Enter second time: 2359
	There are 1439 minutes between the two times.
	--------------------------------
	Process exited after 13.46 seconds with return value 0
	Press any key to continue . . .
*/

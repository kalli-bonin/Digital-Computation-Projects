// Kalli Bonin

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{  
	const int RADIUS = 17;
	
	int pizzas = 0, students = 0;
	
	cout << "Enter the number of pizzas required: ";
	cin >> pizzas;
	
	cout << "Enter the number of students attending: ";
	cin >> students;
	cout << endl;
	
	if (students > 0)
	{
		//it is assumed that each student is eating an equal amount of pizza
		double surfaceArea = M_PI * RADIUS * RADIUS;
	
		cout <<"The surface area of pizza consumed by each student is "
			 << surfaceArea / students
			 << "cm^2";
	}
	else if (students < 0)
		cout << "The student input must be positive.";
	else
		cout << "There are no students who will get pizza.";
}

/*
	Enter the number of pizzas required: 22
	Enter the number of students attending: 11
	
	The surface area of pizza consumed by each student is 82.5382cm^2
	--------------------------------
	Process exited after 2.507 seconds with return value 0
	Press any key to continue . . .
*/

/*
	Enter the number of pizzas required: 5
	Enter the number of students attending: 9
	
	The surface area of pizza consumed by each student is 100.88cm^2
	--------------------------------
	Process exited after 3.724 seconds with return value 0
	Press any key to continue . . .
*/

/*
	Enter the number of pizzas required: 6
	Enter the number of students attending: 0
	
	There are no students who will get pizza.
	--------------------------------
	Process exited after 2.469 seconds with return value 0
	Press any key to continue . . .	
*/


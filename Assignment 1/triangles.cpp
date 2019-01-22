// Kalli Bonin

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{  
	//lowercase letters represent the side lengths
	double a = 0, b = 0, c = 0;
	cout << "Enter the three side lengths of a triangle: ";
	
	cin >> a >> b >> c;
	cout << endl;
	
	if ( (a || b || c) <= 0 )
		cout << "The lengths of the triangle must be greater than 0.";
	else if (a + b < c)
		cout << "This is an invalid triangle.";
	else if (b + c < a)
		cout << "This is an invalid triangle.";
	else if (a + c < b)
		cout << "This is an invalid triangle.";
		
	//the inputs form a valid triangle and we can proceed with calculations
	else
	{
		double s = (a+b+c)/2;
		
		//uppercase letters represent the angles
		double A = 0, B = 0, C = 0;
		
		//calculating angles using cosine law and convert to degrees
		A = (acos((b*b + c*c - a*a) / (2*b*c)))*180/M_PI;
		B = (acos((a*a + c*c - b*b) / (2*a*c)))*180/M_PI;
		C = (acos((a*a + b*b - c*c) / (2*a*b)))*180/M_PI;
		
		cout << "The angles according to Cosine Law are: "
			 << A << " "
			 << B << " "
			 << C << " "
			 << endl;
			 
		//calculating angles using sine law and convert to degrees
		//angle A must be used from the solving from cosine law but converted
		//back to radians
		A = A * M_PI / 180;
		B = (asin(b*sin(A)/a)) *180/M_PI;
		C = (asin(c*sin(A)/a)) *180/M_PI;
		
		//convert A back to degrees
		A = A * 180 / M_PI;
		
		cout << "The angles according to Sine Law are: "
			 << A << " "
			 << B << " "
			 << C << " "
			 << endl;
				
		//calculating and displaying area of the triangle
		cout << "Area: "
			 << sqrt(s*(s-a)*(s-b)*(s-c))
			 << endl;
		
	}
}

//to be a valid triangle, the sum of two sides must be greater than the third

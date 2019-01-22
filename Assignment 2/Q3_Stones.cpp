//Kalli Bonin and Derek Broekhoven
//Question 3 - Paving Stones

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

const double TOL_SIDE = 0.7;
const double TOL_ANGLE = 0.5;

int main()
{  
	ifstream fin("stones.txt");
	ofstream fout("shapes.txt");
	
	if (!fin || !fout)
	{
		cout << "Could not open file.";
		return EXIT_FAILURE;
	}
	
	int numStones = 0;
	fin >> numStones;
	
	for (int i = 0; i < numStones; i++)
	{
		double a = 0, b = 0, angle = 0;
		
		fin >> a >> b >> angle;
		
		if (fabs(a-b) < TOL_SIDE)
		{
			if (fabs (angle - 90) < TOL_ANGLE)
				fout << "Square" << endl;
			else
				fout << "Rhombus" << endl;
		}
		else
		{
			if (fabs (angle - 90) < TOL_ANGLE)
				fout << "Rectangle" << endl;
			else
				fout << "Parallelogram" << endl;
		}
	
	}
	
	fin.close();
	fout.close();
	
	return EXIT_SUCCESS;
}



//Kalli Bonin and Brian Chang
//Question 3 - Water Taxi

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{  
	const int SERVICE = 11;
	const double PER_KM = 2.7;
	
	ifstream fin("taxi.txt");
	ofstream fout("earnings.txt");
	
	if (!fin || !fout)
	{
		cout << "Could not open file.";
		return EXIT_FAILURE;
	}
	
	double totalDistance = 0, totalCost = 0;
	double longestTrip = 0, leastExpensive = 1e6;
	unsigned int numberTrip = 0;
	
	fout << fixed << setprecision(2)
		 << setw(4)  << "Trip"
		 << setw(8)  << "Return"
		 << setw(7)  << "Stops"
		 << setw(10) << "Distance"
		 << setw(10) << "Cost"
		 << setw(12) << "Cumulative"
		 << setw(12) << "Cumulative" << endl;
		 
	fout << setw(51) << "Distance"
	     << setw(12) << "Cost" << endl;
	
	while (fin.good())
	{
		numberTrip++;
		bool roundTrip = 0;
		fin >> roundTrip;
		
		unsigned int numberStops = 0;
		fin >> numberStops;
		
		if (numberStops > 0)
		{
			double distance = 0;
		
		
			double lastX = 0, lastY = 0;
			
			for (int i = 0; i < numberStops; i++)
			{
				double curX = 0, curY = 0;
				fin >> curX >> curY;
				
				distance += sqrt(pow(lastX-curX, 2) + pow(lastY-curY,2));
				
				lastX = curX;
				lastY = curY;
			}
			
			if (roundTrip)
				distance += sqrt(lastX*lastX + lastY*lastY);
			
			double cost = 0;
			cost = SERVICE*numberStops + distance*PER_KM;
			
			totalDistance += distance;
			totalCost += cost;
			
			if (distance > longestTrip)
				longestTrip = distance;
			if (cost < leastExpensive)
				leastExpensive = cost;
			
			fout << setw(4)  << numberTrip
			 	 << setw(8)  << roundTrip
			  	 << setw(7)  << numberStops
				 << setw(10) << distance
				 << setw(10) << cost
				 << setw(12) << totalDistance
			 	 << setw(12) << totalCost << endl;
		}
	
	}
	
	fout << "Cumulative Distance: " << totalDistance << "km" << endl
		 << "Cumulative Cost: $" << totalCost << endl
		 << "Longest Trip: " << longestTrip << "km" << endl
		 << "Least Expensive Trip: $" << leastExpensive << endl;
	
	fin.close();
	fout.close();
}



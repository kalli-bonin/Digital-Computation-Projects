//Kalli Bonin and Hashem Alnader
//Question 2 - Rabbit Season

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

int hours(int time)
{
	return time / 1e5;
}

int minutes(int time)
{	

	return (time % 10000)/100;
}

int seconds (int time)
{
	return time % 100;
}

double x_coordinate (double heading, double distance)
{
	return distance*cos(heading);
}

double y_coordinate (double heading, double distance)
{
	return distance*sin(heading);
}

int get_duration (int start_hours, int start_minutes, int start_seconds, 
				  int end_hours,   int end_minutes,   int end_seconds)
{
	int dur_hours = 0, dur_mins = 0, dur_secs = 0;
	/*
	if (end_seconds > start_seconds)
	{
		end_minutes--;
		end_seconds += 60;
	}
	
	dur_secs =  end_seconds - start_seconds;
	
	if (end_minutes > start_minutes)
	{
		end_hours--;
		end_minutes += 60;	
	}
	*/
	
	dur_hours = end_hours   - start_hours;
	dur_mins  = end_minutes - start_minutes;
	dur_secs  = end_seconds - start_seconds;
	
	return dur_hours*3600 + dur_mins*60 + dur_secs;
}


int main()
{  	
	ifstream fin("wascally_wabbits.txt");
	ofstream fout("launch_info.txt");
	
	if (!fin || !fout)
	{
		cout << "Could not open file.";
		return EXIT_FAILURE;
	}
	
	fout << fixed << setprecision(2)
		 << setw(8)  << "#Rabbit"
		 << setw(10) << "Time"
		 << setw(11) << "Coordinates"
		 << setw(10) << "Duration" << endl;
	
	int start_hours = 0, start_mins = 0, start_secs = 0;
	
	int numRabbit = 0, launchTime = 0;
	double heading = 0, distance = 0;

	while (fin >> numRabbit)
	{	
		fin >> launchTime >> heading >> distance;
		
		//convert heading from degrees into radians
		heading = heading*(M_PI/180);
		
		double x = 0, y = 0;
		int duration = 0;
		
		
		int end_hours = hours(launchTime);
		int end_mins  = minutes(launchTime);
		int end_secs  = seconds(launchTime);
		
		x = x_coordinate(heading, distance);
		y = y_coordinate(heading, distance);
		
		
		
		duration = get_duration(start_hours, start_mins, start_secs,
								end_hours, end_mins, end_secs);
		
		if (duration < 0)
			duration += 86400;	
		
		
		
		if (start_hours == 0 && start_mins == 0 && start_secs == 0)
			duration = 0;
		
		fout << setw(8) << numRabbit
			 << setfill('0') << setw(1) << end_hours << ":"
			 << setfill('0') << setw(2) << end_mins  << ":"
			 << setfill('0') << setw(2) << end_secs << setfill(' ')
			 << "(" << setw(2) << x << "," << setw(2) << y << ")"
			 << setw(10) << duration << endl;
			 
		start_hours = end_hours;
		start_mins  = end_mins;
		start_secs  = end_secs;
	}
	
	
	fin.close();
	fout.close();
}



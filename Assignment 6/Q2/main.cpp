//Kalli Bonin
//Question 2 - Drawing Flowers

#include <cmath>
#include <fstream>

using namespace std;

#include "ccc_win.h"

int ccc_win_main()
{
	int count = cwin.get_int("Enter the number of flower");
	
	int radius = 1;
	
	for (int i = 0; i < count; i++)
	{
		Point centre = cwin.get_mouse("Click on point");
	
		cwin << Circle(centre, radius)
			 << Circle(Point(centre.get_x(), centre.get_y()+radius), radius)
			 << Circle(Point(centre.get_x()+radius, centre.get_y()), radius)
			 << Circle(Point(centre.get_x(), centre.get_y()-radius), radius)
			 << Circle(Point(centre.get_x()-radius, centre.get_y()), radius)
			 
			 << Circle(Point(radius*sin(M_PI/4)+centre.get_x(), 
			 	radius*cos(M_PI/4)+centre.get_y()), radius)
			 << Circle(Point(radius*sin(3*M_PI/4)+centre.get_x(), 
			 	radius*cos(3*M_PI/4)+centre.get_y()), radius)
			 << Circle(Point(radius*sin(5*M_PI/4)+centre.get_x(), 
			 	radius*cos(5*M_PI/4)+centre.get_y()), radius)
			 << Circle(Point(radius*sin(7*M_PI/4)+centre.get_x(), 
			 	radius*cos(7*M_PI/4)+centre.get_y()), radius)
			 
			 << Line(centre, Point(centre.get_x(),centre.get_y()-6))
			 << Line(Point(centre.get_x(),centre.get_y()-4), Point(centre.get_x()+1,centre.get_y()-3))
			 << Line(Point(centre.get_x(),centre.get_y()-5), Point(centre.get_x()+1,centre.get_y()-3));
	}
}

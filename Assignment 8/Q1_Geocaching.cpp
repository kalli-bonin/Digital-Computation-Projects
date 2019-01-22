//Kalli Bonin and Amy Dwyer
//Question 1 - Robotic Geocaching

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

void read_elevations (ifstream & fin, int elevations[25][50])
{
	for (int col = 0; col < 50; col++)
	{
		for (int row = 0; row < 25; row++)
			fin >> elevations[row][col];
	}
}

void read_caches (ifstream & fin, bool cache[25][50])
{
	for (int col = 0; col < 50; col++)
	{
		for (int row = 0; row < 25; row++)
			fin >> cache[row][col];
	}
}

double energy_required (int elevation[25][50], int startx, int starty,
					  int endx, int endy)
{
	int x = (endx-startx)*100;
	int y = (endy-starty)*100;
	int z = elevation[endx][endy] - elevation[startx][starty];
	
	return sqrt(x*x + y*y + z*z) + 7*z;
}

bool find_next (int elevation[25][50], bool cache[25][50], int curx, int cury, 
				int & cacheCount, int coordinates[2][25], int i)
{
	double curEnergy = 0, minEnergy = 1000000;
	
	cacheCount = 0;
	
	for (int col = 0; col < 50; col++)
	{
		for (int row = 0; row < 25; row++)
		{
			if (cache[row][col] == 1)
			{
				curEnergy = energy_required(elevation, curx, cury, row, col);
				if (curEnergy < minEnergy)
				{
					minEnergy = curEnergy;
					coordinates[0][i] = row;
					coordinates[1][i] = col;	
				}
				cacheCount++;
			}
		}
	}
	
	//remove geocache location from array
	if (cacheCount > 0)
	{
		cache[endx][endy] = 0;
		cacheCount--;
		return true;
	}
	else
		return false;
}

void optimal_path(int elevations[25][50], bool cache[25][50], 
				  int coordinates[2][cacheCount], int cacheCount)
{
	for (int i = 0; i < cacheCount; i++)
		find_next(elevations, cache, startx, starty, cacheCount, coordinates, i);
}

void output_path (ofstream & fout, int coordinates[2][25])
{
	for (int row = 0; i < totalCache; i++)
	{
		for (int col = 0; i < 2; col++)
			fout << coordinates[col][row];
	}
}
			

int main()
{
	ifstream fin_ele("elevations.txt");
	ifstream fin_cac("caches.txt");
	ofstream fout("travel.txt");
	
	if (!fin_ele || !fin_cac || !fout)
	{
		cout << "Could not open file.";
		return EXIT_FAILURE;
	}
	
	int elevations[25][50];
	bool cache[25][50];
	
	int cacheCount = 0;
	
	read_elevation(fin_ele, elevations);
	read_caches(fin_cac, cache);
	
	int startx = 0, starty = 0;
	
	
	int coordinates[2][25];

	fin_ele.close();
	fin_cac.close();
	fout.close();
}


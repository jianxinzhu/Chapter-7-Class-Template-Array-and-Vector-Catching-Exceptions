/*  name: jianxin zhu
    date: july/20/2020
    
    //copy form geeksforgeeks.com
    website: https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/
*/


#include<iostream>
#include<iomanip>
using namespace std;

const int SIZE = 8;

int solveKTtil(int x, int y, int movei, int sol[SIZE][SIZE], int xMove[], int yMove[]);

int isSafe(int x, int y, int sol[SIZE][SIZE])
{
	return(x >= 0 && x < SIZE && y >= 0 && y < SIZE && sol[x][y] == -1);
}

void printSolution(int sol[SIZE][SIZE])
{
	for (int x = 0; x < SIZE; x++)
	{
		for (int y = 0; y < SIZE; y++)
		{
			cout << " " << setw(2) << sol[x][y] << " ";
		}

		cout << endl;
	}
}

int solveKT()
{
	int sol[SIZE][SIZE];

	for (int x = 0; x < SIZE; x++)
	{
		for (int y = 0; y < SIZE; y++)
		{
			sol[x][y] = -1;
		}
	}

	int xMove[8] = { 2,1,-1,-2,-2,-1,1,2 };
	int yMove[8] = { 1,2,2,1,-1,-2,-2,-1 };

	sol[0][0] = 0;

	if (solveKTtil(0, 0, 1, sol, xMove, yMove) == 0)
	{
		cout << "Solution does not exist" << endl;
		return 0;
	}
	else
	{
		printSolution(sol);
	}
}

int solveKTtil(int x, int y, int movei, int sol[SIZE][SIZE], int xMove[], int yMove[])
{
	int k, next_x, next_y;
	if (movei == SIZE * SIZE)
	{
		return 1;
	}
	for (k = 0; k < 8; k++)
	{
		next_x = x + xMove[k];
		next_y = y + yMove[k];

		if (isSafe(next_x, next_y, sol))
		{
			sol[next_x][next_y] = movei;
			if (solveKTtil(next_x, next_y, movei + 1, sol, xMove, yMove) == 1)
			{
				return 1;
			}
			else
			{
				sol[next_x][next_y] = -1;
			}
		}
	}
	return 0;
}

int main()
{
	solveKT();
	return 0;
}

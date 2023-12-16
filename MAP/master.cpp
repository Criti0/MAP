#include <iostream>
#include <iomanip>
#define N 8

int turaCal()
{
	int sol[N][N];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			sol[0][0] = -1;
		}
	}

	int iMutare[8] = { 2,1,-1,-2,-2,-1,1,2 };
	int jMutare[8] = { 1,2,2,1,-1,-2,-2,-1 };

	sol[0][0] = 0;

	return 1;
}

int main()
{

	return 0;
}
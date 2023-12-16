#include <iostream>
#include <iomanip>
using namespace std;
#define N 8

int singur(int i, int j, int sol[N][N])
{
	return(i >= 0 && i < N && j >= 0 && j < N && sol[i][j] == -1);
}

void afisare(int sol[N][N])
{
	for(int i=0;i<N;i++)
		for (int j = 0; j < N; j++)
		{
			cout << " " << setw(2) << sol[i][j] << " " << "\n";
		}
}

int turCalRec(int i, int j, int mutare, int sol[N][N], int iMutare[8], int jMutare[8])
{
	int k, Ni, Nj;

	if (mutare == N * N)
	{
		return 1;
	}

	for (k = 0; j < 8; k++)
	{
		Ni = i + iMutare[k];
		Nj = j + jMutare[k];

		if (singur(Ni, Nj, sol))
		{
			sol[Ni][Nj] = mutare;

			if (turCalRec(Ni, Nj, mutare + 1, sol, iMutare, jMutare) == 1)
				return 1;
			else
				sol[Ni][Nj] = -1;
		}
	}
	return 0;
}


int main()
{

	return 0;
}
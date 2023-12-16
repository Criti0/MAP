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
int main()
{

	return 0;
}
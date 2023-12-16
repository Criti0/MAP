#include <iostream>
#include <iomanip>
//Bibliotecile de care avem noevoie
using namespace std;
#define N 8

int singur(int i, int j, int sol[N][N])//Verifica daca pozitia (i,j) este valida si nevizitata
{
	return(i >= 0 && i < N && j >= 0 && j < N && sol[i][j] == -1);
}

void afisare(int sol[N][N])//Functia de afisare
{
	for(int i=0;i<N;i++)
	{
		for (int j = 0; j < N; j++)
			cout << " " << setw(2) << sol[i][j] << " ";//Folosim setw(2) pentru a rezerva tot timpul 2 spatii pentru a afisa un caracter
		cout << endl;
	}
}

int turCalRec(int i, int j, int mutare, int sol[N][N], int iMutare[8], int jMutare[8])
{
	int k, Ni, Nj;

	if (mutare == N * N)//Verificam daca am efectuat toate mutarile posibile.
	{
		return 1;
	}

	for (k = 0; k < 8; k++)//Iteram prin toate cele 8 directii pe care calul le poate lua
	{
		Ni = i + iMutare[k];//Calculeaza noile coordonate potentiale ale calului (in functie de pozitia actuala)
		Nj = j + jMutare[k];//Same as up ^

		if (singur(Ni, Nj, sol))//Verifica daca noua pozitie este valida si nevizitata
		{
			sol[Ni][Nj] = mutare;//Marcheaza pozitia curenta

			if (turCalRec(Ni, Nj, mutare + 1, sol, iMutare, jMutare) == 1)//Apeleaza recursiv functia pentru a continua explorarea(daca gaseste solutie returneaza 1)
				return 1;
			else
				sol[Ni][Nj] = -1;//Altfel, revine prin backtracking si marcheaza pozitia curenta ca fiind nevizitata pentru a explora alte posibilitati
		}
	}
	return 0;//Daca nu s-a gasit solutie in directia curenta, returneaza 1
}

int turCal()
{
	int sol[N][N];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			sol[i][j] = -1;
		}

	int iMutare[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int jMutare[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	sol[0][0] = 0;

	if (turCalRec(0, 0, 1, sol, iMutare, jMutare) == 0)
	{
		cout << "Solutia nu exista";
		return 0;
	}
	else
	{
		afisare(sol);
	}
	
	return 1;
}

int main()
{
	turCal();

	return 0;
}
#include<iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

double** getRandMatrix(int n, bool prim)
{
	int min = 0, max = 0;

	double** matrix = new double* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new double[n];
		for (int k = 0; k < n; k++)
			matrix[i][k] = 0.0;
	}

	cout << "min = ";
	cin >> min;
	cout << "max = ";
	cin >> max;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (prim)
				matrix[i][j] = min + rand() % ((max - min + 1) * 10) / 10.0;
			else
				matrix[i][j] = min + rand() % (max - min + 1);
		}

	return matrix;
}

void algPrim() {
	int n = 0;

	cout << "n = ";
	cin >> n;

	if (n <= 1)
	{
		cout << "Wrong size of array." << endl;
		return;
	}

	srand(time(NULL));

	double** DD = getRandMatrix(n, 1);

	cout << endl << "Array DD:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << DD[i][j] << '\t';
		cout << endl;
	}

	int* col = new int[n];
	int* res1 = new int[n];
	int* res2 = new int[n];
	int k = 0, m, j, j1, i, i1;
	double DMin, L = 0.0;

	for (i = 0; i < n; i++)
		col[i] = i;

	while (k < n - 1)
	{
		DMin = 30000;
		for (i1 = 0; i1 < n - 1; i1++)
			for (j1 = i1 + 1; j1 < n; j1++)
				if (DD[i1][j1] < DMin && col[i1] != col[j1])
				{
					DMin = DD[i1][j1];
					i = i1;
					j = j1;
				}
		L += DMin;
		res1[k] = i;
		res2[k] = j;
		k++;
		j1 = col[j];
		for (m = 1; m <= n; m++)
			if (col[m] == j1)
				col[m] = col[i];
	}

	cout << endl;
	for (i = 0; i < n - 1; i++)
		printf("%d %d ** ", res1[i], res2[i]);
	printf(" \nL=%f \n", L);
}

void algDijkstra()
{
	int n = 0;

	cout << "n = ";
	cin >> n;

	int* a = new int[n];
	int* c = new int[n];
	double* b = new double[n];

	double Dmin;
	int i, k, z, j, m;
	i = 3;

	double** DD = getRandMatrix(n, 0);

	for (j = 0; j < n; j++)
	{
		a[j] = 0;
		c[j] = i;
		b[j] = DD[i][j];
	}

	a[i] = 1;
	c[i] = 0;

	for (m = 0; m < n; m++)
	{
		Dmin = 300000;
		for (k = 0; k < n; k++)
			if ((a[k] == 0) && (b[k] < Dmin))
			{
				j = k;
				Dmin = b[k];
			}
		printf("\nDmin=%f j=%d", Dmin, j);
		a[j] = 1;
		for (k = 0; k < n; k++)
			if (b[k] > b[j] + DD[j][k])
			{
				b[k] = b[j] + DD[j][k];
				printf("\nk=%d b[k]=%f", k, b[k]);
				c[k] = j;
			}
		cout << endl;
	}

	for (k = 0; k < n; k++)
	{
		z = c[k];
		printf("\nk=%d ** ", k);
		while (z != 0)
		{
			printf("%d ", z);
			z = c[z];
		}
	}
	cout << endl;
}

void main() 
{
	int choise = 1;

	while (choise < 3 && choise > 0)
	{
		cout << "--------------------\n\n";

		cout << "1) Prim-Kraskal\n2) Dijkstra\n";
		cout << "Choise: ";
		cin >> choise;

		if (!(choise < 3 && choise > 0))
			break;

		cout << endl;

		switch (choise) {
		case 1:
			algPrim();
			break;
		case 2:
			algDijkstra();
			break;
		}

		cout << endl;
	}
}
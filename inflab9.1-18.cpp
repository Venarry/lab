#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(void)
{
	setlocale(LC_CTYPE, "");
	int i,j,j1, n, m ,x,summ,sred[50]; 
	printf("Введите размерность массива\n");
	cin >> n;
	cin >> m;
	int** arr = new int*[n];
	for (i = 0; i < n; i++)
		arr[i] = new int[m];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("Введите [%d][%d] элемент массива\n", i+1,j+1);
			cin >> arr[i][j];
		}
	}


	printf("Исходный Массив a:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d ", arr[i][j]);
			if (j == m - 1)
			{
				printf("\n");
			}
		}
	}


	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if ((arr[i][j] == 0) and (j>0))
			{
				j1 = j;
				while (j1 > 0 )
				{
					x = arr[i][j1];
					arr[i][j1] = arr[i][j1 - 1];
					arr[i][j1 - 1] = x;
					j1--; 
				}
			}
		}
	}

	printf("Конечный Массив a:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d ", arr[i][j]);
			if (j == m - 1)
			{
				printf("\n");
			}
		}
	}

	delete[] arr;
}

#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#define N 5
using namespace std;

int file (int a[N][N]) // ���� ������ � �����
{
	ifstream in("D:\\in.txt");

	if (in.is_open())
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				in >> a[i][j];
		in.close();
	}
	else 
	{
		printf("���� �� ������\n");
	}
	return a[N][N];
}

int klava(int a[N][N]) // ���� ������ � ����������
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("������� ������� [%d,%d]\n", i + 1, j + 1);
			cin >> a[i][j];
		}
	}
	return a[N][N];
}

int reshenie(int a[N][N],int x[N], int m) // ������� ������������ ������
{
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			if ((a[i][j] < a[i + 1][j]) and (a[i + 1][j] < a[i + 2][j]))
			{
				x[j] = 1;
				break;
			}
		}
	}
	return x[N];
}

void vivod(int a[N][N], int x[N], int i, int j, int y) // ����� ����������� ������� � ��������� ������� x
{
	printf("������ a:\n");
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%d ", a[i][j]);
			if (j == 4)
			{
				printf("\n");
			}
		}
	}
	printf("������ x:\n");
	for (i = 0; i < N; i++)
	{
		printf("%d ", x[i]);
	}
}
	
	void vvodY(int y,int x[N],int i,int j) // ���������� �������� y
	{
		for (i = 0; i < N; i++)
		{
			if (x[i] % 2 == 0)
			{
				if (x[0] == 0) 
				{ 
					y = 0; 
				}
				for (j=0; j<i; j++)
				y *= x[j];
				break;
			}
		}
		printf("������������ �������� ���������, ������������� ����� ������ ������������� ������ ��������� ������� X:%d \n", y);
		ofstream in("D:\\in.txt");
		for (i = 0; i < N; i++)
		{
			in << x[i] << ' ';
		}
		in << "Y:" << y;
		in.close();

	}


void prog() // ��������� �� ���� �-���
{
	int p, i = 0, j = 0, m = 0, a[N][N], x[N] = { 0,0,0,0,0 }, y = 0;
	setlocale(LC_CTYPE, "");
	printf("���� � ����������(1) ��� � �����(2)?");
	cin >> p;
	if (p == 2)
	{
		file(a);
	}
	else
	{
		klava(a);
	}
	y = 1;
	reshenie(a,x,m);
	vivod(a,x,i,j,y);
	vvodY(y, x, i, j);
}

int main(void)
{
	prog();
}

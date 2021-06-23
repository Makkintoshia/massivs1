#include <math.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

int main()
{
	int stroka;
	int stolb;
	cout << "Write number of strok :";
	cin >> stroka;
	cout << "Write number of stolb :";
	cin >> stolb;
	int** massiv = new int* [stroka];
	for (int i = 0;i < stroka;i++)
	{
		massiv[i] = new int[stolb];
	}


	for (int i = 0; i < stroka; i++)
	{
		for (int j = 0; j < stolb; j++)
		{
			massiv[i][j] = 0;
		}
	}
	for (int i = 0;i < stroka; i++)
	{
		for (int j = 0;j < stolb;j++)
		{
			cout << "write element :";
			cin >> massiv[i][j];
		}
	}
	for (int i = 0; i < stroka; i++)
	{
		for (int j = 0; j < stolb; j++)
		{
			cout << " " << massiv[i][j];
		}
		cout << endl;
	}

	//-------------------------------Определить номер строки матрицы, содержащей максимальное количество нулевых элементов----------------------------------------------
	int zero = 0;

	int MaxNumZeros = 0;//количестов нулей
	int numbstring=0;//номер строки 
	bool a = false;

	for (int i = 0; i < stroka; i++)
	{
		int kolzeroinstring = 0; // количество нулей в строке

		for (int j = 0; j < stolb; j++)
		{

			if (massiv[i][j] == 0)
			{
				kolzeroinstring++;

				a = true;
			}
			if (kolzeroinstring > MaxNumZeros)
			{
				MaxNumZeros = kolzeroinstring;
				numbstring = i;
			}

		}

	}

	if (a == false)
	{
		cout << "No zero in matrix";
	}
	else
	{
		cout << numbstring+1;
	}
	cout << "\n";
	//======================================   Определить минимум среди сумм модулей элементов диагоналей, параллельных побочной диагонали матрицы   ==============================================
	int summin;


	int Count1 = stroka;
	int Count2 = stroka;
	int sum1 = 0;

	for (int i = 0; i < Count2; i++)
	{
		Count1--;
		Count2--;

		for (int i = 0; i < Count2; i++)
		{
			Count1--;
			sum1 += abs(massiv[i][Count1]);
		}
	}



	for (int i = 0; i < stroka; i++)

	{
		int sum = 0;

		for (int j = stroka - 2; j >= 0; j--)
		{
			sum += abs(massiv[i][j]);
			if ((i == 0) || (summin > sum))
			{
				summin = sum;
			}
		}
	}
	for (int i = 1;i < stroka;i++)
	{
		int sum = 0;
		for (int j = 0;j < stolb-i;j++)
		{
			sum += abs(massiv[i + j][stolb - i - j]);
			if (summin > sum)
			{
				summin = sum;
			}
		}
	}
	cout << summin;
}

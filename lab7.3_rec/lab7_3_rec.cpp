#include <iostream>
#include <Windows.h>
#include <time.h>
#include <iomanip>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < colCount-1)
		return Create(a, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount-1)
			return Create(a, rowCount, colCount, Low, High, i + 1, 0);
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1)
		return Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1) {
			cout << endl;
			return Print(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}

int Part1_Count(int** a, const int rowCount, const int colCount, int i, int j, int k_zero)
{
	if (a[i][j] == 0) {
		k_zero++;
		j++;
	}
	if (j < colCount - 1) 
		Part1_Count(a, rowCount, colCount, i, j + 1, k_zero);
	else
		if (i < rowCount - 1) 
			Part1_Count(a, rowCount, colCount, i + 1, 0, k_zero);
		else 
			return k_zero;
}

void Num_Col(int** a, const int rowCount, const int colCount)
{
	int m = 0; // числа в рядках
	int col = 0; // номер колонки
	for (int j = 0; j < colCount; j++)
	{
		int count = 0; // кількість однакових чисел
		for (int i = 0; i < rowCount; i++)
			for (int k = i + 1; k < rowCount; k++)
				if (a[i][j] == a[k][j])
					count++;
		if (count > m) {
			m = count;
			col = j;
			cout << " Номер стовпця з серією елементів: " << col << endl << endl;
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand((unsigned)time(NULL));

	int Low = -5;
	int High = 5;

	int rowCount = 0;
	int colCount = 0;
	cout << " Кількість рядків: "; cin >> rowCount; // k
	cout << " Кількість стовпців: "; cin >> colCount; // n

	int** a = new int* [rowCount];
	for (int i = 0; i < colCount; i++)
		a[i] = new int[colCount];

	Create(a, rowCount, colCount, Low, High, 0, 0);
	Print(a, rowCount, colCount, 0, 0);
	cout << " Кількість рядків з нулювим елементом: " << Part1_Count(a, rowCount, colCount, 0, 0, 0) << endl << endl;
	
	Num_Col(a, rowCount, colCount);

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}

#include <iostream>

#include <ctime>

using namespace std;

void per(int** chislo, int chislo2, int chislo3);

void vtor(int** chislo, int chislo2, int chislo3);

int main()

{

	setlocale(LC_ALL, "rus");

	int string = 0;

	int stolbec = 0;

	cout << "Введите размерность двумерного массива\n";

	cout << "Строк: ";

	cin >> string;

	cout << "Столбцов: ";

	cin >> stolbec;

	int** change = new int* [string];

	for (int i = 0; i < string; i++)

	{

		change[i] = new int[stolbec];

	}

	vtor(change, string, stolbec);

	per(change, string, stolbec);

	for (int i = 0; i < string; i++)

	{

		delete[] change[i];

	}

	delete[] change;

	return 0;

}

void per(int** chislo, int chislo2, int chislo3)

{

	cout << endl << endl;

	for (int i = 0; i < chislo2; i++)

	{

		cout << " ";

		for (int j = 0; j < chislo3; j++)

		{

			cout << chislo[i][j] << " ";

		}

		cout << " " << endl;

	}

}

void vtor(int** chislo, int chislo2, int chislo3)

{

	srand(time(0));

	for (int i = 0; i < chislo2; i++)

	{

		for (int j = 0; j < chislo3; j++)

		{

			chislo[i][j] = 10 + rand() % 41;

		}

	}

}
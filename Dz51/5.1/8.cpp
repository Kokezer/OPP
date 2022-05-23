#include <string>
#include <conio.h>
#include <iostream> 
using namespace std; 
double* mem(double* startPtr, int j);
void fill(double* m, int j);
void pr(double* m, int j);
double* del(double* m);
int main() {
	setlocale(LC_ALL, 0);
	double* mfill = 0;
	char q = 0;
	do
	{
		int j = 0;
		cout << "Размер массива: ";
		cin >> j;
		mfill = mem(mfill, j);
		fill(mfill, j);
		pr(mfill, j);
		mfill = del(mfill);
		cout << "\nПродолжить (1). Выйти (0): ";
		cin >> q;
	} while (q != '0');
	_getch();
}
double* mem(double* m, int j)
{
	m = new double[j];
	return m;
}
void fill(double* m, int j)
{
	for (int i = 0; i < j; i++)
	{
		m[i] = (i + 1) * 0.2;
	}
}
void pr(double* m, int j)
{
	for (int i = 0; i < j; i++)
	{
		cout << m[i] << " ";
	}
	cout << endl;
}
double* del(double* m)
{
	delete[] m; 
	m = 0;

	return m;
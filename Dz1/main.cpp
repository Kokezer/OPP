#include "Complex.h"
#include <iostream>
#include <fstream>
using namespace std;


int main() 
{
	setlocale(LC_ALL, "Russian");
	Complex num1, num2{ 5, 13 };
	num1 = { 0, 7 };
	num1.re = 4;
	cout << "Первое число: ";
	num1.Display();
	cout << "Второе число: ";
	num2.Display();

	Complex
		num_add = num1 + num2,
		num_sub = num1 - num2,
		num_mul = num1 * num2,
		num_div = num1 / num2;
	cout << "+: ";
	num_add.Display();
	cout << "-: ";
	num_sub.Display();
	cout << "*: ";
	num_mul.Display();
	cout << "/: ";
	num_div.Display();

	cout << "Номер массива = " << num_div << ", Это длина = " << num_div.Length() << '\n';

	ifstream file("complex.txt");
	if (!file) {
		cerr << "Файл не открылся\n";
		return -1;
	}

	int c_amount = 0;
	file >> c_amount;
	Complex* c_arr = new Complex[c_amount] {};
	Complex max_v{};
	for (int i = 0; i < c_amount && !file.eof(); ++i) {
		file >> c_arr[i].re >> c_arr[i].im;
		if (c_arr[i].Length() > max_v.Length()) {
			max_v = c_arr[i];
		}
	}

	for (int i = 0; i < c_amount; ++i) {
		c_arr[i].Display();
	}
	cout << "Самая большая длина составляет " << max_v.Length() << " (" << max_v << ")\n";

	return 0;
}
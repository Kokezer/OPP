#include "Complex.h"
#include <iostream>
#include <fstream>
using namespace std;


int main() {
	Complex num1, num2{ 5, 13 };
	num1 = { 0, 7 };
	num1.re = 4;
	cout << "1 number: ";
	num1.Display();
	cout << "2 number: ";
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

	cout << "num_div = " << num_div << ", it's length = " << num_div.Length() << '\n';

	//2 files
	ifstream file("complex.txt");
	setlocale(LC_ALL, 0);
	if (!file) {
		cerr << "uh oh file no open a\n";
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
	cout << "The biggest length is " << max_v.Length() << " (" << max_v << ")\n";

	return 0;
}
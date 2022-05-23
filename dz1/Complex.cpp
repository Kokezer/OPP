#include "Complex.h"
#include <iostream>
#include <iomanip>
using namespace std;

Complex::Complex() {}
Complex::~Complex() {}
Complex::Complex(double _re, double _im) : re(_re), im(_im) {}



const Complex Complex::operator+(const Complex& n2) const {
	return Complex(re + n2.re, im + n2.im);
}

const Complex Complex::operator-(const Complex& n2) const {
	return Complex(re - n2.re, im - n2.im);
}

const Complex Complex::operator*(const Complex& n2) const {
	return Complex(
		re * n2.re - im * n2.im,
		re * n2.im + n2.re * im
	);
}

const Complex Complex::operator/(const Complex& n2) const {
	return Complex(
		(re * n2.re + im * n2.im) / (n2.re * n2.re + n2.im * n2.im),
		(n2.re * im - re * n2.im) / (n2.re * n2.re + n2.im * n2.im)
	);
}

bool Complex::operator>(const Complex& n2) const {
	return Length() > n2.Length();
}

bool Complex::operator<(const Complex& n2) const {
	return Length() < n2.Length();
}

void Complex::Display() const {
	ios_base::fmtflags old_flags = std::cout.flags();
	cout << re << std::showpos << im << "i\n";
	cout.unsetf(0xFFFFFFFF);
	cout.setf(old_flags);
}

double Complex::Length() const {
	return sqrt(re * re + im * im);
}

ostream& operator<<(std::ostream& out, const Complex& val) {
	ios_base::fmtflags old_flags = out.flags();
	out << val.re << std::showpos << val.im << 'i';
	out.unsetf(0xFFFFFFFF);
	out.setf(old_flags);
	return out;
}
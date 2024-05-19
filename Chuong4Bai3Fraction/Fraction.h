#pragma once
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<iomanip>
using namespace std;
class Fraction
{
private:
	int numerator;
	int denominator;
public:
	friend istream& operator>>(istream& in, Fraction& nhap);
	friend ostream& operator<<(ostream& out, Fraction& xuat);
	Fraction();
	Fraction(int tu, int mau);
	void setNumerator(int x);
	void setDenominator(int x);
	int getNumerator() const;
	int getDenominator() const;
	Fraction toiGian(int x, int y);
	Fraction operator+(const Fraction& phanSo);
	Fraction operator-(const Fraction& phanSo);
	Fraction operator*(const Fraction& phanSo);
	Fraction operator/(const Fraction& phanSo);
	bool operator==(const Fraction& phanSo);
	bool operator!=(const Fraction& phanSo);
	bool operator>=(const Fraction& phanSo);
	bool operator<=(const Fraction& phanSo);

};




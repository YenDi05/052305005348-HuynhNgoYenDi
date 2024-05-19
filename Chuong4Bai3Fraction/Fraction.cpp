#include "Fraction.h"
#include<iostream>
#include<istream>
using namespace std;
int rutGon(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return rutGon(b, a % b);
	}
}

istream& operator>>(istream& in, Fraction& nhap)
{
	cout << "Nhap tu so: ";
	in >> nhap.numerator;
	cout << "Nhap mau so: ";
	in >> nhap.denominator;
	return in;
}

ostream& operator<<(ostream& out, Fraction& xuat)
{
	cout << xuat.numerator << "/" << xuat.denominator;
	return out;
}
Fraction::Fraction()
{
	this->numerator = 0;
	this->denominator = 1;
}

Fraction::Fraction(int tu, int mau)
{
	setNumerator(tu);
	setDenominator(mau);
}

void Fraction::setNumerator(int x)
{
	this->numerator = x;
}
void Fraction::setDenominator(int x)
{
	this->denominator = x;
}
int Fraction::getNumerator() const
{
	return this->numerator;
}
int Fraction::getDenominator() const
{
	return this->denominator;
}
Fraction Fraction::toiGian(int x, int y)
{
	int ucln;
	ucln = rutGon(x, y);
	if (ucln < 0)
	{
		ucln = -ucln;
	}
	x = x / ucln;
	y = y / ucln;

	return Fraction(x, y);
}
Fraction Fraction::operator+(const Fraction& phanSo)
{
	int tu, mau;
	tu = (this->numerator * phanSo.denominator) + (this->denominator * phanSo.numerator);
	mau = this->denominator * phanSo.denominator;

	return Fraction(tu, mau) = toiGian(tu, mau);
}
Fraction Fraction::operator-(const Fraction& phanSo)
{
	int tu, mau;
	tu = (this->numerator * phanSo.denominator) - (this->denominator * phanSo.numerator);
	mau = this->denominator * phanSo.denominator;
	return Fraction(tu, mau) = toiGian(tu, mau);
}

Fraction Fraction::operator*(const Fraction& phanSo)
{
	int tu, mau;
	tu = this->numerator * phanSo.numerator;
	mau = this->denominator * phanSo.denominator;
	return Fraction(tu, mau) = toiGian(tu, mau);
}
Fraction Fraction::operator/(const Fraction& phanSo)
{
	int tu, mau;
	tu = this->numerator * phanSo.denominator;
	mau = this->denominator * phanSo.numerator;
	return Fraction(tu, mau) = toiGian(tu, mau);
}
bool Fraction::operator==(const Fraction& phanSo)
{
	Fraction phanSo1 = *this, phanSo2 = phanSo;
	phanSo1 = toiGian(phanSo1.numerator, phanSo1.denominator);
	phanSo2 = toiGian(phanSo2.numerator, phanSo2.denominator);
	return (phanSo1.numerator == phanSo2.numerator) && (phanSo1.denominator == phanSo2.denominator);
}

bool Fraction::operator!=(const Fraction& phanSo)
{
	Fraction phanSo1 = *this, phanSo2 = phanSo;
	phanSo1 = toiGian(phanSo1.numerator, phanSo1.denominator);
	phanSo2 = toiGian(phanSo2.numerator, phanSo2.denominator);
	return (phanSo1.numerator != phanSo2.numerator) || (phanSo1.denominator != phanSo2.denominator);
}

bool Fraction::operator>=(const Fraction& phanSo)
{
	Fraction phanSo1, phanSo2;
	phanSo1.numerator = this->numerator * phanSo.denominator;
	phanSo2.numerator = this->denominator * phanSo.numerator;
	return (phanSo1.numerator >= phanSo2.numerator);
}
bool Fraction::operator<=(const Fraction& phanSo)
{
	Fraction phanSo1, phanSo2;
	phanSo1.numerator = this->numerator * phanSo.denominator;
	phanSo2.numerator = this->denominator * phanSo.numerator;
	return (phanSo1.numerator <= phanSo2.numerator);
}


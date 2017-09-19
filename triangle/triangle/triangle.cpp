#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

bool ValidateInput(int argc)
{
	if (argc != 4)
	{
		cout << "Укажите длины сторон в качестве параметров. Формат ввода: triangle.exe a b c" << endl;
		return false;
	}
	return true;
}

bool CorrectValue(long double a, long double b, long double c)
{
	return a <= b + c;
}

int main(int argc, char * argv[])
{
	setlocale(LC_CTYPE, "Russian");
	if (!ValidateInput(argc))
	{
		return 1;
	}

	long double a = 0;
	long double b = 0;
	long double c = 0;
	try
	{
		a = stod(argv[1]);
		b = stod(argv[2]);
		c = stod(argv[3]);
	}
	catch(const logic_error)
	{
		cout << "Стороны - числа! Не иначе." << endl;
		return 1;
	}

	if (a <= 0 || b <= 0 || c <= 0)
	{
		cout << "Длины сторон должны быть больше 0!" << endl;
		return 1;
	}

	if (!(CorrectValue(a, b, c) && CorrectValue(b, c, a) && CorrectValue(c, a, b)))
		cout << "не треугольник";
	else if (a == b && b == c)
		cout << "равносторонний";
	else if (a == b && b != c || b == c && c != a || c == a && a != b)
		cout << "равнобедренный";
	else
		cout << "обычный";
	cout << endl;

	return 0;
}


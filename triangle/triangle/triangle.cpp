#include "stdafx.h"
#include <iostream>
#include <string>
#include <regex>

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

bool CorrectValue(double a, double b, double c)
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
	regex validateNumber("^[0-9]*[.]?[0-9]+$");
	if (!regex_match(argv[1], validateNumber) || !regex_match(argv[2], validateNumber) || !regex_match(argv[3], validateNumber))
	{
		cout << "Некорректная длина стороны." << endl;
		return 1;
	}

	double a = stod(argv[1]);
	double b = stod(argv[2]);
	double c = stod(argv[3]);

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


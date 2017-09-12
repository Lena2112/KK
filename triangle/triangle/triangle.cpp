#include "stdafx.h"
#include <iostream>

using namespace std;

bool ValidateInput(int argc)
{
	if (argc != 4)
	{
		cout << "������� ����� ������ � �������� ����������. ������ �����: triangle.exe a b c" << endl;
		return false;
	}
	return true;
}

bool CorrectValue(int a, int b, int c)
{
	return a <= b + c;
}

int main(int argc, char * argv[])
{
	if (!ValidateInput(argc))
	{
		return 1;
	}

	setlocale(LC_ALL, "RUS");

	float a = atoi(argv[1]);
	float b = atoi(argv[2]);
	float c = atoi(argv[3]);

	if (a <= 0 || b <= 0 || c <= 0)
	{
		cout << "����� ������ ������ ���� ������ 0!" << endl;
		return 1;
	}

	if (!(CorrectValue(a, b, c) && CorrectValue(b, c, a) && CorrectValue(c, a, b)))
		cout << "�� �����������";
	else if (a == b && b == c)
		cout << "��������������";
	else if (a == b && b != c || b == c && c != a || c == a && a != b)
		cout << "��������������";
	else
		cout << "�������";
	cout << endl;

	return 0;
}


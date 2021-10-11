#include<iostream>
#include<Windows.h>
using namespace std;

int StringLength(char str[]);
void to_upper(char str[]);
void to_lower(char str[]);
void shrink(char str[]);

void main()
{
	setlocale(LC_ALL, "");
	//char str[] = { 'H', 'e', 'l', 'l', 'o', 0};
	//char str[] = "Hello";
	const int n = 200;
	char str[200]{};
	cout << "Введите строку: ";
	//cin >> str;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cin.getline(str, n);
	cout << str << endl;
	cout << "Количество символов в строке: " << StringLength(str) << endl;
	//cout << strlen(str);
	to_upper(str);
	cout << str << endl;
	to_lower(str);
	cout << str << endl;
	shrink(str);
	cout << str << endl;
}

int StringLength(char str[])
{
	int n = 0;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != 0)
			n++;
	}
	return n;
}
void to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		str[i] = toupper(str[i]);
	}
}
void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		str[i] = tolower(str[i]);
	}
}
void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ')
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
			i--;
		}
	}
}

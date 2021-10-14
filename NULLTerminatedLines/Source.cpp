#include<iostream>
#include<Windows.h>
using namespace std;

int StringLength(char str[]);
int StringLength1(char str[]);
void to_upper(char str[]);
void to_upper1(char str[]);
void to_lower(char str[]);
void to_lower1(char str[]);
void shrink(char str[]);
void shrink1(char str[]);
bool is_palindrom(char str[]);
bool is_int_number(char str[]);
bool is_bin_number(char str[]);
bool is_hex_number(char str[]);

void main()
{
	setlocale(LC_ALL, "");
	//char str[] = { 'H', 'e', 'l', 'l', 'o', 0};
	//char str[] = "Hello";
	const int n = 200;
	//char str[n]="Аргентина манит негра";
	char str[n]{};
	cout << "Введите строку: ";
	//cin >> str;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cin.getline(str, n);
	cout << str << endl;
	cout << "Количество символов в строке: " << StringLength1(str) << endl;
	//cout << strlen(str);
	to_upper1(str);
	cout << str << endl;
	to_lower1(str);
	cout << str << endl;
	shrink1(str);
	cout << str << endl;
	cout << "Строка " << (is_palindrom(str) ? "" : "НЕ ") << "является палиндромом" << endl;
	//cout << str << endl;
	cout << "Строка " << (is_int_number(str) ? "" : "НЕ ") << "является числом!" << endl;
	cout << "Строка " << (is_bin_number(str) ? "" : "НЕ ") << "является двоичным числом!" << endl;
	cout << "Строка " << (is_hex_number(str) ? "" : "НЕ ") << "является шестнадцатеричным числом!" << endl;
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
int StringLength1(char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}
void to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		str[i] = toupper(str[i]);
	}
}
void to_upper1(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if(
			str[i]>='a' && str[i]<='z' ||
			str[i] >= 'а' && str[i] <= 'я'
			)
			str[i] -= 32;
	}
}
void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		str[i] = tolower(str[i]);
	}
}
void to_lower1(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (
			str[i] >= 'A' && str[i] <= 'Z' ||
			str[i] >= 'А' && str[i] <= 'Я'
			)
			str[i] += 32;
	}
}
void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
			i--;
		}
	}
}
void shrink1(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i; str[j]; j++) str[j] = str[j + 1];
		}
	}
}
void remove_symbol(char str[], const char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++)str[j] = str[j + 1];
		}
	}
}
bool is_palindrom(char str[])
{
	int n = strlen(str);
	char* buffer = new char[n + 1]{};
	for(int i = 0; str[i]; i++)buffer[i] = str[i];
	to_upper(buffer);
	remove_symbol(buffer, ' ');
	n = strlen(buffer);
	for (int i = 0; i < n / 2; i++)
	{
		if (buffer[i] != buffer[n - 1 - i])
		{
		delete[]buffer;
		return false;
		}
	}
	delete[]buffer;
	return true;
}
bool is_int_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9') return false;
	}
	return true;
}
bool is_bin_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '0' && str[i] != '1')return false;
	}
	return true;
}
bool is_hex_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9' || str[i] >= 'A' && str[i] <= 'F' || str[i] >= 'a' && str[i] <= 'f'))return false;
	}
	return true;
}

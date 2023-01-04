#include "tools.h"


ArrayException::ArrayException(std::string error) : m_error(error) {}
const char* ArrayException::getError() { return m_error.c_str(); }

bool CheckLettersABC(char str) {
	if (str != 'A' || str != 'B' || str != 'C')
	{
		return false;
	}
	return true;
}

bool CheckLetters(char str[])
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] <= '9' && str[i] >= '0')
		{
			return false;
		}
	}
	return true;
}

bool CheckNumbers(char str[])
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] > '9' || str[i] < '0')
		{
			if (isspace(str[i])) {
				continue;
			}
			else {
				return false;
			}
		}
	}
	return true;
}

char* CopyCharArray(char* originale, char* pattern) {
	try {
		for (int i = 0; i < strlen(pattern) and i < strlen(originale); i++) {
			originale[i] = pattern[i];
		}
	}
	catch (...) {
		throw ArrayException("������ ����������� �����.");
	}

	return originale;
}

int SetNumbers(int first = -777, int last = -777) // 
{
	int i = 0;
	while (true) {
		if (first != -777 and last != -777 and first != last) {
			cout << "������� ����� ����� � ��������� [" << first << ";" << last << "]: ";
		}
		else {
			cout << "������� ����� �����: ";
		}
		//cin.clear();
		cin >> i;
		if (cin.good()) {
			break;
		}
		cin.clear();
		cout << "\n������������ ���� ������.������� �����.\n";
		cin.ignore(10, '\n');//������� �� ������ 10 �������� �� ����� \n
	}

	if (first != -777 and last != -777) {
		do {
			if (i > last or i < first) {
				i = SetNumbers(first, last);
			}
			else
				break;
		} while (true);
	}
	return i;
}

void SetString(char nameChar[256]) {
	cin.ignore(10, '\n');
	cin.unsetf(ios::skipws);
	while (true) {
		cout << "��� �����: ";
		cin.getline(nameChar, 255);

		if (!cin.good() or isspace(nameChar[0]) or nameChar == "" or nameChar[0] == '\0') {
			cout << "\n������� ��������� ��� ������!\n";
			continue;
		}
		if (CheckLetters(nameChar)) {
			break;
		}
	}
	cin.setf(ios::skipws);
}

void SetStringInt(char nameChar[256]) {
	cin.ignore(10, '\n');
	cin.unsetf(ios::skipws);
	while (true) {
		cout << "��� �����: ";
		cin.getline(nameChar, 255);

		if (!cin.good() or isspace(nameChar[0]) or nameChar[0] == '\0') {
			cout << "\n������� ��������� ��� ������!\n";
			continue;
		}
		if (CheckNumbers(nameChar)) {
			break;
		}
	}
	cin.setf(ios::skipws);
}

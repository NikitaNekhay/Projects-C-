#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<algorithm>
#include<stdio.h>
#include<vector>
#include<queue>
#include<stack>
#include <fstream>
#include <iostream>
#include <string.h>
#include <conio.h>// ����� _getch()
#include<stdlib.h> // ����� rand() � srand(); malloc(), calloc() � ��
#include<Windows.h>// ��� ����������� ������ � ������ ������� �������� � ����
#include<locale.h>

using namespace std;


class ArrayException
{
	std::string m_error;

public:
	ArrayException(std::string error);
	const char* getError();
};

bool CheckLettersABC(char str);

bool CheckLetters(char str[]);

bool CheckNumbers(char str[]);

char* CopyCharArray(char* originale, char* pattern);

int SetNumbers(int first, int last);

void SetString(char nameChar[256]);

void SetStringInt(char nameChar[]);

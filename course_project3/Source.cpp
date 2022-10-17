#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <io.h>
#include <fcntl.h>
using namespace std;
struct Adress
{
	char street[30];
	int home;
};
struct Log
{
	char logIn[40];
	char passWord[40];
};
struct Date
{
	int day;
	int month;
	int year;
};
struct Time
{
	int hour;
	int min;
};
struct FIO
{
	char name[30];
	char s_name[30];
	char l_name[30];
};
struct Theatre
{
	long int t_code;
	char t_name[30];
	Adress location;
	long int phone;
	int t_place;
};
struct Performance
{
	long int p_code;
	char p_name[30];
	int rating;
	FIO actor;
	int cost;
	char genre[30];
	char author[30];
};

struct Record
{
	long int t_code;
	long int p_code;
	char season[30];
	Time _time;
	Date _date;
	int tickets;
};
//////////////////////// Del
bool CheckLetters(char[]);//
bool CheckNumbers(char[]);//
void AddTheatre();//
void AddRecord();//
void AddPerformance();//
void ViewTheatre(Theatre* arr, int n);//
void ViewRecord(Record* arr, int n);//
void ViewPerformance(Performance* arr, int n);//
void DeletePerformance();//
void DeleteTheatre();//
void DeleteRecord();//
void EditPerformance();//
void EditTheatre();//
void EditRecord();//
int Compare_time(Time a, Time b);//
Time ReadTime();//
void WriteTime(Time a);//
int Compare_date(Date a, Date b);//
Date ReadDate();//
void WriteDate(Date a);//
void MenuAdmin();//
void MenuUserControl();
void MenuView();//
void MenuAdd();//
void MenuEdit();//
void MenuDelete();//
void MenuSearch();//
void MenuSort();//
void MenuFiltration();//
bool LogIn(char[]);//
void UserMenu();
void MenuLogIn();//
int GetFileLog(Log**, char[]);//
int GetFileRecord(Record**);//
int GetFileTheatre(Theatre**);//
int GetFilePerformance(Performance**);//
void SetFileLog(Log*, int, char[]);//
void SetFileRecord(Record*, int);//
void SetFileTheatre(Theatre*, int);//
void SetFilePerformance(Performance*, int);//
void SearchRecordSes();//
void SearchTheatre();
void SearchPerformance();
void SearchPerformanceActor();
void SearchPerformanceGenre();
void SortAbc();//
void SortRating();
void SortCost();
void FilterCost();//
void FilterRating();
Log AddUser(Log* arr, int n);//
void DelUser(Log* arr, int n);//
void ViewUser(Log* arr, int n);//
void Srart();//
void Task();


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
			return false;
		}
	}
	return true;
}
bool CheckTheatreCode(Theatre* arr, int n, int code)
{
	if (n == 0)
	{
		return false;
	}
	for (int i = 0; i < n; i++)
	{
		if (code == arr[i].t_code)
		{
			return true;
		}
	}
	return false;
}
bool CheckPerformanceCode(Performance* arr, int n, int code)
{
	if (n == 0)
	{
		return false;
	}
	for (int i = 0; i < n; i++)
	{
		if (code == arr[i].p_code)
		{
			return true;
		}
	}
	return false;
}
bool CheckLength(char str[])
{
	if (strlen(str) != 9)
	{
		return false;
	}
	else return true;
}
void AddTheatre()
{
	Theatre* arr = NULL;
	int n = GetFileTheatre(&arr);
	Theatre a;
	char s[70];
	int flag = 0;
	int fl = 0;
	while (fl == 0 || fl == 1)
	{
		flag = 0;
		while (flag == 1 || flag == 0)
		{
			printf("Enter the code:\n");
			scanf(" %s", s);
			if (!CheckNumbers(s))
			{
				flag = 1;
			}
			else flag = 2;
		}
		a.t_code = atoi(s);
		if (CheckTheatreCode(arr, n, a.t_code))
		{
			printf("There's already t.code exist\n");
			fl = 1;
			system("pause");
		}
		else fl = 2;
	}
	flag = 0;
	while (flag == 1 || flag == 0)
	{
		printf("Enter the name:\n");
		scanf(" %s", s);
		if (!CheckLetters(s))
		{
			flag = 1;
		}
		else flag = 2;
	}
	strcpy(a.t_name, s);
	flag = 0;
	while (flag == 1 || flag == 0)
	{
		printf("Enter street:\n");
		scanf(" %s", s);
		if (!CheckLetters(s))
		{
			flag = 1;
		}
		else flag = 2;
	}
	strcpy(a.location.street, s);
	flag = 0;
	while (flag == 1 || flag == 0)
	{
		printf("Enter the number of home:\n");
		scanf(" %s", s);
		if (!CheckNumbers(s))
		{
			flag = 1;
		}
		else flag = 2;
	}
	a.location.home = atoi(s);

	flag = 1;
	while (flag == 1 || flag == 0)
	{
		printf("Enter the numb:\n+375");
		scanf(" %s", s);
		if (!CheckNumbers(s) || !CheckLength(s))
		{
			flag = 1;
		}
		else flag = 2;
	}
	a.phone = atoi(s);
	flag = 1;
	while (flag == 1 || flag == 0)
	{
		printf("Enter the quantity of places:\n");
		scanf(" %s", s);
		if (!CheckNumbers(s))
		{
			flag = 1;
		}
		else flag = 2;
	}
	a.t_place = atoi(s);
	if (n == 0)
	{
		arr = &a;
		SetFileTheatre(arr, 1);
	}
	else
	{
		arr[n] = a;
		SetFileTheatre(arr, n + 1);
		delete[] arr;
	}
}
void AddRecord()
{
	Performance* arrp = NULL;
	int ng = GetFilePerformance(&arrp);
	if (ng == 0)
	{
		printf("No performances\n");
		system("pause");
		return;
	}
	Theatre* arrt = NULL;
	int nt = GetFileTheatre(&arrt);
	if (nt == 0)
	{
		printf("No theatres\n");
		system("pause");
		return;
	}
	Record* arr = NULL;
	int n = GetFileRecord(&arr);
	Record a;
	char s[70];
	int flag = 0;
	int fl = 0;
	while (fl == 0 || fl == 1)
	{
		flag = 0;
		while (flag == 1 || flag == 0)
		{
			printf("Put the code of performance:\n");
			scanf(" %s", s);
			if (!CheckNumbers(s))
			{
				flag = 1;
			}
			else flag = 2;
		}
		a.p_code = atoi(s);
		if (!CheckPerformanceCode(arrp, ng, a.p_code))
		{
			printf("No such code performances\n");
			fl = 1;
			system("pause");
		}
		else fl = 2;
	}
	fl = 0;
	while (fl == 0 || fl == 1)
	{
		flag = 0;
		while (flag == 1 || flag == 0)
		{
			printf("Put the code of theatre:\n");
			scanf(" %s", s);
			if (!CheckNumbers(s))
			{
				flag = 1;
			}
			else flag = 2;
		}
		a.t_code = atoi(s);
		if (!CheckTheatreCode(arrt, nt, a.t_code))
		{
			printf("No theatre with such code\n");
			fl = 1;
			system("pause");
		}
		else fl = 2;
	}
	cout << "enter date\n";
	a._date = ReadDate();
	cout << "enter time\n";
	a._time = ReadTime();

	flag = 0;
	while (flag == 1 || flag == 0)
	{
		printf("Enter the season:\n");
		scanf(" %s", s);
		if (!CheckLetters(s))
		{
			flag = 1;
		}
		else flag = 2;
	}
	strcpy(a.season, s);
	flag = 1;
	while (flag == 1 || flag == 0)
	{
		printf("Enter the numb of tickets:");
		scanf(" %s", s);
		if (!CheckNumbers(s))
		{
			flag = 1;
		}
		else flag = 2;
	}
	a.tickets = atoi(s);

	if (n == 0)
	{
		arr = &a;
		SetFileRecord(arr, 1);
	}
	else
	{
		arr[n] = a;
		SetFileRecord(arr, n + 1);
		delete[]arrp;
		delete[]arrt;
	}
}
void AddPerformance()
{
	Performance* arr = NULL;
	int n = GetFilePerformance(&arr);
	Performance a;
	char s[70];
	int flag = 0;
	int fl = 0;
	while (fl == 0 || fl == 1)
	{
		flag = 0;
		while (flag == 1 || flag == 0)
		{
			printf("Enter the code:\n");
			scanf(" %s", s);
			if (!CheckNumbers(s))
			{
				flag = 1;
			}
			else flag = 2;
		}
		a.p_code = atoi(s);
		if (CheckPerformanceCode(arr, n, a.p_code))
		{
			printf("There's already performance with this code exist\n");
			fl = 1;
			system("pause");
		}
		else fl = 2;
	}
	flag = 0;
	while (flag == 1 || flag == 0)
	{
		printf("Enter the name:\n");
		scanf(" %s", s);
		if (!CheckLetters(s))
		{
			flag = 1;
		}
		else flag = 2;
	}
	strcpy(a.p_name, s);
	flag = 0;
	while (flag == 1 || flag == 0)
	{
		printf("Rating:\n");
		scanf(" %s", s);
		if (!CheckNumbers(s))
		{
			flag = 1;
		}
		else flag = 2;
	}
	a.rating = atoi(s);
	flag = 0;
	while (flag == 1 || flag == 0)
	{
		printf("Enter the cost:\n");
		scanf(" %s", s);
		if (!CheckNumbers(s))
		{
			flag = 1;
		}
		else flag = 2;
	}
	a.cost = atoi(s);
	flag = 0;
	while (flag == 1 || flag == 0)
	{
		printf("Enter the surname:\n");
		scanf(" %s", s);
		if (!CheckLetters(s))
		{
			flag = 1;
		}
		else flag = 2;
	}
	strcpy(a.actor.s_name, s);
	flag = 0;
	while (flag == 1 || flag == 0)
	{
		printf("Enter the name:\n");
		scanf(" %s", s);
		if (!CheckLetters(s))
		{
			flag = 1;
		}
		else flag = 2;
	}
	strcpy(a.actor.name, s);
	flag = 0;
	while (flag == 1 || flag == 0)
	{
		printf("Enter the last name:\n");
		scanf(" %s", s);
		if (!CheckLetters(s))
		{
			flag = 1;
		}
		else flag = 2;
	}
	strcpy(a.actor.l_name, s);
	flag = 0;
	while (flag == 1 || flag == 0)
	{
		printf("Enter the genre:\n");
		scanf(" %s", s);
		if (!CheckLetters(s))
		{
			flag = 1;
		}
		else flag = 2;
	}
	strcpy(a.genre, s);
	flag = 0;
	while (flag == 1 || flag == 0)
	{
		printf("Enter the author:\n");
		scanf(" %s", s);
		if (!CheckLetters(s))
		{
			flag = 1;
		}
		else flag = 2;
	}
	strcpy(a.author, s);
	if (n == 0)
	{
		arr = &a;
		SetFilePerformance(arr, 1);
	}
	else
	{
		arr[n] = a;
		SetFilePerformance(arr, n + 1);
		delete[]arr;
	}

}
void ViewTheatre(Theatre* arr, int n)
{
	puts("***************************************************************************************");
	puts("| № | Theatre  code | Theatre  name |       Adress       |   Phone   | Numb of places |");
	puts("***************************************************************************************");
	for (int i = 0; i < n; i++)
	{
		printf("|%3d|%15d|%15s|%14s %5d|%11d|%16d|\n", i + 1, arr[i].t_code, arr[i].t_name, arr[i].location.street, arr[i].location.home, arr[i].phone, arr[i].t_place);
		puts("***************************************************************************************");
	}
	system("pause");
}
void ViewRecord(Record* arr, int n)
{
	puts("****************************************************************************************");
	puts("| № | Theatre  code | Performance  code |    Season    |   Time   |   Date   | Tickets |");
	puts("****************************************************************************************");
	for (int i = 0; i < n; i++)
	{
		printf("|%3d|%15d|%19d|%14s|  %2d.%2d   |%2d.%2d.%4d|%9d|\n", i + 1, arr[i].t_code, arr[i].p_code, arr[i].season, arr[i]._time.hour, arr[i]._time.min, arr[i]._date.day, arr[i]._date.month, arr[i]._date.year, arr[i].tickets);
		puts("****************************************************************************************");
	}
	system("pause");

}
void ViewPerformance(Performance* arr, int n)
{
	puts("*************************************************************************************************************************************************");
	puts("| № | Performance code |      Performance  name       |  Rating  |               Main  Actor            | Cost |     Genre     |     Author     |");
	puts("*************************************************************************************************************************************************");
	for (int i = 0; i < n; i++)
	{
		printf("|%3d|%18d|%30s|%10d|%16s %8s %12s|%6d|%15s|%16s|\n", i + 1, arr[i].p_code, arr[i].p_name, arr[i].rating, arr[i].actor.s_name, arr[i].actor.name, arr[i].actor.l_name, arr[i].cost, arr[i].genre, arr[i].author);
		puts("*************************************************************************************************************************************************");
	}
	system("pause");
}
void DeletePerformance()
{
	Performance* arr = NULL;
	int n = GetFilePerformance(&arr);
	if (n == 0)
	{
		cout << "File is empty\n";
		system("pause");
		return;
	}
	ViewPerformance(arr, n);
	int z = -1;
	while (z<1 || z>n)
	{
		cout << "Vvedite nomer zapisi, kotoryu hotite ydalit\n";
		char s[70];
		cin >> s;
		if (CheckNumbers(s))
		{
			z = atoi(s);
		}
		if (z<1 || z>n)
		{
			cout << "Ne korrectny vvod\n";
		}
	}
	z--;
	Performance* arr1 = new Performance[n];
	int it = 0;
	for (int i = 0; i < z; i++)
	{
		arr1[it] = arr[i];
		it++;
	}
	for (int i = z + 1; i < n; i++)
	{
		arr1[it] = arr[i];
		it++;
	}
	SetFilePerformance(arr1, it);
	delete[] arr;
	delete[] arr1;
}
void DeleteTheatre()
{
	Theatre* arr = NULL;
	int n = GetFileTheatre(&arr);
	if (n == 0)
	{
		cout << "File of theatres is empty\n";
		system("pause");
		return;
	}
	ViewTheatre(arr, n);
	int z = -1;
	while (z<1 || z>n)
	{
		cout << "Enter the numb of the theatre to delete\n";
		char s[70];
		cin >> s;
		if (CheckNumbers(s))
		{
			z = atoi(s);
		}
		if (z<1 || z>n)
		{
			cout << "Incorrect input\n";
		}
	}
	z--;
	Theatre* arr1 = new Theatre[n];
	int it = 0;
	for (int i = 0; i < z; i++)
	{
		arr1[it] = arr[i];
		it++;
	}
	SetFileTheatre(arr1, it);
	delete[] arr;
	delete[] arr1;
}
void DeleteRecord()
{
	Record* arr = NULL;
	int n = GetFileRecord(&arr);
	if (n == 0)
	{
		cout << "File of records is empty\n";
		system("pause");
		return;
	}
	ViewRecord(arr, n);
	int z = -1;
	while (z<1 || z>n)
	{
		cout << "Enter the numb of record to delete\n";
		char s[70];
		cin >> s;
		if (CheckNumbers(s))
		{
			z = atoi(s);
		}
		if (z<1 || z>n)
		{
			cout << "Incorrect input\n";
		}
	}
	z--;
	Record* arr1 = new Record[n];
	int it = 0;
	for (int i = 0; i < n; i++)
	{
		arr1[it] = arr[i];
		it++;
	}
	SetFileRecord(arr1, it);
	delete[] arr;
	delete[] arr1;
}

void EditTheatre()
{
	bool work = true;
	Theatre* arr = NULL;
	int n = GetFileTheatre(&arr);
	if (n == 0)
	{
		cout << "File of theatres is empty\n";
		system("pause");
		return;
	}
	ViewTheatre(arr, n);
	int z = -1;
	while (z<1 || z>n)
	{
		cout << "Enter the numb of the theatre to edit:\n";
		char s[70];
		cin >> s;
		if (CheckNumbers(s))
		{
			z = atoi(s);
		}
		if (z<1 || z>n)
		{
			cout << "Incorrect input\n";
		}
	}
	z--;
	Theatre a = arr[z];
	while (work)
	{
		cout << "Choose the punct to change:\n1.Edit the name\n2.Edit adress\n3.Edit the phone\n4.Edit the numb of places\n5.Back to menu\n";
		char y;
		cin >> y;
		switch (y)
		{
		case '1':
		{
			char s[70];
			int flag = 0;
			while (flag == 1 || flag == 0)
			{
				printf("Enter the name:\n");
				scanf(" %s", s);
				if (!CheckLetters(s))
				{
					flag = 1;
				}
				else flag = 2;
			}
			strcpy(a.t_name, s);
			break;
		}
		case '2':
		{
			char s[70];
			int flag = 0;
			while (flag == 1 || flag == 0)
			{
				printf("Enter the street:\n");
				scanf(" %s", s);
				if (!CheckLetters(s))
				{
					flag = 1;
				}
				else flag = 2;
			}
			strcpy(a.location.street, s);
			flag = 0;
			while (flag == 1 || flag == 0)
			{
				printf("Enter the number of home:\n");
				scanf(" %s", s);
				if (!CheckNumbers(s))
				{
					flag = 1;
				}
				else flag = 2;
			}
			a.location.home = atoi(s);
			break;
		}
		case '3':
		{
			char s[70];
			int flag = 1;
			while (flag == 1 || flag == 0)
			{
				printf("Enter the number of phone(EX: +375XXXXXXXXX):\n+375");
				scanf(" %s", s);
				if (!CheckNumbers(s) || !CheckLength(s))
				{
					flag = 1;
				}
				else flag = 2;
			}
			a.phone = atoi(s);
			break;
		}
		case '4':
		{
			char s[70];
			int flag = 1;
			while (flag == 1 || flag == 0)
			{
				printf("Enter the quantity of places:\n");
				scanf(" %s", s);
				if (!CheckNumbers(s))
				{
					flag = 1;
				}
				else flag = 2;
			}
			a.t_place = atoi(s);
			break;
		}
		case '5':
			work = false;
			break;
		default:
			cout << "Input error";
			break;
		}
	}

	arr[z] = a;
	if (n == 0)
	{
		arr = &a;
		SetFileTheatre(arr, 1);
	}
	else
	{
		//arr[z] = a;
		SetFileTheatre(arr, n);
		delete[] arr;
	}
}
void EditPerformance()
{
	bool work = true;
	Performance* arr = NULL;
	int n = GetFilePerformance(&arr);
	if (n == 0)
	{
		cout << "File of performances is empty\n";
		return;
	}
	ViewPerformance(arr, n);
	int z = -1;
	while (z<1 || z>n)
	{
		cout << "Put the number of performance to edit:\n";
		char s[70];
		cin >> s;
		if (CheckNumbers(s))
		{
			z = atoi(s);
		}
		if (z<1 || z>n)
		{
			cout << "Incorrect input\n";
		}
	}
	z--;
	Performance a = arr[z];
	while (work)
	{
		cout << "Choose the punct to change:\n1.Edit the name\n2.Edit the rating\n3.Edit the actor\n4.Edit cost\n5.Edit genre\n6.Edit author\n7.Back to menu\n";
		char y;
		cin >> y;
		switch (y)
		{
		case '1':
		{
			char s[70];
			int flag = 0;
			while (flag == 1 || flag == 0)
			{
				printf("Enter the name:\n");
				scanf(" %s", s);
				if (!CheckLetters(s))
				{
					flag = 1;
				}
				else flag = 2;
			}
			strcpy(a.p_name, s);
			break;
		}
		case '2':
		{
			char s[70];
			int flag = 0;
			while (flag == 1 || flag == 0)
			{
				printf("Enter the rating:\n");
				scanf(" %s", s);
				if (!CheckNumbers(s))
				{
					flag = 1;
				}
				else flag = 2;
			}
			a.rating = atoi(s);
			break;
		}
		case '3':
		{
			char s[70];
			int flag = 0;
			while (flag == 1 || flag == 0)
			{
				printf("Enter the surname:\n");
				scanf(" %s", s);
				if (!CheckLetters(s))
				{
					flag = 1;
				}
				else flag = 2;
			}
			strcpy(a.actor.s_name, s);
			flag = 0;
			while (flag == 1 || flag == 0)
			{
				printf("Enter the name:\n");
				scanf(" %s", s);
				if (!CheckLetters(s))
				{
					flag = 1;
				}
				else flag = 2;
			}
			strcpy(a.actor.name, s);
			flag = 0;
			while (flag == 1 || flag == 0)
			{
				printf("Enter the last name:\n");
				scanf(" %s", s);
				if (!CheckLetters(s))
				{
					flag = 1;
				}
				else flag = 2;
			}
			strcpy(a.actor.l_name, s);
			break;
		}
		case '4':
		{
			char s[70];
			int flag = 0;
			while (flag == 1 || flag == 0)
			{
				printf("Enter the cost:\n");
				scanf(" %s", s);
				if (!CheckNumbers(s))
				{
					flag = 1;
				}
				else flag = 2;
			}
			a.cost = atoi(s);
			break;
		}
		case '5':
		{
			char s[70];
			int flag = 0;
			while (flag == 1 || flag == 0)
			{
				printf("Enter the genre:\n");
				scanf(" %s", s);
				if (!CheckLetters(s))
				{
					flag = 1;
				}
				else flag = 2;
			}
			strcpy(a.genre, s);
			break;
		}
		case '6':
		{
			char s[70];
			int flag = 0;
			while (flag == 1 || flag == 0)
			{
				printf("Enter the author:\n");
				scanf(" %s", s);
				if (!CheckLetters(s))
				{
					flag = 1;
				}
				else flag = 2;
			}
			strcpy(a.author, s);

			break;
		}
		case '7':
		{
			work = false;
			break;
		}
		default:
			cout << "Input error";
			break;
		}
	}
	arr[z] = a;
	if (n == 0)
	{
		arr = &a;
		SetFilePerformance(arr, 1);
	}
	else
	{
		arr[z] = a;
		SetFilePerformance(arr, n);
		delete[]arr;
	}
}
void EditRecord()
{

	bool work = true;
	Record* arr = NULL;
	int n = GetFileRecord(&arr);
	if (n == 0)
	{
		cout << "File of records is empty\n";
		return;
	}
	ViewRecord(arr, n);
	int z = -1;
	while (z<1 || z>n)
	{
		cout << "Enter the number of record to edit:\n";
		char s[70];
		cin >> s;
		if (CheckNumbers(s))
		{
			z = atoi(s);
		}
		if (z<1 || z>n)
		{
			cout << "Incorrect input\n";
		}
	}
	z--;
	Record a = arr[z];
	arr[z] = a;
	while (work)
	{
		cout << "Choose the punct to change:\n1.Edit season\n2.Edit time\n3.Edit date\n4.Edit the numb of tickets\n5.Back to menu\n";
		char y;
		cin >> y;
		switch (y)
		{
		case '1':
		{
			char s[70];
			int flag = 0;
			while (flag == 1 || flag == 0)
			{
				printf("Enter the season:\n");
				scanf(" %s", s);
				if (!CheckLetters(s))
				{
					flag = 1;
				}
				else flag = 2;
			}
			strcpy(a.season, s);
			break;
		}
		case '2':
		{
			cout << "Enter the time:\n";
			a._time = ReadTime();
			break;
		}
		case '3':
		{
			cout << "Enter the date:\n";
			a._date = ReadDate();
			break;
		}
		case '4':
		{
			char s[70];
			int flag = 1;
			while (flag == 1 || flag == 0)
			{
				printf("Enter the number of tickets:\n");
				scanf(" %s", s);
				if (!CheckNumbers(s))
				{
					flag = 1;
				}
				else flag = 2;
			}
			a.tickets = atoi(s);
			break;
		}
		case '5':
		{
			work = false;
			break;
		}
		default:
			cout << "Input error\n";
			break;
		}
	}
	arr[z] = a;
	if (n == 0)
	{
		arr = &a;
		SetFileRecord(arr, 1);
	}
	else
	{
		arr[z] = a;
		SetFileRecord(arr, n);
		delete[]arr;
	}
}

int Compare_time(Time a, Time b)
{
	if (a.hour > b.hour)
	{
		return 1;
	}
	else if (a.hour < b.hour)
	{
		return -1;
	}
	else
		if (a.min > b.min)
		{
			return 1;
		}
		else if (a.min < b.min)
		{
			return -1;
		}
		else
		{
			return 0;
		}

}

Time ReadTime()
{
	Time a;
	a.min = -1;
	a.hour = -1;
	while (a.min < 0 || a.min >= 60 || a.hour < 0 || a.hour >= 24)
	{
		cout << "Enter the time in hh.mm format\n";
		char c;
		cin >> a.hour >> c >> a.min;
		if (a.hour < 0 || a.hour >= 24)
		{
			cout << "Error in hours\n";
		}
		if (a.min < 0 || a.min >= 60)
		{
			cout << "Error in minutes\n";
		}
	}
	return a;
}

void WriteTime(Time a)
{
	if (a.hour < 10)
	{
		cout << "0";
	}
	cout << a.hour << ":";
	if (a.min < 10)
	{
		cout << "0";
	}
	cout << a.min;
}

int Compare_date(Date a, Date b)
{
	if (a.year > b.year)
	{
		return 1;
	}
	else if (a.year < b.year)
	{
		return -1;
	}
	else
	{
		if (a.month > b.month)
		{
			return 1;
		}
		else if (a.month < b.month)
		{
			return -1;
		}
		else
		{
			if (a.day > b.day)
			{
				return 1;
			}
			else if (a.day < b.day)
			{
				return -1;
			}
			else
			{
				return 0;
			}
		}
	}
}
Date ReadDate()
{
	Date a;
	a.day = 0;
	a.month = 0;
	a.year = 0;
	while (a.year < 2000 || a.year>2021 || a.month > 12 || a.month < 1 || a.day < 1 || a.day>31)
	{
		cout << "Введите дату в формате dd.mm.yyyy\n";
		char c;
		cin >> a.day >> c >> a.month >> c >> a.year;
		if (a.year < 2000 || a.year>2021)
		{
			cout << "Год должен быть указан в диапазоне от 2000 до 2021.\n";
		}
		if (a.month > 12 || a.month < 1)
		{
			cout << "Не корректный ввод месяца.\n";
		}
		if (a.day < 1 || a.day>31)
		{
			cout << "Не корректный ввод дня.\n";
		}
	}
	return a;
}
void WriteDate(Date a)
{
	if (a.day < 10)
	{
		cout << 0;
	}
	cout << a.day << ".";
	if (a.month < 10)
	{
		cout << 0;
	}
	cout << a.month << "." << a.year;
}


void MenuAdmin()
{
	bool work = true;
	while (work)
	{
		system("cls");
		printf("1.Просмотр всех записей\n");
		printf("2.Добавление новой записи\n");
		printf("3.Редактирование записей\n");
		printf("4.Удаление записей\n");
		printf("5.Алгоритмы поиска\n");
		printf("6.Алгоритмы сортировки\n");
		printf("7.Алгоритмы фильтрации\n");
		printf("8.Меню управления пользователями\n");
		printf("9.Выход в меню выбора пользователей\n");
		char c;
		scanf(" %c", &c);
		switch (c)
		{
		case '1':
		{
			MenuView();
			break;
		}
		case '2':
		{
			MenuAdd();
			break;
		}
		case '3':
		{
			MenuEdit();
			break;
		}
		case '4':
		{
			MenuDelete();
			break;
		}
		case '5':
		{
			MenuSearch();
			break;
		}
		case '6':
		{
			MenuSort();
			break;
		}
		case '7':
		{
			MenuFiltration();
			break;
		}
		case '8':
		{
			MenuUserControl();
			break;
		}
		case '9':
		{
			work = false;
			break;
		}
		default:
		{
			system("cls");
			printf("Некорректный ввод.Попробуйте ещё раз\n");
			system("pause");
			break;
		}
		}
	}

}

void MenuUserControl()
{
	char path[20];
	bool work = true;
	while (work)
	{
		system("cls");
		printf("1.Работа с данными об администраторах\n");
		printf("2.Работа с данными о пользователях\n");
		printf("3.Выход в меню первого уровня\n");
		char c;
		scanf(" %c", &c);
		switch (c)
		{
		case '1':
		{
			char a[20] = "admin.txt";
			strcpy(path, a);
			work = false;
			break;
		}

		case '2':
		{
			char a[20] = "user.txt";
			strcpy(path, a);
			work = false;
			break;
		}
		case '3':
		{
			return;
		}
		default:
		{
			system("cls");
			printf("Некорректный ввод.Попробуйте ещё раз\n");
			system("pause");
			break;
		}
		}
	}
	work = true;
	while (work)
	{
		Log* arr;
		int n = GetFileLog(&arr, path);
		system("cls");
		printf("1.Просмотр всех аккаунтов\n");
		printf("2.Регистрация нового аккаунта\n");
		printf("3.Удаление аккаунта\n");
		printf("4.Выход в меню первого уровня\n");
		char c;
		scanf(" %c", &c);
		switch (c)
		{
		case '1':
		{
			ViewUser(arr, n);
			break;
		}
		case '2':
		{
			arr[n] = AddUser(arr, n);
			n++;
			break;
		}
		case '3':
		{
			DelUser(arr, n);
			n--;
			break;
		}
		case '4':
		{
			work = false;
			break;
		}
		default:
		{
			system("cls");
			printf("Некорректный ввод.Попробуйте ещё раз\n");
			system("pause");
			break;
		}
		}
		SetFileLog(arr, n, path);
		if (n != 0)
		{
			delete[] arr;
		}
	}
}

void MenuView()
{
	bool work(true);
	while (work)
	{
		system("cls");
		cout << "1.Watch throught the list of performances\n2.Watch throught the records\n3.Watch throught the theatre\n4.Back to menu\n";
		char c;
		scanf(" %c", &c);
		switch (c)
		{
		case '1':
		{
			Performance* arr = NULL;
			int n = GetFilePerformance(&arr);
			if (n == 0)
			{
				cout << "File of performances is empty\n";
				system("pause");
				break;
			}
			ViewPerformance(arr, n);
			delete[] arr;
			break;
		}
		case '2':
		{
			Record* arr = NULL;
			int n = GetFileRecord(&arr);
			if (n == 0)
			{
				cout << "File of records is empty\n";
				system("pause");
				break;
			}
			ViewRecord(arr, n);
			delete[] arr;
			break;
		}
		case '3':
		{
			Theatre* arr = NULL;
			int n = GetFileTheatre(&arr);
			if (n == 0)
			{
				cout << "File of theatres is empty\n";
				system("pause");
				break;
			}
			ViewTheatre(arr, n);
			delete[] arr;
			break;
		}
		case '4':
		{
			work = false;
			break;
		}
		default:
			printf("Некорректный ввод.Попробуйте ещё раз\n");
			system("pause");
			break;
		}
	}
}

void MenuAdd()
{
	bool work(true);
	while (work)
	{
		system("cls");
		cout << "1.Add a session\n2.Add a theatre\n3.Add a performance\n4.Back to menu\n";
		char c;
		scanf(" %c", &c);
		switch (c)
		{
		case '1':
		{
			AddRecord();
			break;
		}
		case '2':
		{
			AddTheatre();
			break;
		}
		case '3':
		{
			AddPerformance();
			break;
		}
		case '4':
		{
			work = false;
			break;
		}
		default:
			printf("Некорректный ввод.Попробуйте ещё раз\n");
			system("pause");
			break;
		}
	}
}

void MenuEdit()
{
	bool work(true);
	while (work)
	{
		system("cls");
		cout << "1.Edit information about session\n2.Edit information about theatre\n3.Edit information about performance\n4.Back to menu\n";
		char c;
		scanf(" %c", &c);
		switch (c)
		{
		case '1':
		{
			EditRecord();
			break;
		}
		case '2':
		{
			EditTheatre();
			break;
		}
		case '3':
		{
			EditPerformance();
			break;
		}
		case '4':
		{
			work = false;
			break;
		}
		default:
			printf("Некорректный ввод.Попробуйте ещё раз\n");
			system("pause");
			break;
		}
	}
}

void MenuDelete()
{
	bool work(true);
	while (work)
	{
		system("cls");
		cout << "1.Delete a session\n2.Delete a theatre\n3.Delete a performance\n4.Back to menu\n";
		char c;
		scanf(" %c", &c);
		switch (c)
		{
		case '1':
		{
			DeleteRecord();
			break;
		}
		case '2':
		{
			DeleteTheatre();
			break;
		}
		case '3':
		{
			DeletePerformance();
			break;
		}
		case '4':
		{
			work = false;
			break;
		}
		default:
			printf("Некорректный ввод.Попробуйте ещё раз\n");
			system("pause");
			break;
		}
	}
}

void MenuSearch()
{
	bool work(true);
	while (work)
	{
		system("cls");
		cout << "1.Search acording to season\n2.Search according to the theatre\n3.Search according to performance\n4.Search according to the actor\n5.Search according to genre\n6.Back to menu\n";
		char c;
		scanf(" %c", &c);
		switch (c)
		{
		case '1':
		{
			SearchRecordSes();
			break;
		}
		case '2':
		{
			SearchTheatre();
			break;
		}
		case '3':
		{
			SearchPerformance();
			break;
		}
		case '4':
		{
			SearchPerformanceActor();
			break;
		}
		case '5':
		{
			SearchPerformanceGenre();
			break;
		}
		case '6':
		{
			work = false;
			break;
		}
		default:
			printf("Некорректный ввод.Попробуйте ещё раз\n");
			system("pause");
			break;
		}
	}
}

void MenuSort()
{
	bool work(true);
	while (work)
	{
		system("cls");
		cout << "1.Sort performance according to an alphabet\n2.Sort performance according to rating\n3.Sort performance according to cost \n4.Back to menu\n";
		char c;
		scanf(" %c", &c);
		switch (c)
		{
		case '1':
		{
			SortAbc();
			break;
		}
		case '2':
		{
			SortRating();
			break;
		}
		case '3':
		{
			SortCost();
			break;
		}
		case '4':
		{
			work = false;
			break;
		}
		default:
			printf("Некорректный ввод.Попробуйте ещё раз\n");
			system("pause");
			break;
		}
	}
}

void MenuFiltration()
{
	bool work(true);
	while (work)
	{
		system("cls");
		cout << "1.Filter according to cost\n2.Filter according to rating\n3.Back to menu\n";
		char c;
		scanf(" %c", &c);
		switch (c)
		{
		case '1':
		{
			FilterCost();
			break;
		}
		case '2':
		{
			FilterRating();
			break;
		}
		case '3':
		{
			work = false;
			break;
		}
		default:
			printf("Некорректный ввод.Попробуйте ещё раз\n");
			system("pause");
			break;
		}
	}
}

bool LogIn(char str[])
{
	Log* arr = NULL;
	int n = GetFileLog(&arr, str);
	if (n == 0)
	{
		printf("Это первый вход.Зарегистрируйтесь\n");
		arr = new Log[2];
		arr[0] = AddUser(arr, 0);
		SetFileLog(arr, 1, str);
		return true;
	}
	int k = 3;
	while (k != 0)
	{
		char s[70];
		printf("Введите логин\n");
		scanf(" %70s", s);
		int flag = 0;
		int index = -1;
		for (int i = 0; i < n; i++)
		{
			if (strcmp(s, arr[i].logIn) == 0)
			{
				index = i;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			printf("\nТакого логина не существует\n");
			system("pause");
		}
		else
		{
			printf("Введите пароль\n");
			char c = 0;
			char str[70];
			int it = 0;
			do
			{
				c = _getch();
				if (c == '\b')
				{
					if (it != 0)
					{
						printf("\b \b");
						it--;
					}
				}
				else if (c == 13)
				{
					str[it] = '\0';
					it++;
				}
				else
				{
					str[it] = c;
					it++;
					printf("*");
				}

			} while (c != 13);
			if (strcmp(str, arr[index].passWord) == 0)
			{
				printf("\nВход выполнен успешно\n");
				system("pause");
				return true;
			}
			else
			{
				printf("\nНе верный пароль\n");
				
			}
		}
		k--;
	}
	printf("\nВы исчерпали все попытки\n");
	system("pause");
	return false;
}

void UserMenu()
{
	bool work = true;
	while (work)
	{
		system("cls");
		printf("1.Вывод данных в табличной форме\n");
		printf("2.Поиск данных\n");
		printf("3.Сортировка данных\n");
		printf("4.Фильтрация данных\n");
		printf("5.Выполнение инд.задания\n");
		printf("6.Выход\n");
		char c;
		scanf(" %c", &c);
		switch (c)
		{
		case '1':
		{
			MenuView();
			break;
		}
		case '2':
		{
			MenuSearch();
			break;
		}
		case '3':
		{
			MenuSort();
			break;
		}
		case '4':
		{
			MenuFiltration();
			break;
		}
		case '5':
		{
			Task();
			break;
		}
		case '6':
		{
			work = false;
			break;
		}
		default:
		{
			system("cls");
			printf("Некорректный ввод\n");
			system("pause");
			break;
		}
		}
	}
}

void MenuLogIn()
{
	bool work = true;
	while (work)
	{
		system("cls");
		printf("1.Авторизация под именем администратора\n");
		printf("2.Авторизация под именем пользователя\n");
		printf("3.Выход из программы\n");
		char c;
		scanf(" %c", &c);
		switch (c)
		{
		case '1':
		{
			char s[70] = "admin.txt";
			if (LogIn(s))
			{
				MenuAdmin();
			}
		}
		break;
		case '2':
		{
			char s[70] = "user.txt";
			if (LogIn(s))
			{
				UserMenu();
			}
		}
		break;
		case '3':
		{
			work = false;
		}
		break;
		default:
		{
			system("cls");
			printf("Некорректный ввод.Попробуйте ещё раз\n");
			system("pause");
			break;
		}
		}
	}
}

int GetFileLog(Log** arr, char str[])
{
	int n = 0;
	FILE* fp;
	fp = fopen(str, "r+");
	fseek(fp, 0L, SEEK_END);
	n = ftell(fp) / sizeof(Log);
	fseek(fp, 0L, SEEK_SET);
	if (n == 0)
	{
		return 0;
	}
	*arr = new Log[n + 1];
	for (int i = 0; i < n; i++)
	{
		fread(*arr + i, sizeof(Log), 1, fp);
		for (int j = 0; j < strlen((*arr)[i].logIn); j++)
		{
			(*arr)[i].logIn[j] -= 20;
		}
		for (int j = 0; j < strlen((*arr)[i].passWord); j++)
		{
			(*arr)[i].passWord[j] -= 20;
		}
	}
	fclose(fp);
	return n;
}

int GetFileRecord(Record** arr)
{
	int n = 0;
	FILE* fp = NULL;
	fp = fopen("record.txt", "r+");
	fseek(fp, 0L, SEEK_END);
	n = ftell(fp) / sizeof(Record);
	fseek(fp, 0L, SEEK_SET);
	if (n == 0)
	{
		return 0;
	}
	*arr = new Record[n + 1];
	for (int i = 0; i < n; i++)
	{
		fread(*arr + i, sizeof(Record), 1, fp);
	}
	fclose(fp);
	return n;
}

int GetFileTheatre(Theatre** arr)
{
	int n = 0;
	FILE* fp = NULL;
	fp = fopen("theatre.txt", "r+");
	fseek(fp, 0L, SEEK_END);
	n = ftell(fp) / sizeof(Theatre);
	fseek(fp, 0L, SEEK_SET);
	if (n == 0)
	{
		return 0;
	}
	*arr = new Theatre[n + 1];
	for (int i = 0; i < n; i++)
	{
		fread(*arr + i, sizeof(Theatre), 1, fp);
	}
	fclose(fp);
	return n;
}

int GetFilePerformance(Performance** arr)
{
	int n = 0;
	FILE* fp = NULL;
	fp = fopen("performance.txt", "r+");
	fseek(fp, 0L, SEEK_END);
	n = ftell(fp) / sizeof(Performance);
	fseek(fp, 0L, SEEK_SET);
	if (n == 0)
	{
		return 0;
	}
	*arr = new Performance[n + 1];
	for (int i = 0; i < n; i++)
	{
		fread(*arr + i, sizeof(Performance), 1, fp);
	}
	fclose(fp);
	return n;
}

void SetFileLog(Log* arr, int n, char str[])
{
	FILE* fp;
	fp = fopen(str, "w+");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < strlen(arr[i].logIn); j++)
		{
			arr[i].logIn[j] += 20;
		}
		for (int j = 0; j < strlen(arr[i].passWord); j++)
		{
			arr[i].passWord[j] += 20;
		}
		fwrite(arr + i, sizeof(Log), 1, fp);
	}
	fclose(fp);
}

void SetFileRecord(Record* arr, int n)
{
	FILE* fp;
	fp = fopen("record.txt", "w+");
	for (int i = 0; i < n; i++)
	{
		fwrite(arr + i, sizeof(Record), 1, fp);
	}
	fclose(fp);
}

void SetFileTheatre(Theatre* arr, int n)
{
	FILE* fp;
	fp = fopen("theatre.txt", "w+");
	for (int i = 0; i < n; i++)
	{
		fwrite(arr + i, sizeof(Theatre), 1, fp);
	}
	fclose(fp);
}

void SetFilePerformance(Performance* arr, int n)
{
	FILE* fp;
	fp = fopen("performance.txt", "w+");
	for (int i = 0; i < n; i++)
	{
		fwrite(arr + i, sizeof(Performance), 1, fp);
	}
	fclose(fp);
}
void SearchRecordSes()
{
	Record* arr = NULL;
	int n = GetFileRecord(&arr);
	if (n == 0)
	{
		printf("File of records is epmty\n");
		system("pause");
		return;
	}
	char s[70];
	int flag = 0;
	while (flag == 1 || flag == 0)
	{
		printf("Enter the season:\n");
		scanf(" %s", s);
		if (!CheckLetters(s))
		{
			flag = 1;
		}
		else flag = 2;
	}
	Record* arr1 = new Record[n];
	int it = 0;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(arr[i].season, s) == 0)
		{
			arr1[it] = arr[i];
			it++;
		}
	}
	if (it == 0)
	{
		printf("No records have founded\n");
		system("pause");
		return;
	}
	ViewRecord(arr1, it);
	delete[] arr;
	delete[] arr1;

}
void SearchTheatre()
{
	Theatre* arr = NULL;
	int n = GetFileTheatre(&arr);
	if (n == 0)
	{
		printf("File of thetres is empty\n");
		system("pause");
		return;
	}
	char s[70];
	int flag = 0;
	while (flag == 1 || flag == 0)
	{
		printf("Enter the name of theatre:\n");
		scanf(" %s", s);
		if (!CheckLetters(s))
		{
			flag = 1;
		}
		else flag = 2;
	}
	Theatre* arr1 = new Theatre[n];
	int it = 0;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(s, arr[i].t_name) == 0)
		{
			arr1[it] = arr[i];
			it++;
		}
	}
	SetFileTheatre(arr, n);
	if (it == 0)
	{
		printf("No theatres have founded\n");
			system("pause");
		return;
	}
	ViewTheatre(arr1, it);
	delete[] arr;
	delete[] arr1;
}
void SearchPerformance()
{
	Performance* arr = NULL;
	int n = GetFilePerformance(&arr);
	if (n == 0)
	{
		printf("File of performances is epmty\n");
		system("pause");
		return;
	}
	char s[70];
	int flag = 0;
	while (flag == 1 || flag == 0)
	{
		printf("Enter the name of play:\n");
		scanf(" %s", s);
		if (!CheckLetters(s))
		{
			flag = 1;
		}
		else flag = 2;
	}
	Performance* arr1 = new Performance[n];
	int it = 0;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(s, arr[i].p_name) == 0)
		{
			arr1[it] = arr[i];
			it++;
		}
	}
	SetFilePerformance(arr, n);
	if (it == 0)
	{
		printf("No perfomances have founded\n");
		system("pause");
		return;
	}
	ViewPerformance(arr1, it);
	delete[] arr;
	delete[] arr1;
}
void SearchPerformanceActor()
{
	Performance* arr = NULL;
	int n = GetFilePerformance(&arr);
	if (n == 0)
	{
		printf("File of performancec is empty\n");
		system("pause");
		return;
	}
	char s[70];
	char s1[70];
	char s2[70];
	int flag = 0;
	while (flag == 1 || flag == 0)
	{
		printf("Enter the surname of main actor:\n");
		scanf(" %s", s);
		if (!CheckLetters(s))
		{
			flag = 1;
		}
		else flag = 2;
	}
	flag = 0;
	while (flag == 1 || flag == 0)
	{
		printf("Enter the name of main actor:\n");
		scanf(" %s", s1);
		if (!CheckLetters(s1))
		{
			flag = 1;
		}
		else flag = 2;
	}
	flag = 0;
	while (flag == 1 || flag == 0)
	{
		printf("Enter the lastname of main actor:\n");
		scanf(" %s", s2);
		if (!CheckLetters(s2))
		{
			flag = 1;
		}
		else flag = 2;
	}
	Performance* arr1 = new Performance[n];
	int it = 0;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(arr[i].actor.s_name, s) == 0)
		{
			if (strcmp(arr[i].actor.name, s1) == 0)
			{
				if (strcmp(arr[i].actor.l_name, s2) == 0)
				{
					arr1[it] = arr[i];
					it++;
				}
			}
		}
	}
	if (it == 0)
	{
		printf("No performancec have founded\n");
		system("pause");
		return;
	}
	ViewPerformance(arr1, it);
	delete[] arr;
	delete[] arr1;
}
void SearchPerformanceGenre()
{
	Performance* arr = NULL;
	int n = GetFilePerformance(&arr);
	if (n == 0)
	{
		printf("File of performances is empty\n");
		system("pause");
		return;
	}
	char s[70];
	int flag = 0;
	while (flag == 1 || flag == 0)
	{
		printf("Enter the genre:\n");
		scanf(" %s", s);
		if (!CheckLetters(s))
		{
			flag = 1;
		}
		else flag = 2;
	}
	Performance* arr1 = new Performance[n];
	int it = 0;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(arr[i].genre, s) == 0)
		{
			arr1[it] = arr[i];
			it++;
		}
	}
	if (it == 0)
	{
		printf("No performances have founded\n");
		system("pause");
		return;
	}
	ViewPerformance(arr1, it);
	delete[] arr;
	delete[] arr1;
}
void SortAbc()
{
	Performance* arr = NULL;
	int n = GetFilePerformance(&arr);
	if (n == 0)
	{
		printf("File of performances is epmty\n");
		system("pause");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (strcmp(arr[i].p_name, arr[j].p_name) > 0)
			{
				swap(arr[i], arr[j]);
			}
		}
	}
	ViewPerformance(arr, n);
	delete[] arr;
}
void SortRating()
{
	Performance* arr = NULL;
	int n = GetFilePerformance(&arr);
	if (n == 0)
	{
		printf("File of performances is empty\n");
		system("pause");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (arr[i].rating < arr[j].rating)
			{
				swap(arr[i], arr[j]);
			}
		}
	}
	ViewPerformance(arr, n);
	delete[] arr;
}
void SortCost()
{
	Performance* arr = NULL;
	int n = GetFilePerformance(&arr);
	if (n == 0)
	{
		printf("File of performances is empty\n");
		system("pause");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (arr[i].cost < arr[j].cost)
			{
				swap(arr[i], arr[j]);
			}
		}
	}
	ViewPerformance(arr, n);
	delete[] arr;
}
void FilterCost()
{
	Performance* arr = NULL;
	int n = GetFilePerformance(&arr);
	if (n == 0)
	{
		printf("File of performances is empty\n");
		system("pause");
		return;
	}
	char s[70];
	int flag = 0;
	while (flag == 1 || flag == 0)
	{
		printf("Enter the cost (bottom):");
		scanf(" %s", s);
		if (!CheckNumbers(s))
		{
			flag = 1;
		}
		else flag = 2;
	}
	int a = atoi(s);
	flag = 0;
	while (flag == 1 || flag == 0)
	{
		printf("Enter the cost (ceiling):");
		scanf(" %s", s);
		if (!CheckNumbers(s))
		{
			flag = 1;
		}
		else flag = 2;
	}
	int b = atoi(s);
	if (b < a)
	{
		swap(a, b);
	}
	Performance* arr1 = new Performance[n];
	int it = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i].cost<b && arr[i].cost>a)
		{
			arr1[it] = arr[i];
			it++;
		}
	}
	ViewPerformance(arr1, it);
	delete[] arr;
	delete[] arr1;
}
void FilterRating()
{
	Performance* arr = NULL;
	int n = GetFilePerformance(&arr);
	if (n == 0)
	{
		printf("File of performances is empty\n");
		system("pause");
		return;
	}
	char s[70];
	int flag = 0;
	while (flag == 1 || flag == 0)
	{
		printf("Enter the ratting (bottom):");
		scanf(" %s", s);
		if (!CheckNumbers(s))
		{
			flag = 1;
		}
		else flag = 2;
	}
	int a = atoi(s);
	flag = 0;
	while (flag == 1 || flag == 0)
	{
		printf("Enter the ratting (ceiling):");
		scanf(" %s", s);
		if (!CheckNumbers(s))
		{
			flag = 1;
		}
		else flag = 2;
	}
	int b = atoi(s);
	if (b < a)
	{
		swap(a, b);
	}
	Performance* arr1 = new Performance[n];
	int it = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i].rating<b && arr[i].rating>a)
		{
			arr1[it] = arr[i];
			it++;
		}
	}
	ViewPerformance(arr1, it);
	delete[] arr;
	delete[] arr1;
}

Log AddUser(Log* arr, int n)
{
	Log a;
	bool correct = false;
	while (!correct)
	{
		printf("Введите логин\n");
		scanf(" %s", a.logIn);
		correct = true;
		for (int i = 0; i < n; i++)
		{
			if (strcmp(a.logIn, arr[i].logIn) == 0)
			{
				correct = false;
				printf("Такой логин уже существует\n");
				break;
			}
		}
	}
	printf("Введите пароль\n");
	scanf(" %s", a.passWord);
	return a;
}
void DelUser(Log* arr, int n)
{
	ViewUser(arr, n);
	printf("Выберите номер записи, которую хотите удалить\n");
	int z = -1;
	char c[50];
	while (z<1 || z>n)
	{
		scanf(" %s", c);
		if (CheckNumbers(c))
		{
			z = atoi(c);
		}
		if (z<1 || z>n)
		{
			printf("Некорректный ввод\n");
		}
	}
	z--;
	for (int i = z; i < n; i++)
	{
		arr[i] = arr[i + 1];
	}
}
void ViewUser(Log* arr, int n)
{
	puts("**********************************");
	puts("| №  |    Логин    |    Пароль   |");
	puts("**********************************");
	for (int i = 0; i < n; i++)
	{
		printf("|%3d | %11s | %11s |\n", i + 1, arr[i].logIn, arr[i].passWord);
		puts("**********************************");
	}
	system("pause");
}
void Srart()
{
	FILE* f = NULL;
	f = fopen("theatre.txt", "w+");
	fclose(f);
	f = fopen("record.txt", "w+");
	fclose(f);
	f = fopen("performance.txt", "w+");
	fclose(f);
	f = fopen("user.txt", "w+");
	fclose(f);
	f = fopen("admin.txt", "w+");
	fclose(f);
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RUS");
	//Srart();
	MenuLogIn();
	return 0;
}

void Task()
{
	system("cls");
	Record* arr = NULL;
	int n = GetFileRecord(&arr);
	if (n == 0)
	{
		printf("Not enought data\n");
		system("pause");
		return;
	}

	char s[70];
	int month = 0;
	while (month < 1 || month >12)
	{
		printf("Выберите месяц:\n");
		printf("1.Январь\n");
		printf("2.Февраль\n");
		printf("3.Март\n");
		printf("4.Апрель\n");
		printf("5.Май\n");
		printf("6.Июнь\n");
		printf("7.Июль\n");
		printf("8.Август\n");
		printf("9.Сентябрь\n");
		printf("10.Октябрь\n");
		printf("11.Ноябрь\n");
		printf("12.Декабрь\n");
		scanf(" %s", s);
		if (CheckNumbers(s))
		{
			month = atoi(s);
		}
	}
	int year = 0;
	while (year < 2000 || year>2023)
	{
		printf("Выберите год:\n");
		scanf(" %s", s);
		if (CheckNumbers(s))
		{
			year = atoi(s);
		}
	}

	Record* rec = (Record*)malloc(sizeof(Record) * n);
	int nRec = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i]._date.year == year && arr[i]._date.month == month)
		{
			rec[nRec] = arr[i];
			nRec++;
		}
	}
	if (nRec == 0)
	{
		printf("В этом месяце постановок нет\n");
		free(arr);
		free(rec);
		system("pause");
		return;
	}

	Theatre* theatres = NULL;
	int nTh = GetFileTheatre(&theatres);
	if (nTh == 0)
	{
		printf("Недостаточно данных\n");
		system("pause");
		free(arr);
		free(rec);
		return;
	}

	Performance* perf = NULL;
	int nPer = GetFilePerformance(&perf);
	if (nPer == 0)
	{
		printf("Недостаточно данных\n");
		system("pause");
		free(arr);
		free(rec);
		free(theatres);
		return;
	}

	int* indexesT = (int*)malloc(sizeof(int) * nTh);
	for (int i = 0; i < nTh; i++)
	{
		indexesT[i] = 0;
	}

	for (int i = 0; i < nRec; i++)
	{
		for (int j = 0; j < nTh; j++)
		{
			if (rec[i].t_code == theatres[j].t_code)
			{
				indexesT[j]++;
			}
		}
	}
	for (int i = 0; i < nTh; i++)
	{
		for (int j = i; j < nTh; j++)
		{
			if (indexesT[i] < indexesT[j])
			{
				Theatre temp = theatres[i];
				theatres[i] = theatres[j];
				theatres[j] = temp;
				int t = indexesT[i];
				indexesT[i] = indexesT[j];
				indexesT[j] = t;
			}
		}
	}
	int x = 0;
	while (x < nTh && indexesT[x] != 0)
	{
		x++;
	}
	if (x != 0)
	{
		printf("Самые популярные театры этого месяца:\n");
		ViewTheatre(theatres, x);
	}
	else
	{
		printf("Театров в этом месяце нет\n");
	}
	free(theatres);
	free(indexesT);

	indexesT = (int*)malloc(sizeof(int) * nPer);
	for (int i = 0; i < nPer; i++)
	{
		indexesT[i] = 0;
	}

	for (int i = 0; i < nRec; i++)
	{
		for (int j = 0; j < nPer; j++)
		{
			if (rec[i].p_code == perf[j].p_code)
			{
				indexesT[j]++;
			}
		}
	}
	for (int i = 0; i < nPer; i++)
	{
		for (int j = i; j < nPer; j++)
		{
			if (indexesT[i] < indexesT[j])
			{
				Performance temp = perf[i];
				perf[i] = perf[j];
				perf[j] = temp;
				int t = indexesT[i];
				indexesT[i] = indexesT[j];
				indexesT[j] = t;
			}
		}
	}
	x = 0;
	while (x < nPer && indexesT[x] != 0)
	{
		x++;
	}
	if (x != 0)
	{
		printf("Самые популярные постановки этого месяца:\n");
		ViewPerformance(perf, x);
	}
	else
	{
		printf("Постановок в этом месяце нет\n");
	}

	system("pause");
	free(perf);
	free(arr);
	free(rec);
	free(indexesT);
}
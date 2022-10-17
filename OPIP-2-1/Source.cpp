#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <iostream>

using namespace std;

class Intern {
public:
	int salary;
	Intern() { //cout << "Вызван конструктор класса Intern " << this << endl; 
		salary = 150;
	}
	~Intern() {
		salary = -1;
		cout << "Вызван деструктор класса Intern " << this << endl;
	}
	virtual void makeCoffee() = 0;
	virtual void makeIssue() = 0;
	virtual void returnWorker(int) = 0;
};

class Employee : public Intern {
public:
	Employee() { //cout << "Вызван конструктор класса Employee " << this << endl; 
		this->salary = 500;
	}
	~Employee() {
		salary = -1;
		cout << "Вызван деструктор класса Employee " << this << endl;
	}
	void returnWorker(int prev) {
		cout << "Новый сотрудник прибыл на место прошлого номера " << prev + 1 << endl; this->salary = 500;
	}
	void makeCoffee() { cout << "Вот ваш вкусный кофе!\n"; }
	void makeIssue() { cout << "Отчёт выполнен и ждёт проверки на вашей почте!\n"; }
	virtual void makeFeature() { cout << "Я долго работал и готов показать вам свою наработку!\n"; };
	int virtual operator=(Employee& obj) {
		this->salary = obj.salary;
		return 1;
	}
};

class HardwareEng : public virtual Employee {
public:
	HardwareEng() { this->salary = 1500; }
	~HardwareEng() {
		salary = -1;
		cout << "Вызван деструктор класса HardwareEng " << this << endl;
	}
	void returnWorker(int prev) {
		Employee::returnWorker(prev);
		this->salary = 1500;
	}
	void makeFeature() {
		Employee::makeFeature();
		cout << "Проверьте её в новой ветке 'HRDWRfeature' в нашем репозитории\n";
	}
	void makeIssue() {
		cout << "Для получения отчёта обратитесь к Employee. Он обладает моим отчётом!" << endl;
	}
	int operator=(HardwareEng& obj) {
		this->salary = obj.salary;
		return 1;
	}
};

class SoftwareEng : public virtual Employee {
public:
	SoftwareEng() { this->salary = 1500; }
	~SoftwareEng() {
		cout << "Вызван деструктор класса SoftwareEng " << this << endl;
		this->salary = 1500;
	}
	void returnWorker(int prev) {
		Employee::returnWorker(prev);
	}
	void makeFeature() {
		Employee::makeFeature();
		cout << "Проверьте её в новой ветке 'SFTWRfeature' в нашем репозитории\n";
	}
	void makeIssue() {
		cout << "Для получения отчёта обратитесь к Employee. Он обладает моим отчётом!" << endl;
	}
	int operator=(SoftwareEng& obj) {
		this->salary = obj.salary;
		return 1;
	}
};

class Teamlead : public HardwareEng {
public:
	Teamlead() { this->salary = 3000; }
	~Teamlead() {
		salary = -1;
		cout << "Вызван деструктор класса Teamlead " << this << endl;
	}
};

class CSTeacher : public SoftwareEng, public HardwareEng { // множественное наследование
public:
	CSTeacher() { this->salary = 2000; }
	~CSTeacher() {
		salary = -1;
		cout << "Вызван деструктор класса CSTeacher " << this << endl;
	}
	void returnWorker(int prev) {
		Employee::returnWorker(prev);
		this->salary = 2000;
	}
	void sayThank() { cout << "Thank you, Teamlead. - CSTeacher said" << endl; };
	void makeReport() { cout << "There is a bug in the system, we need to fix this area of code at branch 54." << endl; };
	void makeIssue() {
		Employee::makeIssue();
	}
	void makeFeature() {
		Employee::makeFeature();
		cout << "Это инновационная технолгоия искусственного интеллекта, позволяющая осуществлять адаптивное обучение!\n";
	}
	int operator=(CSTeacher& obj) {
		this->salary = obj.salary;
		return 1;
	}
};

int main()
{
	int var = 0;
	setlocale(0, "RUS");

	cout << "Вы играете за Teamlead. Сегодня у вас есть возможность сделать 3 действия." << endl;
	cout << "Вы желаете продолжить?" << endl << "1 - Да\n2 - Нет" << endl;
	cin >> var;
	if (var == 1)
	{
		int te = 10, em = 10, ha = 10, so = 10, le = 10, in = 10;
		CSTeacher Teach[20];
		Employee Emplo[20];
		HardwareEng HardEng[20];
		SoftwareEng SoftEng[20];
		Teamlead* Teamleader = new Teamlead;
		while (var != 10)
		{
			printf("Меню действий:\n1 - Получить кофе от Employee\n2 - Получить отчёт от Employee\n3 - Получить новую фичу от Hardware Engenier\n4 - Получить отчёт от Hardware Engenier\n5 - Получить новую фичу от Software Engenier\n6 - Получить отчёт от Software Engenier");
			printf("66 - Получить отчёт от CSTeacher\n7 - Получить жалобу от CSTeacher\n8 - Поблагодарить CSTeacher\n9 - Уволить сотрудника\n99 - Добавить сотрудника в штат\n10 - Уйти отдыхать\nВаш выбор: ");
			cin >> var;
			switch (var)
			{
			case 1:
			{
				int flag1 = 0;
				for (int i = 0; i < 10 and flag1 != 1; i++)
				{
					if (Emplo[i].salary != -1)
					{
						Emplo[i].makeCoffee();
						flag1 = 1;
					}
				}
				if (flag1 != 1)
				{
					printf("Нету доступных Employee.Требуется пополнение.\n");
				}
				_getch();
				system("cls");
				break;
			}
			case 2:
			{
				int flag2 = 0;
				for (int i = 0; i < 10 and flag2 != 1; i++)
				{
					if (Emplo[i].salary != -1)
					{
						Emplo[i].makeIssue();
						flag2 = 1;
					}
				}
				if (flag2 != 1)
				{
					printf("Нету доступных Employee.Требуется пополнение.\n");
				}
				_getch();
				system("cls");
				break;
			}
			case 3:
			{
				int flag3 = 0;
				for (int i = 0; i < 10 and flag3 != 1; i++)
				{
					if (HardEng[i].salary != -1)
					{
						HardEng[i].makeFeature();
						flag3 = 1;
					}
				}
				if (flag3 != 1)
				{
					printf("Нету доступных HardwareEngeniers.Требуется пополнение.\n");
				}
				_getch();
				system("cls");
				break;
			}
			case 4:
			{
				int flag4 = 0;
				for (int i = 0; i < 10 and flag4 != 1; i++)
				{
					if (HardEng[i].salary != -1)
					{
						HardEng[i].makeIssue();
						flag4 = 1;
					}
				}
				if (flag4 != 1)
				{
					printf("Нету доступных HardwareEngeniers.Требуется пополнение.\n");
				}
				_getch();
				system("cls");
				break;
			}
			case 5:
			{
				int flag5 = 0;
				for (int i = 0; i < 10 and flag5 != 1; i++)
				{
					if (SoftEng[i].salary != -1)
					{
						SoftEng[i].makeFeature();
						flag5 = 1;
					}
				}
				if (flag5 != 1)
				{
					printf("Нету доступных SoftwareEngeniers.Требуется пополнение.\n");
				}
				_getch();
				system("cls");
				break;
			}
			case 6:
			{
				int flag6 = 0;
				for (int i = 0; i < 10 and flag6 != 1; i++)
				{
					if (SoftEng[i].salary != -1)
					{
						SoftEng[i].makeIssue();
						flag6 = 1;
					}
				}
				if (flag6 != 1)
				{
					printf("Нету доступных SoftwareEngeniers.Требуется пополнение.\n");
				}
				_getch();
				system("cls");
				break;
			}
			case 66:
			{
				int flag66 = 0;
				for (int i = 0; i < 10 and flag66 != 1; i++)
				{
					if (Teach[i].salary != -1)
					{
						Teach[i].makeIssue();
						flag66 = 1;
					}
				}
				if (flag66 != 1)
				{
					printf("Нету доступных Teachers.Требуется пополнение.\n");
				}
				_getch();
				system("cls");
				break;
			}
			case 7:
			{
				int flag7 = 0;
				for (int i = 0; i < 10 and flag7 != 1; i++)
				{
					if (Teach[i].salary != -1)
					{
						Teach[i].makeReport();
						flag7 = 1;
					}
				}
				if (flag7 != 1)
				{
					printf("Нету доступных Teachers.Требуется пополнение.\n");
				}
				_getch();
				system("cls");
				break;
			}
			case 8:
			{
				int flag8 = 0;
				for (int i = 0; i < 10 and flag8 != 1; i++)
				{
					if (Teach[i].salary != -1)
					{
						Teach[i].sayThank();
						flag8 = 1;
					}
				}
				if (flag8 != 1)
				{
					printf("Нету доступных Teachers.Требуется пополнение.\n");
				}
				_getch();
				system("cls");
				break;
			}
			case 9:
			{
				int var9 = 0;
				while (var9 != 6)
				{
					printf("Кого уволить?\n2 - Employee\n3 - Hardware Engenier\n4 - Software Engenier\n5 - CSTeacher\n6 - Вернуться в меню\nВаш выбор: ");
					cin >> var9;
					switch (var9)
					{
					case 2:
					{
						int flag92 = 0;
						for (int i = 0; i < 10 and flag92 != 1; i++)
						{
							if (Emplo[i].salary != -1)
							{
								Emplo[i].~Employee();
								em--;
								flag92 = 1;
							}
						}
						if (flag92 != 1)
						{
							printf("Нету доступных Employee.Требуется пополнение.\n");
						}
						_getch();
						system("cls");
						break;
					}
					case 3:
					{
						int flag93 = 0;
						for (int i = 0; i < 10 and flag93 != 1; i++)
						{
							if (HardEng[i].salary != -1)
							{
								HardEng[i].~HardwareEng();
								ha--;
								flag93 = 1;
							}
						}
						if (flag93 != 1)
						{
							printf("Нету доступных HardwareEngeniers.Требуется пополнение.\n");
						}
						_getch();
						system("cls");
						break;
					}
					case 4:
					{
						int flag94 = 0;
						for (int i = 0; i < 10 and flag94 != 1; i++)
						{
							if (SoftEng[i].salary != -1)
							{
								SoftEng[i].~SoftwareEng();
								so--;
								flag94 = 1;
							}
						}
						if (flag94 != 1)
						{
							printf("Нету доступных SoftwareEngeniers.Требуется пополнение.\n");
						}
						_getch();
						system("cls");
						break;
					}
					case 5:
					{
						int flag95 = 0;
						for (int i = 0; i < 10 and flag95 != 1; i++)
						{
							if (Teach[i].salary != -1)
							{
								Teach[i].~CSTeacher();
								te--;
								flag95 = 1;
							}
						}
						if (flag95 != 1)
						{
							printf("Нету доступных Teachers.Требуется пополнение.\n");
						}
						_getch();
						system("cls");
						break;
					}
					case 6:
					{
						var9 = 6;
						system("cls");
						break;
					}
					default:
					{
						break;
					}
					}
				}
				_getch();
				system("cls");
				break;
			}
			case 99:
			{
				int var99 = 0;
				while (var99 != 6)
				{
					printf("Кого добавить в штат?\n2 - Employee\n3 - Hardware Engenier\n4 - Software Engenier\n5 - CSTeacher\n6 - Вернуться в меню\nВаш выбор: ");
					cin >> var99;
					switch (var99)
					{
					case 2:
					{
						int flag992 = 0;
						for (int i = 0; i < 10 and flag992 != 1; i++)
						{
							if (Emplo[i].salary == -1) {
								Emplo[i].returnWorker(i);
								flag992 = 1;
							}
						}
						if (flag992 != 1)
						{
							printf("Был достигнут лимит сотрудников 10шт.\n");
						}
						_getch();
						system("cls");
						break;
					}
					case 3:
					{
						int flag993 = 0;
						for (int i = 0; i < 10 and flag993 != 1; i++)
						{
							if (HardEng[i].salary == -1) {
								HardEng[i].returnWorker(i);
								flag993 = 1;
							}
						}
						if (flag993 != 1)
						{
							printf("Был достигнут лимит сотрудников 10шт.\n");
						}
						_getch();
						system("cls");
						break;
					}
					case 4:
					{
						int flag994 = 0;
						for (int i = 0; i < 10 and flag994 != 1; i++)
						{
							if (SoftEng[i].salary == -1) {
								SoftEng[i].returnWorker(i);
								flag994 = 1;
							}
						}
						if (flag994 != 1)
						{
							printf("Был достигнут лимит сотрудников 10шт.\n");
						}
						_getch();
						system("cls");
						break;
					}
					case 5:
					{
						int flag995 = 0;
						for (int i = 0; i < 10 and flag995 != 1; i++)
						{
							if (Teach[i].salary == -1) {
								Teach[i].returnWorker(i);
								flag995 = 1;
							}
						}
						if (flag995 != 1)
						{
							printf("Был достигнут лимит сотрудников 10шт.\n");
						}
						_getch();
						system("cls");
						break;
					}
					case 6:
					{
						var99 = 6;
						system("cls");
						break;
					}
					default:
					{
						break;
					}
					}
				}
				_getch();
				system("cls");
				break;
			}
			case 10:
			{
				var = 10;
				system("cls");
				break;
			}
			default:
			{
				break;
			}
			}
		}
	}
	else { return 1; }
}





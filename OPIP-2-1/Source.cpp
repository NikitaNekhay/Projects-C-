#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <iostream>

using namespace std;

class Intern {
public:
	int salary;
	Intern() { //cout << "������ ����������� ������ Intern " << this << endl; 
		salary = 150;
	}
	~Intern() {
		salary = -1;
		cout << "������ ���������� ������ Intern " << this << endl;
	}
	virtual void makeCoffee() = 0;
	virtual void makeIssue() = 0;
	virtual void returnWorker(int) = 0;
};

class Employee : public Intern {
public:
	Employee() { //cout << "������ ����������� ������ Employee " << this << endl; 
		this->salary = 500;
	}
	~Employee() {
		salary = -1;
		cout << "������ ���������� ������ Employee " << this << endl;
	}
	void returnWorker(int prev) {
		cout << "����� ��������� ������ �� ����� �������� ������ " << prev + 1 << endl; this->salary = 500;
	}
	void makeCoffee() { cout << "��� ��� ������� ����!\n"; }
	void makeIssue() { cout << "����� �������� � ��� �������� �� ����� �����!\n"; }
	virtual void makeFeature() { cout << "� ����� ������� � ����� �������� ��� ���� ���������!\n"; };
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
		cout << "������ ���������� ������ HardwareEng " << this << endl;
	}
	void returnWorker(int prev) {
		Employee::returnWorker(prev);
		this->salary = 1500;
	}
	void makeFeature() {
		Employee::makeFeature();
		cout << "��������� � � ����� ����� 'HRDWRfeature' � ����� �����������\n";
	}
	void makeIssue() {
		cout << "��� ��������� ������ ���������� � Employee. �� �������� ���� �������!" << endl;
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
		cout << "������ ���������� ������ SoftwareEng " << this << endl;
		this->salary = 1500;
	}
	void returnWorker(int prev) {
		Employee::returnWorker(prev);
	}
	void makeFeature() {
		Employee::makeFeature();
		cout << "��������� � � ����� ����� 'SFTWRfeature' � ����� �����������\n";
	}
	void makeIssue() {
		cout << "��� ��������� ������ ���������� � Employee. �� �������� ���� �������!" << endl;
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
		cout << "������ ���������� ������ Teamlead " << this << endl;
	}
};

class CSTeacher : public SoftwareEng, public HardwareEng { // ������������� ������������
public:
	CSTeacher() { this->salary = 2000; }
	~CSTeacher() {
		salary = -1;
		cout << "������ ���������� ������ CSTeacher " << this << endl;
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
		cout << "��� ������������� ���������� �������������� ����������, ����������� ������������ ���������� ��������!\n";
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

	cout << "�� ������� �� Teamlead. ������� � ��� ���� ����������� ������� 3 ��������." << endl;
	cout << "�� ������� ����������?" << endl << "1 - ��\n2 - ���" << endl;
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
			printf("���� ��������:\n1 - �������� ���� �� Employee\n2 - �������� ����� �� Employee\n3 - �������� ����� ���� �� Hardware Engenier\n4 - �������� ����� �� Hardware Engenier\n5 - �������� ����� ���� �� Software Engenier\n6 - �������� ����� �� Software Engenier");
			printf("66 - �������� ����� �� CSTeacher\n7 - �������� ������ �� CSTeacher\n8 - ������������� CSTeacher\n9 - ������� ����������\n99 - �������� ���������� � ����\n10 - ���� ��������\n��� �����: ");
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
					printf("���� ��������� Employee.��������� ����������.\n");
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
					printf("���� ��������� Employee.��������� ����������.\n");
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
					printf("���� ��������� HardwareEngeniers.��������� ����������.\n");
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
					printf("���� ��������� HardwareEngeniers.��������� ����������.\n");
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
					printf("���� ��������� SoftwareEngeniers.��������� ����������.\n");
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
					printf("���� ��������� SoftwareEngeniers.��������� ����������.\n");
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
					printf("���� ��������� Teachers.��������� ����������.\n");
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
					printf("���� ��������� Teachers.��������� ����������.\n");
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
					printf("���� ��������� Teachers.��������� ����������.\n");
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
					printf("���� �������?\n2 - Employee\n3 - Hardware Engenier\n4 - Software Engenier\n5 - CSTeacher\n6 - ��������� � ����\n��� �����: ");
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
							printf("���� ��������� Employee.��������� ����������.\n");
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
							printf("���� ��������� HardwareEngeniers.��������� ����������.\n");
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
							printf("���� ��������� SoftwareEngeniers.��������� ����������.\n");
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
							printf("���� ��������� Teachers.��������� ����������.\n");
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
					printf("���� �������� � ����?\n2 - Employee\n3 - Hardware Engenier\n4 - Software Engenier\n5 - CSTeacher\n6 - ��������� � ����\n��� �����: ");
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
							printf("��� ��������� ����� ����������� 10��.\n");
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
							printf("��� ��������� ����� ����������� 10��.\n");
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
							printf("��� ��������� ����� ����������� 10��.\n");
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
							printf("��� ��������� ����� ����������� 10��.\n");
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





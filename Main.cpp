#include "Keeper.h"
#include <iostream>
#include <Windows.h>
#include<string>
using namespace std;

int main() {
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������
	setlocale(LC_ALL, "Rus");
	Keeper Contain;
	char menu = 0;
	cout << "������������ ������ �1. ������� �1!" << endl;
	do {
		try {
			cout << "������� ���������� ��������� � ����������: " << Contain.GetSize() << "." << endl
				<< "�������� ��������" << endl
				<< "1. �������� �������" << endl
				<< "2. ������������� �������" << endl
				<< "3. ������� �������" << endl
				<< "4. ��������� ������ � ����" << endl
				<< "5. ��������� ������ �� �����" << endl
				<< "6. ������� ������ �� ����������" << endl
				<< "0. �����" << endl
				<< ">> ";
			cin >> menu;
			if ((!isdigit(menu)) && ((menu >= 7) || (menu <= -1))) {
				throw 1;
			}
			switch (menu) {
			case '0':
				break;
			case '1':
				Contain.Add();
				break;
			case '2':
				cout << Contain;
				Contain.Edit();
				break;
			case '3':
				cout << Contain;
				Contain.Del();
				break;
			case '4':
				Contain.Save();
				break;
			case '5':
				Contain.Load();
				break;
			case '6':
				cout << Contain;
				break;
			}
		}
		catch (int) {
			cout << "���������� �������� ���������� 'menu' = 0, 1, 2, 3, 4, 5, 6." << endl;
		}
		system("pause");
		system("cls");
	} while (menu != '0');
	return 0;
}
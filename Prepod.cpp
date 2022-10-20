#include "Prepod.h"

Prepod::Prepod() {
		SetType(2);
		SetErr(false);
		cin.ignore(256, '\n');
		cout << "Введите ФИО преподавателя:" << endl
			<< "Фамилия: ";
		getline(cin, this->prepFIO.SurName);
		cout << "Имя ";
		getline(cin, this->prepFIO.Name);
		cout << "Отчество: ";
		getline(cin, this->prepFIO.LastName);
		cout << "Введите группы: ";
		getline(cin, this->groups);
		cout << "Введите дисциплины: ";
		getline(cin, this->disc);
}

Prepod::Prepod(ifstream& fin) {
	SetType(2);
	fin.ignore(256, '\n');
	getline(fin, this->prepFIO.Name);
	getline(fin, this->prepFIO.SurName);
	getline(fin, this->prepFIO.LastName);
	fin >> this->groups;
	fin.ignore(256, '\n');
	getline(fin, this->disc);
}

Prepod::~Prepod() {
	cout << "prep dstrctr" << endl;
}

void Prepod::Edit() {
	SetErr(false);
	int choose;
	FIO fio_temp;
	string i_temp;
	string s_temp;
	cout << "Выберите редактируемый параметр:" << endl
		<< "[1] ФИО." << endl
		<< "[2] Группы." << endl
		<< "[3] Дисциплины." << endl
		<< "[0] Отмена." << endl;
	cin >> choose;
		switch (choose) {
		case 1:
			cout << "Текущее: ";
			cout << this->prepFIO.SurName << " "
				<< this->prepFIO.Name << " "
				<< this->prepFIO.LastName << endl
				<< "Новое:  Фамилия >> ";
			cin.ignore(256, '\n');
			getline(cin, fio_temp.SurName);
			cout << "\tИмя >> ";
			getline(cin, fio_temp.Name);
			cout << "\tОтчество >> ";
			getline(cin, fio_temp.LastName);
			prepFIO = fio_temp;
			break;
		case 2:
			cout << "Текущее: ";
			cout << this->groups << endl
				<< "Новое >> ";
			getline(cin, this->groups);
			groups = i_temp;
			break;
		case 3:
			cout << "Текущее: ";
			cout << this->disc << endl
				<< "Новое >> ";
			cin.ignore(256, '\n');
			getline(cin, s_temp);
			disc = s_temp;
			break;
		default:
			break;
		}
}

void Prepod::Save(ofstream& fout) {
	fout << GetType() << endl
		<< this->prepFIO.Name << endl
		<< this->prepFIO.SurName << endl
		<< this->prepFIO.LastName << endl
		<< this->groups << endl
		<< this->disc << endl;
}

void Prepod::Print(ostream& out) {
	out << "Преподаватель:" << endl
		<< "ФИО:" << this->prepFIO.SurName << " " << this->prepFIO.Name << " " << this->prepFIO.LastName << endl
		<< "Группы:" << this->groups << endl
		<< "Дисциплина:" << this->disc << endl
		<< "=================================" << endl;
}
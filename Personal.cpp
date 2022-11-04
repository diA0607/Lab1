#include "Personal.h"

Personal::Personal() {
		SetType(3);
		SetErr(false);
		cin.ignore(256, '\n');
		cout << "Введите ФИО:" << endl
			<< "Фамилия: ";
		getline(cin, this->persFIO.SurName);
		cout << "Имя: ";
		getline(cin, this->persFIO.Name);
		cout << "Отчество: ";
		getline(cin, this->persFIO.LastName);
		cout << "Должность: ";
		getline(cin, this->spec);
		cout << "Введите телефон: ";
		getline(cin, this->tel);
		cout << "Введите область ответственности:";
		getline(cin, this->obl);
	
}

Personal::Personal(ifstream& fin) {
	SetType(3);
	fin.ignore(256, '\n');
	getline(fin, this->persFIO.SurName);
	getline(fin, this->persFIO.Name);
	getline(fin, this->persFIO.LastName);
	getline(fin, this->spec);
	getline(fin, this->tel);
	getline(fin, this->obl);
}

Personal::~Personal() {
	cout << "pers dstrctr";
}

void Personal::Edit() {
	int choose;
	FIO fio_temp;
	string s_temp;
	string i_temp;
	string t_temp;
	cout << "Выберите редактируемый параметр:" << endl
		<< "1. ФИО" << endl
		<< "2. Специальность" << endl
		<< "3. Телефон" << endl
		<< "4. Область ответственности" << endl
		<< "0. Отмена" << endl;
		cin >> choose;
		switch (choose) {
		case 1:
			cout << "Текущее: ";
			cout << this->persFIO.SurName << " "
				<< this->persFIO.Name << " "
				<< this->persFIO.LastName << endl;
			cin.ignore(256, '\n');
			cout	<< "Новое:  Фамилия >> ";
			getline(cin, fio_temp.SurName);
			cout << "\tИмя >> ";
			getline(cin, fio_temp.Name);
			cout << "\tОтчество >> ";
			getline(cin, fio_temp.LastName);
			persFIO = fio_temp;
			break;
		case 2:
			cout << "Текущее: ";
			cout << this->spec << endl
				<< "Новое >> ";
			cin.ignore(256, '\n');
			getline(cin, s_temp);
			spec = s_temp;
			break;
		case 3:
			cout << "Текущее: ";
			cout << this->tel << endl
				<< "Новое >> ";
			cin.ignore(256, '\n');
			getline(cin, i_temp);
			tel = i_temp;
			break;
		case 4:
			cout << "Текущее: ";
			cout << this->obl << endl
				<< "Новое >> ";
			cin.ignore(256, '\n');
			getline(cin, t_temp);
			obl = t_temp;
			break;
		default:
			break;
		}
}

void Personal::Save(ofstream& fout) {
	fout << GetType() << endl
		<< this->persFIO.SurName << endl
		<< this->persFIO.Name << endl
		<< this->persFIO.LastName << endl
		<< this->spec << endl
		<< this->tel << endl
		<< this->obl << endl;

}

void Personal::Print(ostream& out) {
	out << "Персонал:" << endl
		<< "ФИО:" << this->persFIO.SurName << " " << this->persFIO.Name << " " << this->persFIO.LastName << endl
		<< "Специальность:" << this->spec << endl
		<< "Телефон:" << this->tel << endl
		<< "Область ответственности:" << this->obl << endl
		<< "=================================" << endl;
}
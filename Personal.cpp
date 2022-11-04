#include "Personal.h"

Personal::Personal() {
		SetType(3);
		SetErr(false);
		cin.ignore(256, '\n');
		cout << "������� ���:" << endl
			<< "�������: ";
		getline(cin, this->persFIO.SurName);
		cout << "���: ";
		getline(cin, this->persFIO.Name);
		cout << "��������: ";
		getline(cin, this->persFIO.LastName);
		cout << "���������: ";
		getline(cin, this->spec);
		cout << "������� �������: ";
		getline(cin, this->tel);
		cout << "������� ������� ���������������:";
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
	cout << "�������� ������������� ��������:" << endl
		<< "1. ���" << endl
		<< "2. �������������" << endl
		<< "3. �������" << endl
		<< "4. ������� ���������������" << endl
		<< "0. ������" << endl;
		cin >> choose;
		switch (choose) {
		case 1:
			cout << "�������: ";
			cout << this->persFIO.SurName << " "
				<< this->persFIO.Name << " "
				<< this->persFIO.LastName << endl;
			cin.ignore(256, '\n');
			cout	<< "�����:  ������� >> ";
			getline(cin, fio_temp.SurName);
			cout << "\t��� >> ";
			getline(cin, fio_temp.Name);
			cout << "\t�������� >> ";
			getline(cin, fio_temp.LastName);
			persFIO = fio_temp;
			break;
		case 2:
			cout << "�������: ";
			cout << this->spec << endl
				<< "����� >> ";
			cin.ignore(256, '\n');
			getline(cin, s_temp);
			spec = s_temp;
			break;
		case 3:
			cout << "�������: ";
			cout << this->tel << endl
				<< "����� >> ";
			cin.ignore(256, '\n');
			getline(cin, i_temp);
			tel = i_temp;
			break;
		case 4:
			cout << "�������: ";
			cout << this->obl << endl
				<< "����� >> ";
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
	out << "��������:" << endl
		<< "���:" << this->persFIO.SurName << " " << this->persFIO.Name << " " << this->persFIO.LastName << endl
		<< "�������������:" << this->spec << endl
		<< "�������:" << this->tel << endl
		<< "������� ���������������:" << this->obl << endl
		<< "=================================" << endl;
}
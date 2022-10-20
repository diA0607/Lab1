#include "Student.h"

Student::Student() {
	try {
		SetType(1);
		SetErr(false);
		cin.ignore(256, '\n');
		cout << "������� ��� ��������:" << endl;
		cout << "�������: ";
		getline(cin, this->stdFIO.SurName);
		cout << "���: ";
		getline(cin, this->stdFIO.Name);
		cout << "��������: ";
		getline(cin, this->stdFIO.LastName);
		cout << "������: ";
		getline(cin, this->group);
		cout << "�������������: ";
		getline(cin, this->spec);
		cout << "������� ����: ";
		cin >> this->course;
		if (this->course>5 || this->course < 1)
			throw 1;
		cout << "������� ����: ";
		cin >> this->sr_ball;
		if (this->sr_ball >5 || this->sr_ball < 2)
			throw 2;
	}
	catch (int err) {
		SetErr(true);
		switch (err) {
		case 1:
			cout << "����� ����� ����� ���� ������ � ��������� 1-5!" << endl;
			break;
		case 2:
			cout << "������� ���� ����� ���� � ��������� �������� 2-5!" << endl;
			break;
		}
	}
}

Student::Student(ifstream& fin) {
	SetType(1);
	fin.ignore(256, '\n');
	getline(fin, this->stdFIO.SurName);
	getline(fin, this->stdFIO.Name);
	getline(fin, this->stdFIO.LastName);
	getline(fin, this->group);
	getline(fin, this->spec);
	fin >> this->course;
	fin >> this->sr_ball;
}

Student::~Student() {
	cout << "std dstrctr" << endl;
}

void Student::Edit() {
	SetErr(false);
	int choose;
	FIO fio_temp;
	string i_temp;
	string s_temp;
	int course_temp;
	float srball_temp;
	cout << "�������� ������������� ��������:" << endl
		<< "1. ���" << endl
		<< "2. ������" << endl
		<< "3. �������������" << endl
		<< "4. ����� �����" << endl
		<< "5. ������� ����" << endl
		<< "0. ������" << endl
		<< ">> ";
	cin >> choose;
	try {
		switch (choose) {
		case 1:
			cout << "�������: ";
			cout << this->stdFIO.SurName << " " << this->stdFIO.Name << " " << this->stdFIO.LastName << endl;
			cout	<< "�����:  ������� >> ";
			cin.ignore(256, '\n');
			getline(cin, fio_temp.SurName);
			cout << "\t��� >> ";
			getline(cin, fio_temp.Name);
			cout << "\t�������� >> ";
			getline(cin, fio_temp.LastName);
			stdFIO = fio_temp;
			break;
		case 2:
			cout << "�������: ";
			cout << this->group << endl
				<< "����� >> ";
			cin.ignore(256, '\n');
			getline(cin, i_temp);
			group = i_temp;
			break;
		case 3:
			cout << "�������: ";
			cout << this->spec << endl
				<< "����� >> ";
			cin.ignore(256, '\n');
			getline(cin, s_temp);
			spec = s_temp;
			break;
		case 4:
			cout << "�������: ";
			cout << this->course << endl
				<< "����� >> ";
			cin >> course_temp;
			if (course_temp > 5 || course_temp < 1)
				throw 1;
			course = course_temp;
			break;
		case 5:
			cout << "�������: ";
			cout << this->sr_ball << endl
				<< "����� >> ";
			cin >> srball_temp;
			if (srball_temp > 5 || srball_temp < 2)
				throw 2;
			sr_ball = srball_temp;
			break;
		default:
			break;
		}
	}
	catch (int err) {
		SetErr(true);
		switch (err) {
		case 1:
			cout << "����� ����� ����� ���� ������ � ��������� 1-5!" << endl;
			break;
		case 2:
			cout << "������� ���� ����� ���� � ��������� �������� 2-5!" << endl;
			break;

		}
	}
}

void Student::Save(ofstream& fout) {
	fout << GetType() << endl
		<< this->stdFIO.SurName << endl
		<< this->stdFIO.Name << endl
		<< this->stdFIO.LastName << endl
		<< this->group << endl
		<< this->spec << endl
		<< this->course << endl
		<< this->sr_ball << endl;
}

void Student::Print(ostream& out) {
	out << "�������:" << endl
		<< "���:" << this->stdFIO.SurName << " " << this->stdFIO.Name << " " << this->stdFIO.LastName << endl
		<< "������:" << this->group << endl
		<< "�������������:" << this->spec << endl
		<< "����� �����:" << this->course << endl
		<< "������� ����:" << this->sr_ball << endl
		<< "=================================" << endl;
}
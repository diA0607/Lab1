#include "Keeper.h"

int Choose() {
	int x = 0;
	cout << "Выберите класс:" << endl
		<< "1. Студенты" << endl
		<< "2. Преподаватели." << endl
		<< "3. Персонал." << endl
		<< ">> ";
	cin >> x;
	return x;
}
Keeper Contain2;
int count = 0;

Keeper::Keeper() {
	this->Value = nullptr;
	this->size = 0;
}

Keeper::~Keeper() {
	delete[] Value;
}

int Keeper::GetSize() {
	return size;
}

void Keeper::Add() {
	try {
		VUZ** temp = new VUZ * [size + 1];
		int i = 0;
		while (i < size) {
			temp[i] = Value[i];
			i++;
		}
		switch (Choose()) {
		case 1:
			temp[size] = new Student;
			break;
		case 2:
			temp[size] = new Prepod;
			break;
		case 3:
			temp[size] = new Personal;
			break;
		}
		if ((!temp[size]) || (temp[size]->GetErr()))
			throw 1;
		size++;
		if (Value)
			delete[] Value;
		Value = temp;
		cout << "Объект успешно добавлен!" << endl;
	}
	catch (int) {
		cout << "Объект не был добавлен из-за ошибки." << endl;
	}
}

void Keeper::Add(int _type, ifstream& fin) {
	VUZ** temp = new VUZ * [size + 1];
	int i = 0;
	while (i < size) {
		temp[i] = Value[i];
		i++;
	}
	switch (_type) {
	case 1:
		temp[size] = new Student(fin);
		break;
	case 2:
		temp[size] = new Prepod(fin);
		break;
	case 3:
		temp[size] = new Personal(fin);
		break;
	}
	::count++;
	size++;
	if (Value)
		delete[] Value;
	Value = temp;
}

void Keeper::Edit() {
	
	int x;
	try {
		if (!size)
			cout << "Контейнер пуст!" << endl;
		else{ 
			for (int i = 0; i < size; i++)
			{
				cout << i + 1;
				switch (Value[i]->GetType())
				{
				case 1:
					cout << ". Студент" << endl;
					break;
				case 2:
					cout << ". Преподаватель" << endl;
					break;
				case 3:
					cout << ". Персонал" << endl;
					
					break;
				default:
					break;
				}
			}

			cout << ">> ";
			cin >> x;
			if ((x < 1) || (x > size)) {
				throw 1;
			}
			x -= 1;
			Value[x]->Edit();
			if ((Value[x]->GetErr()) || (!Value[x]))
				cout << "Редактирование не удалось." << endl;
			else
				cout << "Редактирование завершено." << endl;
			}
		}
	catch (int)
	{
		cout << "Выбранный пункт недоступен." << endl;
	}
}

void Keeper::Del() {
	int x;
	try {
		if (!size)
		{
			throw 1;

		}
		for (int i = 0; i < size; i++) {
			switch (Value[i]->GetType()) {
			case 1:
				cout << i + 1 << ". Студент" << endl;
				break;
			case 2:
				cout << i + 1 << ". Преподаватель" << endl;
				break;
			case 3:
				cout << i + 1 << ". Персонал" << endl;
				break;
			default:
				break;
			}
		}
		cout << ">> ";
		cin >> x;
		x -= 1;
		if (size == 1) {
			delete[] Value;
			Value = nullptr;
			cout << "Объект удален!" << endl;
			size--;
		}
		else {
			VUZ** temp = new VUZ * [size - 1];
			int j = 0;
			for (int i = 0; i < size; i++) {
				if (x == i)
					continue;
				temp[j++] = Value[i];
			}
			delete[] Value;
			Value = temp;
			size--;
			cout << "Объект удален!" << endl;
		}
	}
	catch (int)
	{
		cout << "Контейнер пуст!" << endl;
	}
}

void Keeper::Save() {
	ofstream fout("test.txt");
	for (int i = 0; i < size; i++) {
		Value[i]->Save(fout);
	}
	fout.close();
	cout << "Сохранено!" << endl;
	
}

void Keeper::Load() {
	
	ifstream fin("test.txt");
	if (!fin.is_open()) cout << "Файл не существует\n"; // если не открылся
	else if (fin.peek() == EOF)
	{
		cout << "Файл пуст\n"; // если первый символ конец файла
	}
		
	int type = 0;
	while (fin) {
		fin >> type;
		if (fin.peek() != EOF)
		{
			Add(type, fin);
		}
	}
	fin.close();
	if ((::count >= 1))
		cout << "Успешно загружен ["<<::count<< "] объект." << endl;
}
ostream& operator<< (ostream& out, Keeper& obj) {
	if (!obj.size) {
		cout << "Контейнер пуст!" << endl;
		return out;
	}
	for (int i = 0; i < obj.size; i++) {
		cout << i + 1<<". ";
		obj.Value[i]->Print(out);
	}
	return out;
}



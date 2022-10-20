#pragma once
#include "Base.h"
#include "Personal.h"
#include "Prepod.h"
#include "Student.h"
#include <fstream>
#include <iostream>
using namespace std;

class Keeper {
private:
	VUZ** Value;
	int size;
public:
	Keeper();
	~Keeper();
	int GetSize();
	void Add();
	void Add(int _type, ifstream& fin);
	void Edit();
	void Del();
	void Save();
	void Load();
	friend ostream& operator<< (ostream& out, Keeper& obj);
};

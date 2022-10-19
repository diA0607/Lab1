#pragma once
#include "Base.h"
#include "Data.h"
using namespace std;

class Prepod : public VYZ {
private:
	FIO prepFIO;
	string groups;
	string disc;
public:
	Prepod();
	Prepod(ifstream& fin);
	~Prepod();
	void Edit();
	void Save(ofstream& fout);
	void Print(ostream& out);
};

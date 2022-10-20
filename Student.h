#pragma once
#include "Base.h"
#include "Data.h"
using namespace std;

class Student : public VUZ {
private:
	FIO stdFIO;
	string group; 
	string spec;
	int course; 
	float sr_ball; 
public:
	Student();
	Student(ifstream& fin);
	~Student();
	void Edit();
	void Save(ofstream& fout);
	void Print(ostream& out);
};

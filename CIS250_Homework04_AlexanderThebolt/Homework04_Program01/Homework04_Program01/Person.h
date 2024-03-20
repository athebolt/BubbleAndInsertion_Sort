#pragma once
#include "iostream"

using namespace std;

class Person
{
private:
	string name;
	string deptId;
	string wage;
	int id;
public:
	Person();

	void setName(string);
	void setDeptId(string);
	void setWage(string);
	void setId(int);

	string getName() const;
	string getDeptId() const;
	string getWage() const;
	int getId() const;
};


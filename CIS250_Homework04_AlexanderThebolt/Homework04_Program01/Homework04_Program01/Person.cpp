#include "Person.h"
#include "iostream"

using namespace std;

Person::Person()
{

}

void Person::setName(string n)
{
	name = n;
}
void Person::setDeptId(string d)
{
	deptId = d;
}
void Person::setWage(string w)
{
	wage = w;
}
void Person::setId(int i)
{
	id = i;
}

string Person::getName() const
{
	return name;
}
string Person::getDeptId() const
{
	return deptId;
}
string Person::getWage() const
{
	return wage;
}
int Person::getId() const
{
	return id;
}
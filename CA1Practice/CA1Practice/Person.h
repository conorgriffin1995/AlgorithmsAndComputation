#pragma once
#include <string>
#include <iostream>
#include <ostream>
using namespace std;

class Person
{
public:
	Person(string);
	virtual void printname();

	friend bool operator <(Person &lhs, Person &rhs);
	friend bool operator >(Person &lhs, Person &rhs);
private:
	string name;
};


#pragma once
#include "Person.h"
#include <string>
#include <iostream>
using namespace std;

class Employee : public Person
{
public:
	Employee(string nameIn, double salaryIn);
	virtual void printname();
private:
	string name;
	double salary;
};


#pragma once
#include "Person.h"
#include <string>
#include <iostream>
using namespace std;

class Customer : public Person
{
public:
	Customer(string nameIn);
	virtual void printname();
private:
	string name;
};


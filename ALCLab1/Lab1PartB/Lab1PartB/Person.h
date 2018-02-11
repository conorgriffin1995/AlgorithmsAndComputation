#pragma once
#include <string>
#include <ostream>
#include <iostream>
using namespace std;

class Person
{
public:
	Person(string nameIn);			// initialise the name
	virtual void printname(); // = 0; this is abstract 0 makes it a pure virtual method.
	
	// overloaded assignent
	bool operator==(const Person& rhs) const;
	bool operator<(const Person& rhs) const;
	bool operator>(const Person& rhs) const;
protected:
	string name;
};


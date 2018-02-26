#include "Person.h"
#include <iostream>
using namespace std;


Person::Person(string nameIn)
{
	name = nameIn;
}


void Person::printname() {
	cout << "Name: " + name;
}


bool operator <(Person &lhs, Person &rhs) {
	if (lhs.name < rhs.name) {
		return true;
	}
	else {
		return false;
	}
}

bool operator >(Person &lhs, Person &rhs) {
	if (lhs.name > rhs.name) {
		return true;
	}
	else {
		return false;
	}
	
}



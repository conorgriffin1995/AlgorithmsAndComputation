#include "Person.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;


Person::Person(string nameIn) {
	name = nameIn;
}

void Person::printname() {
	cout << "My name is " << name;
}

bool Person::operator==(const Person& rhs) const {
	if (this->name.compare(rhs.name) == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool Person::operator<(const Person& rhs) const {
	if (this->name.compare(rhs.name)) {
		return true;
	}
	else {
		return false;
	}
}

bool Person::operator>(const Person& rhs) const {
	if (this->name.compare(rhs.name)) {
		return true;
	}
	else {
		return false;
	}
}



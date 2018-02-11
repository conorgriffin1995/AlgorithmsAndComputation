#include "Employee.h"
#include "Person.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

Employee::Employee(string nameIn, double salaryIn) : Person(nameIn) {
	salary = salaryIn;
}

void Employee::printname() {
	Person::printname();
	cout << " and my salary is: " << salary;
}


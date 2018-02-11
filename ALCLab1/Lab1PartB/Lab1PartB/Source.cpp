#include "Person.h"
#include "Employee.h"
#include "Customer.h"
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm> // Needed for the sort function below
using namespace std;

int main() {
	// pointer to person class
	Person *personPtr;

	personPtr = new Person("Mark");
	personPtr->printname();
	cout << endl;

	personPtr = new Employee("Tom", 34000);
	personPtr->printname();
	cout << endl;

	personPtr = new Customer("Ed");
	personPtr->printname();
	cout << endl;
	cout << endl;
	cout << endl;

	Person* people[3];
	people[0] = new Employee("Barry", 27000);
	people[1] = new Customer("Cherry");
	people[2] = new Employee("Aaron", 33000);

	Person* temp;

	// Sort from https://www.sitesbay.com/cpp-program/cpp-short-array-element-ascending-order
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (people[j] > people[j+1]) {
				temp = people[j];
				people[j] = people[j + 1];
				people[j+1] = temp;
				
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		people[i]->printname();
		cout << endl;
	}

	system("pause");
	return 0;
}
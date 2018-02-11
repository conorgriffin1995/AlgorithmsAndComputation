#include "Customer.h"
#include "Person.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

Customer::Customer(string nameIn) : Person(nameIn){

}

void Customer::printname() {
	Person::printname();
	cout << name << " and I want to make a complaint.";
}


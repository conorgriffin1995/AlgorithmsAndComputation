#include "Product.h"
#include "Software.h"
#include "Book.h"
#include "string"
#include <iostream>

// X00111602
// Conor Griffin

using namespace std;

// sorting function
void sortList(Product* productsArr[]);

int main() {
	const int ARRAY_MAX = 8;
	double productPrice = 0;
	string productChoice;

	// Declare an array of ARRAY_MAX (8) pointers to Product
	Product* productPtrArray[ARRAY_MAX];
	Product t[ARRAY_MAX];

	// Pointer to Book and Software
	Book *bookPtr = new Book;
	Software *softwarePtr = new Software;

	// Ask the user to enter details of the book, 
	// and of the software item, create the two items dynamically 
	// and store their addresses in your pointers.
	cout << "\nPlease enter in the price of the book: ";
	cin >> productPrice;
	Book b1(productPrice);
	*bookPtr = b1;
	productPtrArray[0] = bookPtr;

	cout << "\nPlease enter in the price of the software: ";
	cin >> productPrice;
	Software s1(productPrice);
	*softwarePtr = s1;
	productPtrArray[1] = softwarePtr;

	// Check your method getGrossPrice works correctly with each type, 
	// and then add them as the first 2 pointers in the array of product. 

	cout << "\nBook gross price: " << bookPtr->getGrossPrice();
	cout << "\nSoftware gross price: " << softwarePtr->getGrossPrice();

	cout << "\nEnter the details of the remaining products.";
	for (int i = 0; i < 6; i++) {
		cout << "\nIs your product a book or software? ";
		cin >> productChoice;

		if (productChoice == "software" || productChoice == "Software" || productChoice == "s") {
			cout << "\nWhat is the cost of this software? ";
			cin >> productPrice;

			productPtrArray[i + 2] = new Software(productPrice);
		}
		else if (productChoice == "book" || productChoice == "Book" || productChoice == "b") {
			cout << "\nWhat is the cost of the book? ";
			cin >> productPrice;

			productPtrArray[i + 2] = new Book(productPrice);
		}
		else {
			cout << "\nNot available, try again.";
			return 0;
		}
		
	}

	for (int i = 0; i < ARRAY_MAX; i++) {
		cout << "\nProduct " << i << " gross price: " << productPtrArray[i]->getGrossPrice();
	}

	cout << endl << endl;

	// call sortList method
	sortList(productPtrArray);		// pass in productPtrArray

	cout << "*** Sorting Array ***" << endl;

	for (int i = 0; i < ARRAY_MAX; i++) {
		cout << "\nProduct " << i << " gross price: " << productPtrArray[i]->getGrossPrice();
	}

	cout << "\n";
	system("pause");
	return 0;
}


void sortList(Product* productsArr[]) {
	Product* temp;					// temporary pointer
	const int ARRAY_MAX = 8;

	for (int i = 0; i < ARRAY_MAX; i++) {
		for (int j = i + 1; j < ARRAY_MAX; j++) {
			if (productsArr[i]->getGrossPrice() > productsArr[j]->getGrossPrice()) {
				temp = productsArr[i];
				productsArr[i] = productsArr[j];
				productsArr[j] = temp;
			}
		}
	}
}
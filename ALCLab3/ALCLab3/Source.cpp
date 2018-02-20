#include "MergeSort.h"
#include "QuickSort.h"
#include <string>
#include <iostream>
using namespace std;


int main() {
	cout << "*** MERGE SORT ***\n" << endl;
	MergeSort ms;		// create mergesort object
	const int SIZE = 10;
	int array[SIZE] = { 1,5,6,4,7,2,8,3,4,10 };
	cout << "*** ARRAY ***" << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << array[i] << " ";
	}

	// Sorting array.
	cout << "\n\n*** MERGE-SORTING ARRAY ***" << endl;
	ms.mergeSort(array, 0, SIZE - 1);
	for (int i = 0; i < SIZE; i++) {
		cout << array[i] << " ";
	}

	// Quick Sort.)
	cout << "\n\n\n*** QUICK SORT ***\n" << endl;

	QuickSort qs; // Create QuickSort Object.
	const int SIZE2 = 10;
	int myArray2[SIZE2] = { 2,5,6,4,7,2,8,3,1,10 }; // Creating array of ints.

												 // Print the non-sorted array
	cout << "*** ARRAY ***" << endl;
	for (int i = 0; i < 10; i++) {
		cout << myArray2[i] << " ";
	}

	// Sorting array now.
	cout << "\n\n*** QUICK-SORTING ARRAY ***" << endl;
	qs.quickSortDivide(myArray2, 0, SIZE2 - 1);
	for (int i = 0; i < 10; i++) {
		cout << myArray2[i] << " ";
	}
	
	cout << endl;
	system("pause");
	return 0;
}


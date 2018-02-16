#include "MergeSort.h"
#include "QuickSort.h"
#include <string>
#include <iostream>
using namespace std;


int main() {
	cout << "*** MERGE SORT ***\n" << endl;
	MergeSort ms;		// create mergesort object
	const int SIZE = 10;
	int array[SIZE] = { 1,5,6,4,7,2,8,3,9,10 };
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
	cout << "\n\n\nQUICK SORT: \n" << endl;

	QuickSort qs; // Create QuickSort Object.

	int myArray2[10] = { 2,5,6,4,7,2,8,3,9,10 }; // Creating array of ints.

												 // Print the non-sorted array
	cout << "PRINTING NON-SORTED ARRAY:" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << myArray2[i] << " ";
	}

	// Sorting array now.
	cout << "\n\nQUICK-SORTING ARRAY NOW..." << endl;
	qs.quickSortDivide(myArray2, 0, 9);

	// Print the sorted array
	cout << "\nPRINTING SORTED ARRAY:" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << myArray2[i] << " ";
	}
	
	cout << endl;
	system("pause");
	return 0;
}


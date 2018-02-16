#include "QuickSort.h"



void QuickSort::
quickSortDivide(int theArray[], int first, int last) {
	int i = first, j = last;
	int temp;

	int pivot = theArray[(first + last) / 2];

	// Divide
	while (i <= j) {
		while (theArray[i] < pivot) {
			i++;
		}
		while (theArray[j] > pivot) {
			j--;
		}
		if (i <= j) {
			temp = theArray[i];
			theArray[i] = theArray[j];
			theArray[j] = temp;
			i++;
			j--;
		}
	};

	// Recursive call
	if (first < j) {
		quickSortDivide(theArray, first, j);
	}
	if (i < last) {
		quickSortDivide(theArray, i, last);
	}

}


#include "MergeSort.h"


// I got some of the code referenced from: https://stackoverflow.com/questions/37121452/merge-sort-algorithm-merge-function-does-not-work
void MergeSort::
mergeSort(int arrayToSort[], int startIndex, int lengthToSort) {
	int midIndex = 0;			// pivot, central value

	// check for base case
	if (startIndex >= lengthToSort) {
		return;
	}
		
	midIndex = (startIndex + lengthToSort) / 2;				// split array into 2 halves
	mergeSort(arrayToSort, startIndex, midIndex);			// recursively call method to sort first half
	mergeSort(arrayToSort, midIndex + 1, lengthToSort);	// recursively call method to sort second half
	merge(arrayToSort, startIndex, lengthToSort);			// merge back together
	

}

// merge contents of array which has been divoided into 2 halves
// from startIndex to length/2 and from startIndex + length/2 until the full sorted length
void MergeSort::
merge(int arraySortedInTwoHalves[], int startIndex, int length) {
	int size = (length - startIndex) + 1;
	// Tip: create( using new) a temporary array to hold the merged result, merge to
	// this array, then copy back to the array to be merged, and delete the temp array)
	int *temp = new int[size];	// temp array to hold elements

	int left = startIndex;						// left side of the array
	int pivot = (startIndex + length) / 2;		// border, pivot

	int right = pivot + 1;						// right side of the array
	int i = 0;

	while (i < size) {							// while there are elements in both sides
		// add whichever is lower from the appropriate side
		if ((left <= pivot) && (arraySortedInTwoHalves[left] < arraySortedInTwoHalves[right])) {
			temp[i++] = arraySortedInTwoHalves[left++];
		}
		else {
			temp[i++] = arraySortedInTwoHalves[right++];
		}
	}

	for (i = 0; i < size; i++) {							// copy elements to the original array
		arraySortedInTwoHalves[startIndex + i] = temp[i];	// startIndex + i because of recursion
	}
	delete[]temp;	// delete temp array

}

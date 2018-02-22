#include "QuickSort.h"

int QuickSort::
quickSortDivide(int theArray[], int first, int last) {
	int pivot = theArray[last]; 
	int partitionIndex = first;							// set the partition index as start initially
	for (int i = first; i < last; i++) {
		if (theArray[i] <= pivot) {						// swap if element is lesser than pivot
			int temp = theArray[i];
			theArray[i] = theArray[partitionIndex];
			theArray[partitionIndex] = temp;
			partitionIndex = partitionIndex + 1;
		}
	}
	// swap pivot with element at partition index
	int temp2 = theArray[partitionIndex];
	theArray[partitionIndex] = theArray[last];
	theArray[last] = temp2;
	return partitionIndex;
}

void QuickSort::
quickSort(int theArray[], int start, int end) {

	// if segment index is less that end index, then recursively call quickSortDivide function
	if (start < end) {		
		int partitionIndex = quickSortDivide(theArray, start, end);			// for partition, set pivot value
		quickSort(theArray, start, partitionIndex - 1);			// quick sort first half (less than pivot)
		quickSort(theArray, partitionIndex + 1, end);			// quick sort second half (greater that pivot)
	}
	else {
		// exit condition, if segment has only 1 element left
		return;
	}
	


}



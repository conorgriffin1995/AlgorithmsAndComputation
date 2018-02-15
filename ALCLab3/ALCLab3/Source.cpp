#include <string>
#include <iostream>
using namespace std;

void Merge(int[], int, int);
void MergeSort(int [], int, int);

int main() {
	const int SIZE = 8;
	int array[SIZE] = { 1,4,1,6,8,5,3,7 };
	for (int i = 0; i < SIZE; i++) {
		cout << array[i] << " ";
	}
	MergeSort(array, 0, SIZE -1);
	for (int i = 0; i < SIZE; i++) {
		cout << array[i] << " ";
	}
	
	system("pause");
	return 0;
}
// referenced from: https://stackoverflow.com/questions/37121452/merge-sort-algorithm-merge-function-does-not-work
void MergeSort(int arrayToSort[], int startIndex, int lengthToSort) {
	int midIndex = 0;			// pivot, central value

	if (startIndex < lengthToSort) {							// if base case not reached
		midIndex = (startIndex + lengthToSort) / 2;				// split array into 2 halves
		MergeSort(arrayToSort, startIndex, midIndex);			// recursively call method to sort first half
		MergeSort(arrayToSort, (midIndex + 1), lengthToSort);	// recursively call method to sort second half
		Merge(arrayToSort, startIndex, lengthToSort);
	}

}
// merge contents of array which has been divoided into 2 halves
// from startIndex to length/2 and from startIndex + length/2 until the full sorted length
void Merge(int arraySortedInTwoHalves[], int startIndex, int length) {
	int size = (length - startIndex) + 1;
	// Tip: create( using new) a temporary array to hold the merged result, merge to
	// this array, then copy back to the array to be merged, and delete the temp array)
	int *temp = new int[size];	// temp array to hold elements
	int left = startIndex;		// left side of the array
	int midIndex = (startIndex + length) / 2; // border
	int right = midIndex + 1;	// right side of the array
	int i = 0;

	while ((left <= midIndex) && (right <= length)) { // while there are elements in both sides
		// // add whichever is lower from the appropriate side
		if (arraySortedInTwoHalves[left] <= arraySortedInTwoHalves[right]) {
			temp[i] = arraySortedInTwoHalves[left];
			left++;
		}
		else {
			temp[i] = arraySortedInTwoHalves[right];
			right++;
		}
		i++;
	}

	while (left <= midIndex) {		// if one runs out
		temp[i] = arraySortedInTwoHalves[left];
		i++;
	}

	while (left <= length) {		// if one runs out
		temp[i] = arraySortedInTwoHalves[right];
		i++;
	}

	for (i = 0; i < size; i++) {	// copy elements to the original array
		arraySortedInTwoHalves[startIndex + i] = temp[i];	// startIndex + i because of recursion
	}
	delete []temp;	// delete temp array

}
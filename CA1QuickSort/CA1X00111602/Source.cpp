// X00111602
// Conor Griffin
// I tried to create 2 functions for the quicksort algorithm but couldn't get it to work
// I wrote the algorithm within the same function and this works, I hope this is ok.
#include <iostream>
using namespace std;

template<typename T> void quickSort(T array[], int start, int end);

int main() {
	const int SIZE = 10;
	int array[SIZE] = { 3,4,1,7,5,6,9,8,4,7 };
	cout << "*** Array of integers unsorted ***" << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << array[i] << ", ";
	}
	quickSort(array, 0, SIZE - 1);
	cout << "\n\n*** Array of integers with quicksort algorithm ***" << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << array[i] << ", ";
	}

	double array2[SIZE] = { 2.1, 5.5, 3.3, 4.6, 19.8, 22.7, 11.0, 12.9, 55.4, 1.6 };
	cout << "\n\n*** Array of doubles unsorted ***" << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << array2[i] << ", ";
	}
	quickSort(array2, 0, SIZE - 1);
	cout << "\n\n*** Array of doubles with quicksort algorithm ***" << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << array2[i] << ", ";
	}


	cout << "\n\n";
	system("pause");
	return 0;
}

template<typename T> 
void quickSort(T array[], int start, int end) {
	T pivot = array[(start + end) / 2];				// set pivot value by adding forst index and last and dividing by 2
	int i = start;									// first index
	int j = end;									// last index

	// while first index is less than last index
	while (i <= j) {
		while (array[i] < pivot) {	// first half of array less than pivot
			i++;
		}
		while (array[j] > pivot) {	// second half 
			j--;
		}
		// swap posotions
		if (i <= j) {								
			T temp = array[i];						// create temp array to store values in i
			array[i] = array[j];					// set i = j
			array[j] = temp;						// j = temp, positions are swapped
			i++;
			j--;
		}

		// Recursion, I learned to recursively call the quicksort function from within the same method
		if (start < j) {
			quickSort(array, start, j);		// sort 1st half of array
		}
		if (i < end) {
			quickSort(array, i, end);		// sort 2nd half of array	
		}
	}

}



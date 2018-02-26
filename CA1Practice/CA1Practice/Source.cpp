#include "Person.h"
#include <iostream>
using namespace std;

template <typename T> void quickSort(T* array, int start, int end);

int main() {
	cout << "QuickSort\n\n";
	const int SIZE = 10;
	int A[SIZE] = { 5,6,8,4,2,1,7,9,12,3 };
	cout << "The Unsorted Array" << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << A[i] << ", ";
	}
	quickSort(A, 0, SIZE - 1);
	cout << "\nThe QuickSorted array" << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << A[i] << ", ";
	}

	Person people[] = { Person("Bob"), Person("Conor"), Person("Andrew") };

	cout << "\nPeople Unsorted" << endl;
	for (int i = 0; i < 3; i++) {
		people[i].printname();
		cout << endl;
	}

	cout << "\nPeople Sorted" << endl;
	quickSort(people, 0, 2);
	for (int i = 0; i < 3; i++) {
		people[i].printname();
		cout << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}

template<typename T>
void quickSort(T* array, int start, int end) {
	T pivot = array[(start + end) / 2];
	int i = start;
	int j = end;

	while (i <= j) {
		while (array[i] < pivot) {
			i++;
		}
		while (array[j] > pivot) {
			j--;
		}
		if (i <= j) {
			T temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}

		// Recursion
		if (start < j) {
			quickSort(array, start, j);
		}
		if (i < end) {
			quickSort(array, i, end);
		}

	}

}
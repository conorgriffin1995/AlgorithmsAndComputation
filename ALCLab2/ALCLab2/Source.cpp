#include <iostream>
using namespace std;

template <typename T> void swapByRef(T &lhs, T &rhs);							// swap by reference function
template <typename T> void swapByAdd(T *lhs, T *rhs);							// swap by address function
template <typename WhatKind> void multiples(WhatKind &sum, WhatKind x, int n);	// multiples function
template <typename T1, typename T2> T1 init(T1 num1, T1 num2, T2 &start);		// init function
template<typename T> T* quicksort(T* array, int start, int end);				// quicksort algorithm
template<typename T> int partition(T* array, int start, int end);
int main() {
	//1
	cout << "*** Question 1 ***" << endl;
	float a = 5.5, b = 4.3;
	int x = 4, y = 7;

	swapByRef(a, b);
	cout << a << " " << b << endl;

	swapByRef(x, y);
	cout << x << " " << y << endl;
	cout << endl;

	int *c = new int(5);
	int *d = new int(9);
	float *s = new float(3.3);
	float *t = new float(4.5);

	swapByAdd(c, d);
	cout << c << " " << d << endl;

	swapByAdd(s, t);
	cout << s << " " << t << endl;
	cout << endl;

	//2
	cout << "*** Question 2 ***" << endl;
	int sum = 0;
	multiples(sum, 1, 3);
	cout << sum << endl;
	sum = 0;
	multiples(sum, 2, 3);
	cout << sum << endl;
	cout << endl;

	//3
	cout << "*** Question 3 ***" << endl;
	double start = 2.2;
	cout << init(2, 3, start) << endl;
	cout << "Start: " << start << endl;
	cout << endl;

	//4
	cout << "*** Question 4 ***" << endl;
	const int SIZE = 10;
	int array[SIZE] = { 4,5,7,2,3,1,8,11,15,12 };
	
	cout << "*** Before Sort ***" << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << array[i] << ", ";
	}
	cout << endl;

	quicksort(array, 0, 9);
	cout << "*** Sorted ***" << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << array[i] << ", ";
	}

	cout << endl;

	system("pause");
	return 0;
}


template <typename T> void swapByRef(T &lhs, T &rhs) {
	T temp = lhs;
	lhs = rhs;
	rhs = temp;
}

template <typename T> void swapByAdd(T *lhs, T *rhs) {
	T *temp = lhs;
	lhs = rhs;
	rhs = temp;
}

template <typename WhatKind> void multiples(WhatKind &sum, WhatKind x, int n) {
	sum += 1;
	for (int i=0; i < n; i++) {
		sum += ((i + 1) *x);
	}
}

template <typename T1, typename T2> T1 init(T1 num1, T1 num2, T2 &start) {
	start = 1;
	return (num1 + num2);
}

// referenced from http://www.cplusplus.com/forum/beginner/119660/
template<typename T> T* quicksort(T* array, int start, int end) {
	
	if (start < end) {
		int p = partition(array, start, end);
		quicksort(array, start, p - 1);
		quicksort(array, p + 1, end);
		
	}
	return array;
}

// referenced from http://technotip.org/forums/topic/c-program-to-create-a-template-function-for-quick-sort 
template<typename T> int partition(T* array, int start, int end) {
	T num = array[start];
	int i = start + 1;
	int j = end;
	T temp;

	while (1) {
		while (i < end && num > array[i])
			i++;
		while (num < array[j])
			j--;
		if (i < j) {
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		else {
			temp = array[start];
			array[start] = array[j];
			array[j] = temp;
			return (j);
		}
	}

}
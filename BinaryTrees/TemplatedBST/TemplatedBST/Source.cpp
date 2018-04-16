#include "BinarySearchTree.h"
#include <iostream>
using namespace std;
int main() {
	BinarySearchTree<int> tree1;
	tree1.insert(7);
	tree1.insert(4);
	tree1.insert(9);
	tree1.insert(12);
	tree1.insert(3);
	tree1.insert(1);

	if (tree1.search(9) == true) {
		cout << "FOUND";
	}
	else {
		cout << "NOT FOUND";
	}

	cout << endl;

	cout << "A tree of ints in order" << endl;
	tree1.print_inOrder();

	cout << endl;
	cout << "MAX: " << tree1.maxValue() << endl;
	cout << "MIN: " << tree1.minValue() << endl;
	//tree1.~BinarySearchTree();

	cout << endl;
	system("pause");
	return 0;
}
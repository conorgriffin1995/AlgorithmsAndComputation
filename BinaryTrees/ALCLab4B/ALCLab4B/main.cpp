#include "BinaryTree.h"
#include <iostream>
using namespace std;

int main() {
	BinaryTree tree;

	tree.add(7);
	tree.add(4);
	tree.add(2);
	tree.add(3);
	tree.add(6);
	tree.add(1);
	tree.add(8);
	tree.add(9);
	tree.add(5);
	tree.add(10);

	cout << "The height of the tree is " << tree.height() << endl;
	cout << endl;

	cout << "Searching for integer: ";
	tree.search(6);
	cout << endl;

	cout << "Printing characters in order traversal" << endl;
	tree.inOrder();
	cout << endl;

	cout << "Printing min value in binary search tree: " << tree.minValue() << endl;
	cout << endl;

	cout << "Printing max value in binary search tree: " << tree.maxValue() << endl;
	cout << endl;

	cout << "Is a BST: " << tree.isBST() << endl;

	system("pause");
	return 0;
}
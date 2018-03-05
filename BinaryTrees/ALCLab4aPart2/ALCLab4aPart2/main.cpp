#include "BinaryTree.h"
#include <iostream>
using namespace std;

int main() {
	BinaryTree tree;

	tree.add(5);
	tree.add(4);
	tree.add(8);
	tree.add(11);
	tree.add(13);
	tree.add(4);
	tree.add(7);
	tree.add(2);
	tree.add(1);

	cout << "The height of the tree is " << tree.height() << endl;
	cout << endl;

	// Has Path Sum : 5 + 4 + 2 + 1 = 12
	// Has Path Sum : 5 + 4 + 4 = 13
	// Has Path Sum : 5 + 8 + 7 = 20
	// Has Path Sum : 5 + 8 + 11 + 13 = 37
	if (tree.hasPathSum(37) == true) {
		cout << "true";
	}
	else {
		cout << "false";
	}
	cout << endl;

	cout << "Printing paths..." << endl;
	// Has Path: 5 4 2 1
	// Has Path: 5 4 4 
	// Has Path: 5 8 7
	// Has Path: 5 8 11 13
	tree.printPaths();

	cout << endl;
	system("pause");
	return 0;
}
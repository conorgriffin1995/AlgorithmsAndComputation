#include <iostream>
#include <string>
#include "BinaryTree.h"
using namespace std;

int main() {
	BinaryTree tree;
	tree.add(1);
	tree.add(2);
	tree.add(3);
	tree.add(4);
	tree.add(5);
	tree.add(4);
	tree.add(6);
	tree.add(7);
	tree.add(5);
	tree.add(8);
	tree.add(9);

	cout << "The height of the tree is: " << tree.height() << endl;

	system("pause");
	return 0;
}
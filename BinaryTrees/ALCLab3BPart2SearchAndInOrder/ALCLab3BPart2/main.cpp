#include "BinaryTree.h"
#include <iostream>
using namespace std;

int main() {
	BinaryTree tree;

	tree.add('a');
	tree.add('c');
	tree.add('b');
	tree.add('d');
	tree.add('e');

	cout << "The height of the tree is " << tree.height() << endl;

	tree.search('a');

	tree.inOrder();

	cout << endl;
	system("pause");
	return 0;
}
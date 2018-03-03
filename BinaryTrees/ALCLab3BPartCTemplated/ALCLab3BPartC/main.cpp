#include "BinaryTree.h"
#include <iostream>
using namespace std;

int main() {
	BinaryTree<char> tree;
	tree.add('a');
	tree.add('c');
	tree.add('b');
	tree.add('d');
	tree.add('e');
	cout << "A tree of characters.. " << endl;
	cout << "The height of the tree is " << tree.height() << endl;
	tree.search('a');
	tree.inOrder();
	cout << endl << endl;

	BinaryTree<int> tree2;
	tree2.add(1);
	tree2.add(3);
	tree2.add(5);
	tree2.add(2);
	tree2.add(7);
	cout << "A tree of integers.. " << endl;
	cout << "The height of the tree is " << tree2.height() << endl;
	tree2.search(3);
	tree2.inOrder();
	cout << endl;

	system("pause");
	return 0;
}
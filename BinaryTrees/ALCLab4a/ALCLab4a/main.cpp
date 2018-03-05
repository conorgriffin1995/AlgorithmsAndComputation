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
	cout << endl;

	cout << "Searching for charater: ";
	tree.search('a');
	cout << endl;

	cout << "Printing characters in order traversal" << endl;
	tree.inOrder();
	cout << endl;

	cout << "Printing characters preorder traversal" << endl;
	tree.preOrder();
	cout << endl;

	cout << "Printing characters postorder traversal" << endl;
	tree.postOrder();
	cout << endl;

	system("pause");
	return 0;
}
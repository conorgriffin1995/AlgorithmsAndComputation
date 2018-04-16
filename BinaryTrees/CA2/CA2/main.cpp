#include "BinarySearchTree.h"
#include <iostream>
using namespace std;
// CA2
// Conor Griffin
// x00111602
int main() {
	// tree of ints
	BinarySearchTree<int> tree1;
	tree1.insert(5);
	tree1.insert(8);
	tree1.insert(4);
	tree1.insert(2);
	tree1.insert(10);
	tree1.insert(12);
	// print in order
	tree1.print_inOrder();
	cout << endl;
	tree1.increasing_orderTree();
	cout << endl;
	// search for 8
	if (tree1.search(8) == true) {
		cout << "FOUND!!!" << endl;
	}
	else {
		cout << "NOT FOUND" << endl;
	}
	// remove 4
	tree1.remove(4);
	// print in order ints with removed value 4
	tree1.print_inOrder();
	cout << endl;

	// tree of chars
	BinarySearchTree<char> tree2;
	tree2.insert('h');
	tree2.insert('g');
	tree2.insert('m');
	tree2.insert('x');
	tree2.insert('c');
	tree2.insert('a');
	// print in order
	tree2.print_inOrder();
	cout << endl;
	// search for m
	if (tree2.search('m') == true) {
		cout << "FOUND!!!" << endl;
	}
	else {
		cout << "NOT FOUND" << endl;
	}
	// remove c
	tree2.remove('c');
	// print in order ints with removed value c
	tree2.print_inOrder();
	cout << endl;

	// tree of doubles
	BinarySearchTree<double> tree3;
	tree3.insert(5.6);
	tree3.insert(8.4);
	tree3.insert(4.7);
	tree3.insert(2.9);
	tree3.insert(10.5);
	tree3.insert(12.3);

	// print in order
	tree3.print_inOrder();
	cout << endl;
	// search for 8
	if (tree3.search(8.4) == true) {
		cout << "FOUND!!!" << endl;
	}
	else {
		cout << "NOT FOUND" << endl;
	}
	// remove 4
	tree3.remove(10.5);
	// print in order ints with removed value 4
	tree3.print_inOrder();
	cout << endl;

	cout << endl;
	system("pause");
	return 0;
}
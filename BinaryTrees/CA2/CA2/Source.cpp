#include "BinarySearchTree.h"
#include <iostream>
#include <sstream>
using namespace std;
// CA2
// Conor Griffin
// x00111602
int main() {
	int answer;
	BinarySearchTree<int> tree;

	cout << "Enter list if integers" << endl;
	cin >> answer;

	while (answer != 0) {
		tree.insert(answer);
		if (answer = 0) {
			return 0;
		}
	}

	tree.print_inOrder();
	tree.print_postOrder();

	system("pause");
	return 0;
}
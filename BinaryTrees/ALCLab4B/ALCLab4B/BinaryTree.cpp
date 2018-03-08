#include "BinaryTree.h"
#include <iostream>


BinaryTree::BinaryTree() {
	root = NULL;
}

void BinaryTree::add(int dataIn) {
	add(root, dataIn);
}

void BinaryTree::add(Node *subtreeRoot, int dataIn) {
	if (subtreeRoot == NULL) {
		root = new Node(dataIn);
	}
	else {
		if (subtreeRoot->isLeaf()) {
			if (dataIn < subtreeRoot->data) {
				subtreeRoot->left = new Node(dataIn);
			}
			else {
				subtreeRoot->right = new Node(dataIn);
			}
		}
		else {
			if (dataIn < subtreeRoot->data) {
				if (subtreeRoot->left != NULL) {
					add(subtreeRoot->left, dataIn);
				}
				else {
					subtreeRoot->left = new Node(dataIn);
				}
			}
			else {
				if (subtreeRoot->right != NULL) {
					add(subtreeRoot->right, dataIn);
				}
				else {
					subtreeRoot->right = new Node(dataIn);
				}
			}
		}
	}
}

int BinaryTree::height() {
	return height(root);
}

int BinaryTree::height(Node *subtreeRoot) {
	if (subtreeRoot == NULL) {
		return -1;
	}
	else {
		// compute the height of the subtree
		int lDepth = height(subtreeRoot->left);
		int rDepth = height(subtreeRoot->right);

		// use the larger one
		if (lDepth > rDepth) {
			return(lDepth + 1);
		}
		else {
			return (rDepth + 1);
		}
	}
}

bool BinaryTree::search(int dataIn) {
	return search(root, dataIn);
}

bool BinaryTree::search(Node *subtreeRoot, int dataIn) {
	bool found = false;
	Node* currentNode;
	currentNode = subtreeRoot;
	while (!found && currentNode != NULL) {
		if (dataIn == currentNode->data) {
			found = true;
		}
		else if (dataIn < currentNode->data) {
			currentNode = currentNode->left;
		}
		else if (dataIn > currentNode->data) {
			currentNode = currentNode->right;
		}
	}
	if (!found) {
		std::cout << "Data not found! " << std::endl;
	}
	else
	{
		std::cout << dataIn;
		std::cout << std::endl;
		std::cout << "Data found! " << std::endl;
	}

	return found;

}

void BinaryTree::inOrder() {
	inOrder(root);
}

void BinaryTree::inOrder(Node *subtreeRoot) {
	if (subtreeRoot != NULL) {
		if (subtreeRoot->left) {
			inOrder(subtreeRoot->left);
		}
		std::cout << " " << subtreeRoot->data << " ";
		if (subtreeRoot->right) {
			inOrder(subtreeRoot->right);
		}
	}
	else {
		return;
	}
}
// Lab 4B
/* Given a non-empty binary search tree,
return the minimum data value found in that
tree. Note that the entire tree does not need
to be searched. */
int BinaryTree::minValue() {
	return minValue(root);
}

int BinaryTree::minValue(Node *node) {
	if (node != NULL) {
		while (node->left != NULL) {
			node = node->left;
		}
		return(node->data);
	}
	else {
		return 0;
	}
}

int BinaryTree::maxValue() {
	return maxValue(root);
}

int BinaryTree::maxValue(Node *node) {
	if (node != NULL) {
		while (node->right != NULL) {
			node = node->right;
		}
		return(node->data);
	}
	else {
		return 0;
	}
}

int BinaryTree::isBST() {
	int min = minValue();
	std::cout << min << std::endl;
	int max = maxValue();
	std::cout << max << std::endl;
	return isBSTRecur(root, min, max);
}
/*
Returns true if the given tree is a BST and its
values are >= min and <= max.
*/
int BinaryTree::isBSTRecur(Node *node, int min, int max) {
	if (node == NULL) {
		return 1;
	}
	if (node->data < min || node->data > max) {
		return 0;
	}
	// otherwise check the subtrees recursively, 
	// tightening the min or max constraint 
	return
		isBSTRecur(node->left, min, node->data) &&
		isBSTRecur(node->right, node->data + 1, max);
}

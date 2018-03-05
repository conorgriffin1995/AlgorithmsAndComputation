#include "BinaryTree.h"
#include <iostream>


BinaryTree::BinaryTree() {
	root = NULL;
}

void BinaryTree::add(char dataIn) {
	add(root, dataIn);
}

void BinaryTree::add(Node *subtreeRoot, char dataIn) {
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

bool BinaryTree::search(char dataIn) {
	return search(root, dataIn);
}

bool BinaryTree::search(Node *subtreeRoot, char dataIn) {
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

void BinaryTree::preOrder() {
	preOrder(root);
}

void BinaryTree::preOrder(Node *subtreeRoot) {
	if (subtreeRoot != NULL) {
		std::cout << " " << subtreeRoot->data << " ";
		if (subtreeRoot->left) {
			preOrder(subtreeRoot->left);
		}
		if (subtreeRoot->right) {
			preOrder(subtreeRoot->right);
		}
	}
	else {
		return;
	}
	
}

void BinaryTree::postOrder() {
	postOrder(root);
}

void BinaryTree::postOrder(Node *subtreeRoot) {
	if (subtreeRoot != NULL) {
		if (subtreeRoot->left) {
			preOrder(subtreeRoot->left);
		}
		if (subtreeRoot->right) {
			preOrder(subtreeRoot->right);
		}
		std::cout << " " << subtreeRoot->data << " ";
	}
	else {
		return;
	}

}

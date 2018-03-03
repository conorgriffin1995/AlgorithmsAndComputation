#include "BinaryTree.h"
#include <iostream>


BinaryTree::BinaryTree(){
	root = NULL;
}


BinaryTree::~BinaryTree(){
	clear();
}

void BinaryTree::clear() {
	clear(root);
}

void BinaryTree::clear(Node *p) {
	Node* n = p;
	if (n->left != NULL)
		clear(n->left);
	if (n->right != NULL)
		clear(n->right);
	delete n;
	p = NULL;
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
		else if(dataIn < currentNode->data){
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

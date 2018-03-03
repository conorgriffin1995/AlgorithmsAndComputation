#pragma once
#include "Node.h"
#include <iostream>
#include <algorithm>
template<class T>
class BinaryTree
{
public:
	BinaryTree() {
		root = NULL;
	}
	~BinaryTree();
	void clear();
	void add(T dataIn);
	int height();
	bool search(T dataIn);
	void inOrder();

private:
	Node<T> *root;
	void add(Node<T> *subtreeRoot, T dataIn);
	int height(Node<T> *subtreeRoot);
	bool search(Node<T> *subtreeRoot, T dataIn);
	void inOrder(Node<T> *subtreeRoot);
	void clear(Node<T> *p);
};

template<class T>
BinaryTree<T>::~BinaryTree() {
	clear();
}

template<class T>
void BinaryTree<T>::clear() {
	clear(root);
}

template<class T>
void BinaryTree<T>::clear(Node<T> *p) {
	Node<T>* n = p;
	if (n->left != NULL)
		clear(n->left);
	if (n->right != NULL)
		clear(n->right);
	delete n;
	p = NULL;
}

template<class T>
void BinaryTree<T>::add(T dataIn) {
	add(root, dataIn);
}

template<class T>
void BinaryTree<T>::add(Node<T> *subtreeRoot, T dataIn) {
	if (subtreeRoot == NULL) {
		root = new Node<T>(dataIn);
	}
	else {
		if (subtreeRoot->isLeaf()) {
			if (dataIn < subtreeRoot->data) {
				subtreeRoot->left = new Node<T>(dataIn);
			}
			else {
				subtreeRoot->right = new Node<T>(dataIn);
			}
		}
		else {
			if (dataIn < subtreeRoot->data) {
				if (subtreeRoot->left != NULL) {
					add(subtreeRoot->left, dataIn);
				}
				else {
					subtreeRoot->left = new Node<T>(dataIn);
				}
			}
			else {
				if (subtreeRoot->right != NULL) {
					add(subtreeRoot->right, dataIn);
				}
				else {
					subtreeRoot->right = new Node<T>(dataIn);
				}
			}
		}
	}
}
template<class T>
int BinaryTree<T>::height() {
	return height(root);
}

template<class T>
int BinaryTree<T>::height(Node<T> *subtreeRoot) {
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

template<class T>
bool BinaryTree<T>::search(T dataIn) {
	return search(root, dataIn);
}

template<class T>
bool BinaryTree<T>::search(Node<T> *subtreeRoot, T dataIn) {
	bool found = false;
	Node<T>* currentNode;
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
		std::cout << "Data found! " << std::endl;
	}

	return found;
}

template<class T>
void BinaryTree<T>::inOrder() {
	inOrder(root);
}

template<class T>
void BinaryTree<T>::inOrder(Node<T> *subtreeRoot) {
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





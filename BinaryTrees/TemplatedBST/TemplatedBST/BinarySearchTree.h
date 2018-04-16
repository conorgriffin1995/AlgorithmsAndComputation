#pragma once
#include <iostream>
#include "Node.h"
template<class T>
class BinarySearchTree {
public:
	BinarySearchTree();
	~BinarySearchTree();
	void insert(T dataIn);
	bool search(T dataIn);
	bool isEmpty() const;
	void remove(T dataIn);
	void print_inOrder();
	T maxValue();
	T minValue();
private:
	void removeSubtree(Node<T> *subtreeroot);
	void insert(Node<T> *subtreeRoot, T dataIn);
	bool search(Node<T> *subtreeRoot, T dataIn);
	void remove(Node<T> *subtreeRoot, T dataIn);
	void inOrder(Node<T> *subtreeRoot);
	T maxValue(Node<T> *subtreeRoot);
	T minValue(Node<T> *subtreeRoot);
private:
	Node<T> *root;
};

// Constructor
template<class T>
BinarySearchTree<T>::BinarySearchTree() {
	root = NULL;
}
// Destructor
template<class T>
BinarySearchTree<T>::~BinarySearchTree() {
	if (root) delete root;
}
// destroy nodes and delete root
template<class T>
void BinarySearchTree<T>::removeSubtree(Node<T> *subtreeRoot) {
	if (subtreeRoot != NULL) {
		if (subtreeRoot->left != NULL) {
			removeSubtree(subtreeRoot->left);
		}
		if (subtreeRoot->right != NULL) {
			removeSubtree(subtreeRoot->right);
		}
		std:cout << "Deleting the node containing data: " << subtreeRoot->data << endl;
		delete subtreeRoot;
	}
}
// test if tree is empty
template<class T>
bool BinarySearchTree<T>::isEmpty() const {
	return root == NULL;
}


// insert
template<class T>
void BinarySearchTree<T>::insert(T dataIn) {
	insert(root, dataIn);
}
template<class T>
void BinarySearchTree<T>::insert(Node<T> *subtreeRoot, T dataIn) {
	// if tree root is empty, add first node with data
	if (isEmpty()) {
		root = new Node<T>(dataIn);
	}
	// else tree is not empty
	else {
		// if root left and right is empty
		if (subtreeRoot->isLeaf()) {
			// if dataIn < data of root node add as new node to the left
			if (dataIn < subtreeRoot->data) {
				subtreeRoot->left = new Node<T>(dataIn);
			}
			// else add it to the right as new node
			else {
				subtreeRoot->right = new Node<T>(dataIn);
			}
		}
		// root left and right is not empty
		else {
			// if dataIn < sub tree data
			if (dataIn < subtreeRoot->data) {
				// if left not null recursively call add method and add to left dataIn
				if (subtreeRoot->left != NULL) {
					insert(subtreeRoot->left, dataIn);
				}
				// else add as new node to left in tree
				else {
					subtreeRoot->left = new Node<T>(dataIn);
				}
			}
			// dataIn > sub tree data
			else {
				// if right not null recursively call add method and add to right dataIn
				if (subtreeRoot->right != NULL) {
					insert(subtreeRoot->right, dataIn);
				}
				// else add as new node to right in tree
				else {
					subtreeRoot->right = new Node<T>(dataIn);
				}
			}
		}
	}
}

// search
template<class T>
bool BinarySearchTree<T>::search(T dataIn) {
	return search(root, dataIn);
}
template<class T>
bool BinarySearchTree<T>::search(Node<T> *subtreeRoot, T dataIn) {
	// if empty return false
	if (isEmpty()) {
		return false;
	}
	else {
		// if sub tree data not != dataIn
		if (subtreeRoot->data != dataIn) {
			// if sub tree left and right is empty
			if (subtreeRoot->isLeaf()) {
				return false;
			}
			// sub tree left and right not empty
			else {
				// if dataIn < sub tree data search left tree for dataIn
				if (dataIn < subtreeRoot->data) {
					search(subtreeRoot->left, dataIn);
				}
				// else search right tree for dataIn
				else {
					search(subtreeRoot->right, dataIn);
				}
			}
		}
		// return found!
		else {
			return true;
		}
	}
}

// print inOrder tree
template<class T>
void BinarySearchTree<T>::print_inOrder() {
	inOrder(root);
}
template<class T>
void BinarySearchTree<T>::inOrder(Node<T> *subtreeRoot) {
	if (subtreeRoot != NULL) {
		if (subtreeRoot->left) {
			inOrder(subtreeRoot->left);
		}		
		std::cout << subtreeRoot->data << ", ";
		if (subtreeRoot->right) {
			inOrder(subtreeRoot->right);
		}
	}
}

// remove node
template<class T>
void BinarySearchTree<T>::remove(T dataIn) {
	remove(root, dataIn);
}
template<class T>
void BinarySearchTree<T>::remove(Node<T> *subtreeRoot, T dataIn) {

}

// Get Max Value in tree
template<class T>
T BinarySearchTree<T>::maxValue() {
	return maxValue(root);
}
// Max means you go right in the tree
template<class T>
T BinarySearchTree<T>::maxValue(Node<T> *subtreeRoot) {
	if (subtreeRoot != NULL) {
		if (subtreeRoot->isLeaf()) {
			return subtreeRoot->data;
		}
		else if (subtreeRoot->right == NULL) {
			return subtreeRoot->data;
		}
		else {
			return maxValue(subtreeRoot->right);
		}
	}
}

// Get min value in tree
template<class T>
T BinarySearchTree<T>::minValue() {
	return minValue(root);
}
// go left in tree
template<class T>
T BinarySearchTree<T>::minValue(Node<T> *subtreeRoot) {
	if (subtreeRoot != NULL) {
		if (subtreeRoot->isLeaf()) {
			return subtreeRoot->data;
		}
		else if (subtreeRoot->left == NULL) {
			return subtreeRoot->data;
		}
		else {
			return minValue(subtreeRoot->left);
		}
	}
}
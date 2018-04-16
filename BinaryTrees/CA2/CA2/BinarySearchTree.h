#pragma once
#include "Node.h"
#include <iostream>
// CA2
// Conor Griffin
// x00111602
template<class T>
class BinarySearchTree {
public:
	BinarySearchTree() { root = NULL; }
	~BinarySearchTree() { if (root) delete root; }
	bool isEmpty() const { return root == NULL; }
	bool isLeaf();
	bool search(T dataIn);
	void insert(T dataIn);
	void remove(T dataIn);
	void print_inOrder() const;
	void increasing_orderTree();
	void print_postOrder();
private:
	Node<T> *root;
	bool isLeaf(Node<T> *str) const;
	bool search(Node<T> *str, T dataIn);
	void insert(Node<T> *str, T dataIn);
	Node<T>* remove(Node<T> *node, T dataIn);
	void inOrder(Node<T> *str) const;
	Node<T>* minValueNode(Node<T> *node);
	void increasing_orderTree(Node<T> *str);
	void print_postOrder(Node<T> *str);
};

template<class T>
bool BinarySearchTree<T>::isLeaf() {
	return isLeaf(root);
}

template<class T>
bool BinarySearchTree<T>::isLeaf(Node<T> *str) const {
	// if left and right subtreeroot is NULL return true
	if (str->left == NULL && str->right == NULL) {
		return true;
	}
	else {
		return false;
	}
}

// inserts are done recursively
template<class T>
void BinarySearchTree<T>::insert(T dataIn) {
	insert(root, dataIn);
}

template<class T>
void BinarySearchTree<T>::insert(Node<T> *str, T dataIn) {
	// if is empty
	if (isEmpty()) {
		root = new Node <T> (dataIn);
	}
	// else tree is not empty
	else {
		// if left and right empty
		if (isLeaf()) {
			if (dataIn < str->data) {
				str->left = new Node<T>(dataIn);
			}
			else {
				str->right = new Node<T>(dataIn);
			}
		}
		// left and right not empty
		else {
			// if dataIn < root data go left
			if (dataIn < str->data) {
				// if left not null recursively go down left until left is NULL and create new Node
				if (str->left != NULL) {
					insert(str->left, dataIn);
				}
				else {
					str->left = new Node<T>(dataIn);
				}				
			}
			// else dataIn > root data go right
			else {
				// if right not null recursively go down right until right is NULL and create new Node
				if (str->right != NULL) {
					insert(str->right, dataIn);
				}
				else {
					str->right = new Node<T>(dataIn);
				}				
			}
		}
	}
}

template<class T>
bool BinarySearchTree<T>::search(T dataIn) {
	return search(root, dataIn);
}

template<class T>
bool BinarySearchTree<T>::search(Node<T> *str, T dataIn) {
	// if tree is empty return not found
	if (isEmpty()) {
		return false;
	}
	else {
		// if subtreeroot data not found
		if (str->data != dataIn) {
			// if left and right is null return not found
			if (isLeaf()) {
				return false;
			}
			// if data < subtreeroot data recursively search left side of tree
			else {
				if (dataIn < str->data) {
					search(str->left, dataIn);
				}
				// else re cursively search right side of tree
				else {
					search(str->right, dataIn);
				}
			}
		}
		// else data found
		else {
			return true;
		}
	}
}

template<class T>
void BinarySearchTree<T>::print_inOrder() const {
	inOrder(root);
}

template<class T>
void BinarySearchTree<T>::inOrder(Node<T> *str) const {
	// start at root, then go left and then right
	if (str != NULL) {
		cout << str->data << ", ";
		if (str->left) inOrder(str->left);		
		if (str->right) inOrder(str->right);
	}
}

template<class T>
void BinarySearchTree<T>::increasing_orderTree() {
	increasing_orderTree(root);
}

template<class T>
void BinarySearchTree<T>::increasing_orderTree(Node<T> *str) {
	// traverse the tree starting with left most node to get the smallest, print values and 
	// work back to root then go down tree to right and print values 
	if (str != NULL) {		
		if (str->left) increasing_orderTree(str->left);
		cout << str->data << ", ";
		if (str->right) increasing_orderTree(str->right);
	}
}

template<class T>
void BinarySearchTree<T>::print_postOrder() {
	print_postOrder(root);
}

template<class T>
void BinarySearchTree<T>::print_postOrder(Node<T> *str) {
	// traverse the tree starting with root then go left and go right 
	if (str != NULL) {
		if (str->left) print_postOrder(str->left);		
		if (str->right) print_postOrder(str->right);
		cout << str->data << ", ";
	}
}

template<class T>
void BinarySearchTree<T>::remove(T dataIn) {
	remove(root, dataIn);
}

template<class T>
Node<T>* BinarySearchTree<T>::remove(Node<T> *node, T dataIn) {
	// if roo is null return node
	if (node == NULL)
	{
		return node;
	}
	// go left of BST by checking if dataIn < node data
	if (dataIn < node->data)
	{
		node->left = remove(node->left, dataIn);
	}
	// right of BST
	else if (dataIn > node->data)
	{
		node->right = remove(node->right, dataIn);
	}
	// same as root's key
	else												
	{
		// left child case
		if (node->left == NULL)							
		{
			Node<T> *temp = node->right;
			// Deallocate memory block
			free(node);									
			return temp;
		}
		// right child case
		else if (node->right == NULL)					
		{
			Node<T> *temp = node->left;
			// Deallocate memory block
			free(node);									
			return temp;
		}
		// both children case
		// create temp node = to the minimum value node in left most node in right of tree
		Node<T> *temp = minValueNode(node->right);	
		node->data = temp->data;
		node->right = remove(node->right, temp->data);
	}
	return node;
}

template<class T>
Node<T>* BinarySearchTree<T>::minValueNode(Node<T> *node) {
	Node<T> *current = node;

	while (current->left != NULL)
	{
		current = current->left;
	}
	return current;
}
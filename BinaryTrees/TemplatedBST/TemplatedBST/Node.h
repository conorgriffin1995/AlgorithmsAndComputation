#pragma once
#include <iostream>

template<class T>
class Node
{
	template<class T> friend class BinarySearchTree;
public:
	Node(T dataIn) {
		data = dataIn;
		left = right = NULL;
	}
	bool isLeaf();

private:
	Node<T> *left;
	Node<T> *right;
	T data;
};

template<class T>
bool Node<T>::isLeaf() {
	if (this->left == NULL && this->right == NULL) {
		return true;
	}
	else {
		return false;
	}
}



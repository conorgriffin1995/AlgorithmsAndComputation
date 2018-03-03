#pragma once
#include <iostream>
template<class T>
class Node
{
	template<class T> friend class BinaryTree;
public:
	Node(T dataIn) {
		data = dataIn;
		left = right = NULL;
	}
	int isLeaf();
private:
	Node<T> *left;
	Node<T> *right;
	T data;
};

template<class T>
int Node<T>::isLeaf() {
	if (this->left == NULL && this->right == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}


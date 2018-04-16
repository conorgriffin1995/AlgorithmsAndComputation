#pragma once
#include <iostream>
// CA2
// Conor Griffin
// x00111602
template<class T>
class Node
{
	template<class T> friend class BinarySearchTree;
public:
	Node(T dataIn) {
		data = dataIn;
		left = right = NULL;
	}
private:
	Node<T> *left;
	Node<T> *right;
	T data;

};


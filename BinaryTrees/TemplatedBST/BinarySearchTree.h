#pragma once
#include <iostream>
#include <cctype>
#include <queue>
#include <utility>   // for std::pair
#include "TreeNode.h"

using namespace std;
template <typename T>
class BinarySearchTree {
public:
	BinarySearchTree();
	void add(T);
	bool search(T);
	void print();
	bool isBST();
	T maxValue();
	T minValue();
	void remove(T);
	void pT();
private:
	TreeNode<T> * root;
	void add(TreeNode<T> *subTreeRoot, T);
	bool search(TreeNode<T> *subTreeRoot, T);
	void print(TreeNode<T> *subTreeRoot);
	T maxValue(TreeNode<T> *subTreeRoot);
	T minValue(TreeNode<T> *subTreeRoot);
	bool isBST(TreeNode<T> *subTreeRoot);
	void remove(TreeNode<T> * subTreeRoot, T);
	void removeRoot(TreeNode<T> *subTreeRoot);
	void printBinaryTree(const TreeNode<T> * subTreeRoot);
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree() {
	root = NULL;
}

template <typename T>
void BinarySearchTree<T>::add(const T dataIn) {
	add(root, dataIn);
}

template <typename T>
bool BinarySearchTree<T>::search(const T itemToFind) {
	return search(root, itemToFind);
}

template <typename T>
void BinarySearchTree<T>::print() {
	print(root);
}

template <typename T>
T BinarySearchTree<T>::maxValue() {
	return maxValue(root);
}

template <typename T>
T BinarySearchTree<T>::minValue() {
	return minValue(root);
}

template <typename T>
bool BinarySearchTree<T>::isBST() {
	return isBST(root);
}

template <typename T>
void BinarySearchTree<T>::remove(T toRemove) {
	remove(root, toRemove);
}

template <typename T>
void BinarySearchTree<T>::pT() {
	printBinaryTree(root);
}

template <typename T>
void BinarySearchTree<T>::printBinaryTree(const TreeNode<T> *n) {
	if (nullptr == n) {
		return;
	}
	int level = 0;

	// Use a queue for breadth-first traversal of the tree.  The pair is
	// to keep track of the depth of each node.  (Depth of root node is 1.)
	typedef std::pair<const TreeNode<T>*, int> node_level;
	std::queue<node_level> q;
	q.push(node_level(n, 1));

	while (!q.empty()) {
		node_level nl = q.front();
		q.pop();
		if (nullptr != (n = nl.first)) {
			if (level != nl.second) {
				std::cout << " Level " << nl.second << ": ";
				level = nl.second;
			}
			std::cout << n->data << ' ';
			q.push(node_level(n->leftNode, 1 + level));
			q.push(node_level(n->rightNode, 1 + level));
		}
	}
	std::cout << std::endl;
}


template <typename T>
void BinarySearchTree<T>::add(TreeNode<T> *subTreeRoot, const T dataIn) {
	if (subTreeRoot == NULL) {
		root = new TreeNode<T>(dataIn);
	}
	else {
		if (subTreeRoot->isLeaf()) {
			if (dataIn < subTreeRoot->data) {
				subTreeRoot->leftNode = new TreeNode<T>(dataIn);
			}
			else {
				subTreeRoot->rightNode = new TreeNode<T>(dataIn);
			}
		}
		else {
			if (dataIn < subTreeRoot->data) {
				if (subTreeRoot->leftNode != NULL) {
					add(subTreeRoot->leftNode, dataIn);
				}
				else {
					subTreeRoot->leftNode = new TreeNode<T>(dataIn);
				}
			}
			else {
				if (subTreeRoot->rightNode != NULL) {
					add(subTreeRoot->rightNode, dataIn);
				}
				else {
					subTreeRoot->rightNode = new TreeNode<T>(dataIn);
				}
			}
		}
	}
}

template <typename T>
bool BinarySearchTree<T>::search(TreeNode<T> *subTreeRoot,const T itemToFind) {
	if (subTreeRoot == NULL) {
		return false;
	}
	else {
		if (subTreeRoot->data != itemToFind) {
			if (subTreeRoot->isLeaf()) {
				return false;
			}
			else {
				if (itemToFind < subTreeRoot->data) {
					search(subTreeRoot->leftNode, itemToFind);
				}
				else {
					search(subTreeRoot->rightNode, itemToFind);
				}
			}
		}
		else {
			return true;
		}
	}
}

template <typename T>
void BinarySearchTree<T>::print(TreeNode<T> *subTreeRoot) {
	if (subTreeRoot == NULL) {
		cout << "Tree is empty!" << endl;
	}
	else {
		if (subTreeRoot->leftNode)
			print(subTreeRoot->leftNode);
		cout << subTreeRoot->data << ", ";
		if (subTreeRoot->rightNode)
			print(subTreeRoot->rightNode);
	}
}

template <typename T>
T BinarySearchTree<T>::maxValue(TreeNode<T> *subTreeRoot) {
	if (subTreeRoot != NULL) {
		if (subTreeRoot->isLeaf()) {
			return subTreeRoot->data;
		}
		else if(subTreeRoot->rightNode == NULL) {
			return subTreeRoot->data;
		}
		else {
			return maxValue(subTreeRoot->rightNode);
		}
	}
}

template <typename T>
T BinarySearchTree<T>::minValue(TreeNode<T> *subTreeRoot) {
	if (subTreeRoot != NULL) {
		if (subTreeRoot->isLeaf()) {
			return subTreeRoot->data;
		}
		else if (subTreeRoot->leftNode == NULL) {
			return subTreeRoot->data;
		}
		else {
			return minValue(subTreeRoot->leftNode);
		}
	}
}


template <typename T>
bool BinarySearchTree<T>::isBST(TreeNode<T> *subTreeRoot) {
	if (subTreeRoot != NULL) {
		if (subTreeRoot->leftNode != NULL && maxValue(subTreeRoot->leftNode) > subTreeRoot->data) {
			return false;
		}
		if (subTreeRoot->rightNode != NULL && minValue(subTreeRoot->rightNode) < subTreeRoot->data) {
			return false;
		}
		if (!isBST(subTreeRoot->leftNode) || !isBST(subTreeRoot->rightNode)) {
			return false;
		}
	}
	return true;
}

template <typename T>
void BinarySearchTree<T>::remove(TreeNode<T> *subTreeRoot, T toRemove) {
	if (subTreeRoot != NULL) {
		if (subTreeRoot->data == toRemove) {
			removeRoot(subTreeRoot);
		}
		else {
			if (toRemove < subTreeRoot->data) {
				if (toRemove == subTreeRoot->leftNode->data) {
					if (subTreeRoot->leftNode->isLeaf()) {
						free(subTreeRoot->leftNode);
						subTreeRoot->leftNode = NULL;
					}
					else {
						if (subTreeRoot->leftNode->leftNode != NULL) {
							TreeNode<T> *temp;
							temp = subTreeRoot->leftNode->leftNode;
							free(subTreeRoot->leftNode);
							subTreeRoot->leftNode = temp;
						}
						else {
							if (subTreeRoot->leftNode->rightNode != NULL) {
								TreeNode<T> * temp = subTreeRoot->leftNode->rightNode;
								free(subTreeRoot->leftNode);
								subTreeRoot->leftNode = temp;
							}
							else {
								free(subTreeRoot->leftNode);
								subTreeRoot->leftNode = NULL;
							}
						}
					}
				}
				else {
					remove(subTreeRoot->leftNode, toRemove);
				}
			}
			else {
				if (toRemove == subTreeRoot->rightNode->data) {
					if (subTreeRoot->rightNode->isLeaf()) {
						free(subTreeRoot->rightNode);
						subTreeRoot->rightNode = NULL;
					}
					else {
						if (subTreeRoot->rightNode->rightNode != NULL) {
							TreeNode<T> *temp;
							temp = subTreeRoot->rightNode->rightNode;
							free(subTreeRoot->rightNode);
							subTreeRoot->rightNode = temp;
						}
						else {
							if (subTreeRoot->rightNode->rightNode != NULL) {
								TreeNode<T> * temp = subTreeRoot->rightNode->rightNode;
								free(subTreeRoot->rightNode);
								subTreeRoot->rightNode = temp;
							}
							else {
								free(subTreeRoot->rightNode);
								subTreeRoot->rightNode = NULL;
							}
						}
					}
				}
				else {
					remove(subTreeRoot->rightNode, toRemove);
				}
			}
		}
	}
}

template <typename T>
void BinarySearchTree<T>::removeRoot(TreeNode<T> *subTreeRoot) {
	if (!subTreeRoot->isLeaf()) {
		if (subTreeRoot->rightNode != NULL) {
			T temp = minValue(subTreeRoot->rightNode);
			remove(temp);
			subTreeRoot->data = temp;

		}
		else {
			if (subTreeRoot->leftNode != NULL)
			{
				TreeNode<T> *temp = subTreeRoot->leftNode;
				free(subTreeRoot);
				root = temp;
			}
			else {
				root = NULL; // Tree now empty
			}
		}
	}
	else { // Tree now empty;
		root = NULL;
	}
}
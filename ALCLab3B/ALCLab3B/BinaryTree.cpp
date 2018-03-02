#include "BinaryTree.h"
#include <iostream>


BinaryTree::BinaryTree(){
	root = NULL;
}

BinaryTree::~BinaryTree(){
	Clear();
}

void BinaryTree::Clear() {
	clear(root);
}

void BinaryTree::clear(TreeNode* &p) {
	if (p != 0) {
		clear(p->leftPtr);
		clear(p->rightPtr);
		delete p;
	}
}

int BinaryTree::height() {
	return height(root);
}

int BinaryTree::height(TreeNode *subtreeRoot) {
	if (subtreeRoot == NULL) {
		std::cout << "-" << std::endl;
		return 0;
	}
	else {
		// compute the height of the subtree
		int lDepth = height(subtreeRoot->leftPtr);
		int rDepth = height(subtreeRoot->rightPtr);

		// use the larger one
		if (lDepth > rDepth) {
			return(lDepth + 1);
		}
		else {
			return (rDepth + 1);
		}
	}
}

void BinaryTree::add(int dataIn) {
	//TreeNode *node = new TreeNode(data);
	add(root, dataIn);
}

void BinaryTree::add(TreeNode *subtreeRoot, int dataIn) {
	if (subtreeRoot == NULL) {
		root = new TreeNode(dataIn);
	}
	else {
		if (subtreeRoot->isLeaf()) {
			if (dataIn < subtreeRoot->data) {
				subtreeRoot->leftPtr = new TreeNode(dataIn);
			}
			else {
				subtreeRoot->rightPtr = new TreeNode(dataIn);
			}
		}
		else {
			if (dataIn < subtreeRoot->data) {
				if (subtreeRoot->leftPtr != NULL) {
					add(subtreeRoot->leftPtr, dataIn);
				}
				else {
					subtreeRoot->leftPtr = new TreeNode(dataIn);
				}
			}
			else {
				if (subtreeRoot->rightPtr != NULL) {
					add(subtreeRoot->rightPtr, dataIn);
				}
				else {
					subtreeRoot->rightPtr = new TreeNode(dataIn);
				}
			}
		}
		
	}
}




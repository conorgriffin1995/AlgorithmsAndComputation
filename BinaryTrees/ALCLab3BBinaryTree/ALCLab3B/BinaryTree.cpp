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
	TreeNode* n = p;
	if (n->leftPtr != NULL)
		clear(n->leftPtr);
	if (n->rightPtr != NULL)
		clear(n->rightPtr);
	delete n;
	p = NULL;
}

int BinaryTree::height() {
	return height(root);
}

int BinaryTree::height(TreeNode *subtreeRoot) {
	if (subtreeRoot == NULL) {
		return -1;
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




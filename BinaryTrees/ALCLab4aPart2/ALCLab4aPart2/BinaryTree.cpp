#include "BinaryTree.h"
#include <iostream>


BinaryTree::BinaryTree() {
	root = NULL;
}

void BinaryTree::add(int dataIn) {
	add(root, dataIn);
}

void BinaryTree::add(Node *subtreeRoot, int dataIn) {
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

bool BinaryTree::hasPathSum(int sum) {
	return hasPathSum(root, sum);
}

bool BinaryTree::hasPathSum(Node *subtreeRoot, int sum) {
	if (subtreeRoot == NULL) {
		return false;

	}
	if ((subtreeRoot->left == NULL) && (subtreeRoot->right == NULL)) {
		// if it is a leaf node, we compare the remaining sum with the value
		return sum == subtreeRoot->data;
	}
	// subtract the node value and continue visit two sub trees.  
	return hasPathSum(subtreeRoot->left, sum - subtreeRoot->data) || 
			hasPathSum(subtreeRoot->right, sum - subtreeRoot->data);
	
}

void BinaryTree::printPaths() {
	printPaths(root);
}

void BinaryTree::printPaths(Node *node) {
	int path[500];
	printPathsRecur(root, path, 0);
}

void BinaryTree::printPathsRecur(Node *node, int path[], int pathLen) {
	if (node == NULL) {
		return;
	}
	else {
		/* append this node to the path array */
		path[pathLen] = node->data;
		pathLen++;
		/* it's a leaf, so print the path that led to here */
		if (node->left == NULL && node->right == NULL)
		{
			for (int i = 0; i < pathLen; i++) {
				std::cout << path[i] << " ";
			}
			std::cout << std::endl;
		}
		else
		{
			/* otherwise try both subtrees */
			printPathsRecur(node->left, path, pathLen);
			printPathsRecur(node->right, path, pathLen);
		}
	}
}

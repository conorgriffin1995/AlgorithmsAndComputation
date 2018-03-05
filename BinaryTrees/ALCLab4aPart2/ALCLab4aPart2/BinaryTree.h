#pragma once
#include "Node.h"
class BinaryTree {
public:
	BinaryTree();
	void add(int);
	int height();
	bool hasPathSum(int);
	void printPaths();
private:
	void add(Node *subtreeRoot, int dataIn);
	int height(Node *subtreeRoot);
	bool hasPathSum(Node *subtreeRoot, int sum);
	void printPaths(Node *node);
	void printPathsRecur(Node *node, int path[], int pathLen);
	Node *root;
};


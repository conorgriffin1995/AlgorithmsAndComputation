#pragma once
#include "Node.h"
class BinaryTree
{
public:
	BinaryTree();
	void add(int dataIn);
	int height();
	bool search(int dataIn);
	void inOrder();

	int minValue();			// Lab 4B
	int maxValue();			// Lab 4B
	int isBST();			// Lab 4B
private:
	Node *root;
	void add(Node *subtreeRoot, int dataIn);
	int height(Node *subtreeRoot);
	bool search(Node *subtreeRoot, int dataIn);
	void inOrder(Node *subtreeRoot);

	int minValue(Node *node);	// Lab 4B
	int maxValue(Node *node);	// Lab 4B
	int isBSTRecur(Node *node, int min, int max);		// Lab 4B
};	


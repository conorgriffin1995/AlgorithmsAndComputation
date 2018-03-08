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

	char minValue();			// Lab 4B
private:
	Node *root;
	void add(Node *subtreeRoot, int dataIn);
	int height(Node *subtreeRoot);
	bool search(Node *subtreeRoot, int dataIn);
	void inOrder(Node *subtreeRoot);

	char minValue(Node *node);
};


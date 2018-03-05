#pragma once
#include "Node.h"
class BinaryTree
{
public:
	BinaryTree();
	void add(char dataIn);
	int height();
	bool search(char dataIn);
	void inOrder();
	void preOrder();
	void postOrder();

private:
	Node *root;
	void add(Node *subtreeRoot, char dataIn);
	int height(Node *subtreeRoot);
	bool search(Node *subtreeRoot, char dataIn);
	void inOrder(Node *subtreeRoot);
	void preOrder(Node *subtreeRoot);
	void postOrder(Node *subtreeRoot);
};


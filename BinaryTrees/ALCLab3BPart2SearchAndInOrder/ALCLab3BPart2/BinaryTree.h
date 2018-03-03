#pragma once
#include "Node.h"
class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	void clear();
	void add(char dataIn);
	int height();
	bool search(char dataIn);
	void inOrder();				// to print in ascending order we use inOrder traversal
private:
	Node *root;
	void add(Node *subtreeRoot, char dataIn);
	int height(Node *subtreeRoot);
	bool search(Node *subtreeRoot, char dataIn);
	void inOrder(Node *subtreeRoot);
	void clear(Node *p);
};


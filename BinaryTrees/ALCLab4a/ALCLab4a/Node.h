#pragma once
class Node
{
	friend class BinaryTree;
public:
	Node(char dataIn);
	int isLeaf();
private:
	char data;
	Node *left;
	Node *right;
};


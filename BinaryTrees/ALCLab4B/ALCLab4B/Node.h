#pragma once
class Node
{
	friend class BinaryTree;
public:
	Node(int dataIn);
	int isLeaf();
private:
	int data;
	Node *left;
	Node *right;
};


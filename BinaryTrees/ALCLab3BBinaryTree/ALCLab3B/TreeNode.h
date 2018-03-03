#pragma once
class TreeNode
{
	friend class BinaryTree;
public:
	TreeNode(int dataIn);
	int isLeaf();
private:
	int data;
	TreeNode *leftPtr;
	TreeNode *rightPtr;
};


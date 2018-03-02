#pragma once
#include "TreeNode.h"
class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	void Clear();
	// both the add and height methods are implemented through private recursive methods
	void add(int);
	int height();

private:
	void add(TreeNode *toAdd, int dataIn);
	int height(TreeNode *subtreeRoot);
	TreeNode *root;

protected:
	void clear(TreeNode* &p);
};


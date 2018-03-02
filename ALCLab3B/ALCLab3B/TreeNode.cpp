#include "TreeNode.h"
#include <iostream>
TreeNode::TreeNode(int dataIn)
{
	data = dataIn;
	leftPtr = NULL;
	rightPtr = NULL;
}

int TreeNode::isLeaf() {
	if (this->leftPtr == NULL && this->rightPtr == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}


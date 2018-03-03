#include "Node.h"
#include <iostream>


Node::Node(char dataIn)
{
	data = dataIn;
	left = right = NULL;
}


int Node::isLeaf() {
	if (this->left == NULL && this->right == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}
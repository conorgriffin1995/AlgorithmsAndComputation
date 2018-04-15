Context, for this CA we had a class 'City' and the delete had to be by name

//DELETE BY NAME
void Tree::r_removeNode(string cIn, TreeNode *parent)
{
	if (root != NULL)//checks for root
	{
		if (root->c_value.getName() == cIn)//checks if name matches the name taken in at the root
		{
			r_removeRoot();//calls removeRoot recursive function
		}
		else
		{
			if (cIn < parent->c_value.getName() && parent->lPtr != NULL) //checks for name going left
			{
				if (parent->lPtr->c_value.getName() == cIn)//if name matches it calls the removeMatch function
				{
					r_removeMatch(parent, parent->lPtr, true);
				}
				else //otherwise calls the removeNode function to continue down the tree
				{
					r_removeNode(cIn, parent->lPtr);
				}
			}
			else if (cIn >= parent->c_value.getName() && parent->rPtr != NULL) //checks for name going left
			{
				if (parent->rPtr->c_value.getName() == cIn)//if name matches it calls the removeMatch function
				{
					r_removeMatch(parent, parent->rPtr, false);
				}
				else//otherwise calls the removeNode function to continue down the tree
				{
					r_removeNode(cIn, parent->rPtr);
				}
			}
			else
			{
				cout << "The city " << cIn << " was not found!" << endl;//prints out error message if city isn't found
			}
		}
	}
	else
	{
		cout << "Tree is empty!" << endl; //prints out error message if tree is empty
	}
}
void Tree::removeNode(string cIn)
{
	r_removeNode(cIn, root);
}

//REMOVE ROOT
void Tree::r_removeRoot() //used as a way of removing a root, seperate to removing a matching node, thus the need for 2 seperate functions
{
	if (root != NULL) //checks for root
	{
		TreeNode *tempPtr = root;//creates a temporary pointer and sets its value to root
		City rootCity = root->c_value; //creates 2 local variables of type city, one to hold the city root and the other to indicate the smallest city
		City smallestRightSubTree;
		//Case 1 (Root node has no children)
		if (root->isLeaf(root)) 
		{
			root = NULL;
			delete tempPtr;//can delete temp pointer as it is already set to root
		}
		//Case 2 (Root node has 1 child)
		else if (root->lPtr == NULL && root->rPtr != NULL)//deals with child on the right side
		{
			root = root->rPtr;
			tempPtr->rPtr = NULL;
			delete tempPtr;
			cout << "Root node of " << rootCity.getName() << " has been deleted!" << "\nThe new root node is " << root->c_value.getName() << endl;
		}
		else if (root->lPtr != NULL && root->rPtr == NULL)//deals with child on left side
		{
			root = root->lPtr;
			tempPtr->lPtr = NULL;
			delete tempPtr;
			cout << "Root node of " << rootCity.getName() << " has been deleted!" << "\nThe new root node is " << root->c_value.getName() << endl;
		}
		//Case 3 (Root node has 2 children)
		else 
		{
			//seeing how all values to the left are already smaller than the root we find the smallest value on the right side of the tree 
			//and use that as our replacement for the deleted node
			smallestRightSubTree = r_findSmallest(root->rPtr);
			r_removeNode(smallestRightSubTree.getName(), root);
			root->c_value = smallestRightSubTree;
			cout << "Root node of " << rootCity.getName() << " has been overwritten by " << root->c_value.getName() << endl;
		}
	}
	else 
	{
		cout << "Can't remove root!" << endl;
	}
}
//REMOVE MATCH
//works in a very similar way to removeRoot only that it takes in an extra match pointer which is used to determin is the value is equal to that of the value taken in
void Tree::r_removeMatch(TreeNode *parent, TreeNode *match, bool left) 
{
	if (root != NULL)
	{
		TreeNode *tempPtr;
		City cityMatch = match->c_value;
		City smallestRightSubTree;
		//Case 1 (Node has no children)
		if (match->isLeaf(match))
		{
			tempPtr = match;
			if (left == true) 
			{
				parent->lPtr = NULL;
			}
			else 
			{
				parent->rPtr = NULL;
			}
			delete tempPtr;
			cout << "Node of " << cityMatch.getName() << " has been deleted!" << endl;
		}
		//Case 2 (Node has 1 child)
		else if (match->lPtr == NULL && match->rPtr != NULL) //deals with right child
		{
			if (left == true)
			{
				parent->lPtr = match->rPtr;
			}
			else
			{
				parent->rPtr = match->rPtr;
			}
			match->rPtr = NULL;
			tempPtr = match;
			delete tempPtr;
			cout << "Node of " << cityMatch.getName() << " has been deleted!" << endl;
		}
		else if (match->lPtr != NULL && match->rPtr == NULL)//deals with left child
		{
			if (left == true)
			{
				parent->lPtr = match->lPtr;
			}
			else
			{
				parent->rPtr = match->lPtr;
			}
			match->lPtr = NULL;
			tempPtr = match;
			delete tempPtr;
			cout << "Node of " << cityMatch.getName() << " has been deleted!" << endl;
		}
		//Case 3 (Node has 2 children)
		else 
		{
			smallestRightSubTree = r_findSmallest(match->rPtr);
			r_removeNode(smallestRightSubTree.getName(), match);
			match->c_value = smallestRightSubTree;
		}
	}
	else 
	{
		cout << "ERROR! You should not see this message :'(" << endl;
	}
}
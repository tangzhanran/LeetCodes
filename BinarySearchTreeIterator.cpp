//	173. Binary Search Tree Iterator
//
//	Implement an iterator over a binary search tree(BST).Your iterator will be initialized with the root node of a BST.
//
//	Calling next() will return the next smallest number in the BST.
//
//	Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
//
//	Written by Zhanran Tang @ 7/14/2017
//
//	Ideas: Using stack to store all nodes in order.
//	Complexity: Time & space: O(n) in constructor, O(1) in next and hasnext

#include "Header.h"

using namespace std;

class BSTIterator
{
private:
	stack<TreeNode*> nodestk;
public:
	BSTIterator(TreeNode *root)
	{
		buildStk(root);
	}

	void buildStk(TreeNode *root)
	{
		if (root != nullptr)
		{
			buildStk(root->right);
			nodestk.push(root);
			buildStk(root->left);
		}
	}
	/** @return whether we have a next smallest number */
	bool hasNext()
	{
		if (!nodestk.empty())
			return true;
		return false;
	}

	/** @return the next smallest number */
	int next()
	{
		int nextsmallest = 0;
		if (hasNext())
		{
			nextsmallest = nodestk.top()->val;
			nodestk.pop();
		}
		return nextsmallest;
	}
};

int main()
{
	TreeNode *root = nullptr;
	BSTIterator itr = BSTIterator(root);
	system("pause");
	return 0;
}
//	100. Same Tree
//
//	Given two binary trees, write a function to check if they are equal or not.
//
//	Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
//
//	Written by Zhanran Tang @ 11/1/2017
//
//	Ideas: Simple straight forward
//	Complexity: O(n) in time, O(1) in space.

#include "Header.h"

using namespace std;

bool isSameTree(TreeNode* p, TreeNode* q)
{
	if ((p == nullptr&&q != nullptr) || (p != nullptr&&q == nullptr))
		return false;
	else
	{
		if (p != nullptr && q != nullptr)
		{
			if (p->val != q->val)
				return false;
			else
				return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
		}
		else
			return true;
	}
	return false;
}
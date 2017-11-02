//	99. Recover Binary Search Tree
//
//	Two elements of a binary search tree(BST) are swapped by mistake.
//
//	Recover the tree without changing its structure.
//	
//	Note:
//	A solution using O(n) space is pretty straight forward.Could you devise a constant space solution ?
//
//	Written by Zhanran Tang @ 11/1/2017
//
//	Ideas:
//		1. Get the inorder seqeuence and find the wrong nodes.
//		2. Use 2 nodes to store the wrong nodes. Inorder traverse.
//	Complexity:
//		1. O(n) in time and space.
//		2. O(n) in time, O(1) in space.

#include "Header.h"

using namespace std;

#define METHOD 2

#if METHOD == 1	
void helper(TreeNode* root, vector<TreeNode*> &inorder)
{
	if (root != nullptr)
	{
		helper(root->left, inorder);
		inorder.push_back(root);
		helper(root->right, inorder);
	}
}
void recoverTree(TreeNode* root)
{
	vector<TreeNode*> inorder;
	helper(root, inorder);
	int w1 = -1, w2 = -1;
	for (int i = 0; i<inorder.size() - 1; i++)
	{
		if (inorder[i]->val > inorder[i + 1]->val)
		{
			if (w1 == -1)
				w1 = i;
			else
				w2 = i + 1;
		}
	}
	if (w2 != -1)
		swap(inorder[w1]->val, inorder[w2]->val);
	else
		swap(inorder[w1]->val, inorder[w1 + 1]->val);
}
#else
TreeNode *w1, *w2, *pre;
void helper(TreeNode* root)
{
	if (root != nullptr)
	{
		helper(root->left);
		if (pre != nullptr && pre->val>root->val)
		{
			if (w1 == nullptr)
				w1 = pre;
			w2 = root;
		}
		pre = root;
		helper(root->right);
	}
}
void recoverTree(TreeNode* root)
{
	w1 = w2 = pre = nullptr;
	helper(root);
	swap(w1->val, w2->val);
}
#endif
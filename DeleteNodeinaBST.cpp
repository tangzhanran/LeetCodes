//	450. Delete Node in a BST
//
//	Given a root node reference of a BST and a key, delete the node with the given key in the BST.Return the root node reference(possibly updated) of the BST.
//
//	Basically, the deletion can be divided into two stages :
//
//	1. Search for a node to remove.
//	2. If the node is found, delete the node.
//	Note : Time complexity should be O(height of tree).
//
//	Example :
//	root = [5, 3, 6, 2, 4, null, 7]
//	key = 3
//
//		5
//	   / \
//	  3   6
//	 / \   \
//	2   4   7
//
//	Given key to delete is 3. So we find the node with value 3 and delete it.
//
//	One valid answer is[5, 4, 6, 2, null, null, 7], shown in the following BST.
//
//		5
//	   / \
//	  4   6
//	 /     \
//	2       7
//
//	Another valid answer is[5, 2, 6, null, 4, null, 7].
//
//		5
//	   / \
//	  2   6
//	   \   \
//	    4   7
//
//	Written by Zhanran Tang @ 8/22/2017
//
//	Ideas: Find the target node recursively. 
//		If the target node has no right, then return left. else find the minimum in right, then delete right recursively.
//	Complexity: O(logn) in time. O(1) in space.

#include "Header.h"

using namespace std;

TreeNode* deleteNode(TreeNode* root, int key)
{
	if (root == nullptr)
		return root;
	if (root->val == key)
	{
		if (root->right == nullptr)
			return root->left;
		else
		{
			TreeNode* rightmin = root->right;
			while (rightmin->left != nullptr)
				rightmin = rightmin->left;
			swap(root->val, rightmin->val);
			root->right = deleteNode(root->right, key);
		}
	}
	else if (root->val > key)
		root->left = deleteNode(root->left, key);
	else
		root->right = deleteNode(root->right, key);
	return root;
}

int main()
{
	queue<TreeNode*> nodeq;
	vector<int> valvec = { 44,11,45,7,21,-1,49,6,8,13,24,47,-1,0,-1,-1,9,12,19,23,25,46,48,-1,2,-1,10,-1,-1,15,20,22,-1,-1,38,-1,-1,-1,-1,1,3,-1,-1,14,16,-1,-1,-1,-1,33,41,-1,-1,-1,5,-1,-1,-1,18,29,34,40,43,4,-1,17,-1,27,30,-1,36,39,-1,42,-1,-1,-1,-1,-1,26,28,-1,31,35,37,-1,-1,-1,-1,-1,-1,-1,-1,-1,32 };
	TreeNode* root = new TreeNode(41);
	nodeq.push(root);
	int i = 1;
	while (i < valvec.size())
	{
		TreeNode* head = nodeq.front();
		TreeNode* left = new TreeNode(valvec[i]);
		i++;
		TreeNode* right = nullptr;
		if (i < valvec.size())
		{
			right = new TreeNode(valvec[i]);
			i++;
		}
		if (left->val != -1)
		{
			head->left = left;
			nodeq.push(left);
		}
		if (right != nullptr && right->val != -1)
		{
			head->right = right;
			nodeq.push(right);
		}
		nodeq.pop();
	}
	TreeNode* resroot = deleteNode(root,49);
	system("pause");
	return 0;
}
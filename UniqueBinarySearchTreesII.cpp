//	95. Unique Binary Search Trees II
//
//	Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.
//
//	For example,
//	Given n = 3, your program should return all 5 unique BST
//	
//	Written by Zhanran Tang @ 6/3/2017
//
//	Ideas: Do recursively. Find all left and right subtrees and connect to current root.
//	Complexity: O(n^2)? in time

#include "Header.h"

using namespace std;

vector<TreeNode*> CreateTrees(int start, int end)
{
	vector<TreeNode*> res;
	if (start > end)
	{
		res.push_back(NULL);
		return res;
	}
	for (int i = start; i <= end; i++)
	{
		vector<TreeNode*> left = CreateTrees(start, i - 1);
		vector<TreeNode*> right = CreateTrees(i + 1, end);
		int lsz = left.size(), rsz = right.size();
		for (int x = 0; x<lsz; x++)
		{
			for (int y = 0; y<rsz; y++)
			{
				TreeNode* root = new TreeNode(i);
				root->left = left[x];
				root->right = right[y];
				res.push_back(root);
			}
		}
	}
	return res;
}

vector<TreeNode*> generateTrees(int n)
{
	vector<TreeNode*> res;
	if (n == 0)
		return res;
	return CreateTrees(1, n);
}

int main()
{
	vector<TreeNode*> res = generateTrees(6);
	system("pause");
	return 0;
}
//	113. Path Sum II
//
//	Given a binary tree and a sum, find all root - to - leaf paths where each path's sum equals the given sum.
//
//	For example :
//		Given the below binary tree and sum = 22,
//			5
//		   / \
//		  4   8
//       /   / \
//      11  13  4
//     / \     / \
//    7   2   5   1
//		return
//		[
//			[5, 4, 11, 2],
//			[5, 8, 4, 5]
//		]
//
//	Written by Zhanran Tang @ 7/11/2017
//
//	Ideas: Simple recursive
//	Complexity: O(m+n) in time, O(logn) in space.

#include "Header.h"

using namespace std;

void sumRecursion(vector<vector<int>> &res, vector<int> cur, TreeNode* root, int sum)
{
	if (root == nullptr)
		return;
	if (sum == root->val && root->left == nullptr && root->right == nullptr)
	{
		cur.push_back(root->val);
		res.push_back(cur);
	}
	else
	{
		cur.push_back(root->val);
		sumRecursion(res, cur, root->left, sum - root->val);
		sumRecursion(res, cur, root->right, sum - root->val);
	}
}

vector<vector<int>> pathSum(TreeNode* root, int sum)
{
	vector<vector<int>> res;
	sumRecursion(res, vector<int>(), root, sum);
	return res;
}

int main()
{
	TreeNode* root;
	TreeNode* cur = new TreeNode(3);
	root = cur;
	cur->left = new TreeNode(9);
	cur->right = new TreeNode(20);
	cur = cur->right;
	cur->left = new TreeNode(15);
	cur->right = new TreeNode(7);
	vector<vector<int>> res = pathSum(root, 30);
	for (int i = 0; i < res.size(); i++)
	{
		cout << "[ ";
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << "]" << endl;
	}
	system("pause");
	return 0;
}
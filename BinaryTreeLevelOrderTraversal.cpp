//	102. Binary Tree Level Order Traversal
//
//	Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
//
//	For example :
//		Given binary tree[3, 9, 20, null, null, 15, 7],
//		 3
//		/ \
//	   9  20
//        / \
//		15   7
//		return its level order traversal as :
//		[
//			[3],
//			[9, 20],
//			[15, 7]
//		]
//
//	Written by Zhanran Tang @ 7/10/2017
//
//	Ideas: Simple BFS, using 2 integer to record the number of nodes in current level and the next level.
//	Complexity: O(m+n) in time, O(n) in space.

#include "Header.h"

using namespace std;

vector<vector<int>> levelOrder(TreeNode* root)
{
	vector<vector<int>> res;
	if (root == nullptr)
		return res;
	queue<TreeNode*> nodeq;
	nodeq.push(root);
	int curlvl = 1, nextlvl = 0;
	while (!nodeq.empty())
	{
		vector<int> lvlvec;
		for (int i = 0; i<curlvl; i++)
		{
			TreeNode* cur = nodeq.front();
			lvlvec.push_back(cur->val);
			nodeq.pop();
			if (cur->left != nullptr)
			{
				nodeq.push(cur->left);
				nextlvl++;
			}
			if (cur->right != nullptr)
			{
				nodeq.push(cur->right);
				nextlvl++;
			}
		}
		curlvl = nextlvl;
		nextlvl = 0;
		res.push_back(lvlvec);
	}
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
	vector<vector<int>> res = levelOrder(root);
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
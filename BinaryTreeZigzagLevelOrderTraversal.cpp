//	103. Binary Tree Zigzag Level Order Traversal
//
//	Given a binary tree, return the zigzag level order traversal of its nodes' values. 
//	(ie, from left to right, then right to left for the next level and alternate between).
//
//	For example :
//		Given binary tree[3, 9, 20, null, null, 15, 7],
//		 3
//		/ \
//	   9  20
//        / \
//		15   7
//		return its zigzag level order traversal as:
//		[
//			[3],
//			[20, 9],
//			[15, 7]
//		]
//
//	Written by Zhanran Tang @ 7/10/2017
//
//	Ideas: 
//		1. Simple BFS using deque, using 2 integer to record the number of nodes in current level and the next level.
//			When odd level, pop front, push back from left to right.
//			When even level, pop back, push front front right to left. 
//		2. Use queue.
//	Complexity: O(m+n) in time, O(n) in space.

#include "Header.h"

using namespace std;

#define DEQUE 0

#if DEQUE == 1
vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
	vector<vector<int>> res;
	if (root == nullptr)
		return res;
	int odd = 0;
	deque<TreeNode*> nodedq;
	nodedq.push_front(root);
	int curlvl = 1, nextlvl = 0;
	while (!nodedq.empty())
	{
		vector<int> tmp;
		for (int i = 0; i<curlvl; i++)
		{
			TreeNode* cur;
			if (odd == 1)
			{
				cur = nodedq.back();
				nodedq.pop_back();
				if (cur->right != nullptr)
				{
					nodedq.push_front(cur->right);
					nextlvl++;
				}
				if (cur->left != nullptr)
				{
					nodedq.push_front(cur->left);
					nextlvl++;
				}
			}
			else
			{
				cur = nodedq.front();
				nodedq.pop_front();
				if (cur->left != nullptr)
				{
					nodedq.push_back(cur->left);
					nextlvl++;
				}
				if (cur->right != nullptr)
				{
					nodedq.push_back(cur->right);
					nextlvl++;
				}
			}
			tmp.push_back(cur->val);
		}
		odd = 1 - odd;
		curlvl = nextlvl;
		nextlvl = 0;
		res.push_back(tmp);
	}
	return res;
}
#else
vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
	vector<vector<int>> res;
	if (root == nullptr)
		return res;
	int odd = 1;
	queue<TreeNode*> nodeq;
	nodeq.push(root);
	int curlvl = 1, nextlvl = 0;
	while (!nodeq.empty())
	{
		vector<int> tmp(curlvl, 0);
		for (int i = 0; i<curlvl; i++)
		{
			TreeNode* cur = nodeq.front();
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
			if (odd == 1)
			{
				tmp[i] = cur->val;
			}
			else
			{
				tmp[curlvl - 1 - i] = cur->val;
			}
		}
		odd = 1 - odd;
		curlvl = nextlvl;
		nextlvl = 0;
		res.push_back(tmp);
	}
	return res;
}
#endif // DEQUE == 1

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
	vector<vector<int>> res = zigzagLevelOrder(root);
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
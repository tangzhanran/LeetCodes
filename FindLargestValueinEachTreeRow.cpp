//	515. Find Largest Value in Each Tree Row
//
//	You need to find the largest value in each row of a binary tree.
//
//	Example:
//	Input:
//		1
//	   / \
//	  3   2
//	 / \   \
//	5   3   9
//	Output: [1, 3, 9]
//
//	Written by Zhanran Tang @ 8/28/2017
//
//	Ideas: Simple DFS.
//	Complexity: O(n) in time, O(1) in space.

#include "Header.h"

using namespace std;

void dfs(TreeNode* root, vector<int> &res, int depth)
{
	if (root != nullptr)
	{
		if (depth<res.size() && res[depth] < root->val)
			res[depth] = root->val;
		if (depth >= res.size())
			res.push_back(root->val);
		dfs(root->left, res, depth + 1);
		dfs(root->right, res, depth + 1);
	}
}
vector<int> largestValues(TreeNode* root)
{
	vector<int> res;
	dfs(root, res, 0);
	return res;
}

int main()
{
	queue<TreeNode*> nodeq;
	vector<int> valvec = { 1,3,2,5,3,-1,9 };
	TreeNode* root = new TreeNode(1);
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
	vector<int> res = largestValues(root);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}
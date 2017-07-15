//	199. Binary Tree Right Side View
//
//	Given a binary tree, imagine yourself standing on the right side of it, 
//	return the values of the nodes you can see ordered from top to bottom.
//
//	For example :
//	Given the following binary tree,
//		1           <-- -
//	   / \
//	  2   3         <-- -
//	   \   \
//		5   4       <-- -
//	You should return[1, 3, 4].
//
//	Written by Zhanran Tang @ 7/14/2017
//
//	Ideas:
//		1. Do in BFS iteraively
//		2. Do recursively
//	Complexity:
//		1. O(n) in time and space.
//		2.

#include "Header.h"

using namespace std;

#define METHOD 1

#if METHOD == 1
vector<int> rightSideView(TreeNode* root)
{
	vector<int> res;
	if (root == nullptr)
		return res;
	queue<TreeNode*> nodeq;
	int curlvl = 1, nextlvl = 0;
	nodeq.push(root);
	while (!nodeq.empty())
	{
		for (int i = 0; i<curlvl; i++)
		{
			TreeNode* cur = nodeq.front();
			nodeq.pop();
			if (i == curlvl - 1)
				res.push_back(cur->val);
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
	}
	return res;
}
#elif METHOD == 2
void sideviewRecursion(TreeNode* root, int level, vector<int>&res)
{
	if (res.size() < level)
		res.push_back(root->val);
	if (root->right != nullptr)
		sideviewRecursion(root->right, level + 1, res);
	if (root->left != nullptr)
		sideviewRecursion(root->left, level + 1, res);


}
vector<int> rightSideView(TreeNode* root)
{
	vector<int> res;
	if (root != nullptr)
		sideviewRecursion(root, 1, res);
	return res;
}
#endif // METHOD == 1

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
	vector<int> res = rightSideView(root);
	cout << "[ ";
	for (int i = 0; i < res.size(); i++)
	{		
		cout << res[i] << " ";		
	}
	cout << "]" << endl;
	system("pause");
	return 0;
}
//	337. House Robber III
//
//	The thief has found himself a new place for his thievery again.
//	There is only one entrance to this area, called the "root." 
//	Besides the root, each house has one and only one parent house.
//	After a tour, the smart thief realized that "all houses in this place forms a binary tree".
//	It will automatically contact the police if two directly - linked houses were broken into on the same night.
//
//	Determine the maximum amount of money the thief can rob tonight without alerting the police.
//
//	Example 1:
//		3
//	   / \
//	  2   3
//	   \   \
//	   3    1
//	Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
//
//	Example 2:
//		3
//	   / \
//	  4   5
//	 / \   \
//	1   3   1
//	Maximum amount of money the thief can rob = 4 + 5 = 9.
//
//	Written by Zhanran Tang @ 7/22/2017
//
//	Ideas: Rob *this node or *this node's children.
//	Complexity: O(m+n) in time, O(1) in space.

#include "Header.h"

using namespace std;

pair<int, int> robRecursion(TreeNode* root)
{
	if (root == nullptr)
		return pair<int, int>(0, 0);
	pair<int, int> left = robRecursion(root->left);
	pair<int, int> right = robRecursion(root->right);
	int robthis = root->val + left.second + right.second;
	int l1 = left.first, r1 = right.first, l2 = left.second, r2 = right.second;
	int nrobthis = max(max(max(l1 + r1, l1 + r2), l2 + r1), l2 + r2);
	return pair<int, int>(robthis, nrobthis);
}

int rob(TreeNode* root)
{
	pair<int, int> val = robRecursion(root);
	return max(val.first, val.second);
}

int main()
{
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(3);
	root->right->right = new TreeNode(1);
	cout << rob(root) << endl;
	system("pause");
	return 0;
}
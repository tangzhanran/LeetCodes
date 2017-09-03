//	513. Find Bottom Left Tree Value
//
//	Given a binary tree, find the leftmost value in the last row of the tree.
//
//	Example 1:
//	Input:
//		2
//	   / \
//    1   3
//	Output:
//	1
//
//	Example 2 :
//	Input :
//			1
//		   / \
//		  2   3
//		 /   / \
//		4   5   6
//		   /
//		  7
//	Output:
//	7
//	Note : You may assume the tree(i.e., the given root node) is not NULL.
//
//	Written by Zhanran Tang @ 8/28/2017
//
//	Ideas: Simple DFS.
//	Complexity: O(n) in time. O(1) in space.

#include "Header.h"

using namespace std;

void findValueRecursion(TreeNode* root, int &maxDepth, int depth, int &mostLeft)
{
	if (root != nullptr)
	{
		findValueRecursion(root->left, maxDepth, depth + 1, mostLeft);
		findValueRecursion(root->right, maxDepth, depth + 1, mostLeft);
		if (depth > maxDepth)
		{
			maxDepth = depth;
			mostLeft = root->val;
		}
	}
}
int findBottomLeftValue(TreeNode* root)
{
	int maxDepth = 0;
	int mostLeft = root->val;
	findValueRecursion(root, maxDepth, 0, mostLeft);
	return mostLeft;
}

int main()
{
	queue<TreeNode*> nodeq;
	vector<int> valvec = { 1, 2, 3, 4, -1, 5, 6, -1, -1, 7 };
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
	cout << findBottomLeftValue(root) << endl;
	system("pause");
	return 0;
}
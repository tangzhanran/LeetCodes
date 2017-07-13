//	129. Sum Root to Leaf Numbers
//
//	Given a binary tree containing digits from 0 - 9 only, each root - to - leaf path could represent a number.
//
//	An example is the root - to - leaf path 1->2->3 which represents the number 123.
//
//	Find the total sum of all root - to - leaf numbers.
//
//	For example,
//		1
//	   / \
//	  2   3
//	The root - to - leaf path 1->2 represents the number 12.
//	The root - to - leaf path 1->3 represents the number 13.
//
//	Return the sum = 12 + 13 = 25.
//
//	Written by Zhanran Tang @ 7/12/2017
//
//	Ideas: Record the current node number and pass to next node recusively
//	Complexity: O(n) in time and O(1) in space. n-number of nodes

#include "Header.h"

using namespace std;

int sumRecursion(TreeNode* root, int parent)
{
	if (root == nullptr)
		return 0;
	parent = 10 * parent + root->val;
	if (root->left == nullptr && root->right == nullptr)
		return parent;
	return sumRecursion(root->left, parent) + sumRecursion(root->right, parent);
}
int sumNumbers(TreeNode* root)
{
	return sumRecursion(root, 0);
}

int main()
{
	TreeNode *root;
	TreeNode *cur = new TreeNode(1);
	cur->left = new TreeNode(2);
	cur->right = new TreeNode(3);
	root = cur;
	cout << sumNumbers(root) << endl;
	system("pause");
	return 0;
}
//	222. Count Complete Tree Nodes
//
//	Given a complete binary tree, count the number of nodes.
//
//	Definition of a complete binary tree from Wikipedia :
//	In a complete binary tree every level, except possibly the last, is completely filled, 
//	and all nodes in the last level are as far left as possible.
//	It can have between 1 and 2h nodes inclusive at the last level h.
//
//	Written by Zhanran Tang @ 5/21/2017
//
//	Ideas: If the very left and right nodes in the subtree has the same depth, 
//			the subtree is full and nodes could be calculate without counting.
//	Complexity: O(log(n)^2) in time

#include <cstdlib>
#include <iostream>

using namespace std;

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int countNodes(TreeNode* root)
{
	if (root == NULL)
		return 0;
	TreeNode* left = root->left;
	TreeNode* right = root->right;
	int ldepth = 0, rdepth = 0;
	while (left != NULL)
	{
		ldepth++;
		left = left->left;
	}
	while (right != NULL)
	{
		rdepth++;
		right = right->right;
	}
	if (ldepth == rdepth)
		return pow(2, ldepth + 1) - 1;
	return countNodes(root->left) + countNodes(root->right) + 1;
}

int main()
{
	TreeNode* root = NULL;
	cout << countNodes(root) << endl;
	system("pause");
	return 0;
}
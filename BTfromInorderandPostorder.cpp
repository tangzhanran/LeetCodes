//	106. Construct Binary Tree from Inorder and Postorder Traversal
//
//	Given inorder and postorder traversal of a tree, construct the binary tree.
//
//	Note:
//		You may assume that duplicates do not exist in the tree.
//
//	Written by Zhanran Tang @ 6/5/2017
//
//	Ideas: Doing recursively with stack and hashmap
//	Complexity: O(n) in time and space.

#include "Header.h"

using namespace std;

unordered_map<int, int> nodepos_map;
stack<int> post_stk;

TreeNode* buildRecursion(int start, int end)
{
	if (start > end)
		return NULL;
	int curnode = post_stk.top();
	post_stk.pop();
	if (start == end)
		return new TreeNode(curnode);
	int nodepos = nodepos_map[curnode];
	TreeNode *root = new TreeNode(curnode);
	root->right = buildRecursion(nodepos + 1, end);
	root->left = buildRecursion(start, nodepos - 1);
	return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
	int sz = inorder.size();
	if (inorder.empty() || postorder.empty() || inorder.size() != postorder.size())
		return NULL;
	for (int i = 0; i<sz; i++)
	{
		nodepos_map.insert(pair<int, int>(inorder[i], i));
		post_stk.push(postorder[i]);
	}
	return buildRecursion(0, sz - 1);
}

int main()
{
	vector<int> inorder = { 4,2,7,5,8,1,6,9,3 };
	vector<int> postorder = { 4,7,8,5,2,9,6,3,1 };
	TreeNode *root = buildTree(inorder, postorder);
	system("pause");
	return 0;
}
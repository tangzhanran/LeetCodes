//	105. Construct Binary Tree from Preorder and Inorder Traversal
//
//	Given preorder and inorder traversal of a tree, construct the binary tree.
//
//	Note:
//		You may assume that duplicates do not exist in the tree.
//
//	Written by Zhanran Tang @ 6/4/2017
//
//	Ideas: Doing recursively with queue and hashmap
//	Complexity: O(n) in time and space.

#include "Header.h"

using namespace std;

unordered_map<int, int> node_pos;
queue<int> preorder_queue;

TreeNode* buildRecursion(int start, int end)
{
	if (start > end)
		return NULL;
	int front = preorder_queue.front();
	preorder_queue.pop();
	if (start == end)
		return new TreeNode(front);
	int rootpos = node_pos[front];
	TreeNode *root = new TreeNode(front);
	root->left = buildRecursion(start, rootpos - 1);
	root->right = buildRecursion(rootpos + 1, end);
	return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
	if (preorder.size() == 0 || inorder.size() == 0 || preorder.size() != inorder.size())
		return NULL;
	int sz = inorder.size();
	for (int i = 0; i<sz; i++)
	{
		preorder_queue.push(preorder[i]);
		node_pos.insert(pair<int, int>(inorder[i], i));
	}
	return buildRecursion(0, sz - 1);
}

int main()
{
	vector<int> preorder = { 1,2,4,5,7,8,3,6,9 };
	vector<int> inorder = { 4,2,7,5,8,1,6,9,3 };
	TreeNode *root = buildTree(preorder, inorder);
	system("pause");
	return 0;
}
//	116. Populating Next Right Pointers in Each Node
//
//	Given a binary tree
//
//	struct TreeLinkNode {
//		TreeLinkNode *left;
//		TreeLinkNode *right;
//		TreeLinkNode *next;
//	}
//	Populate each next pointer to point to its next right node.
//	If there is no next right node, the next pointer should be set to NULL.
//
//	Initially, all next pointers are set to NULL.
//
//	Note:
//		You may only use constant extra space.
//		You may assume that it is a perfect binary tree(ie, all leaves are at the same level, and every parent has two children).
//	For example,
//		Given the following perfect binary tree,
//			1
//		   / \
//		  2   3
//		 / \ / \
//		4  5 6  7
//		After calling your function, the tree should look like :
//			1->NULL
//		   / \
//		  2 ->3->NULL
//		 / \ / \
//		4->5->6->7->NULL
//
//	Written by Zhanran Tang @ 7/11/2017
//
//	Ideas:
//		1. Do iteratively. Similar to BFS.
//		2. Do recursively.
//	Complexity:
//		1. O(n) in time and space.
//		2. O(n) in time and O(1) in space.

#include "Header.h"

using namespace std;

#define METHOD 1

#if  METHOD == 1
void connect(TreeLinkNode *root)
{
	if (root != nullptr)
	{
		queue<TreeLinkNode*> nodeq;
		nodeq.push(root);
		int curlvl = 1, nextlvl = 0;
		while (!nodeq.empty())
		{
			for (int i = 0; i<curlvl; i++)
			{
				TreeLinkNode* pre = nodeq.front();
				nodeq.pop();
				if (curlvl>1 && i<curlvl - 1)
					pre->next = nodeq.front();
				if (pre->left != nullptr)
				{
					nodeq.push(pre->left);
					nextlvl++;
				}
				if (pre->right != nullptr)
				{
					nodeq.push(pre->right);
					nextlvl++;
				}
			}
			curlvl = nextlvl;
			nextlvl = 0;
		}
	}
}
#elif METHOD == 2
void connect(TreeLinkNode *root)
{
	if (root != nullptr)
	{
		if (root->left != nullptr)
		{
			root->left->next = root->right;
			if (root->next != nullptr)
				root->right->next = root->next->left;
		}
		connect(root->left);
		connect(root->right);
	}
}
#endif //  METHOD== 1

int main()
{
	TreeLinkNode *root = nullptr;
	connect(root);
	system("pause");
	return 0;
}
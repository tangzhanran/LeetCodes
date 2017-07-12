//	117. Populating Next Right Pointers in Each Node II
//
//	Follow up for problem "Populating Next Right Pointers in Each Node".
//
//	What if the given tree could be any binary tree ? Would your previous solution still work ?
//
//	Note :
//		You may only use constant extra space.
//	For example,
//		Given the following perfect binary tree,
//			1
//		   / \
//		  2   3
//		 / \   \
//		4  5    7
//		After calling your function, the tree should look like :
//			1->NULL
//		   / \
//		  2 ->3->NULL
//		 / \   \
//		4-> 5 ->7->NULL
//
//	Written by Zhanran Tang @ 7/11/2017
//
//	Ideas:
//		1. Do iteratively. EXactly same as Populating Next Right Pointers in Each Node.
//		2. Do recursively.
//	Complexity:
//		1. O(n) in time and space.
//		2. O(n) in time and O(1) in space.

#include "Header.h"

using namespace std;

#define METHOD 1

#if METHOD == 1
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
				TreeLinkNode *cur = nodeq.front();
				nodeq.pop();
				if (i < curlvl - 1)
					cur->next = nodeq.front();
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
	}
	}
#elif METHOD == 2
#endif // METHOD == 1

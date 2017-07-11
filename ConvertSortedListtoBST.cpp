//	109. Convert Sorted List to Binary Search Tree
//
//	Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
//
//	Written by Zhanran Tang @ 7/11/2017
//
//	Ideas: Break the link list from middle and do recursively.
//	Complexity: O(n) in time, O(1) in space.

#include "Header.h"

using namespace std;

int countList(ListNode* head)
{
	ListNode* tmp = head;
	int count = 0;
	while (tmp != nullptr)
	{
		count++;
		tmp = tmp->next;
	}
	return count;
}
TreeNode* sortedListToBST(ListNode* head)
{
	if (head == nullptr)
		return nullptr;
	int len = countList(head);
	if (len == 1)
		return new TreeNode(head->val);
	int mid = len / 2;
	ListNode* midnode = head;
	ListNode* premid = new ListNode(0);
	premid->next = head;
	for (int i = 0; i < mid; i++)
	{
		midnode = midnode->next;
		premid = premid->next;
	}
	premid->next = nullptr;
	TreeNode* root = new TreeNode(midnode->val);
	root->left = sortedListToBST(head);
	root->right = sortedListToBST(midnode->next);
	return root;
}

int main()
{
	ListNode* head = new ListNode(1);
	ListNode* cur = head;
	for (int i = 2; i <= 10; i++)
	{
		cur->next = new ListNode(i);
		cur = cur->next;
	}
	TreeNode* root = sortedListToBST(head);
	queue<TreeNode*> frontier;
	frontier.push(root);
	while (!frontier.empty())
	{
		TreeNode* cur = frontier.front();
		frontier.pop();
		if (cur == nullptr)
			cout << "null ";
		else
		{
			if (cur->left != nullptr || cur->right != nullptr)
			{
				frontier.push(cur->left);
				frontier.push(cur->right);
			}
			cout << cur->val << " ";
		}
	}
	cout << endl;
	system("pause");
	return 0;
}
//	82. Remove Duplicates from Sorted List II
//
//	Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
//
//	For example,
//	Given 1->2->3->3->4->4->5, return 1->2->5.
//	Given 1->1->1->2->3, return 2->3.
//
//	Written by Zhanran Tang @ 5/28/2017
//
//	Ideas: Straight forward idea.
//	Complexity: O(n) in time O(1) in space

#include <iostream>

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head)
{
	if (head == NULL)
		return head;
	ListNode* cur = head;
	ListNode* pre = head;
	int dupnum = head->val;
	bool dup = false;
	if (pre->next != NULL && pre->val == pre->next->val)
		dup = true;
	while (pre != NULL)
	{
		cur = pre->next;
		while (cur != NULL && ((cur->next != NULL && cur->val == cur->next->val) || cur->val == dupnum))
		{
			dupnum = cur->val;
			cur = cur->next;
		}
		pre->next = cur;
		pre = cur;
	}
	if (dup)
		return head->next;
	return head;
}

int main()
{
	ListNode* head = NULL;
	head = deleteDuplicates(head);
	system("pause");
	return 0;
}
//	21. Merge Two Sorted Lists
//
//	Merge two sorted linked lists and return it as a new list.
//	The new list should be made by splicing together the nodes of the first two lists.
//
//	Written by Zhanran Tang @ 9/27/2017
//
//	Ideas: Straight forward idea
//	Complexity: O(n) in time, O(1) in space.

#include "Header.h"

using namespace std;

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	ListNode *head = new ListNode(0), *cur = head;
	while (l1 != nullptr && l2 != nullptr)
	{
		if (l1->val > l2->val)
		{
			cur->next = l2;
			l2 = l2->next;
		}
		else
		{
			cur->next = l1;
			l1 = l1->next;
		}
		cur = cur->next;
	}
	if (l1 != nullptr)
		cur->next = l1;
	if (l2 != nullptr)
		cur->next = l2;
	return head->next;
}
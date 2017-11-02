//	83. Remove Duplicates from Sorted List
//
//	Given a sorted linked list, delete all duplicates such that each element appear only once.
//
//	For example,
//	Given 1->1->2, return 1->2.
//	Given 1->1->2->3->3, return 1->2->3.
//
//	Written by Zhanran Tang @ 11/1/2017
//
//	Ideas: Simple straight forward.
//	Complexity: O(n) in time, O(1) in space.

#include "Header.h"

using namespace std;

ListNode* deleteDuplicates(ListNode* head)
{
	ListNode* cur = head;
	while (cur != nullptr)
	{
		ListNode* next = cur->next;
		if (next != nullptr && cur->val == next->val)
			cur->next = next->next;
		else
			cur = cur->next;
	}
	return head;
}
//	25. Reverse Nodes in k - Group
//
//	Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
//	k is a positive integer and is less than or equal to the length of the linked list.If the number of nodes is not a multiple of k then left - out nodes in the end should remain as it is.
//
//	You may not alter the values in the nodes, only nodes itself may be changed.
//
//	Only constant memory is allowed.
//
//	For example,
//	Given this linked list : 1->2->3->4->5
//
//	For k = 2, you should return : 2->1->4->3->5
//
//	For k = 3, you should return : 3->2->1->4->5
//
//	Written by Zhanran Tang @ 9/28/2017
//
//	Ideas: Do recursively.
//	Complexity: O(n) in time, O(1) in space.

#include "Header.h"

using namespace std;

ListNode* reverseKGroup(ListNode* head, int k)
{
	if (k <= 1)
		return head;
	int n = k;
	ListNode *newhead = head;
	while (n>0 && newhead != nullptr)
	{
		newhead = newhead->next;
		n--;
	}
	if (n > 0)
		return head;
	newhead = reverseKGroup(newhead, k);
	while (k > 0)
	{
		ListNode* tmp = head->next;
		head->next = newhead;
		newhead = head;
		head = tmp;
		k--;
	}
	return newhead;
}
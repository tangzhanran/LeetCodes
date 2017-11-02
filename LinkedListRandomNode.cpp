//	382. Linked List Random Node
//
//	Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.
//
//	Follow up :
//	What if the linked list is extremely large and its length is unknown to you ? Could you solve this efficiently without using extra space ?
//
//	Example :
//		// Init a singly linked list [1,2,3].
//		ListNode head = new ListNode(1);
//		head.next = new ListNode(2);
//		head.next.next = new ListNode(3);
//		Solution solution = new Solution(head);
//
//		// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
//		solution.getRandom();
//
//	Written by Zhanran Tang @ 11/2/2017
//
//	Ideas: When traversing nodes, choose the new value for 1/i possibility. i is the cur index.
//	Complexity: Time: O(1) in construct, O(n) in getRandom. Space: O(1) in both.

#include "Header.h"

using namespace std;

class Solution {
public:
	/** @param head The linked list's head.
	Note that the head is guaranteed to be not null, so it contains at least one node. */
	ListNode *h;

	Solution(ListNode* head)
	{
		h = head;
	}

	/** Returns a random node's value. */
	int getRandom()
	{
		ListNode *cur = h;
		int res = cur->val;
		int count = 2;
		cur = cur->next;
		while (cur)
		{
			int i = rand() % count;
			if (i == 0)
				res = cur->val;
			count++;
			cur = cur->next;
		}
		return res;
	}
};
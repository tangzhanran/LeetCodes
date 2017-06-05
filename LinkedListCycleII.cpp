//	142. Linked List Cycle II
//
//	Given a linked list, return the node where the cycle begins.If there is no cycle, return null.
//
//	Note: Do not modify the linked list.
//
//	Follow up :
//		Can you solve it without using extra space?
//
//	Written by Zhanran Tang @ 6/2/2017
//
//	Ideas: Using slow and fast pointer to find cycle. 
//		If exists than we have the distance between head and cycle entry equals to the distance slow back to entry.
//	Complexity: O(n) in time. O(1) in space.

#include <cstdlib>

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head)
{
	if (head == NULL)
		return NULL;
	ListNode *slow = head;
	ListNode *fast = head;
	while (fast != NULL)
	{
		slow = slow->next;
		fast = fast->next;
		if (fast != NULL)
			fast = fast->next;
		if (fast != NULL && fast == slow)
		{
			fast = head;
			while (fast != slow)
			{
				fast = fast->next;
				slow = slow->next;
			}
			return slow;
		}
	}
	return NULL;
}

int main()
{
	ListNode *head = NULL;
	head = detectCycle(head);
	system("pause");
	return 0;
}
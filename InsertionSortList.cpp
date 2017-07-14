//	147. Insertion Sort List
//
//	Sort a linked list using insertion sort.
//
//	Written by Zhanran Tang @ 7/13/2017
//
//	Ideas: Simple insertion sort
//	Complexity: O(n^2) in time and O(1) in space.

#include "Header.h"

using namespace std;

ListNode* insertionSortList(ListNode* head)
{
	if (head == nullptr)
		return head;
	ListNode *newhead = new ListNode(0);
	newhead->next = head;
	ListNode *headnext = head->next;
	while (headnext != nullptr)
	{
		if (headnext->val < head->val)
		{
			ListNode *ptr = newhead;
			while (headnext->val > ptr->next->val)
				ptr = ptr->next;
			ListNode *ptrnext = ptr->next;
			ptr->next = headnext;
			head->next = headnext->next;
			headnext->next = ptrnext;
			headnext = head->next;
		}
		else
		{
			head = head->next;
			headnext = head->next;
		}
	}
	return newhead->next;
}

int main()
{
	ListNode* head;
	ListNode* node = new ListNode(2);
	head = node;
	node->next = new ListNode(1);
	node = node->next;
	node->next = new ListNode(3);
	head = insertionSortList(head);
	while (head != nullptr)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
	system("pause");
	return 0;
}
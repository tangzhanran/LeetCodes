//	24. Swap Nodes in Pairs
//
//	Given a linked list, swap every two adjacent nodes and return its head.
//
//	For example,
//	Given 1->2->3->4, you should return the list as 2->1->4->3.
//
//	Your algorithm should use only constant space.
//	You may not modify the values in the list, only nodes itself can be changed.
//	
//	Written by Zhanran Tang @ 9/28/2017
//
//	Ideas: Do recursively.
//	Complexity: O(n) in time, O(1) in space.

#include "Header.h"

using namespace std;

ListNode* swapPairs(ListNode* head)
{
	ListNode* newhead = head;
	if (head != nullptr && head->next != nullptr)
	{
		ListNode* nexthead = head->next->next;
		newhead = head->next;
		newhead->next = head;
		head->next = swapPairs(nexthead);
	}
	return newhead;
}

int main()
{
	vector<int> nums = { 1,2,3,4,5 };
	ListNode* head = buildList(nums);
	head = swapPairs(head);
	showList(head);
	system("pause");
	return 0;
}
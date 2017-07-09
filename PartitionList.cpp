//	86. Partition List
//
//	Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//
//	You should preserve the original relative order of the nodes in each of the two partitions.
//
//	For example,
//		Given 1->4->3->2->5->2 and x = 3,
//		return 1->2->2->4->3->5.
//
//	Written by Zhanran Tang @ 7/8/2017
//
//	Ideas:
//		1. Find the first node greater or equal to x then insert nodes less than x before it.
//		2. Separate the list into left and right lists, and then merge them.
//
//	Complexity: O(n) in time and O(1) in space.

#include "Header.h"

#define METHOD 2

using namespace std;

#if METHOD == 1
ListNode* partition(ListNode* head, int x)
{
	if (head != nullptr)
	{
		ListNode* pre = new ListNode(0);
		pre->next = head;
		ListNode* insertpos = head;
		head = pre;
		while (insertpos != nullptr)
		{
			if (insertpos->val >= x)
				break;
			insertpos = insertpos->next;
			pre = pre->next;
		}
		ListNode* curpre = pre, *cur = insertpos;
		while (cur != nullptr)
		{
			if (cur->val < x)
			{
				pre->next = cur;
				curpre->next = cur->next;
				cur->next = insertpos;
				pre = cur;
				cur = curpre->next;
			}
			else
			{
				curpre = curpre->next;
				cur = cur->next;
			}
		}
		return head->next;
	}
	return head;
}
#elif METHOD == 2
ListNode* partition(ListNode* head, int x)
{
	ListNode* left = new ListNode(0);
	ListNode* right = new ListNode(0);
	ListNode *lhead = left, *rhead = right;
	while (head != nullptr)
	{
		if (head->val < x)
		{
			lhead->next = head;
			lhead = lhead->next;
		}
		else
		{
			rhead->next = head;
			rhead = rhead->next;
		}
		head = head->next;
	}
	lhead->next = right->next;
	rhead->next = nullptr;
	return left->next;
}
#endif

int main()
{
	ListNode* pre = new ListNode(1);
	ListNode* head = pre;
	ListNode* cur = new ListNode(4);
	pre->next = cur;
	pre = cur;
	cur = new ListNode(3);
	pre->next = cur;
	pre = cur;
	cur = new ListNode(2);
	pre->next = cur;
	pre = cur;
	cur = new ListNode(5);
	pre->next = cur;
	pre = cur;
	cur = new ListNode(2);
	pre->next = cur;
	pre = cur;
	head = partition(head, 3);
	while (head != nullptr)
	{
		cout << head->val << "->";
		head = head->next;
	}
	cout << "NULL" << endl;
	system("pause");
	return 0;
}
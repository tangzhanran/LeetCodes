//	61. Rotate List
//
//	Given a list, rotate the list to the right by k places, where k is non - negative.
//
//	For example :
//	Given 1->2->3->4->5->NULL and k = 2,
//	return 4->5->1->2->3->NULL.
//
//	Written by Zhanran Tang @ 5/12/2017
//
//	Ideas:
//		1. Count the length of list to handle k>n
//		2. When k>n return to head
//	Note: 2. Exceed Time Limit with k = 2000000000
//	Complexity:
//		1. O(n)
//		2. O(k)

#include <cstdlib>
#include <iostream>

using namespace std;

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRightOn(ListNode* head, int k)
{
	if (head == NULL || k == 0)
		return head;
	ListNode *newhead = head;
	int count = 0;
	while (newhead != NULL)
	{
		count++;
		newhead = newhead->next;
	}
	k = k % count;
	if (k == 0)
		return head;
	newhead = head;
	ListNode *tail = head;
	while (k>0)
	{
		tail = tail->next;
		k--;
	}
	while (tail->next != NULL)
	{
		newhead = newhead->next;
		tail = tail->next;
	}
	tail->next = head;
	head = newhead->next;
	newhead->next = NULL;
	return head;
}

ListNode* rotateRightOk(ListNode* head, int k)
{
	if (head == NULL || k == 0)
		return head;
	int count = 0;
	ListNode *slow = head, *fast = head;
	while (count < k)
	{
		fast = fast->next;
		if (fast == NULL)
			fast = head;
		count++;
	}
	while (fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next;
	}
	fast->next = head;
	head = slow->next;
	slow->next = NULL;
	return head;
}

int main()
{
	ListNode* head = NULL;
	int k = 2;
	head = rotateRightOn(head, k);
	system("pause");
	return 0;
}
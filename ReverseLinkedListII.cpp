//	92. Reverse Linked List II
//
//	Reverse a linked list from position m to n.Do it in - place and in one - pass.
//
//	For example :
//		Given 1->2->3->4->5->NULL, m = 2 and n = 4,
//		return 1->4->3->2->5->NULL.
//
//	Note :
//		Given m, n satisfy the following condition :
//		1 ¡Ü m ¡Ü n ¡Ü length of list.
//
//	Written by Zhanran Tang @ 5/31/2017
//
//	Ideas: Do it straight forward.
//	Complexity: O(n) in time, O(1) in space

#include <cstdlib>
#include <iostream>

using namespace std;

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode* reverseBetween(ListNode* head, int m, int n)
{
	int s = m;
	if (head == NULL || m == n)
		return head;
	ListNode* prestart = new ListNode(0);
	prestart->next = head;
	ListNode* start = NULL;
	ListNode* pre = prestart;
	ListNode* cur = head;
	ListNode* next = cur->next;
	while (n > 1)
	{
		if (m == 1)
		{
			start = cur;
			prestart = pre;
		}
		else if (m < 1)
			cur->next = pre;
		pre = cur;
		cur = next;
		next = cur->next;
		m--;
		n--;
	}
	cur->next = pre;
	prestart->next = cur;
	start->next = next;
	if (s == 1)
		return cur;
	return head;
}

int main()
{
	ListNode* node = new ListNode(1);
	ListNode* head = node;
	for (int i = 2; i < 6; i++)
	{
		node->next = new ListNode(i);
		node = node->next;
	}
	head = reverseBetween(head, 1, 4);
	while (head != NULL)
	{
		cout << head->val << " ";
		head = head->next;
	}
	system("pause");
	return 0;
}
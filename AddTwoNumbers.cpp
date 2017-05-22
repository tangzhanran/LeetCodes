//	2. Add Two Numbers
//
//	You are given two non - empty linked lists representing two non - negative integers.The digits are stored in reverse order and each of their nodes contain a single digit.Add the two numbers and return it as a linked list.
//
//	You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//	Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//	Output : 7 -> 0 -> 8
//
//	Written by Zhanran Tang @ 5/21/2017
//	
//	Ideas: Straight Forward
//	Complexity: O(max(m,n)) m,n the length of the two input list

#include <cstdlib>
#include <iostream>

using namespace std;

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	int carry = 0;
	ListNode* head1 = l1;
	ListNode* head2 = l2;
	ListNode* head = new ListNode(carry);
	ListNode* res = head;
	while (head1 != NULL || head2 != NULL || carry)
	{
		int sum = 0;
		if (head1 != NULL)
		{
			sum += head1->val;
			head1 = head1->next;
		}
		if (head2 != NULL)
		{
			sum += head2->val;
			head2 = head2->next;
		}
		sum += carry;
		carry = sum / 10;
		head->next = new ListNode(sum % 10);
		head = head->next;
	}
	return res->next;
}

int main()
{
	ListNode *l1 = new ListNode(3);
	ListNode *l2 = new ListNode(9);

	ListNode *h1 = l1;
	ListNode *h2 = l2;

	l1->next = new ListNode(7);
	l1 = l1->next;
	l1->next = NULL;

	l2->next = new ListNode(2);
	l2 = l2->next;
	l2->next = NULL;
	ListNode *res = addTwoNumbers(h1, h2);
	while (res != NULL)
	{
		cout << res->val;
		res = res->next;
	}
	cout << endl;
	system("pause");
	return 0;
}
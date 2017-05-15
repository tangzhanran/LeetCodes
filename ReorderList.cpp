//	143. Reorder List
//
//	Given a singly linked list L : L0¡úL1¡ú¡­¡úLn - 1¡úLn,
//	reorder it to : L0¡úLn¡úL1¡úLn - 1¡úL2¡úLn - 2¡ú¡­
//
//	You must do this in - place without altering the nodes' values.
//
//	For example,
//	Given{ 1,2,3,4 }, reorder it to{ 1,4,2,3 }.
//
//	Written by Zhanran Tang @ 5/14/2017
//
//	Ideas: Split the list from middle, reverse the back part and connect.
//	Complexity: O(n) n - length of the list

#include <cstdlib>
#include <iostream>

using namespace std;

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void reorderList(ListNode* head)
{
	if (head == NULL)
		return;
	int n = 0;
	ListNode* tail = head;
	while (tail->next != NULL)
	{
		tail = tail->next;
		n++;
	}
	tail = head;
	int mid = round(n / 2.0);
	ListNode* middle = head;
	int count = 0;
	while (count < mid)
	{
		middle = middle->next;
		count++;
	}
	ListNode *pre = middle, *cur = pre->next, *nxt;
	pre->next = NULL;
	while (cur != NULL)
	{
		nxt = cur->next;
		cur->next = pre;
		pre = cur;
		cur = nxt;
	}
	ListNode *firstnxt = tail->next, *secondnxt = pre->next;
	while (firstnxt != NULL && secondnxt != NULL)
	{
		tail->next = pre;
		pre->next = firstnxt;
		tail = firstnxt;
		pre = secondnxt;
		firstnxt = tail->next;
		secondnxt = pre->next;
	}
}

int main()
{
	ListNode* head = NULL;
	reorderList(head);
	system("pause");
	return 0;
}
//	148. Sort List
//
//	Sort a linked list in O(n log n) time using constant space complexity.
//
//	Written by Zhanran Tang @ 5/23/2017
//
//	Ideas: Merge Sort
//	Complexity: O(nlogn) in time. O(1) in space.

#include <cstdlib>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* sortList(ListNode* head)
{
	if (head == NULL)
		return NULL;
	int length = 0;
	ListNode *cur = head;
	while (cur != NULL)
	{
		cur = cur->next;
		length++;
	}
	if (length == 1)
		return head;
	if (length == 2)
	{
		ListNode *tmp = head->next;
		if (head->val > tmp->val)
		{
			tmp->next = head;
			head->next = NULL;
			return tmp;
		}
		else
			return head;
	}
	length = length / 2 - 1;
	cur = head;
	while (length > 0)
	{
		cur = cur->next;
		length--;
	}
	ListNode *back = cur->next;
	cur->next = NULL;
	head = sortList(head);
	back = sortList(back);
	ListNode *newhead = new ListNode(0);
	ListNode *newtail = newhead;
	while (head != NULL || back != NULL)
	{
		if (head == NULL || (back!=NULL && head->val >= back->val))
		{
			newtail->next = back;
			back = back->next;
		}
		else if (back == NULL || head->val < back->val)
		{
			newtail->next = head;
			head = head->next;
		}
		newtail = newtail->next;
	}
	newtail->next = NULL;
	return newhead->next;
}

int main()
{
	ListNode *head = new ListNode(4);
	ListNode *root = head;
	head->next = new ListNode(2);
	head = head->next;
	head->next = new ListNode(1);
	head = head->next;
	head->next = new ListNode(6);
	head = head->next;
	head->next = new ListNode(7);
	head = head->next;
	head->next = new ListNode(3);
	head = head->next;
	head->next = new ListNode(7);
	root = sortList(root);
	system("pause");
	return 0;
}
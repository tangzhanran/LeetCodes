//	23. Merge k Sorted Lists
//
//	Merge k sorted linked lists and return it as one sorted list.Analyze and describe its complexity.
//
//	Written by Zhanran Tang @ 9/28/2017
//
//	Ideas: Using priority queue.
//	Complexity: O(nlogk) in time, O(k) in space.

#include "Header.h"

using namespace std;

struct mycompare
{
	bool operator()(ListNode* a, ListNode *b)
	{
		return a->val > b->val;
	}
};
ListNode* mergeKLists(vector<ListNode*>& lists)
{
	priority_queue<ListNode*, vector<ListNode*>, mycompare> nodeq;
	ListNode* head = new ListNode(0);
	ListNode* cur = head;
	for (int i = 0; i<lists.size(); i++)
	{
		if (lists[i] != nullptr)
		{
			nodeq.push(lists[i]);
		}
	}
	while (!nodeq.empty())
	{
		ListNode* tmp = nodeq.top();
		cur->next = tmp;
		nodeq.pop();
		if (tmp->next != nullptr)
			nodeq.push(tmp->next);
		cur = cur->next;
	}
	return head->next;
}

int main()
{
	vector<ListNode*> lists;
	vector<vector<int>> nums = { { 2, 4, 5, 7, 8, 9 },{ 1, 4, 6, 7 },{ 1, 2, 3, 4, 8, 9, 10, 13, 15 } };
	for (int i = 0; i < nums.size(); i++)
	{
		ListNode* head = new ListNode(nums[i][0]);
		ListNode* cur = head;
		for (int j = 1; j < nums[i].size(); j++)
		{
			cur->next = new ListNode(nums[i][j]);
			cur = cur->next;
		}
		lists.push_back(head);
	}
	ListNode *res = mergeKLists(lists);
	while (res != nullptr)
	{
		cout << res->val << "->";
		res = res->next;
	}
	cout << "null" << endl;
	system("pause");
	return 0;
}
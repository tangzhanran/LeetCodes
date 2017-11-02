#include "Header.h"

using namespace std;

ListNode* buildList(vector<int> nums)
{
	if (nums.empty())
		return nullptr;
	ListNode* head = new ListNode(nums[0]);
	ListNode* cur = head;
	for (int i = 1; i < nums.size(); i++)
	{
		cur->next = new ListNode(nums[i]);
		cur = cur->next;
	}
	return head;
}

void showList(ListNode* head)
{
	ListNode* tmp = head;
	while (tmp != nullptr)
	{
		cout << tmp->val << "->";
		tmp = tmp->next;
	}
	cout << "null" << endl;
}
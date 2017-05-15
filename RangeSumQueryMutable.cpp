//	307. Range Sum Query - Mutable
//
//	Given an integer array nums, find the sum of the elements between indices i and j(i ¡Ü j), inclusive.
//
//	The update(i, val) function modifies nums by updating the element at index i to val.
//	Example:
//	Given nums = [1, 3, 5]
//
//	sumRange(0, 2) -> 9
//	update(1, 2)
//	sumRange(0, 2) -> 8
//	Note :
//		The array is only modifiable by the update function.
//		You may assume the number of calls to update and sumRange function is distributed evenly.
//
//	Written by Zhanran Tang @5/3/2017
//
//	Idea: Use Segment Tree
//	Complexity: O(n) in building tree, O(logn) in update & search

#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;

struct segmentTree
{
	int start;
	int end;
	int sum;
	segmentTree* left;
	segmentTree* right;
	segmentTree(int s, int e) : start(s), end(e), sum(0), left(NULL), right(NULL) {}
};

class NumArray {
public:
	NumArray(vector<int> nums)
	{
		root = buildTree(0, nums.size() - 1, nums);
	}

	void update(int i, int val)
	{
		updateTree(root, i, val);
	}

	int sumRange(int i, int j)
	{
		return getSum(root, i, j);
	}
private:
	segmentTree *root;
	segmentTree* buildTree(int s, int e, vector<int> &nums)
	{
		if (s > e)
			return NULL;
		segmentTree *head = new segmentTree(s, e);
		if (s == e)
		{
			head->sum = nums[s];
			return head;
		}
		int mid = (s + e) / 2;
		head->left = buildTree(s, mid, nums);
		head->right = buildTree(mid + 1, e, nums);
		head->sum = head->left->sum + head->right->sum;
		return head;
	}
	int updateTree(segmentTree* pointer, int i, int val)
	{
		if (pointer == NULL)
			return 0;
		int diff = 0;
		if (pointer->start == i && pointer->end == i)
		{
			diff = val - pointer->sum;
			pointer->sum = val;
			return diff;
		}
		int mid = (pointer->start + pointer->end) / 2;
		if (i <= mid)
			diff = updateTree(pointer->left, i, val);
		else
			diff = updateTree(pointer->right, i, val);
		pointer->sum += diff;
		return diff;
	}
	int getSum(segmentTree* pointer, int i, int j)
	{
		if (pointer == NULL || i>j)
			return 0;
		if (pointer->start == i && pointer->end == j)
			return pointer->sum;
		int mid = (pointer->start + pointer->end) / 2;
		if (i > mid)
			return getSum(pointer->right, i, j);
		if (j <= mid)
			return getSum(pointer->left, i, j);
		return getSum(pointer->left, i, mid) + getSum(pointer->right, mid + 1, j);;
	}
};

int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(5);
	NumArray obj = NumArray(nums);
	int param_2 = obj.sumRange(0, 2);
	cout << param_2 << endl;
	obj.update(1, 2);
	param_2 = obj.sumRange(0, 2);
	cout << param_2 << endl;
	system("pause");
	return 0;
}
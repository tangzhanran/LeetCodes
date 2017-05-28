//	456. 132 Pattern
//
//	Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence ai, aj, ak such that i < j < k and ai < ak < aj.
//	Design an algorithm that takes a list of n numbers as input and checks whether there is a 132 pattern in the list.
//
//	Note: n will be less than 15, 000.
//
//	Example 1 :
//	Input : [1, 2, 3, 4]
//	Output : False
//	Explanation : There is no 132 pattern in the sequence.
//
//	Example 2 :
//	Input : [3, 1, 4, 2]
//	Output : True
//	Explanation : There is a 132 pattern in the sequence : [1, 4, 2].
//
//	Example 3 :
//	Input : [-1, 3, 2, 0]
//	Output : True
//	Explanation : There are three 132 patterns in the sequence : [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
//
//	Written by Zhanran Tang @ 5/25/2017
//	
//	Ideas: 1. Record the smallest in the left part and largest&smallest in the right part.
//			2. Using stack to record the right decreasing numbers.
//	Complexity: 1. O(n^2) in time. O(1) in space. 2. O(n) in time, O(n) in space.

#include <vector>
#include <stack>
#include <iostream>

using namespace std;

#define SAVETIME 1

#if SAVETIME
bool find132pattern(vector<int>& nums)
{
	int sz = nums.size();
	if (sz < 3)
		return false;
	stack<int> stk;
	int rightlargest = INT_MIN;
	for (int i = sz - 1; i >= 0; i--)
	{
		if (nums[i] < rightlargest)
			return true;
		while (!stk.empty() && nums[i] > stk.top())
		{
			rightlargest = stk.top();
			stk.pop();
		}
		stk.push(nums[i]);
	}
	return false;
}
#else
bool findRightPart(vector<int>& nums, int lower, int upper, int start)
{
	for (int i = start; i<nums.size(); i++)
	{
		if (nums[i] > lower && nums[i] < upper)
			return true;
	}
	return false;
}
bool find132pattern(vector<int>& nums)
{
	int sz = nums.size();
	if (sz < 3)
		return false;
	int lower = nums[0];
	for (int i = 1; i<sz - 1; i++)
	{
		int upper = nums[i];
		if (findRightPart(nums, lower, upper, i + 1))
			return true;
		if (nums[i] < lower)
			lower = nums[i];
	}
	return false;
}
#endif

int main()
{
	vector<int> nums = { 3,5,0,3,4 };
	cout << find132pattern(nums) << endl;
	system("pause");
	return 0;
}
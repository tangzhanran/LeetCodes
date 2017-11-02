//	41. First Missing Positive
//
//	Given an unsorted integer array, find the first missing positive integer.
//
//	For example,
//	Given[1, 2, 0] return 3,
//	and[3, 4, -1, 1] return 2.
//
//	Your algorithm should run in O(n) time and uses constant space.
//
//	Written by Zhanran Tang @ 10/9/2017
//
//	Ideas: Move the positive number into the right place. Then check which is missing.
//	Complexity: O(n) in time, O(1) in space.

#include "Header.h"

using namespace std;

int firstMissingPositive(vector<int>& nums)
{
	int i = 0;
	while (i < nums.size())
	{
		int cur = nums[i];
		if (cur>0 && cur <= nums.size() && (cur - 1) != i && nums[i] != nums[cur - 1])
			swap(nums[i], nums[cur - 1]);
		else
			i++;
	}
	for (int k = 0; k<nums.size(); k++)
	{
		if (nums[k] != k + 1)
			return k + 1;
	}
	return nums.size() + 1;
}
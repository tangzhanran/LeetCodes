//	268. Missing Number
//
//	Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
//
//	For example,
//	Given nums = [0, 1, 3] return 2.
//
//	Note:
//	Your algorithm should run in linear runtime complexity.
//	Could you implement it using only constant extra space complexity ?
//
//	Written by Zhanran Tang @ 9/29/2017
//
//	Ideas: Sum all the number, and subtract it with the real sum.
//	Complexity: O(n) in time, O(1) in space.

#include "Header.h"

using namespace std;

int missingNumber(vector<int>& nums)
{
	int sum = 0;
	for (int i = 0; i<nums.size(); i++)
	{
		sum += nums[i];
	}
	return nums.size()*(nums.size() + 1) / 2 - sum;
}
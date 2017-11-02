//	26. Remove Duplicates from Sorted Array
//
//	Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
//
//	Do not allocate extra space for another array, you must do this in place with constant memory.
//
//	For example,
//	Given input array nums = [1, 1, 2],
//
//	Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
//	It doesn't matter what you leave beyond the new length.
//
//	Written by Zhanran Tang @ 9/28/2017
//
//	Ideas: Move the non-duplicate number to the front.
//	Complexity: O(n) in time, O(1) in space.

#include "Header.h"

using namespace std;

int removeDuplicates(vector<int>& nums)
{
	int n = nums.size();
	int dup = 0;
	for (int i = 1; i<n; i++)
	{
		if (nums[i] == nums[i - 1])
			dup++;
		else
			nums[i - dup] = nums[i];
	}
	return n - dup;
}
//	27. Remove Element
//
//	Given an array and a value, remove all instances of that value in place and return the new length.
//
//	Do not allocate extra space for another array, you must do this in place with constant memory.
//
//	The order of elements can be changed.It doesn't matter what you leave beyond the new length.
//
//	Example:
//	Given input array nums = [3, 2, 2, 3], val = 3
//
//	Your function should return length = 2, with the first two elements of nums being 2.
//
//	Written by Zhanran Tang @ 9/29/2017
//
//	Ideas: The same as remove duplicate from sorted array.
//	Complexity: O(n) in time, O(1) in space.

#include "Header.h"

using namespace std;

int removeElement(vector<int>& nums, int val)
{
	int jump = 0;
	for (int i = 0; i<nums.size(); i++)
	{
		if (nums[i] == val)
			jump++;
		else
			nums[i - jump] = nums[i];
	}
	return nums.size() - jump;
}
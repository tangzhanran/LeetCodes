//	33. Search in Rotated Sorted Array
//
//	Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//	(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//	You are given a target value to search.If found in the array return its index, otherwise return -1.
//
//	You may assume no duplicate exists in the array.
//
//	Written by Zhanran Tang @ 6/28/2017
//
//	Ideas: Binary search find the rotate point, than do binary search
//	Complexity: O(logn) in time, O(1) in space.

#include "Header.h"

using namespace std;

int search(vector<int>& nums, int target)
{
	int start = 0, end = nums.size() - 1;
	if (end < 0)
		return -1;
	while (start<end)
	{
		int mid = (start + end) / 2;
		if (nums[mid]>nums[end])
			start = mid + 1;
		else
			end = mid;
	}
	int mini = start;
	start = 0;
	end = nums.size() - 1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		int realmid = (mid + mini) % nums.size();
		if (nums[realmid] == target)
			return realmid;
		if (nums[realmid] > target)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return -1;
}

int main()
{
	vector<int> nums = { 4, 5, 6, 7, 0, 1, 2 };
	cout << search(nums, 1) << endl;
	system("pause");
	return 0;
}
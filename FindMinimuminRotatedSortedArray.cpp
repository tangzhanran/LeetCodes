//	153. Find Minimum in Rotated Sorted Array
//
//	Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//	(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//	Find the minimum element.
//
//	You may assume no duplicate exists in the array.
//
//	Written by Zhanran Tang @ 7/14/2017
//
//	Ideas: Do binary search
//	Complexity: O(logn) in time. O(1) in space.

#include "Header.h"

using namespace std;

int findMin(vector<int>& nums)
{
	int start = 0, end = nums.size() - 1;
	while (start < end)
	{
		int mid = (start + end) / 2;
		if (nums[mid] > nums[end])
			start = mid + 1;
		else
			end = mid;
	}
	return nums[start];
}

int main()
{
	vector<int> nums = { 4, 5, 6, 7, 0, 1, 2 };
	cout << findMin(nums) << endl;
	system("pause");
	return 0;
}
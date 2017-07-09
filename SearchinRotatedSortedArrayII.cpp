//	81. Search in Rotated Sorted Array II
//
//	Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//	(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//	Write a function to determine if a given target is in the array.
//
//	The array may contain duplicates.
//
//	Written by Zhanran Tang @7/8/2017
//	
//	Ideas: The same as method 2 in Search in Rotated Sorted Array. 
//		The difference is when start==mid==end, start and end move inside together
//	Complexity: O(n) in worst and O(logn) in average time. O(1) in space.

#include "Header.h"

using namespace std;

bool search(vector<int>& nums, int target)
{
	int start = 0, end = nums.size() - 1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (nums[mid] == target || nums[start] == target || nums[end] == target)
			return true;
		if (nums[start] == nums[end] && nums[start] == nums[mid])
		{
			start++;
			end--;
		}
		else if (nums[start] <= nums[mid])
		{
			if (nums[start] <= target && nums[mid]>target)
				end = mid - 1;
			else
				start = mid + 1;
		}
		else
		{
			if (nums[mid]<target && nums[end] >= target)
				start = mid + 1;
			else
				end = mid - 1;
		}
	}
	return false;
}

int main()
{
	vector<int> nums = { 4, 5, 6, 7, 0, 1, 4 };
	cout << search(nums, 1) << endl;
	system("pause");
	return 0;
}
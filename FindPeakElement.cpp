//	162. Find Peak Element
//
//	A peak element is an element that is greater than its neighbors.
//
//	Given an input array where num[i] ¡Ù num[i + 1], find a peak element and return its index.
//
//	The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
//
//	You may imagine that num[-1] = num[n] = -¡Þ.
//
//	For example, in array[1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
//
//	Written by Zhanran Tang @ 7/14/2017
//
//	Ideas:
//		1. Linear scan.
//		2. Binary search
//	Complexity: O(1) in space.
//		1. O(n) in time.
//		2. O(logn) in time.

#include "Header.h"

using namespace std;

#define METHOD 2

#if METHOD == 1
int findPeakElement(vector<int>& nums)
{
	if (nums.size() <= 1)
		return 0;
	for (int i = 0; i<nums.size() - 1; i++)
	{
		if (nums[i] > nums[i + 1])
			return i;
	}
	return nums.size() - 1;
}
#elif METHOD == 2
int findPeakElement(vector<int>& nums)
{
	int start = 0, end = nums.size() - 1;
	while (start < end)
	{
		int mid = (start + end) / 2;
		if (nums[mid] < nums[mid + 1])
			start = mid + 1;
		else
			end = mid;
	}
	return start;
}
#endif // METHOD==1

int main()
{
	vector<int> nums = { 1, 2, 3, 1 };
	cout << findPeakElement(nums) << endl;
	system("pause");
	return 0;
}
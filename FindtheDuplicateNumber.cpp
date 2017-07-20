//	287. Find the Duplicate Number
//
//	Given an array nums containing n + 1 integers where each integer is between 1 and n(inclusive), 
//	prove that at least one duplicate number must exist.Assume that there is only one duplicate number, find the duplicate one.
//
//	Note:
//		You must not modify the array(assume the array is read only).
//		You must use only constant, O(1) extra space.
//		Your runtime complexity should be less than O(n2).
//		There is only one duplicate number in the array, but it could be repeated more than once.
//
//	Written by Zhanran Tang @ 7/19/2017
//
//	Ideas: Similar to Linked List Cycle II, use value as pointer to next index.
//	Complexity: O(n) in time, O(1) in space.

#include "Header.h"

using namespace std;

int findDuplicate(vector<int>& nums)
{
	int slow = nums[nums[0]];
	int fast = nums[slow];
	while (slow != fast)
	{
		slow = nums[slow];
		fast = nums[nums[fast]];
	}
	fast = nums[0];
	while (slow != fast)
	{
		slow = nums[slow];
		fast = nums[fast];
	}
	return slow;
}

int main()
{
	vector<int> nums = { 2,3,1,7,4,3,6,5 };
	cout << findDuplicate(nums) << endl;
	system("pause");
	return 0;
}
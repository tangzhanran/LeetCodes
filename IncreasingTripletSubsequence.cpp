//	334. Increasing Triplet Subsequence
//
//	Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
//
//	Formally the function should :
//		Return true if there exists i, j, k
//		such that arr[i] < arr[j] < arr[k] given 0 ¡Ü i < j < k ¡Ü n - 1 else return false.
//	Your algorithm should run in O(n) time complexity and O(1) space complexity.
//
//	Examples :
//	Given[1, 2, 3, 4, 5],
//	return true.
//
//	Given[5, 4, 3, 2, 1],
//	return false.
//	
//	Written by Zhanran Tang @ 7/22/2017
//
//	Ideas: Similar to 300. Longest Increasing Subsequence
//	Complexity: O(n) in time, O(1) in space.

#include "Header.h"

using namespace std;

bool increasingTriplet(vector<int>& nums)
{
	int minimum = INT_MAX;
	int maximum = INT_MAX;
	for (int i = 0; i<nums.size(); i++)
	{
		if (nums[i] <= minimum)
			minimum = nums[i];
		else if (nums[i] <= maximum)
			maximum = nums[i];
		else
			return true;
	}
	return false;
}

int main()
{
	vector<int> nums = { 0,4,2,1,0,-1,-3 };
	cout << increasingTriplet(nums) << endl;
	system("pause");
	return 0;
}
//	416. Partition Equal Subset Sum
//
//	Given a non - empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
//
//	Note:
//	Each of the array element will not exceed 100.
//	The array size will not exceed 200.
//
//	Example 1 :
//	Input : [1, 5, 11, 5]
//	Output : true
//	Explanation : The array can be partitioned as[1, 5, 5] and [11].
//
//	Example 2 :
//	Input : [1, 2, 3, 5]
//	Output : false
//	Explanation : The array cannot be partitioned into equal sum subsets.
//
//	Written by Zhanran Tang @ 7/31/2017
//
//	Ideas: 
//		1. Backtracking after sort the input.
//		2. 0/1 knapsack prob in DP
//	Complexity:
//		1. O(n^2) in time, O(1) in space.
//		2. O(cn) in time. O(n) in space.

#include "Header.h"

using namespace std;

#define METHOD 1

#if METHOD == 1
bool partitionRecursion(vector<int>& nums, int start, int remainder)
{
	if (remainder == 0)
		return true;
	for (int i = start; i<nums.size(); i++)
	{
		if (i>start && nums[i] == nums[i - 1])
			continue;
		if (nums[i] <= remainder)
		{
			if (partitionRecursion(nums, i + 1, remainder - nums[i]))
				return true;
		}
		else
			return false;
	}
	return false;
}
bool canPartition(vector<int>& nums)
{
	int sum = 0;
	for (int i = 0; i<nums.size(); i++)
		sum += nums[i];
	if (sum % 2 != 0)
		return false;
	sort(nums.begin(), nums.end());
	return partitionRecursion(nums, 0, sum / 2);
}
#elif METHOD == 2
#elif METHOD == 3
#endif // METHOD == 1

int main()
{
	vector<int> nums = { 1,5,11,5 };
	cout << canPartition(nums) << endl;
	system("pause");
	return 0;
}
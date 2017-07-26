//	377. Combination Sum IV
//
//	Given an integer array with all positive numbers and no duplicates, 
//	find the number of possible combinations that add up to a positive integer target.
//
//	Example:
//
//	nums = [1, 2, 3]
//	target = 4
//
//	The possible combination ways are :
//	(1, 1, 1, 1)
//	(1, 1, 2)
//	(1, 2, 1)
//	(1, 3)
//	(2, 1, 1)
//	(2, 2)
//	(3, 1)
//
//	Note that different sequences are counted as different combinations.
//
//	Therefore the output is 7.
//
//	Follow up :
//	What if negative numbers are allowed in the given array ?
//	How does it change the problem ?
//	What limitation we need to add to the question to allow negative numbers ?

#include "Header.h"

using namespace std;

#define NONEG 0

#if NONEG
int sumRecursion(vector<int>&dp, vector<int>& nums, int target)
{
	if (dp[target] != -1)
		return dp[target];
	int res = 0;
	for (int i = 0; i<nums.size(); i++)
	{
		if (nums[i] <= target)
			res += sumRecursion(dp, nums, target - nums[i]);
	}
	dp[target] = res;
	return res;
}

int combinationSum4(vector<int>& nums, int target)
{
	vector<int> dp(target + 1, -1);
	dp[0] = 1;
	return sumRecursion(dp, nums, target);
}
#else
//	0. If we have both negetive and positive nums, the result can be infinite.
//	1. do not use vector as dp vector, use map. 
//	2. change the limitation nums[i] <= max num in array
int sumRecursion(unordered_map<int,int> &dp, vector<int>& nums, int target)
{
	if (dp.find(target) != dp.end())
		return dp[target];
	int res = 0;
	for (int i = 0; i<nums.size(); i++)
	{
		if (target >= 0)
			res += sumRecursion(dp, nums, target - nums[i]);
	}
	dp[target] = res;
	return res;
}

int combinationSum4(vector<int>& nums, int target)
{
	unordered_map<int, int> dp;
	dp[0] = 1;
	return sumRecursion(dp, nums, target);
}
#endif

int main()
{
	vector<int> nums = { 1,2,3 };
	cout << combinationSum4(nums, 6) << endl;
	system("pause");
	return 0;
}
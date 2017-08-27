//	494. Target Sum
//
//	You are given a list of non - negative integers, a1, a2, ..., an, and a target, S.Now you have 2 symbols + and -.For each integer, you should choose one from + and -as its new symbol.
//
//	Find out how many ways to assign symbols to make sum of integers equal to target S.
//
//	Example 1:
//	Input: nums is[1, 1, 1, 1, 1], S is 3.
//	Output : 5
//	Explanation :
//	-1 + 1 + 1 + 1 + 1 = 3
//	+ 1 - 1 + 1 + 1 + 1 = 3
//	+ 1 + 1 - 1 + 1 + 1 = 3
//	+ 1 + 1 + 1 - 1 + 1 = 3
//	+ 1 + 1 + 1 + 1 - 1 = 3
//
//	There are 5 ways to assign symbols to make the sum of nums be target 3.
//	Note:
//	1. The length of the given array is positive and will not exceed 20.
//	2. The sum of elements in the given array will not exceed 1000.
//	3. Your output answer is guaranteed to be fitted in a 32 - bit integer.
//
//	Written by Zhanran Tang @ 8/26/2017
//
//	Ideas: The problem can be convert to subset sum problem.
//		The array can be split to positive part P and negtive part N. So sum(P)-sum(N) == target.
//		sum(P)+sum(N)+sum(P)-sum(N) == sum(nums)+target
//		2*sum(P) == sum(nums)+target
//		sum(P) == (sum(nums)+target)/2
//		For subset sum problem, using 0-1 knapsack DP.
//		opt(i,w) means for first i num, the number of subset sum equals to w.
//		opt(i,w) = opt(i-1,w)+opt(i-1,w-nums[i-1])
//		So it can be optimize to 1-D dp array, which is opt(i) = opt(i)+opt(w-nums[i]), every turn fill the opt from back.
//	Complexity: O(n) in space, O(sn) in time.

#include "Header.h"

using namespace std;

int findTargetSumWays(vector<int>& nums, int S)
{
	int sum = 0;
	for (int i = 0; i<nums.size(); i++)
		sum += nums[i];
	if (sum<S || (S + sum) % 2 != 0)
		return 0;
	S = (S + sum) / 2;
	vector<int> dp(S + 1, 0);
	dp[0] = 1;
	for (int i = 0; i<nums.size(); i++)
	{
		for (int j = S; j >= nums[i]; j--)
		{
			dp[j] += dp[j - nums[i]];
		}
	}
	return dp.back();
}

int main()
{
	vector<int> nums = { 1,1,1,1,1 };
	cout << findTargetSumWays(nums, 3) << endl;
	system("pause");
	return 0;
}
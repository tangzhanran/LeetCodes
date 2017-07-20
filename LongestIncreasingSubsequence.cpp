//	300. Longest Increasing Subsequence
//
//	Given an unsorted array of integers, find the length of longest increasing subsequence.
//
//	For example,
//		Given[10, 9, 2, 5, 3, 7, 101, 18],
//		The longest increasing subsequence is[2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.
//
//	Your algorithm should run in O(n2) complexity.
//
//	Follow up : Could you improve it to O(n log n) time complexity ?
//
//	Written by Zhanran Tang @ 7/19/2017
//
//	Ideas: DP solution. 
//		1. For each number i find backwards all the number less to i. Choose the largest length and add 1.
//		2. if number i is smaller than any number in dp, find the least one greater or eqaul to i and replace it with i. 
//			else add i into dp
//	Complexity: O(n) in space
//		1. O(n^2) in time.
//		2. O(nlogn) in time.

#include "Header.h"

using namespace std;

#define ONSQUARE 0

#if ONSQUARE == 1
int lengthOfLIS(vector<int>& nums)
{
	int n = nums.size();
	if (n == 0)
		return 0;
	vector<int> dp(n, 1);
	int maxlength = 1;
	for (int i = 1; i<n; i++)
	{
		int pastmax = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (nums[j] < nums[i])
			{
				pastmax = max(pastmax, dp[j]);
			}
		}
		dp[i] = pastmax + 1;
		if (dp[i] > maxlength)
			maxlength = dp[i];
	}
	return maxlength;
}
#else
int lengthOfLIS(vector<int>& nums)
{
	vector<int> dp;
	for (int i = 0; i<nums.size(); i++)
	{
		int start = 0, end = dp.size() - 1;
		while (start <= end)
		{
			int mid = (start + end) / 2;
			if (dp[mid] >= nums[i] && (mid == 0 || dp[mid - 1]<nums[i]))
			{
				dp[mid] = nums[i];
				break;
			}
			else if (dp[mid] <= nums[i])
				start = mid + 1;
			else
				end = mid - 1;
		}
		if (start > end)
			dp.push_back(nums[i]);
	}
	return dp.size();
}
#endif

int main()
{
	vector<int> nums = { 10,9,8,7,6,5 };
	cout << lengthOfLIS(nums) << endl;
	system("pause");
	return 0;
}
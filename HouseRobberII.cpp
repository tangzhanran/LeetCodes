//	213. House Robber II
//
//	Note : This is an extension of House Robber.
//
//	After robbing those houses on that street, 
//	the thief has found himself a new place for his thievery so that he will not get too much attention.
//	This time, all houses at this place are arranged in a circle.
//	That means the first house is the neighbor of the last one.
//	Meanwhile, the security system for these houses remain the same as for those in the previous street.
//
//	Given a list of non - negative integers representing the amount of money of each house, 
//	determine the maximum amount of money you can rob tonight without alerting the police.
//
//	Written by Zhanran Tang @ 7/15/2017
//
//	Ideas: Split the rob into 2 rounds. return the greater result.
//	Complexity: O(n) in time, O(1) in space.

#include "Header.h"

using namespace std;

int rob(vector<int>& nums)
{
	if (nums.empty())
		return 0;
	int n = nums.size();
	if (n <= 2)
		return max(nums[0], nums.back());
	int nonadj = nums[0], adj = max(nums[0], nums[1]);
	int round1 = adj, round2 = 0;
	for (int i = 2; i<n - 1; i++)
	{
		round1 = max(adj, nonadj + nums[i]);
		nonadj = adj;
		adj = round1;
	}
	nonadj = nums[1];
	adj = max(nums[1], nums[2]);
	round2 = adj;
	for (int i = 3; i<n; i++)
	{
		round2 = max(adj, nonadj + nums[i]);
		nonadj = adj;
		adj = round2;
	}
	return max(round1, round2);
}

int main()
{
	vector<int> nums = { 1,2,1,1,2 };
	cout << rob(nums) << endl;
	system("pause");
	return 0;
}
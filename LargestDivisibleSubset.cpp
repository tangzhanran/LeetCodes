//	368. Largest Divisible Subset
//
//	Given a set of distinct positive integers, 
//	find the largest subset such that every pair(Si, Sj) of elements in this subset satisfies : Si % Sj = 0 or Sj % Si = 0.
//
//	If there are multiple solutions, return any subset is fine.
//
//	Example 1 :
//	nums : [1, 2, 3]
//	Result : [1, 2](of course, [1, 3] will also be ok)
//
//	Example 2 :
//	nums : [1, 2, 4, 8]
//	Result : [1, 2, 4, 8]
//
//	Written by Zhanran Tang @ 7/22/2017
//
//	Ideas: Use pair to store the length of subset include number i and where it comes. Backtrack the result.
//	Complexity: O(n^2) in time, O(n) in space.

#include "Header.h"

using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums)
{
	if (nums.empty())
		return vector<int>();
	sort(nums.begin(), nums.end());
	vector<pair<int, int>> dp;
	dp.push_back(pair<int, int>(1, 0));
	int maxval = 1;
	int maxindex = 0;
	for (int i = 1; i<nums.size(); i++)
	{
		pair<int, int> cur(1, i);
		for (int j = i - 1; j >= 0; j--)
		{
			if (nums[i] % nums[j] == 0)
			{
				if (cur.first < (1 + dp[j].first))
				{
					cur.first = 1 + dp[j].first;
					cur.second = j;
				}
			}
		}
		if (maxval < cur.first)
		{
			maxval = cur.first;
			maxindex = i;
		}
		dp.push_back(cur);
	}
	vector<int> res;
	while (dp[maxindex].second != maxindex)
	{
		res.push_back(nums[maxindex]);
		maxindex = dp[maxindex].second;
	}
	res.push_back(nums[maxindex]);
	return res;
}

int main()
{
	vector<int> nums = { 4,8,10,240 };
	vector<int> res = largestDivisibleSubset(nums);
	for (int i = res.size() - 1; i >= 0; i--)
	{
		cout << res[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
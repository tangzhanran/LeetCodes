//	15. 3Sum
//
//	Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0 ? Find all unique triplets in the array which gives the sum of zero.
//
//	Note : The solution set must not contain duplicate triplets.
//
//	For example, given array S = [-1, 0, 1, 2, -1, -4],
//
//	A solution set is :
//	[
//		[-1, 0, 1],
//		[-1, -1, 2]
//	]
//
//	Written by Zhanran Tang @	5/4/2017

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums)
{
	vector<vector<int>> res;
	if (nums.size() < 3)
		return res;
	sort(nums.begin(), nums.end());
	int i = 0;
	for (int i = 0; i<nums.size() - 2; i++)
	{
		if (i>0 && nums[i] == nums[i - 1])
			continue;
		int max = nums.size() - 1, min = i + 1;
		while (min < max)
		{
			if (nums[i] + nums[min] + nums[max] > 0)
				max--;
			else if (nums[i] + nums[min] + nums[max] < 0)
				min++;
			else
			{
				vector<int> tmp;
				tmp.push_back(nums[i]);
				tmp.push_back(nums[min]);
				tmp.push_back(nums[max]);
				res.push_back(tmp);
				while (min<max && nums[min] == tmp[1])
					min++;
				while (min<max && nums[max] == tmp[2])
					max--;
			}
		}
	}
	return res;
}

int main()
{
	vector<int> nums;
	threeSum(nums);
	system("pause");
	return 0;
}
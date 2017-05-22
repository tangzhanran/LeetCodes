//	18. 4Sum
//
//	Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target ? Find all unique quadruplets in the array which gives the sum of target.
//
//	Note : The solution set must not contain duplicate quadruplets.
//
//	For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
//
//	A solution set is :
//	[
//		[-1, 0, 0, 1],
//		[-2, -1, 1, 2],
//		[-2, 0, 0, 2]
//	]
//
//	Written by Zhanran Tang @ 5/18/2017
//
//	Ideas: Based on 3Sum.
//	Complexity:	O(n^3) in time. n-the size of input array

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
	vector<vector<int>> res;
	if (nums.size() < 4)
		return res;
	sort(nums.begin(), nums.end());
	int end = nums.size() - 1;
	for (int i = 0; i<end - 2; i++)
	{
		if (i>0 && nums[i] == nums[i - 1])
			continue;
		int remainder = target - nums[i];
		for (int j = i + 1; j<end; j++)
		{
			if (j>i + 1 && nums[j] == nums[j - 1])
				continue;
			int next = j + 1, back = end;
			while (next < back)
			{
				if (nums[j] + nums[next] + nums[back] > remainder)
					back--;
				else if (nums[j] + nums[next] + nums[back] < remainder)
					next++;
				else
				{
					vector<int> tmp;
					tmp.push_back(nums[i]);
					tmp.push_back(nums[j]);
					tmp.push_back(nums[next]);
					tmp.push_back(nums[back]);
					res.push_back(tmp);
					while (next<back && nums[next] == tmp[2])
						next++;
					while (next<back && nums[back] == tmp[3])
						back--;
				}
			}
		}
	}
	return res;
}

int main()
{
	vector<int> nums = { 1,0,-1,0,-2,2 };
	int target = 0;
	vector<vector<int>> res;
	res = fourSum(nums, target);
	for (int i = 0; i < res.size(); i++)
	{
		cout << "[";
		for (int j = 0; j < 4; j++)
		{
			cout << res[i][j];
			if (j != 3)
				cout << ",";
		}
		cout << "]" << endl;
	}
	system("pause");
	return 0;
}
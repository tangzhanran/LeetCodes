//	47. Permutations II
//
//	Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
//	For example,
//	[1, 1, 2] have the following unique permutations :
//	[
//		[1, 1, 2],
//		[1, 2, 1],
//		[2, 1, 1]
//	]
//
//	Written by Zhanran Tang @ 6/29/2017
//
//	Ideas: Backtracking
//	Complexity: Polynomial in time

#include "Header.h"

using namespace std;

vector<vector<int>> res;

void permuteRecursion(vector<int> nums, int start)
{
	if (start >= nums.size() - 1)
		res.push_back(nums);
	else
	{
		for (int i = start; i<nums.size(); i++)
		{
			if (i>start && nums[i] == nums[start])
				continue;
			swap(nums[i], nums[start]);
			permuteRecursion(nums, start + 1);
		}
	}
}

vector<vector<int>> permuteUnique(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	permuteRecursion(nums, 0);
	return res;
}

int main()
{
	vector<int> nums = { 1,2,3,1 };
	permuteUnique(nums);
	for (int i = 0; i < res.size(); i++)
	{
		cout << "[ ";
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << "]" << endl;
	}
	system("pause");
	return 0;
}
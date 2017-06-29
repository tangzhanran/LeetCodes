//	46. Permutations
//
//	Given a collection of distinct numbers, return all possible permutations.
//
//	For example,
//	[1, 2, 3] have the following permutations :
//	[
//		[1, 2, 3],
//		[1, 3, 2],
//		[2, 1, 3],
//		[2, 3, 1],
//		[3, 1, 2],
//		[3, 2, 1]
//	]
//
//	Written by Zhanran Tang @ 6/28/2017
//
//	Ideas: Backtracking
//	Complexity: Polynomial in time

#include "Header.h"

using namespace std;

vector<vector<int>> res;

void permuteRecursion(vector<int>& nums, int start)
{
	if (start >= nums.size() - 1)
		res.push_back(nums);
	else
	{
		for (int i = start; i<nums.size(); i++)
		{
			swap(nums[i], nums[start]);
			permuteRecursion(nums, start + 1);
			swap(nums[i], nums[start]);
		}
	}
}

vector<vector<int>> permute(vector<int>& nums)
{
	permuteRecursion(nums, 0);
	return res;
}

int main()
{
	vector<int> nums = { 1,2,3 };
	permute(nums);
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
//	78. Subsets
//
//	Given a collection of integers that might contain duplicates, nums, return all possible subsets.
//
//	Note: The solution set must not contain duplicate subsets.
//
//		For example,
//		If nums = [1, 2, 2], a solution is :
//		[
//			[2],
//			[1],
//			[1, 2, 2],
//			[2, 2],
//			[1, 2],
//			[]
//		]
//
//	Written by Zhanran Tang @ 7/9/2017
//
//	Ideas:
//		1. Do backtracking recursively
//		2. Add number to each subset each turn
//
//	Complexity: Polynomial in time.

#include "Header.h"

using namespace std;

#define RECURSIVE 1

#if RECURSIVE
void subsetRecursion(vector<vector<int>> &res, vector<int> &nums, vector<int> cur, int start, int count)
{
	if (count <= 0)
		res.push_back(cur);
	else
	{
		for (int i = start; i<nums.size(); i++)
		{
			if (i>start && nums[i] == nums[i - 1])
				continue;
			cur.push_back(nums[i]);
			subsetRecursion(res, nums, cur, i + 1, count - 1);
			cur.pop_back();
		}
	}
}
vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	vector<vector<int>> res;
	for (int i = 0; i <= nums.size(); i++)
	{
		subsetRecursion(res, nums, vector<int>(), 0, i);
	}
	return res;
}
#else

#endif // RECURSIVE

int main()
{
	vector<int> nums = { 1,2,2 };
	vector<vector<int>> res = subsetsWithDup(nums);
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
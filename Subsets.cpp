//	78. Subsets
//
//	Given a set of distinct integers, nums, return all possible subsets.
//
//	Note: The solution set must not contain duplicate subsets.
//
//		For example,
//		If nums = [1, 2, 3], a solution is :
//		[
//			[3],
//			[1],
//			[2],
//			[1, 2, 3],
//			[1, 3],
//			[2, 3],
//			[1, 2],
//			[]
//		]
//
//	Written by Zhanran Tang @ 7/8/2017
//
//	Ideas:
//		1. Do backtracking recursively
//		2. Add number to each subset each turn
//
//	Complexity: Polynomial in time.

#include "Header.h"

#define RECURSIVE 1

using namespace std;

#if RECURSIVE
void subsetRecursion(vector<vector<int>> &res, vector<int>& nums, vector<int> cur, int start, int count)
{
	if (count == 0)
		res.push_back(cur);
	else
	{
		for (int i = start; i<nums.size(); i++)
		{
			cur.push_back(nums[i]);
			subsetRecursion(res, nums, cur, i + 1, count - 1);
			cur.pop_back();
		}
	}
}

vector<vector<int>> subsets(vector<int>& nums)
{
	vector<vector<int>> res;
	vector<int> cur;
	for (int i = 0; i <= nums.size(); i++)
	{
		subsetRecursion(res, nums, cur, 0, i);
	}
	return res;
}
#else
vector<vector<int>> subsets(vector<int>& nums)
{
	vector<vector<int>> res;
	res.push_back(vector<int>());
	for (int i = 0; i<nums.size(); i++)
	{
		int sz = res.size();
		for (int j = 0; j<sz; j++)
		{
			vector<int> tmp = res[j];
			tmp.push_back(nums[i]);
			res.push_back(tmp);
		}
	}
	return res;
}
#endif

int main()
{
	vector<int> nums = { 1,2,3 };
	vector<vector<int>> res = subsets(nums);
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
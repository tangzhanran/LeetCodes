//	491. Increasing Subsequences
//
//	Given an integer array, your task is to find all the different possible increasing subsequences of the given array, 
//	and the length of an increasing subsequence should be at least 2 .
//
//	Example:
//	Input: [4, 6, 7, 7]
//	Output : [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7, 7], [4, 7, 7]]
//	Note :
//	The length of the given array will not exceed 15.
//	The range of integer in the given array is[-100, 100].
//	The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.
//
//	Written by Zhanran Tang @ 8/25/2017
//
//	Ideas: DFS Backtracking using hashset.
//	Complexity: Polynomial in time O(n) in space.

#include "Header.h"

using namespace std;

void subseqRecursion(vector<int>& nums, int start, vector<int> curseq, vector<vector<int>> &res)
{
	if (curseq.size() > 1)
		res.push_back(curseq);
	unordered_set<int> explored;
	for (int i = start; i<nums.size(); i++)
	{
		if ((curseq.empty() || nums[i] >= curseq.back()) && explored.find(nums[i]) == explored.end())
		{
			explored.insert(nums[i]);
			curseq.push_back(nums[i]);
			subseqRecursion(nums, i + 1, curseq, res);
			curseq.pop_back();
		}
	}
}
vector<vector<int>> findSubsequences(vector<int>& nums)
{
	vector<vector<int>> res;
	subseqRecursion(nums, 0, vector<int>(), res);
	return res;
}

int main()
{
	vector<int> nums = { 4,5,7,7 };
	vector<vector<int>> res = findSubsequences(nums);
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
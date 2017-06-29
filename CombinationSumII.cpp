//	40. Combination Sum II
//
//	Given a collection of candidate numbers(C) and a target number(T), find all unique combinations in C where the candidate numbers sums to T.
//
//	Each number in C may only be used once in the combination.
//
//	Note:
//		All numbers(including target) will be positive integers.
//		The solution set must not contain duplicate combinations.
//	For example, given candidate set[10, 1, 2, 7, 6, 1, 5] and target 8,
//	A solution set is :
//	[
//		[1, 7],
//		[1, 2, 5],
//		[2, 6],
//		[1, 1, 6]
//	]
//
//	Written by Zhanran Tang @ 6/28/2017
//
//	Ideas: Simple backtracking
//	Complexity: Polynomial in time

#include "Header.h"

using namespace std;

vector<vector<int>> res;

void sumRecursion(vector<int>& candidates, int target, vector<int>currentvec, int start)
{
	if (target < 0)
		return;
	for (int i = start; i<candidates.size(); i++)
	{
		if (i>0 && candidates[i] == candidates[i - 1] && i>start)
			continue;
		if (candidates[i] < target)
		{
			currentvec.push_back(candidates[i]);
			sumRecursion(candidates, target - candidates[i], currentvec, i + 1);
			currentvec.pop_back();
		}
		else if (candidates[i] == target)
		{
			currentvec.push_back(candidates[i]);
			res.push_back(currentvec);
			return;
		}
		else
			return;
	}
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
	sort(candidates.begin(), candidates.end());
	vector<int> currentvec;
	sumRecursion(candidates, target, currentvec, 0);
	return res;
}

int main()
{
	vector<int> candidates = { 10, 1, 2, 7, 6, 1, 5 };
	combinationSum2(candidates, 8);
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
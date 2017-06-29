//	39. Combination Sum
//
//	Given a set of candidate numbers(C) (without duplicates) and a target number(T), find all unique combinations in C where the candidate numbers sums to T.
//
//	The same repeated number may be chosen from C unlimited number of times.
//
//	Note:
//		All numbers(including target) will be positive integers.
//		The solution set must not contain duplicate combinations.
//	For example, given candidate set[2, 3, 6, 7] and target 7,
//	A solution set is :
//	[
//		[7],
//		[2, 2, 3]
//	]
//
//	Written by Zhanran Tang @ 6/28/2017
//
//	Ideas: Simple backtracking
//	Complexity:	Polynomial in time

#include "Header.h"

using namespace std;

vector<vector<int>> res;

void sumRecursion(vector<int>& candidates, vector<int> currentvec, int remainder, int start)
{
	if (remainder < 0)
		return;
	for (int i = start; i<candidates.size(); i++)
	{
		if (candidates[i] < remainder)
		{
			currentvec.push_back(candidates[i]);
			sumRecursion(candidates, currentvec, remainder - candidates[i], i);
			currentvec.pop_back();
		}
		else if (candidates[i] == remainder)
		{
			currentvec.push_back(candidates[i]);
			res.push_back(currentvec);
			return;
		}
		else
			return;
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
	vector<int> currentvec;
	sort(candidates.begin(), candidates.end());
	sumRecursion(candidates, currentvec, target, 0);
	return res;
}

int main()
{
	vector<int> candidates = { 2,3,6,7 };
	vector<vector<int>> out = combinationSum(candidates, 7);
	system("pause");
	return 0;
}
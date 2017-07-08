//	77. Combinations
//
//	Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
//
//	For example,
//	If n = 4 and k = 2, a solution is :
//
//	[
//		[2, 4],
//		[3, 4],
//		[2, 3],
//		[1, 2],
//		[1, 3],
//		[1, 4],
//	]
//
//	Written by Zhanran Tang @ 7/6/2017
//
//	Ideas:
//		1. Backtracking recursively.
//		2. Backtracking iteratively.
//	Comlexity:
//		1&2. Polynomial in time and space

#include "Header.h"

using namespace std;

#define RECURSIVE false

#if RECURSIVE
void recursion(int start, int k, int n, vector<int>& tmp, vector<vector<int>> &res)
{
	if (tmp.size() == k)
		res.push_back(tmp);
	else
	{
		for (int i = start; i <= n; i++)
		{
			tmp.push_back(i);
			recursion(i + 1, k, n, tmp, res);
			tmp.pop_back();
		}
	}
}

vector<vector<int>> combine(int n, int k)
{
	vector<vector<int>> res;
	vector<int> tmp;
	if (k <= n)
		recursion(1, k, n, tmp, res);
	return res;
}
#else
vector<vector<int>> combine(int n, int k)
{
	vector<vector<int>> res;
	if (n >= k)
	{
		vector<int> tmp(k, 0);
		int i = 0;
		while (i >= 0 && tmp[0] <= n - k + 1)
		{
			tmp[i]++;
			if (tmp[i] > n)
				i--;
			else if (i == k - 1)
				res.push_back(tmp);
			else
			{
				i++;
				tmp[i] = tmp[i - 1];
			}
		}
	}
	return res;
}
#endif

int main()
{
	vector<vector<int>> res = combine(6, 3);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
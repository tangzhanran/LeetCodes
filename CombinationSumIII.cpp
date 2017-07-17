//	216. Combination Sum III
//
//	Find all possible combinations of k numbers that add up to a number n, 
//	given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
//
//	Example 1:
//	Input: k = 3, n = 7
//	Output : [[1, 2, 4]]
//
//	Example 2 :
//	Input : k = 3, n = 9
//	Output : [[1, 2, 6], [1, 3, 5], [2, 3, 4]]
//
//	Written by Zhanran Tang @ 7/16/2017
//
//	Ideas: Backtracking.
//	Complexity: Polynomial in time. O(k) in space.

#include "Header.h"

using namespace std;

void sumRecursion(vector<vector<int>> &res, vector<int> &cur, int n, int k, int start)
{
	if (cur.size() == k)
	{
		if (n == 0)
			res.push_back(cur);
	}
	else
	{
		for (int i = start; i <= 9; i++)
		{
			if (i <= n)
			{
				cur.push_back(i);
				sumRecursion(res, cur, n - i, k, i + 1);
				cur.pop_back();
			}
			else
				break;
		}
	}
}
vector<vector<int>> combinationSum3(int k, int n)
{
	vector<vector<int>> res;
	if (9 * k < n)
		return res;
	vector<int> cur;
	sumRecursion(res, cur, n, k, 1);
	return res;
}

int main()
{
	vector<vector<int>> res = combinationSum3(3, 9);
	for (int i = 0; i < res.size(); i++)
	{
		cout << "[ ";
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << "]" << endl;
	}
	system("pause");
	return 0;
}
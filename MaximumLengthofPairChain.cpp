//	646. Maximum Length of Pair Chain
//
//	You are given n pairs of numbers.In every pair, the first number is always smaller than the second number.
//
//	Now, we define a pair(c, d) can follow another pair(a, b) if and only if b < c.Chain of pairs can be formed in this fashion.
//
//	Given a set of pairs, find the length longest chain which can be formed.You needn't use up all the given pairs. You can select pairs in any order.
//
//	Example 1:
//	Input: [[1, 2], [2, 3], [3, 4]]
//	Output : 2
//	Explanation : The longest chain is[1, 2] ->[3, 4]
//
//	Note :
//	1. The number of given pairs will be in the range[1, 1000].

#include "Header.h"

using namespace std;

bool mycompare(const vector<int> &p1, const vector<int> &p2)
{
	if (p1[1] < p2[1])
		return true;
	return false;
}

int findLongestChain(vector<vector<int>>& pairs)
{
	sort(pairs.begin(), pairs.end(), mycompare);
	int end = pairs[0][1];
	int res = 1;
	for (int i = 1; i<pairs.size(); i++)
	{
		if (pairs[i][0] > end)
		{
			end = pairs[i][1];
			res++;
		}
	}
	return res;
}

int main()
{
	vector<vector<int>> pairs = { {-6, 9},{1, 6},{8, 10},{-1, 4},{-6, -2},{-9, 8},{-5, 3},{0, 3} };
	cout << findLongestChain(pairs) << endl;
	system("pause");
	return 0;
}
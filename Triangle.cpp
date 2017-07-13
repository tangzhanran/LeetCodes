//	120. Triangle
//
//	Given a triangle, find the minimum path sum from top to bottom.Each step you may move to adjacent numbers on the row below.
//
//	For example, given the following triangle
//	[
//		[2},
//		[3, 4},
//		[6, 5, 7},
//		[4, 1, 8, 3}
//	}
//	The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//
//	Note:
//		Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
//
//	Written by Zhanran Tang @ 7/12/2017
//
//	Ideas:
//		1. DFS recusively.
//		2. DP solution
//
//	Complexity:
//		1. O(2^n) in time, O(1) in space. n-the number of rows.
//		2. O(n^2) in time, O(n) in space. n-the number of rows.

#include "Header.h"

using namespace std;

#define METHOD 2

#if METHOD == 1
int minRecursion(vector<vector<int>>& triangle, int i, int j)
{
	if (i >= triangle.size())
		return 0;
	int leftmin = triangle[i][j] + minRecursion(triangle, i + 1, j);
	int rightmin = triangle[i][j] + minRecursion(triangle, i + 1, j + 1);
	return min(leftmin, rightmin);
}
int minimumTotal(vector<vector<int>>& triangle)
{
	return minRecursion(triangle, 0, 0);
}
#elif METHOD == 2
int minimumTotal(vector<vector<int>>& triangle)
{
	int n = triangle.size();
	vector<int> dp(n, 0);
	for (int i = 0; i<n; i++)
		dp[i] = triangle[n - 1][i];
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
		}
	}
	return dp[0];
}
#endif

int main()
{
	vector<vector<int>> triangle = { {2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3} };
	cout << minimumTotal(triangle) << endl;
	system("pause");
	return 0;
}
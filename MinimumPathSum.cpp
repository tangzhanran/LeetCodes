//	64. Minimum Path Sum
//
//	Given a m x n grid filled with non - negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//
//	Note: You can only move either down or right at any point in time.
//
//	Written by Zhanran Tang @ 6/30/2017
//
//	Ideas: DP
//	Complexity: O(m*n) in time and O(n) in space

#include "Header.h"

using namespace std;

int minPathSum(vector<vector<int>>& grid)
{
	int m = grid.size();
	int n = 0;
	if (m == 0)
		return 0;
	n = grid[0].size();
	vector<vector<int>> dp(2, vector<int>(n, grid[0][0]));
	for (int j = 1; j<n; j++)
	{
		dp[0][j] = grid[0][j] + dp[0][j - 1];
	}
	dp[1] = dp[0];
	for (int i = 1; i<m; i++)
	{
		for (int j = 0; j<n; j++)
		{
			if (j == 0)
				dp[1][j] = dp[0][j] + grid[i][j];
			else
				dp[1][j] = min(dp[1][j - 1], dp[0][j]) + grid[i][j];
			dp[0][j] = dp[1][j];
		}
	}
	return dp[1][n - 1];
}

int main()
{
	vector<vector<int>> grid = { {1,3,1},{1,5,1},{4,2,1} };
	cout << minPathSum(grid) << endl;
	system("pause");
	return 0;
}
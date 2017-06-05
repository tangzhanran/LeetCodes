//	63. Unique Paths II
//
//	Follow up for "Unique Paths":
//
//	Now consider if some obstacles are added to the grids.How many unique paths would there be ?
//	An obstacle and empty space is marked as 1 and 0 respectively in the grid.
//
//	For example,
//		There is one obstacle in the middle of a 3x3 grid as illustrated below.
//		[
//			[0, 0, 0],
//			[0, 1, 0],
//			[0, 0, 0]
//		]
//		The total number of unique paths is 2.
//
//	Note: m and n will be at most 100.
//
//	Written by Zhanran Tang @ 6/3/2017
//
//	Ideas: DP
//	Complexity: O(m*n) in time, O(m*n) in space.

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
	int n = obstacleGrid.size();
	if (n == 0)
		return 0;
	int m = obstacleGrid[0].size();
	if (m == 0 || obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1)
		return 0;
	vector<vector<int>> opt(n, vector<int>(m, 0));
	opt[0][0] = 1;
	for (int j = 1; j<m; j++)
		opt[0][j] = min(opt[0][j - 1], 1 - obstacleGrid[0][j]);
	for (int i = 1; i<n; i++)
		opt[i][0] = min(opt[i - 1][0], 1 - obstacleGrid[i][0]);
	for (int i = 1; i<n; i++)
	{
		for (int j = 1; j<m; j++)
		{
			if (obstacleGrid[i][j] == 1)
				continue;
			opt[i][j] = opt[i - 1][j] + opt[i][j - 1];
		}
	}
	return opt[n - 1][m - 1];
}

int main()
{
	vector<vector<int>> obstacleGrid = { {0, 0, 0},{0, 1, 0},{0, 0, 0} };
	cout << uniquePathsWithObstacles(obstacleGrid) << endl;
	system("pause");
	return 0;
}
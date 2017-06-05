//	62. Unique Paths
//
//	A robot is located at the top - left corner of a m x n grid(marked 'Start' in the diagram below).
//	The robot can only move either down or right at any point in time.The robot is trying to reach the bottom - right corner of the grid(marked 'Finish' in the diagram below).
//
//	How many possible unique paths are there ?
//
//	Note : m and n will be at most 100.
//
//	Written by Zhanran Tang @ 6/3/2017
//
//	Ideas: DP
//	Complexity: O(m*n) in time and space.

#include <vector>
#include <iostream>

using namespace std;

int uniquePaths(int m, int n)
{
	if (m == 0 || n == 0)
		return 0;
	vector<vector<int>> opt(m, vector<int>(n, 0));
	opt[0][0] = 1;
	for (int j = 1; j<n; j++)
		opt[0][j] = 1;
	for (int i = 1; i<m; i++)
		opt[i][0] = 1;
	for (int i = 1; i<m; i++)
	{
		for (int j = 1; j<n; j++)
			opt[i][j] = opt[i - 1][j] + opt[i][j - 1];
	}
	return opt[m - 1][n - 1];
}

int main()
{
	cout << uniquePaths(3, 7) << endl;
	system("pause");
	return 0;
}
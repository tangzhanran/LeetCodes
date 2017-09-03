//	576. Out of Boundary Paths
//
//	There is an m by n grid with a ball.Given the start coordinate(i, j) of the ball, 
//	you can move the ball to adjacent cell or cross the grid boundary in four directions(up, down, left, right).
//	However, you can at most move N times. Find out the number of paths to move the ball out of grid boundary.
//	The answer may be very large, return it after mod 109 + 7.
//
//	Example 1:
//	Input:m = 2, n = 2, N = 2, i = 0, j = 0
//	Output : 6
//
//	Example 2 :
//	Input : m = 1, n = 3, N = 3, i = 0, j = 1
//	Output : 12
//
//	Note :
//	1. Once you move the ball out of boundary, you cannot move it back.
//	2. The length and height of the grid is in range[1, 50].
//	3. N is in range[0, 50].
//
//	Written by Zhanran Tang @ 9/2/2017
//
//	Ideas: DP. OPT(i,j,n) = OPT(i-1,j,n-1)+OPT(i+1,j,n-1)+OPT(i,j-1,n-1)+OPT(i,j+1,n-1). 
//			If out of bound, OPT(i,j,n)=1. OPT(i,j,0)=0.
//	Complexity: O(mnN) in time and space.

#include "Header.h"

using namespace std;

vector<vector<vector<int>>> dp;

int modval(int val)
{
	return val % (int)(pow(10, 9) + 7);
}

int helper(int m, int n, int N, int i, int j)
{
	if (i >= m || i<0 || j >= n || j<0)
		return 1;
	if (N <= 0)
		return 0;
	if (dp[i][j][N] == -1)
		dp[i][j][N] = modval(helper(m, n, N - 1, i - 1, j) + helper(m, n, N - 1, i + 1, j)) + modval(helper(m, n, N - 1, i, j + 1) + helper(m, n, N - 1, i, j - 1));
	return modval(dp[i][j][N]);
}

int findPaths(int m, int n, int N, int i, int j)
{
	dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(N + 1, -1)));
	return helper(m, n, N, i, j);
}

int main()
{
	cout << findPaths(8, 50, 23, 5, 26) << endl;
	system("pause");
	return 0;
}
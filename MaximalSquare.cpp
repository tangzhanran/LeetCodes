//	221. Maximal Square
//
//	Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
//
//	For example, given the following matrix :
//	1 0 1 0 0
//	1 0 1 1 1
//	1 1 1 1 1
//	1 0 0 1 0
//	Return 4.
//
//	Written by Zhanran Tang @ 5/24/2017
//
//	Ideas: DP. OPT(i,j) is the max length of the square right bottom at (i,j).
//		if V(i,j) == 0, OPT(i,j) = 0. If V(i,j) == 1, OPT(i,j) = min(OPT(i-1,j),OPT(i,j-1),OPT(i-1,j-1))
//	Complexity: O(n*n) in time. O(n*n) in space. (Space can be optimize to O(n))

#include <vector>
#include <iostream>
#include <algorithm>

#define OPTSPACE 1

using namespace std;

int minimum(int a, int b, int c)
{
	int mini = a;
	if (mini > b)
		mini = b;
	if (mini > c)
		mini = c;
	return mini;
}

#if OPTSPACE
int maximalSquare(vector<vector<char>>& matrix)
{
	int row = matrix.size();
	if (row == 0)
		return 0;
	int col = matrix[0].size();
	if (col == 0)
		return 0;
	vector<vector<int>> opt(2, vector<int>(col, 0));
	int res = 0;
	for (int j = 0; j<col; j++)
	{
		opt[0][j] = matrix[0][j] - 48;
		res = max(res, opt[0][j]);
	}
	for (int i = 1; i<row; i++)
	{
		opt[1][0] = matrix[i][0] - 48;
		for (int j = 1; j<col; j++)
		{
			if (matrix[i][j] == '0')
				opt[1][j] = 0;
			else
			{
				opt[1][j] = minimum(opt[0][j], opt[1][j - 1], opt[0][j - 1]) + 1;
				if (opt[1][j] > res)
					res = opt[1][j];
			}
		}
		opt[0] = opt[1];
	}
	return res*res;
}
#else
int maximalSquare(vector<vector<char>>& matrix)
{
	int row = matrix.size();
	if (row == 0)
		return 0;
	int col = matrix[0].size();
	if (col == 0)
		return 0;
	vector<vector<int>> opt(row, vector<int>(col, 0));
	bool oneflag = false;
	for (int j = 0; j<col; j++)
	{
		opt[0][j] = matrix[0][j] - 48;
		if (!oneflag && opt[0][j] == 1)
			oneflag = true;
	}
	for (int i = 0; i<row; i++)
	{
		opt[i][0] = matrix[i][0] - 48;
		if (!oneflag && opt[i][0] == 1)
			oneflag = true;
	}
	int res = 0;
	if (oneflag)
		res = 1;
	for (int i = 1; i<row; i++)
	{
		for (int j = 1; j<col; j++)
		{
			if (matrix[i][j] == '0')
				opt[i][j] = 0;
			else
			{
				opt[i][j] = minimum(opt[i - 1][j], opt[i][j - 1], opt[i - 1][j - 1]) + 1;
				res = max(opt[i][j], res);
			}
		}
	}
	return res*res;
}
#endif

int main()
{
	vector<vector<char>> matrix = { {'0','0','0','0','0'}, {'1','0','0','0','0'}, {'0','0','0','0','0'}, { '0','0','0','0','0' } };
	cout << maximalSquare(matrix) << endl;
	system("pause");
	return 0;
}
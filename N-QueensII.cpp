//	52. N - Queens II
//
//	Follow up for N - Queens problem.
//
//	Now, instead outputting board configurations, return the total number of distinct solutions.
//
//	Written by Zhanran Tang @ 10/15/2017
//
//	Ideas: Exactly the same as N-Queens.
//	Complexity: O(n^2) in space, O(n^n) in time.

#include "Header.h"

using namespace std;

int res = 0;
bool isValid(vector<string> &board, int i, int j)
{
	if (board.empty())
		return true;
	for (int m = 0; m<i; m++)
	{
		if (board[m][j] == 'Q')
			return false;
	}
	int n = board[0].length(), k = 1;
	while ((j - k >= 0 || j + k<n) && i - k >= 0)
	{
		if (j - k >= 0 && board[i - k][j - k] == 'Q')
			return false;
		if (j + k<n && board[i - k][j + k] == 'Q')
			return false;
		k++;
	}
	return true;
}
void recusionHelper(vector<string> &board, int row, int n)
{
	if (row >= n)
		res++;
	else
	{
		string currow(n, '.');
		for (int i = 0; i<n; i++)
		{
			if (isValid(board, row, i))
			{
				currow[i] = 'Q';
				board.push_back(currow);
				recusionHelper(board, row + 1, n);
				currow[i] = '.';
				board.pop_back();
			}
		}
	}
}
int totalNQueens(int n)
{
	vector<string> board;
	recusionHelper(board, 0, n);
	return res;
}
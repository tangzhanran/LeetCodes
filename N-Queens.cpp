//	51. N - Queens
//
//	The n - queens puzzle is the problem of placing n queens on an n¡Án chessboard such that no two queens attack each other.
//
//	Given an integer n, return all distinct solutions to the n - queens puzzle.
//
//	Each solution contains a distinct board configuration of the n - queens' placement, 
//	where 'Q' and '.' both indicate a queen and an empty space respectively.
//
//	For example,
//	There exist two distinct solutions to the 4 - queens puzzle :
//
//	[
//		[".Q..",  // Solution 1
//		"...Q",
//		"Q...",
//		"..Q."],
//
//		["..Q.",  // Solution 2
//		"Q...",
//		"...Q",
//		".Q.."]
//	]
//
//	Written by Zhanran Tang @ 10/13/2017
//
//	Ideas: Simple backtracking.
//	Complexity: O(n^2) in space, O(n^n) in time.

#include "Header.h"

using namespace std;

vector<vector<string>> res;
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
		res.push_back(board);
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
vector<vector<string>> solveNQueens(int n)
{
	vector<string> board;
	recusionHelper(board, 0, n);
	return res;
}
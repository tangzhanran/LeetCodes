//	130. Surrounded Regions
//
//	Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
//
//	A region is captured by flipping all 'O's into 'X's in that surrounded region.
//
//	For example,
//	X X X X
//	X O O X
//	X X O X
//	X O X X
//	After running your function, the board should be :
//
//	X X X X
//	X X X X
//	X X X X
//	X O X X
//
// Written by Zhanran Tang @ 5/2/2017

#include <vector>
#include <iostream>

using namespace std;

void expandOpen(vector<vector<char>>& board, int i, int j, int rows, int cols)
{
	if (board[i][j] == 'O')
	{
		board[i][j] = 'M';
		if (i > 1)
			expandOpen(board, i - 1, j, rows, cols);
		if (i < rows - 1)
			expandOpen(board, i + 1, j, rows, cols);
		if (j > 1)
			expandOpen(board, i, j - 1, rows, cols);
		if (j < cols - 1)
			expandOpen(board, i, j + 1, rows, cols);
	}
}
void solve(vector<vector<char>>& board)
{
	int rows = board.size();
	if (rows == 0)
		return;
	int cols = board[0].size();
	if (cols == 0)
		return;
	for (int j = 0; j<cols; j++)
	{
		expandOpen(board, 0, j, rows, cols);
		if (rows > 1)
			expandOpen(board, rows - 1, j, rows, cols);
	}
	for (int i = 1; i<rows - 1; i++)
	{
		expandOpen(board, i, 0, rows, cols);
		if (cols > 1)
			expandOpen(board, i, cols - 1, rows, cols);
	}
	for (int i = 0; i<rows; i++)
	{
		for (int j = 0; j<cols; j++)
		{
			if (board[i][j] == 'O')
				board[i][j] = 'X';
		}
	}
	for (int i = 0; i<rows; i++)
	{
		for (int j = 0; j<cols; j++)
		{
			if (board[i][j] == 'M')
				board[i][j] = 'O';
		}
	}
}

int main()
{	
	vector<vector<char>> board;
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
		{
			cout << board[i][j] << endl;
		}
		cout << endl;
	}
	system("pause");
}
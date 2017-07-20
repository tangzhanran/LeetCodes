//	289. Game of Life
//
//	According to the Wikipedia's article: 
//	"The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
//
//	Given a board with m by n cells, each cell has an initial state live(1) or dead(0).
//	Each cell interacts with its eight neighbors(horizontal, vertical, diagonal) 
//	using the following four rules(taken from the above Wikipedia article) :
//		1. Any live cell with fewer than two live neighbors dies, as if caused by under - population.
//		2. Any live cell with two or three live neighbors lives on to the next generation.
//		3. Any live cell with more than three live neighbors dies, as if by over - population..
//		4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
//	Write a function to compute the next state(after one update) of the board given its current state.
//
//	Follow up :
//		1. Could you solve it in - place ? 
//			Remember that the board needs to be updated at the same time : 
//			You cannot update some cells first and then use their updated values to update other cells.
//		2. In this question, we represent the board using a 2D array.In principle, 
//			the board is infinite, which would cause problems when the active area encroaches the border of the array.
//			How would you address these problems ?
//
//	Written by Zhanran Tang @ 7/19/2017
//
//	Ideas: If live->dead, make it -1. If dead->live, make it 2.
//	Complexity:	O(mn) in time, O(1) in space.

#include "Header.h"

using namespace std;

void gameOfLife(vector<vector<int>>& board)
{
	int m = board.size();
	if (m > 0)
	{
		int n = board[0].size();
		for (int i = 0; i<m; i++)
		{
			for (int j = 0; j<n; j++)
			{
				int liveneighb = 0;
				int l = 0, r = 0, u = 0, d = 0;
				if (i - 1 >= 0)
					u = -1;
				if (i + 1 < m)
					d = 1;
				if (j - 1 >= 0)
					l = -1;
				if (j + 1 < n)
					r = 1;
				for (int x = u; x <= d; x++)
				{
					for (int y = l; y <= r; y++)
					{
						if (x != 0 || y != 0)
						{
							if (board[i + x][j + y] == 1 || board[i + x][j + y] == -1)
								liveneighb++;
						}
					}
				}
				if (board[i][j] == 0 && liveneighb == 3)
					board[i][j] = 2;
				else if (board[i][j] == 1)
				{
					if (liveneighb < 2 || liveneighb > 3)
						board[i][j] = -1;
				}
			}
		}
		for (int i = 0; i<m; i++)
		{
			for (int j = 0; j<n; j++)
			{
				if (board[i][j] == -1)
					board[i][j] = 0;
				else if (board[i][j] == 2)
					board[i][j] = 1;
			}
		}
	}
}

int main()
{
	vector<vector<int>> board = { {1, 1}, { 1,0 }};
	gameOfLife(board);
	for (int i = 0; i < board.size(); i++)
	{
		cout << "[ ";
		for (int j = 0; j < board[i].size(); j++)
			cout << board[i][j] << " ";
		cout << "]" << endl;
	}
	system("pause");
	return 0;
}
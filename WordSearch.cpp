//	79. Word Search
//
//	Given a 2D board and a word, find if the word exists in the grid.
//
//	The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring.The same letter cell may not be used more than once.
//
//	For example,
//	Given board =
//	[
//		['A', 'B', 'C', 'E'],
//		['S', 'F', 'C', 'S'],
//		['A', 'D', 'E', 'E']
//	]
//	word = "ABCCED", ->returns true,
//	word = "SEE", ->returns true,
//	word = "ABCB", ->returns false.
//
//	Written by Zhanran Tang @ 5/17/2017
//
//	Ideas: Search in DFS recursively.
//	Complexity: O(n^2) in time. O(1) in space.

#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool check(vector<vector<char>>& board, int i, int j, string &word, int index)
{
	if (index >= word.length())
		return true;
	if (i<0 || i >= board.size() || j<0 || j >= board[0].size() || board[i][j] != word[index])
		return false;
	index++;
	char current = board[i][j];
	board[i][j] = '*';
	if (check(board, i - 1, j, word, index) || check(board, i + 1, j, word, index) ||
		check(board, i, j - 1, word, index) || check(board, i, j + 1, word, index))
	{
		board[i][j] = current;
		return true;
	}
	board[i][j] = current;
	return false;
}

bool exist(vector<vector<char>>& board, string word)
{
	if (board.size() == 0 || board[0].size() == 0 || word.length() == 0)
		return false;
	for (int i = 0; i<board.size(); i++)
	{
		for (int j = 0; j<board[0].size(); j++)
		{
			if (check(board, i, j, word, 0))
				return true;
		}
	}
	return false;
}

int main()
{
	vector<vector<char>> board = { {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'} };
	string word = "ABCB";
	cout << exist(board, word) << endl;
	system("pause");
	return 0;
}
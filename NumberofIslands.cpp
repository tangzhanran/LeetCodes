//	200. Number of Islands
//
//	Given a 2d grid map of '1's(land) and '0's(water), count the number of islands.
//	An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
//	You may assume all four edges of the grid are all surrounded by water.
//
//	Example 1:
//	11110
//	11010
//	11000
//	00000
//	Answer : 1
//
//	Example 2 :
//	11000
//	11000
//	00100
//	00011
//	Answer : 3
//
//	Written by Zhanran Tang @ 7/15/2017
//
//	Ideas: Expand the land recursively.
//	Complexity: O(n) in time, O(1) in space.

#include "Header.h"

using namespace std;

void expandLand(vector<vector<char>>& grid, int i, int j)
{
	grid[i][j] = '0';
	if (i > 0 && grid[i - 1][j] == '1')
	{
		expandLand(grid, i - 1, j);
	}
	if (i < grid.size() - 1 && grid[i + 1][j] == '1')
	{
		expandLand(grid, i + 1, j);
	}
	if (j > 0 && grid[i][j - 1] == '1')
	{
		expandLand(grid, i, j - 1);
	}
	if (j < grid[i].size() - 1 && grid[i][j + 1] == '1')
	{
		expandLand(grid, i, j + 1);
	}
}
int numIslands(vector<vector<char>>& grid)
{
	if (grid.empty())
		return 0;
	int islandNum = 0;
	for (int i = 0; i<grid.size(); i++)
	{
		for (int j = 0; j<grid[i].size(); j++)
		{
			if (grid[i][j] == '1')
			{
				islandNum++;
				grid[i][j] = '0';
				expandLand(grid, i, j);
			}
		}
	}
	return islandNum;
}

int main()
{
	vector<vector<char>> grid = { {'0','1','1','0','1'}, {'1','0','1','1','1'}, {'0','1','1','0','0'}, {'0','0','0','0','0'} };
	cout << numIslands(grid) << endl;
	system("pause");
	return 0;
}
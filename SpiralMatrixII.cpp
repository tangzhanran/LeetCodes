//	59. Spiral Matrix II
//
//	Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
//
//	For example,
//	Given n = 3,
//
//	You should return the following matrix :
//	[
//		[1, 2, 3],
//		[8, 9, 4],
//		[7, 6, 5]
//	]
//	
//	Written by Zhanran Tang @ 6/30/2017
//
//	Ideas: Do iteratively.
//	Complexity: O(n^2) in time and space.

#include "Header.h"

using namespace std;

vector<vector<int>> generateMatrix(int n)
{
	vector<vector<int>> res(n, vector<int>(n, -1));
	int count = 1, i = 0, j = 0;
	bool right = true, down = false, left = false, up = false;
	while (count <= n*n)
	{
		res[i][j] = count;
		if (right)
		{
			j++;
			if (j >= n || res[i][j] != -1)
			{
				right = false;
				down = true;
				j--;
				i++;
			}
		}
		else if (down)
		{
			i++;
			if (i >= n || res[i][j] != -1)
			{
				down = false;
				left = true;
				i--;
				j--;
			}
		}
		else if (left)
		{
			j--;
			if (j<0 || res[i][j] != -1)
			{
				left = false;
				up = true;
				j++;
				i--;
			}
		}
		else if (up)
		{
			i--;
			if (i<0 || res[i][j] != -1)
			{
				up = false;
				right = true;
				i++;
				j++;
			}
		}
		count++;
	}
	return res;
}

int main()
{
	vector<vector<int>> res = generateMatrix(5);
	for (int i = 0; i < res.size(); i++)
	{
		cout << "[ ";
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << "]" << endl;
	}
	system("pause");
	return 0;
}
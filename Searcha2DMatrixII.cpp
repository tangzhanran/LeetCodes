//	240. Search a 2D Matrix II
//
//	Write an efficient algorithm that searches for a value in an m x n matrix.This matrix has the following properties :
//		1. Integers in each row are sorted in ascending from left to right.
//		2. Integers in each column are sorted in ascending from top to bottom.
//
//	For example,
//	Consider the following matrix :
//	[
//		[1, 4, 7, 11, 15],
//		[2, 5, 8, 12, 19],
//		[3, 6, 9, 16, 22],
//		[10, 13, 14, 17, 24],
//		[18, 21, 23, 26, 30]
//	]
//	Given target = 5, return true.
//	Given target = 20, return false.
//
//	Written by Zhanran Tang @ 7/16/2017
//
//	Ideas: Start from the top right, if greater than target move left, if smaller move down.
//	Complexity: O(m+n) in time, O(1) in space.

#include "Header.h"

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
	if (matrix.empty())
		return false;
	int m = matrix.size();
	int n = matrix[0].size();
	int i = 0, j = n - 1;
	while (i<m && j >= 0)
	{
		if (matrix[i][j] == target)
			return true;
		else if (matrix[i][j] > target)
			j--;
		else
			i++;
	}
	return false;
}

int main()
{
	vector<vector<int>> matrix = { {1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, 
	{10, 13, 14, 17, 24}, {18, 21, 23, 26, 30} };
	cout << searchMatrix(matrix, 14) << endl;
	system("pause");
	return 0;
}
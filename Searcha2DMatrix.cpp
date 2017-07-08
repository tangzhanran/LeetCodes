//	74. Search a 2D Matrix
//
//	Write an efficient algorithm that searches for a value in an m x n matrix.This matrix has the following properties :
//
//	Integers in each row are sorted from left to right.
//	The first integer of each row is greater than the last integer of the previous row.
//	For example, Consider the following matrix :
//	[
//		[1, 3, 5, 7],
//		[10, 11, 16, 20],
//		[23, 30, 34, 50]
//	]
//	Given target = 3, return true.
//
//	Written by Zhanran Tang @ 7/6/2017
//
//	Ideas: 
//		1. Do binary search for each row.
//		2. Do binary search on the matrix.
//	Complexity: 
//		1. O(mlogn) in time, O(1) in space.
//		2. O(log(mn)) in time, O(1) in space.

#include "Header.h"

using namespace std;

#define IDEAS 2

#if IDEAS == 1
bool binarySearch(vector<int>& values, int target, int start, int end)
{
	if (start > end)
		return false;
	int mid = (start + end) / 2;
	if (values[mid] > target)
		return binarySearch(values, target, start, mid - 1);
	else if (values[mid] < target)
		return binarySearch(values, target, mid + 1, end);
	else
		return true;
}

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
	int m = matrix.size();
	if (m == 0)
		return false;
	int n = matrix[0].size();
	if (n == 0)
		return false;
	for (int i = 0; i<m; i++)
	{
		if (matrix[i].front() > target)
			return false;
		if (matrix[i].front() <= target && matrix[i].back() >= target)
		{
			if (binarySearch(matrix[i], target, 0, matrix[i].size() - 1))
				return true;
		}
	}
	return false;
}

#else
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
	int m = matrix.size();
	if (m == 0)
		return false;
	int n = matrix[0].size();
	int start = 0, end = m*n - 1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (matrix[mid / n][mid%n] > target)
			end = mid - 1;
		else if (matrix[mid / n][mid%n] < target)
			start = mid + 1;
		else
			return true;
	}
	return false;
}
#endif

int main()
{
	vector<vector<int>> matrix = { {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50} };
	cout << searchMatrix(matrix, 3) << endl;
	system("pause");
	return 0;
}
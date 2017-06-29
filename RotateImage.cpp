//	48. Rotate Image
//
//	You are given an n x n 2D matrix representing an image.
//
//	Rotate the image by 90 degrees(clockwise).
//
//	Follow up :
//	Could you do this in - place?
//
//	Written by Zhanran Tang @ 6/29/2017
//
//	Ideas: Can be done recursively or iteratively
//	Complexity: O(n^2) in time.

#include "Header.h"

using namespace std;

#define RECURSIVE 0

#if RECURSIVE
void rotateRecursion(vector<vector<int>>& matrix, int s, int n)
{
	if (s <= n / 2)
	{
		for (int j = s; j < n - s; j++)
		{
			swap(matrix[s][j], matrix[j][n - s]);
			swap(matrix[s][j], matrix[n - s][n - j]);
			swap(matrix[s][j], matrix[n - j][s]);
		}
		rotateRecursion(matrix, s + 1, n);
	}
}
void rotate(vector<vector<int>>& matrix)
{
	int n = matrix.size() - 1;
	if (n >= 0)
		rotateRecursion(matrix, 0, n);
}
#else
void rotate(vector<vector<int>>& matrix)
{
	int n = matrix.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			swap(matrix[i][j], matrix[j][i]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		reverse(matrix[i].begin(), matrix[i].end());
	}
}
#endif

int main()
{
	vector<vector<int>> matrix = { { 1,2,3,4 }, { 1,2,3,4 }, { 1,2,3,4 }, { 1,2,3,4 } };
	cout << "before rotate" << endl;
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix.size(); j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	rotate(matrix);
	cout << "after rotate" << endl;
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix.size(); j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
//	73. Set Matrix Zeroes
//
//	Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
//
//	Written by Zhanran Tang @ 7/4/2017
//
//	Ideas: Store status of each row at the first colums and status of colums at first row.
//		use a variable to store the status of the first colum separately.
//	Complexity: O(mn) in time and O(1) in space.

#include "Header.h"

using namespace std;

void setZeroes(vector<vector<int>>& matrix)
{
	int m = matrix.size();
	if (m != 0)
	{
		int n = matrix[0].size();
		bool colonezero = false;
		for (int i = 0; i<m; i++)
		{
			for (int j = 0; j<n; j++)
			{
				if (matrix[i][j] == 0)
				{
					if (j == 0)
					{
						colonezero = true;
					}
					else
					{
						matrix[0][j] = 0;
					}
					matrix[i][0] = 0;
				}
			}
		}
		for (int i = 1; i<m; i++)
		{
			for (int j = 1; j<n; j++)
			{
				if (matrix[i][0] == 0 || matrix[0][j] == 0)
					matrix[i][j] = 0;
			}
		}
		if (matrix[0][0] == 0)
		{
			for (int j = 0; j<n; j++)
			{
				matrix[0][j] = 0;
			}
		}
		if (colonezero)
		{
			for (int i = 0; i<m; i++)
			{
				matrix[i][0] = 0;
			}
		}
	}
}

int main()
{
	vector<vector<int>> matrix = { {0, 0, 0, 5}, {4, 3, 1, 4}, {0, 1, 1, 4}, {1, 2, 1, 3}, {0, 0, 1, 1} };
	setZeroes(matrix);
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}
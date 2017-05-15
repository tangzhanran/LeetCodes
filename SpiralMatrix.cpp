//	54. Spiral Matrix
//
//	Given a matrix of m x n elements(m rows, n columns), return all elements of the matrix in spiral order.
//
//	For example,
//	Given the following matrix :
//
//	[
//		[1, 2, 3],
//		[4, 5, 6],
//		[7, 8, 9]
//	]
//	You should return[1, 2, 3, 6, 9, 8, 7, 4, 5].
//
//	Written by Zhanran Tang @ 5/15/2017
//
//	Ideas: Simply put numbers in a new matrix in spiral order.
//	Complexity:	O(row*col) in time and space.

#include <vector>
#include <iostream>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix)
{

	if (matrix.size() == 0 || matrix[0].size() == 0)
		return vector<int>();
	int row = matrix.size(), col = matrix[0].size();
	int sz = row * col;
	vector<int> res(sz);
	int upbound = 0, rbound = col, lbound = 0, dbound = row;
	int count = 0;
	while (1)
	{
		for (int j = lbound; j<rbound; j++)
		{
			res[count] = matrix[upbound][j];
			count++;
		}
		if (count >= sz)
			break;
		for (int i = upbound + 1; i<dbound; i++)
		{
			res[count] = matrix[i][rbound - 1];
			count++;
		}
		if (count >= sz)
			break;
		for (int j = rbound - 2; j >= lbound; j--)
		{
			res[count] = matrix[dbound - 1][j];
			count++;
		}
		if (count >= sz)
			break;
		for (int i = dbound - 2; i>upbound; i--)
		{
			res[count] = matrix[i][lbound];
			count++;
		}
		if (count >= sz)
			break;
		upbound++;
		rbound--;
		dbound--;
		lbound++;
		if (upbound>dbound || rbound<lbound)
			break;
	}
	return res;
}

int main()
{
	vector<vector<int>> matrix;
	vector<int> res = spiralOrder(matrix);
	system("pause");
	return 0;
}
//	304. Range Sum Query 2D - Immutable
//
//	Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner(row1, col1) and lower right corner(row2, col2).
//
//	Range Sum Query 2D
//	The above rectangle(with the red border) is defined by(row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.
//
//	Example:
//	Given matrix = [
//		[3, 0, 1, 4, 2],
//		[5, 6, 3, 2, 1],
//		[1, 2, 0, 1, 5],
//		[4, 1, 0, 1, 7],
//		[1, 0, 3, 0, 5]
//	]
//
//	sumRegion(2, 1, 4, 3) -> 8
//	sumRegion(1, 1, 2, 2) -> 11
//	sumRegion(1, 2, 2, 4) -> 12
//	Note:
//	1. You may assume that the matrix does not change.
//	2. There are many calls to sumRegion function.
//	3. You may assume that row1 ¡Ü row2 and col1 ¡Ü col2.
//
//	Written by Zhanran Tang @ 5/11/2017
//
//	Ideas:	Using subtract
//	Complexity:	O(m*n) in constructing, O(1) in sum

#include <vector>
#include <iostream>

using namespace std;

class NumMatrix {
private:
	vector<vector<int>> sumval;
public:
	NumMatrix(vector<vector<int>> matrix)
	{
		if (!matrix.empty())
		{
			sumval = vector<vector<int>>(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
			for (int i = 1; i <= matrix.size(); i++)
			{
				for (int j = 1; j <= matrix[0].size(); j++)
				{
					sumval[i][j] = sumval[i - 1][j] + sumval[i][j - 1] - sumval[i - 1][j - 1] + matrix[i - 1][j - 1];
				}
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2)
	{
		return sumval[row2 + 1][col2 + 1] - sumval[row1][col2 + 1] - sumval[row2 + 1][col1] + sumval[row1][col1];
	}
};

int main()
{
	vector<vector<int>> matrix;
	int tmpa[] = { 3,0,1,4,2 }, tmpb[] = { 5,6,3,2,1 }, tmpc[] = { 1,2,0,1,5 }, tmpd[] = { 4,1,0,1,7 }, tmpe[] = { 1,0,3,0,5 };
	vector<int> a(tmpa, tmpa+sizeof(tmpa)/sizeof(int));
	vector<int> b(tmpb, tmpb + sizeof(tmpb) / sizeof(int));
	vector<int> c(tmpc, tmpc + sizeof(tmpc) / sizeof(int));
	vector<int> d(tmpd, tmpd + sizeof(tmpd) / sizeof(int));
	vector<int> e(tmpe, tmpe + sizeof(tmpe) / sizeof(int));
	matrix.push_back(a);
	matrix.push_back(b);
	matrix.push_back(c);
	matrix.push_back(d);
	matrix.push_back(e);
	NumMatrix test(matrix);
	cout << test.sumRegion(0, 1, 0, 1) << endl;
	system("pause");
	return 0;
}
//	498. Diagonal Traverse
//
//	Given a matrix of M x N elements(M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.
//
//	Example:
//	Input:
//	[
//		[1, 2, 3],
//		[4, 5, 6],
//		[7, 8, 9]
//	]
//	Output : [1, 2, 4, 7, 5, 3, 6, 8, 9]
//	Note :
//		The total number of elements of the given matrix will not exceed 10, 000.
//
//	Written by Zhanran Tang @ 8/26/2017
//
//	Ideas: The moving direction follows the following patten£ºUpRight, down leftdown, right. Using a vector to store direction
//	Complexity: O(m*n) in time, O(1) in space.

#include "Header.h"

using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& matrix)
{
	vector<int> res;
	int m = matrix.size();
	if (m == 0)
		return res;
	int n = matrix[0].size();
	vector<pair<int, int>> direction = { pair<int,int>(-1,1),pair<int,int>(1,0),pair<int,int>(1,-1),pair<int,int>(0,1) };
	int i = 0, j = 0, k = 0;
	res.push_back(matrix[0][0]);
	for (int cnt = 1; cnt<m*n; cnt++)
	{
		i += direction[k].first;
		j += direction[k].second;
		while (i<0 || j<0 || i >= m || j >= n)
		{
			k = (k + 1) % 4;
			i += direction[k].first;
			j += direction[k].second;
		}
		res.push_back(matrix[i][j]);
		if (k == 1 || k == 3)
			k = (k + 1) % 4;
	}
	return res;
}

int main()
{
	vector<vector<int>> matrix = { { 1, 2, 3 },{ 4, 5, 6 },{ 7, 8, 9 } };
	vector<int> res = findDiagonalOrder(matrix);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}
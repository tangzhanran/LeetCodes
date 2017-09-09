//	85. Maximal Rectangle
//
//	Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
//
//	For example, given the following matrix :
//	1 0 1 0 0
//	1 0 1 1 1
//	1 1 1 1 1
//	1 0 0 1 0
//	Return 6.
//
//	Written by Zhanran Tang @ 9/6/2017
//
//	Ideas: Based on Largest Rectangle in Histogram, calculate heights vector for each row.
//	Complexity: O(m*n) in time, O(n) in space. m, n is the height and width of the input matrix.

#include "Header.h"

using namespace std;

int largestRectangleArea(vector<int>& heights)
{
	heights.push_back(0);
	stack<int> indexstk;
	int maxarea = 0;
	for (int i = 0; i<heights.size(); i++)
	{
		while (!indexstk.empty() && heights[indexstk.top()] >= heights[i])
		{
			int curh = heights[indexstk.top()];
			indexstk.pop();
			if (indexstk.empty())
				maxarea = max(maxarea, curh*i);
			else
				maxarea = max(maxarea, curh*(i - indexstk.top() - 1));
		}
		indexstk.push(i);
	}
	return maxarea;
}
int maximalRectangle(vector<vector<char>>& matrix)
{
	if (matrix.empty())
		return 0;
	int m = matrix.size(), n = matrix[0].size();
	vector<int> heights(n, 0);
	for (int j = 0; j<n; j++)
	{
		if (matrix[0][j] == '1')
			heights[j] = 1;
	}
	int maxarea = largestRectangleArea(heights);
	for (int i = 1; i<matrix.size(); i++)
	{
		for (int j = 0; j<matrix[i].size(); j++)
		{
			if (matrix[i][j] == '0')
				heights[j] = 0;
			else
				heights[j] += 1;
		}
		maxarea = max(maxarea, largestRectangleArea(heights));
	}
	return maxarea;
}

int main()
{
	vector<vector<char>> matrix = { {1,0,1,0,0},{1,0,1,1,1 },{1,1,1,1,1},{1,0,0,1,0} };
	cout << maximalRectangle(matrix) << endl;
	system("pause");
	return 0;
}
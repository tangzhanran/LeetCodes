//	378. Kth Smallest Element in a Sorted Matrix
//
//	Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
//
//	Note that it is the kth smallest element in the sorted order, not the kth distinct element.
//
//	Example:
//	matrix = 
//	[
//		[1, 5, 9],
//		[10, 11, 13],
//		[12, 13, 15]
//	],
//	k = 8,
//	return 13.
//
//	Note:
//	You may assume k is always valid, 1 <= k <= n2.
//
//	Written by Zhanran Tang @ 7/26/2017
//
//	Ideas: Using min heap. Push first line in heap, every time when poping an element, push its next line neighbour into heap.
//	Complexity: O(n+k) in time, O(n) in space.

#include "Header.h"

using namespace std;

class MatrixVal
{
public:
	int val;
	int row;
	int col;
	MatrixVal(int v, int r, int c)
	{
		val = v;
		row = r;
		col = c;
	}
	bool operator () (const MatrixVal&left, const MatrixVal& right)
	{
		return left.val > right.val;
	}
};

class MyCompare 
{
public:
	bool operator () (const MatrixVal&left, const MatrixVal& right)
	{
		return left.val > right.val;
	}
};

int kthSmallest(vector<vector<int>>& matrix, int k)
{
	if (matrix.empty() || matrix[0].empty())
		return 0;
	int n = matrix.size();
	priority_queue<MatrixVal, vector<MatrixVal>, MyCompare> minHeap;
	for (int j = 0; j<n; j++)
	{
		minHeap.push(MatrixVal(matrix[0][j], 0, j));
	}
	int res = 0;
	while (k > 0)
	{
		MatrixVal val = minHeap.top();
		minHeap.pop();
		res = val.val;
		if (val.row < n - 1)
			minHeap.push(MatrixVal(matrix[val.row + 1][val.col], val.row + 1, val.col));
		k--;
	}
	return res;
}

int main()
{
	vector<vector<int>> matrix = { {1,5,9},{10,11,13},{12,13,15} };
	cout << kthSmallest(matrix, 2) << endl;
	system("pause");
	return 0;
}
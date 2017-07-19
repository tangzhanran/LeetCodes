//	279. Perfect Squares
//
//	Given a positive integer n, find the least number of perfect square numbers(for example, 1, 4, 9, 16, ...) which sum to n.
//
//	For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
//
//	Written by Zhanran Tang @ 7/18/2017
//
//	Ideas: DP. It can be done mathematically. See Legendre's three-square theorem and Lagrange's four-square theorem
//	Complexity: O(n^2) in time, O(n) in space. O(n) in time with math.

#include "Header.h"

using namespace std;

int numSquares(int n)
{
	if (n == 0)
		return 0;
	vector<int> res(n + 1, INT_MAX);
	res[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j*j <= i; j++)
		{
			if (res[i] > 1 + res[i - j*j])
				res[i] = 1 + res[i - j*j];
		}
	}
	return res.back();
}

int main()
{
	cout << numSquares(21) << endl;
	system("pause");
	return 0;
}
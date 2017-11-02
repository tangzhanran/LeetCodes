//	69. Sqrt(x)
//
//	Implement int sqrt(int x).
//
//	Compute and return the square root of x.
//
//	Written by Zhanran Tang @ 10/20/2017
//
//	Ideas: Using binary search to find sqrt.
//	Complexity: O(logx) in time, O(1) in space.

#include "Header.h"

using namespace std;

int mySqrt(int x)
{
	long long i = 0, j = x;
	while (i < j - 1)
	{
		long long mid = (i + j) / 2;
		if (mid*mid > x)
			j = mid;
		else if (mid*mid < x)
			i = mid;
		else
			return mid;
	}
	if (j*j == x)
		return (int)j;
	return (int)i;
}
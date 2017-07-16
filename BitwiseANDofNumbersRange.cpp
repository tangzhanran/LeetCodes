//	201. Bitwise AND of Numbers Range
//
//	Given a range[m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
//
//	For example, given the range[5, 7], you should return 4.
//
//	Written by Zhanran Tang @ 7/15/2017
//
//	Ideas: Whenever the two number has different bit count from highest, the bits before followed by 0s is the answer.
//	Complexity: O(1) in time and space.

#include "Header.h"

using namespace std;

int rangeBitwiseAnd(int m, int n)
{
	if (m <= 0 && n >= 0)
		return 0;
	int count = 0;
	while (m != n)
	{
		m /= 2;
		n /= 2;
		count++;
	}
	return m << count;
}

int main()
{
	cout << rangeBitwiseAnd(40, 45) << endl;
	system("pause");
	return 0;
}
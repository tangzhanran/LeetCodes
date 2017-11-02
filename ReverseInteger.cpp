//	7. Reverse Integer
//
//	Reverse digits of an integer.
//
//	Example1: x = 123, return 321
//	Example2 : x = -123, return -321
//
//	Note :
//	The input is assumed to be a 32 - bit signed integer.
//	Your function should return 0 when the reversed integer overflows.
//
//	Written by Zhanran Tang @ 9/26/2017
//
//	Ideas: Straight forward. Be careful about overflow.
//	Complexity: O(l) in time and O(1) in space. l is the length of the input number.

#include "Header.h"

using namespace std;

int reverse(int x)
{
	int sign = 1;
	if (x < 0)
		sign = -1;
	long long num = x;
	num = labs(num);
	int res = 0;
	while (num >= 10)
	{
		if (res>214748364 || (res == 214748364 && num>7))
			return 0;
		res = 10 * res + num % 10;
		num /= 10;
	}
	if (res>214748364 || (res == 214748364 && num>7))
		return 0;
	else
		res = res * 10 + num;
	return sign*res;
}
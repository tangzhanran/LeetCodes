//	67. Add Binary
//
//	Given two binary strings, return their sum(also a binary string).
//
//	For example,
//	a = "11"
//	b = "1"
//	Return "100".
//
//	Written by Zhanran Tang @ 10/18/2017
//
//	Ideas: Simple plus.
//	Complexiyt: O(n) in time and space.

#include "Header.h"

using namespace std;

string addBinary(string a, string b)
{
	if (a.empty())
		return b;
	if (b.empty())
		return a;
	int carry = 0;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	string res = "";
	int i = 0, j = 0;
	while (i<a.length() || j<b.length())
	{
		if (i<a.length() && j<b.length())
			carry += a[i] - '0' + b[j] - '0';
		else if (i<a.length())
			carry += a[i] - '0';
		else
			carry += b[j] - '0';
		res += (carry % 2) + '0';
		if (carry >= 2)
			carry = 1;
		else
			carry = 0;
		i++;
		j++;
	}
	if (carry != 0)
		res += (carry % 2) + '0';
	reverse(res.begin(), res.end());
	return res;
}
//	66. Plus One
//
//	Given a non - negative integer represented as a non - empty array of digits, plus one to the integer.
//
//	You may assume the integer do not contain any leading zero, except the number 0 itself.
//
//	The digits are stored such that the most significant digit is at the head of the list.
//
//	Written by Zhanran Tang @ 10/18/2017
//
//	Ideas: Simple plus one
//	Complexity: O(n) in time, O(1) in space.

#include "Header.h"

using namespace std;

vector<int> plusOne(vector<int>& digits)
{
	if (!digits.empty())
	{
		reverse(digits.begin(), digits.end());
		int carry = 0;
		digits[0]++;
		for (int i = 0; i<digits.size(); i++)
		{
			digits[i] += carry;
			if (digits[i] >= 10)
			{
				carry = 1;
				digits[i] = 0;
			}
			else
				carry = 0;
		}
		if (carry != 0)
			digits.push_back(carry);
		reverse(digits.begin(), digits.end());
	}
	return digits;
}
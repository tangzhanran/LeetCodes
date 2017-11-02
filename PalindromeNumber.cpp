//	9. Palindrome Number
//
//	Determine whether an integer is a palindrome.Do this without extra space.
//
//	Written by Zhanran Tang @ 9/26/2017
//
//	Ideas: keep track the reverse number. 
//		When reverse number equals to original one, it is a palindrome.
//		When reverse number greater than orignal one, it is not a palindrome
//	Complexity: O(1) in space, O(l) in time. l is the length of the number.

#include "Header.h"

using namespace std;

bool isPalindrome(int x)
{
	if (x<0 || (x != 0 && x % 10 == 0))
		return false;
	int rev = 0;
	while (x >= 10)
	{
		rev = rev * 10 + x % 10;
		if (rev == x)
			return true;
		x /= 10;
		if (rev == x)
			return true;
		if (rev > x)
			return false;
	}
	return true;
}
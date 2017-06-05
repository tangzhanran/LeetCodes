//	397. Integer Replacement
//
//	Given a positive integer n and you can do operations as follow :
//		1. If n is even, replace n with n / 2.
//		2. If n is odd, you can replace n with either n + 1 or n - 1.
//	What is the minimum number of replacements needed for n to become 1 ?
//
//	Example 1 :
//		Input :
//		8
//		Output :
//		3
//		Explanation :
//		8 -> 4 -> 2 -> 1
//
//	Example 2 :
//		Input :
//		7
//		Output :
//		4
//		Explanation :
//		7 -> 8 -> 4 -> 2 -> 1
//		or
//		7 -> 6 -> 3 -> 2 -> 1
//
//	Written by Zhanran Tang @ 5/29/2017
//
//	Ideas: f(2n) = f(n)+1, f(2n+1) = min(f(2n),f(2n+2))+1
//	Complexity: O(logn) in time, O(1) in space

#include <iostream>

using namespace std;

int integerReplacement(int n)
{
	if (n == 1)
		return 0;
	if (n == INT_MAX)
		return 32;
	if (n == 3)
		return 2;
	if (n % 2 == 0)
		return integerReplacement(n / 2) + 1;
	else
	{
		if ((n + 1) % 4 == 0)
			return integerReplacement(n + 1) + 1;
		else
			return integerReplacement(n - 1) + 1;
	}
}

int main()
{
	int num = 2991343;
	cout << integerReplacement(num) << endl;
	system("pause");
	return 0;
}
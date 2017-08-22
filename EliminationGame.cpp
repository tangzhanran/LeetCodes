//	390. Elimination Game
//
//	There is a list of sorted integers from 1 to n.Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.
//
//	Repeat the previous step again, but this time from right to left, remove the right most number and every other number from the remaining numbers.
//
//	We keep repeating the steps again, alternating left to right and right to left, until a single number remains.
//
//	Find the last number that remains starting with a list of length n.
//
//	Example:
//
//	Input:
//	n = 9,
//	1 2 3 4 5 6 7 8 9
//	2 4 6 8
//	2 6
//	6
//
//	Output :
//	6
//
//	Written by Zhanran Tang @ 7/28/2017
//
//	Ideas: 
//		1. Do recursively by using 2 method.
//		2.Track the head. The head will change when left->right or right->left when n is odd.
//	Complexity: O(logn) in time, O(1) in space.

#include "Header.h"

using namespace std;

#define METHOD 1

#if METHOD==1
int leftToRight(int n);
int rightToLeft(int n);

int leftToRight(int n)
{
	if (n <= 2)
		return n;
	return 2 * rightToLeft(n / 2);
}
int rightToLeft(int n)
{
	if (n <= 2)
		return 1;
	if (n % 2 == 0)
		return 2 * leftToRight(n / 2) - 1;
	return 2 * leftToRight(n / 2);
}
int lastRemaining(int n)
{
	return leftToRight(n);
}
#elif METHOD==2
int lastRemaining(int n)
{
	int head = 1;
	int remain = n;
	bool lTor = true;
	int gap = 1;
	while (remain > 1)
	{
		if (lTor || remain % 2 == 1)
			head += gap;
		lTor = !lTor;
		remain /= 2;
		gap *= 2;
	}
	return head;
}
#endif // METHOD==1

int main()
{
	cout << lastRemaining(27) << endl;
	system("pause");
	return 0;
}
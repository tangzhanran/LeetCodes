//	70. Climbing Stairs
//
//	You are climbing a stair case.It takes n steps to reach to the top.
//
//	Each time you can either climb 1 or 2 steps.In how many distinct ways can you climb to the top ?
//
//	Note : Given n will be a positive integer.
//
//	Written by Zhanran Tang @ 10/21/2017
//
//	Ideas: Simple DP.
//	Complexity: O(n) in time, O(1) in space.

#include "Header.h"

using namespace std;

int climbStairs(int n)
{
	int last1 = 1, last2 = 2;
	for (int i = 3; i <= n; i++)
	{
		int cur = last1 + last2;
		last1 = last2;
		last2 = cur;
	}
	if (n <= 1)
		return last1;
	return last2;
}
//	42. Trapping Rain Water
//
//	Given n non - negative integers representing an elevation map where the width of each bar is 1, 
//	compute how much water it is able to trap after raining.
//
//	For example,
//	Given[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1], return 6.
//
//	Written by Zhanran Tang @ 10/10/2017
//	
//	Ideas: Use 2 pointers. One from left and one from right.
//		Keep track on the largest values on both left and right.
//		Move the smaller height pointer once per loop.
//		Add the water stored in each bin.
//	Complexity: O(n) in time, O(1) in space.

#include "Header.h"

using namespace std;

int trap(vector<int>& height)
{
	if (height.size() < 3)
		return 0;
	int l = 0, r = height.size() - 1;
	int ml = 0, mr = 0;
	int res = 0;
	while (l < r)
	{
		if (height[l] > height[r])
		{
			if (height[r] < mr)
				res += mr - height[r];
			else
				mr = height[r];
			r--;
		}
		else
		{
			if (height[l] < ml)
				res += ml - height[l];
			else
				ml = height[l];
			l++;
		}
	}
	return res;
}
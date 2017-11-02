//	11. Container With Most Water
//
//	Given n non - negative integers a1, a2, ..., an, 
//	where each represents a point at coordinate(i, ai).
//	n vertical lines are drawn such that the two endpoints of line i is at(i, ai) and (i, 0).
//	Find two lines, which together with x - axis forms a container, 
//	such that the container contains the most water.
//
//	Note: You may not slant the container and n is at least 2.
//
//	Written by Zhanran Tang @ 9/27/2017
//
//	Ideas: Use two pointers, one from begin and one from end.
//		calculate and store the maximum area, move the pointer which has smaller height.
//	Complexity: O(n) in time, O(1) in space.

#include "Header.h"

using namespace std;

int maxArea(vector<int>& height)
{
	int s = 0, e = height.size() - 1, res = 0;
	while (s < e)
	{
		if (height[s] > height[e])
		{
			res = max(res, (e - s)*height[e]);
			e--;
		}
		else
		{
			res = max(res, (e - s)*height[s]);
			s++;
		}
	}
	return res;
}
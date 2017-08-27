//452. Minimum Number of Arrows to Burst Balloons
//
//	There are a number of spherical balloons spread in two - dimensional space.
//	For each balloon, provided input is the start and end coordinates of the horizontal diameter.
//	Since it's horizontal, y-coordinates don't matter and hence the x - coordinates of start and end of the diameter suffice.
//	Start is always smaller than end.
//	There will be at most 104 balloons.
//
//	An arrow can be shot up exactly vertically from different points along the x - axis.
//	A balloon with xstart and xend bursts by an arrow shot at x if xstart ¡Ü x ¡Ü xend.
//	There is no limit to the number of arrows that can be shot.An arrow once shot keeps travelling up infinitely.The problem is to find the minimum number of arrows that must be shot to burst all balloons.
//
//	Example:
//
//	Input:
//	[[10, 16], [2, 8], [1, 6], [7, 12]]
//	Output :
//	2
//	Explanation :
//	One way is to shoot one arrow for example at x = 6 (bursting the balloons[2, 8] and [1, 6]) 
//	and another arrow at x = 11 (bursting the other two balloons).
//
//	Written by Zhanran Tang @ 8/23/2017
//
//	Ideas: Sort the points by start position. Shot the end point of the first ballon.
//		From the second, track the last arrow shot. There are 3 situations:
//		1. Current ballon is in the range of the last shot. Change the last shot to the end of current ballon.
//		2. Current ballon is out of the range of the last shot. Change the last shot to the end of current ballon and arrow count++.
//		3. Current ballon overlap with the last shot. Do nothing.
//	Complexity: O(nlogn) in time, O(1) in space.

#include "Header.h"

using namespace std;

bool mycompare(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.first < p2.first)
		return true;
	return false;
}

int findMinArrowShots(vector<pair<int, int>>& points)
{
	if (points.empty())
		return 0;
	sort(points.begin(), points.end(), mycompare);
	int count = 1, lastarrow = points[0].second;
	for (int i = 1; i<points.size(); i++)
	{
		if (points[i].second < lastarrow)
			lastarrow = points[i].second;
		else if (points[i].first > lastarrow)
		{
			lastarrow = points[i].second;
			count++;
		}
	}
	return count;
}

int main()
{
	vector<pair<int, int>> points = { {10,16},{2,8},{1,6},{7,12} };
	cout << findMinArrowShots(points) << endl;
	system("pause");
	return 0;
}
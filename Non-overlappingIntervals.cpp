//	435. Non - overlapping Intervals
//
//	Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non - overlapping.
//
//	Note:
//		You may assume the interval's end point is always bigger than its start point.
//		Intervals like[1, 2] and [2, 3] have borders "touching" but they don't overlap each other.
//
//	Example 1 :
//	Input : [[1, 2], [2, 3], [3, 4], [1, 3]]
//	Output : 1
//	Explanation : [1, 3] can be removed and the rest of intervals are non - overlapping.
//
//	Example 2 :
//	Input : [[1, 2], [1, 2], [1, 2]]
//	Output : 2
//	Explanation : You need to remove two[1, 2] to make the rest of intervals non - overlapping.
//
//	Example 3 :
//	Input : [[1, 2], [2, 3]]
//	Output : 0
//	Explanation : You don't need to remove any of the intervals since they're already non - overlapping.
//
//	Ideas: Similar to work time arrangement. Keep track on how many intervals are kept and the rest is the answer.
//	Complexity: O(nlogn) in time, O(1) in space.

#include "Header.h"

using namespace std;

bool mycompare(Interval i1, Interval i2)
{
	if (i1.end < i2.end)
		return true;
	return false;
}
int eraseOverlapIntervals(vector<Interval>& intervals)
{
	if (intervals.empty())
		return 0;
	sort(intervals.begin(), intervals.end(), mycompare);
	int start = intervals[0].start, end = intervals[0].end, res = 1;
	for (int i = 1; i<intervals.size(); i++)
	{
		if (intervals[i].start >= end)
		{
			end = intervals[i].end;
			res++;
		}
	}
	return intervals.size() - res;
}

int main()
{
	vector<Interval> intervals;
	cout << eraseOverlapIntervals(intervals) << endl;
	system("pause");
	return 0;
}
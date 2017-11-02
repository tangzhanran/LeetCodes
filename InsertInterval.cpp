//	57. Insert Interval
//
//	Given a set of non - overlapping intervals, insert a new interval into the intervals(merge if necessary).
//
//	You may assume that the intervals were initially sorted according to their start times.
//
//	Example 1:
//	Given intervals[1, 3], [6, 9], insert and merge[2, 5] in as[1, 5], [6, 9].
//
//	Example 2 :
//	Given[1, 2], [3, 5], [6, 7], [8, 10], [12, 16], insert and merge[4, 9] in as[1, 2], [3, 10], [12, 16].
//
//	This is because the new interval[4, 9] overlaps with[3, 5], [6, 7], [8, 10].
//
//	Written by Zhanran Tang @ 10/15/2017
//
//	Ideas: Find the 2(maybe the same) intervals closest to the new interval. 
//		The first one has smaller start than new, the second one has larger end than new.
//		Merged the 3. Push other into result.
//	Complexity:	O(n) in time, O(1) in space.

#include "Header.h"

using namespace std;

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
{
	vector<Interval> res;
	if (intervals.empty())
	{
		res.push_back(newInterval);
		return res;
	}
	int n = intervals.size();
	int before = -1, after = n;
	int i = 0, j = n - 1;
	while (i<n && j >= 0)
	{
		if (intervals[i].start < newInterval.start)
			before = i;
		if (intervals[j].end > newInterval.end)
			after = j;
		i++;
		j--;
	}
	Interval mergedInterval(newInterval.start, newInterval.end);
	bool eraseBefore = false, eraseAfter = false;
	if (before >= 0 && intervals[before].end >= newInterval.start)
	{
		mergedInterval.start = intervals[before].start;
		eraseBefore = true;
	}
	if (after<n && intervals[after].start <= newInterval.end)
	{
		mergedInterval.end = intervals[after].end;
		eraseAfter = true;
	}
	for (int k = 0; k<before; k++)
		res.push_back(intervals[k]);
	if (before >= 0 && !eraseBefore)
		res.push_back(intervals[before]);
	res.push_back(mergedInterval);
	if (after<n && !eraseAfter)
		res.push_back(intervals[after]);
	for (int k = after + 1; k<n; k++)
		res.push_back(intervals[k]);
	return res;
}
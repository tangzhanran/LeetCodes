//	56. Merge Intervals
//
//	Given a collection of intervals, merge all overlapping intervals.
//
//	For example,
//	Given[1, 3], [2, 6], [8, 10], [15, 18],
//	return[1, 6], [8, 10], [15, 18].
//
//	Written by Zhanran Tang @ 5/29/2017
//
//	Ideas: Sort intervals by start, than merge.
//	Complexity: O(nlogn) in time, O(n) in space

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Interval 
{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool mycompare(Interval a, Interval b)
{
	if (a.start < b.start)
		return true;
	else if (a.start > b.start)
		return false;
	else
	{
		if (a.end < b.end)
			return true;
		return false;
	}
}
vector<Interval> merge(vector<Interval>& intervals)
{
	if (intervals.size() == 0)
		return intervals;
	sort(intervals.begin(), intervals.end(), mycompare);
	vector<Interval> res;
	res.push_back(intervals[0]);
	for (int i = 1; i<intervals.size(); i++)
	{
		if (intervals[i].start > res.back().end)
			res.push_back(intervals[i]);
		else if (intervals[i].start <= res.back().end && intervals[i].end>res.back().end)
			res.back().end = intervals[i].end;

	}
	return res;
}

int main()
{
	vector<Interval> intervals;
	vector<Interval> res = merge(intervals);
	for (int i = 0; i < res.size(); i++)
		cout << "[" << res[i].start << "," << res[i].end << "]" << " ";
	cout << endl;
	system("pause");
	return 0;
}
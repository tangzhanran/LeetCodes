//	436. Find Right Interval
//
//	Given a set of intervals, for each of the interval i, 
//	check if there exists an interval j whose start point is bigger than or equal to the end point of the interval i, 
//	which can be called that j is on the "right" of i.
//
//	For any interval i, you need to store the minimum interval j's index, 
//	which means that the interval j has the minimum start point to build the "right" relationship for interval i. 
//	If the interval j doesn't exist, store - 1 for the interval i.
//	Finally, you need output the stored value of each interval as an array.
//
//	Note:
//	You may assume the interval's end point is always bigger than its start point.
//	You may assume none of these intervals have the same start point.
//
//	Example 1 :
//	Input : [[1, 2]]
//	Output : [-1]
//	Explanation : There is only one interval in the collection, so it outputs - 1.
//
//	Example 2 :
//	Input : [[3, 4], [2, 3], [1, 2]]
//	Output : [-1, 0, 1]
//	Explanation : There is no satisfied "right" interval for[3, 4].
//		For[2, 3], the interval[3, 4] has minimum - "right" start point;
//		For[1, 2], the interval[2, 3] has minimum - "right" start point.
//
//	Example 3:
//	Input: [[1, 4], [2, 3], [3, 4]]
//	Output : [-1, 2, -1]
//	Explanation : There is no satisfied "right" interval for[1, 4] and [3, 4].
//	For[2, 3], the interval[3, 4] has minimum - "right" start point.
//	
//	Written by Zhanran Tang @ 8/21/2017
//
//	Ideas: Using pairs to store start point and index. 
//		Sort pairs with start point. Using binary Search to find right for each interval.
//	Complexity: O(nlogn) in time, O(n) in space.

#include "Header.h"

using namespace std;

vector<pair<int, int>> startmap; // start,index
static bool mycompare(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.first < p2.first)
		return true;
	return false;
}
int binarySearch(int val)
{
	int s = 0, e = startmap.size() - 1;
	while (s < e)
	{
		int mid = (s + e) / 2;
		if (startmap[mid].first >= val)
			e = mid;
		else
			s = mid + 1;
	}
	if (startmap[e].first < val)
		return -1;
	else
		return startmap[e].second;
}
vector<int> findRightInterval(vector<Interval>& intervals)
{
	int n = intervals.size();
	vector<int> res(n, -1);
	for (int i = 0; i<n; i++)
	{
		startmap.push_back(pair<int, int>(intervals[i].start, i));
	}
	sort(startmap.begin(), startmap.end());
	for (int i = 0; i<n; i++)
	{
		res[i] = binarySearch(intervals[i].end);
	}
	return res;
}

int main()
{
	vector<Interval> intervals;
	intervals.push_back(Interval(1, 4));
	intervals.push_back(Interval(2, 3));
	intervals.push_back(Interval(3, 4));
	vector<int> res = findRightInterval(intervals);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}
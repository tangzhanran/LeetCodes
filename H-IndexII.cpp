//	275. H - Index II
//
//	Follow up for H - Index: What if the citations array is sorted in ascending order ? Could you optimize your algorithm?
//
//	Written by Zhanran Tang @ 7/18/2017
//
//	Ideas: Using binary search to find the first citation whose number is greater or equal to n-index.
//	Complexity: O(logn) in time, O(1) in space.

#include "Header.h"

using namespace std;

int hIndex(vector<int>& citations)
{
	int n = citations.size();
	int start = 0, end = n - 1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (citations[mid] >= n - mid)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return n - start;
}

int main()
{
	vector<int> citations = { 3, 0, 6, 1, 5 };
	cout << hIndex(citations) << endl;
	system("pause");
	return 0;
}
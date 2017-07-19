//	274. H - Index
//
//	Given an array of citations(each citation is a non - negative integer) of a researcher, 
//	write a function to compute the researcher's h-index.
//
//	According to the definition of h - index on Wikipedia : 
//	"A scientist has index h if h of his/her N papers have at least h citations each, 
//	and the other N − h papers have no more than h citations each."
//
//	For example, given citations = [3, 0, 6, 1, 5], 
//	which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
//	Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, 
//	his h - index is 3.
//
//	Note : If there are several possible values for h, the maximum one is taken as the h - index.
//
//	Written by Zhanran Tang @ 7/17/2017
//
//	Ideas: 
//		1. Sort the array, if any position i has value equal or greater than n-i, n-i is the h-index. Otherwise 0 is the h-index.
//		2. Use a vector to count the number of citations. Then count the number in the counting vector from back. 
//			When it exceed current index i then return i.
//	Complexity: 
//		1. O(nlogn) in time. O(1) in space.
//		2. O(n) in space and time.

#include "Header.h"

using namespace std;

#define	SAVESPACE 1

#if SAVESPACE
int hIndex(vector<int>& citations)
{
	sort(citations.begin(), citations.end());
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
#else
int hIndex(vector<int>& citations)
{
	int n = citations.size();
	vector<int> count(n + 1, 0);
	for (int i = 0; i<n; i++)
	{
		if (citations[i] > n)
			count[n]++;
		else
			count[citations[i]]++;
	}
	int total = 0;
	for (int i = n; i >= 0; i--)
	{
		total += count[i];
		if (total >= i)
			return i;
	}
	return 0;
}
#endif

int main()
{
	vector<int> citations = { 3, 0, 6, 1, 5 };
	cout << hIndex(citations) << endl;
	system("pause");
	return 0;
}
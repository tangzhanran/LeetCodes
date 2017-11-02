//	4. Median of Two Sorted Arrays
//
//	There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
//	Find the median of the two sorted arrays.The overall run time complexity should be O(log(m + n)).
//
//	Example 1:
//	nums1 = [1, 3]
//	nums2 = [2]
//	The median is 2.0
//
//	Example 2 :
//	nums1 = [1, 2]
//	nums2 = [3, 4]
//	The median is(2 + 3) / 2 = 2.5
//
//	Ideas: Find a place in the shorter vector for separate
//		the separate place in the longer vector can be get by (m+n)/2-i.
//		So the 2 vector are separated into 4 parts.
//		vec1Left+vec2Left will be the left part, vec2Right+vec2Right will be the right part.
//		So if the maximum in left is less than the minimum in right, we find the right separation.
//		To find i, use binary search.
//	Complexity: O(min(m,n)) in time, O(1) in space.

#include "Header.h"

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int m = nums1.size(), n = nums2.size();
	if (m > n)
	{
		swap(nums1, nums2);
		swap(m, n);
	}
	if (m == 0)
	{
		if (n % 2 == 0)
			return (nums2[n / 2] + nums2[n / 2 - 1]) / 2.0;
		else
			return nums2[n / 2];
	}
	int half = (m + n) / 2;
	int start = 0, end = m;
	while (start <= end)
	{
		int i = (start + end) / 2;
		int j = half - i;
		int maxleft, minright;
		if (i>0 && i<m)
		{
			maxleft = max(nums1[i - 1], nums2[j - 1]);
			minright = min(nums1[i], nums2[j]);
			if (maxleft > minright)
			{
				if (nums1[i - 1] > nums2[j])
					end = i - 1;
				else
					start = i + 1;
				continue;
			}
		}
		else
		{
			if (i == 0)
			{
				maxleft = nums2[j - 1];
				if (j < n)
					minright = min(nums1[i], nums2[j]);
				else
					minright = nums1[i];
				if (maxleft > minright)
				{
					start = i + 1;
					continue;
				}
			}
			else
			{
				if (j > 0)
					maxleft = max(nums1[i - 1], nums2[j - 1]);
				else
					maxleft = nums1[i - 1];
				minright = nums2[j];
				if (maxleft > minright)
				{
					end = i - 1;
					continue;
				}
			}
		}
		if ((m + n) % 2 == 0)
			return (maxleft + minright) / 2.0;
		else
			return minright;
	}
	return 0;
}
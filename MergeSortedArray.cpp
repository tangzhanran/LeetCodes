//	88. Merge Sorted Array
//
//	Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
//
//	Note:
//	You may assume that nums1 has enough space(size that is greater or equal to m + n) to hold additional elements from nums2.The number of elements initialized in nums1 and nums2 are m and n respectively.
//
//	Written by Zhanran Tang @ 11/1/2017
//
//	Ideas: Move nums1's elements to the back and insert elements from front.
//	Complexity: O(n+m) in time, O(1) in space.

#include "Header.h"

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	for (int i = m - 1; i >= 0; i--)
	{
		nums1[i + n] = nums1[i];
	}
	int i = n, j = 0, cur = 0;
	while (cur < m + n)
	{
		if (i >= m + n)
		{
			nums1[cur] = nums2[j];
			j++;
		}
		else if (j >= n)
		{
			nums1[cur] = nums1[i];
			i++;
		}
		else
		{
			if (nums1[i] >= nums2[j])
			{
				nums1[cur] = nums2[j];
				j++;
			}
			else
			{
				nums1[cur] = nums1[i];
				i++;
			}
		}
		cur++;
	}
}
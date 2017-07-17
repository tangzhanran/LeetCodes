//	215. Kth Largest Element in an Array
//
//	Find the kth largest element in an unsorted array.Note that it is the kth largest element in the sorted order, not the kth distinct element.
//
//	For example,
//	Given[3, 2, 1, 5, 6, 4] and k = 2, return 5.
//
//	Note:
//	You may assume k is always valid, 1 ? k ? array's length.
//
//	Written by Zhanran Tang @ 7/16/2017
//
//	Ideas:	Use priority queue to store the top k elements
//	Complexity: O(nlogk) in time, O(k) in space.

#include "Header.h"

using namespace std;

int findKthLargest(vector<int>& nums, int k)
{
	priority_queue<int, vector<int>, greater<int>> pq;
	int largest = nums[0];
	pq.push(nums[0]);
	for (int i = 1; i<nums.size(); i++)
	{
		if (pq.size() == k)
		{
			if (nums[i] > largest)
			{
				largest = nums[i];
				pq.pop();
				pq.push(nums[i]);
			}
			else if (nums[i] > pq.top())
			{
				pq.pop();
				pq.push(nums[i]);
			}
		}
		else
			pq.push(nums[i]);
		if (nums[i] > largest)
			largest = nums[i];	
	}
	return pq.top();
}

int main()
{
	vector<int> nums = { 3,2,1,5,6,4 };
	cout << findKthLargest(nums, 2) << endl;
	system("pause");
	return 0;
}
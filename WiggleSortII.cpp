//	324. Wiggle Sort II
//
//	Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
//
//	Example:
//	(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is[1, 4, 1, 5, 1, 6].
//	(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is[2, 3, 1, 3, 1, 2].
//
//	Note :
//	You may assume all input has valid answer.
//
//	Follow Up :
//	Can you do it in O(n) time and / or in - place with O(1) extra space ?
//
//	Written by Zhanran Tang @ 5/16/2017
//
//	Ideas: Combine searching median & Dutch flag problem.
//
//	Complexity: O(n) on average in time, O(1) space.

#include <vector>
#include <algorithm>

using namespace std;

int indexMapping(int i, int n)
{
	return (1 + 2 * i) % (n | 1);
}

void wiggleSort(vector<int>& nums)
{
	int n = nums.size();
	nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
	int mid = *(nums.begin() + n / 2);

	int begin = 0, end = n - 1, cur = 0;
	while (cur <= end)
	{
		int tmp = nums[indexMapping(cur, n)];
		if (tmp > mid)
		{
			swap(nums[indexMapping(cur, n)], nums[indexMapping(begin, n)]);
			begin++;
			cur++;
		}
		else if (tmp < mid)
		{
			swap(nums[indexMapping(cur, n)], nums[indexMapping(end, n)]);
			end--;
		}
		else
			cur++;
	}
}

int main()
{
	vector<int> nums = { 1,5,1,1,6,4 };
	wiggleSort(nums);
	system("pause");
	return 0;
}
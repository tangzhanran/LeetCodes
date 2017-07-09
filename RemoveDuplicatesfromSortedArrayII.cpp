//	80. Remove Duplicates from Sorted Array II
//
//	Follow up for "Remove Duplicates":
//	What if duplicates are allowed at most twice ?
//
//	For example,
//	Given sorted array nums = [1, 1, 1, 2, 2, 3],
//
//	Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. 
//	It doesn't matter what you leave beyond the new length.
//
//	Written by Zhanran Tang 7/8/2017
//
//	Ideas: 
//		1. Use 2 integer to keep track on duplicates and result.
//		2. Move back nums to the front part.
//	Complexity: 1. O(n) in space and time. 2. O(n) in time and O(1) in space.

#include "Header.h"

#define SAVESPACE 0

using namespace std;

#if SAVESPACE
int removeDuplicates(vector<int>& nums)
{
	int same = 0;
	int res = 0;
	if (nums.empty())
		return res;
	vector<int> tmp;
	res++;
	same++;
	tmp.push_back(nums[0]);
	for (int i = 1; i<nums.size(); i++)
	{
		if (nums[i] == nums[i - 1])
		{
			if (same < 2)
			{
				res++;
				same++;
				tmp.push_back(nums[i]);
			}
		}
		else
		{
			same = 1;
			res++;
			tmp.push_back(nums[i]);
		}
	}
	nums = tmp;
	return res;
}
#else
int removeDuplicates(vector<int>& nums)
{
	int n = nums.size(), same = 0;
	for (int i = 2; i<n; i++)
	{
		if (nums[i] == nums[i - 2 - same])
			same++;
		else
			nums[i - same] = nums[i];
	}
	return n - same;
}
#endif

int main()
{
	vector<int> nums = { 1,1,1,2,2,3 };
	cout << removeDuplicates(nums) << endl;
	cout << "[ ";
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << "]" << endl;
	system("pause");
	return 0;
}
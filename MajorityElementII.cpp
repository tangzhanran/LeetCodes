//	229. Majority Element II
//
//	Given an integer array of size n, find all elements that appear more than n/3 times.
//	The algorithm should run in linear time and in O(1) space.
//
//	Written by Zhanran Tang 5/25/2017
//
//	Ideas: 1. Sort then count 2. Majority Vote Algorithm
//	Complexity: 1. O(nlogn) in time, O(1) in space. 2. O(n) in time, O(1) in space

#include <vector>
#include <iostream>

using namespace std;

#define SAVETIME 1

#if SAVETIME
vector<int> majorityElement(vector<int>& nums)
{
	vector<int> res;
	if (nums.size() <= 1)
		return nums;
	int major1 = 0, major2 = 1, count1 = 0, count2 = 0, l = nums.size();
	for (int i = 0; i < l; i++)
	{
		if (major1 == nums[i])
			count1++;
		else if (major2 == nums[i])
			count2++;
		else if (count1 == 0)
		{
			major1 = nums[i];
			count1 = 1;
		}
		else if (count2 == 0)
		{
			major2 = nums[i];
			count2 = 1;
		}
		else
		{
			count1--;
			count2--;
		}
	}
	count1 = 0;
	count2 = 0;
	for (int i = 0; i < l; i++)
	{
		if (major1 == nums[i])
			count1++;
		else if (major2 == nums[i])
			count2++;
	}
	if (count1 > l / 3)
		res.push_back(major1);
	if (count2 > l / 3)
		res.push_back(major2);
	return res;
}
#else
vector<int> majorityElement(vector<int>& nums)
{
	vector<int> res;
	if (nums.size() <= 1)
		return nums;
	sort(nums.begin(), nums.end());
	int pivot = nums[0], count = 0, l = nums.size();
	for (int i = 0; i<l; i++)
	{
		if (nums[i] == pivot)
			count++;
		else
		{
			pivot = nums[i];
			count = 1;
		}
		if (count > l / 3)
		{
			res.push_back(nums[i]);
			if (res.size() == 2)
				return res;
			while (i<l - 1 && nums[i + 1] == pivot)
				i++;
		}
	}
	return res;
}
#endif

int main()
{
	vector<int> nums = { 8,8,8,7,7,9,8,8,8,6,4,4,4,3,4,4,4 };
	vector<int> res = majorityElement(nums);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}
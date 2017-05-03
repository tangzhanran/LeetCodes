//	220. Contains Duplicate III
//
//	Given an array of integers, 
//	find out whether there are two distinct indices i and j in the array 
//	such that the absolute difference between nums[i] and nums[j] is at most t 
//	and the absolute difference between i and j is at most k.
//
//	Written by Zhanran Tang @ 5/2/2017

#include <vector>
#include <iostream>
#include <set>

using namespace std;

//	O(n^2) Method
bool containsNearbyAlmostDuplicateSlow(vector<int>& nums, int k, int t)
{
	int l = nums.size();
	for (int i = 0; i<l; i++)
	{
		int end;
		if (i + k >= l)
			end = l - 1;
		else
			end = i + k;
		for (int j = i + 1; j <= end; j++)
		{
			long long first = nums[i];
			long long second = nums[j];
			long long diff = first - second;
			if (diff < 0)
				diff = -diff;
			if (diff <= t)
				return true;
		}
	}
	return false;
}

bool containsNearbyAlmostDuplicateFast(vector<int>& nums, int k, int t)
{
	set<long long> bucket;
	for (int i = 0; i<nums.size(); i++)
	{
		if (i > k)
			bucket.erase(nums[i - k - 1]);
		long long num = nums[i];
		set<long long>::iterator itr = bucket.lower_bound(num - t);
		if (itr != bucket.end() && *itr <= t + num)
			return true;
		bucket.insert(num);
	}
	return false;
}

int main()
{
	vector<int> nums;
	for (int i = 0; i < 10; i++)
	{
		nums.push_back((i + 8) * 5 - i*i / 2);
	}
	containsNearbyAlmostDuplicateFast(nums, 2, 4);
	system("pause");
	return 0;
}
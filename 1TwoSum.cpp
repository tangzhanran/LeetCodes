//	1. Two Sum
//
//	Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
//	You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
//	Example:
//	Given nums = [2, 7, 11, 15], target = 9,
//
//	Because nums[0] + nums[1] = 2 + 7 = 9,
//	return[0, 1].
//
//	Written by Zhanran Tang @ 9/20/2017
//
//	Ideas: Use Hash table to store value-index.
//	Complexity: O(n) in time and space.

#include "Header.h"

using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
	unordered_map<int, int> indexmap;
	vector<int> res;
	for (int i = 0; i<nums.size(); i++)
	{
		if (indexmap.find(target - nums[i]) != indexmap.end())
		{
			res.push_back(indexmap[target - nums[i]]);
			res.push_back(i);
			break;
		}
		else
			indexmap[nums[i]] = i;
	}
	return res;
}
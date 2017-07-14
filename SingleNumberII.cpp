//	137. Single Number II
//
//	Given an array of integers, every element appears three times except for one, which appears exactly once.Find that single one.
//
//	Note:
//		Your algorithm should have a linear runtime complexity.Could you implement it without using extra memory?
//	
//	Written by Zhanran Tang @ 7/13/2017
//
//	Ideas: Use two 32 bit number to mark 1 on each bits. 
//		e.g. 010 and 001 means 0,1,2 times of 1 on highest, second highes and lowest bits.
//	Complexity: O(n) in time, O(1) in space.

#include "Header.h"

using namespace std;

int singleNumber(vector<int>& nums)
{
	int first = 0, second = 0;
	for (int i = 0; i<nums.size(); i++)
	{
		first = (first ^ nums[i]) & ~second;
		second = (second ^ nums[i]) & ~first;
	}
	return first | second;
}

int main()
{
	vector<int> nums = { 3,3,1,6,10,10,6,10,6,3 };
	cout << singleNumber(nums) << endl;
	system("pause");
	return 0;
}
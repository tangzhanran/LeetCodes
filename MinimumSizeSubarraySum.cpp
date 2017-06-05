//	209. Minimum Size Subarray Sum
//
//	Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ¡Ý s.
//	If there isn't one, return 0 instead.
//
//	For example, given the array[2, 3, 1, 2, 4, 3] and s = 7,
//	the subarray[4, 3] has the minimal length under the problem constraint.
//
//	Written by Zhanran Tang @ 5/30/2017
//
//	Ideas: Keep track the minimum start which sum more than s.
//	Complexity: O(n)(O(2n)) in time, O(1) in space.

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int minSubArrayLen(int s, vector<int>& nums)
{
	if (nums.size() == 0)
		return 0;
	int start = 0, sum = 0, minimum = nums.size() + 1;
	for (int i = 0; i<nums.size(); i++)
	{
		sum += nums[i];
		while (sum >= s)
		{
			minimum = min(minimum, i - start + 1);
			sum -= nums[start];
			start++;
		}
	}
	if (minimum == nums.size() + 1)
		return 0;
	return minimum;
}

int main()
{
	int s = 7;
	vector<int> nums = { 2,3,1,2,4,3 };
	cout << minSubArrayLen(s, nums) << endl;
	system("pause");
	return 0;
}
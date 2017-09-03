//	525. Contiguous Array
//
//	Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.
//
//	Example 1:
//	Input: [0, 1]
//	Output : 2
//	Explanation : [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
//
//	Example 2 :
//	Input : [0, 1, 0]
//	Output : 2
//	Explanation : [0, 1](or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
//
//	Note : The length of the given binary array will not exceed 50, 000
//
//	Written by Zhanran Tang @ 8/30/2017
//
//	Ideas: Using hash map to store <difference,index>, difference is the difference number between 1 and 0.
//	Complexity: O(n) in time and space.

#include "Header.h"

using namespace std;

int findMaxLength(vector<int>& nums)
{
	if (nums.empty())
		return 0;
	unordered_map<int, int> countmap; //<diff01, index>
	countmap[0] = -1;
	int count = 0, res = 0;
	for (int i = 0; i<nums.size(); i++)
	{
		if (nums[i] == 1)
			count++;
		else
			count--;
		if (countmap.find(count) != countmap.end())
			res = max(res, i - countmap[count]);
		else
			countmap[count] = i;
	}
	return res;
}

int main()
{
	vector<int> nums = { 1,1,0,1,1,0,1,1,0,0 };
	cout << findMaxLength(nums) << endl;
	system("pause");
	return 0;
}
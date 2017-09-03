//	303. Range Sum Query - Immutable
//
//	Given an integer array nums, find the sum of the elements between indices i and j(i ¡Ü j), inclusive.
//
//	Example:
//	Given nums = [-2, 0, 3, -5, 2, -1]
//	sumRange(0, 2) -> 1
//	sumRange(2, 5) -> - 1
//	sumRange(0, 5) -> - 3
//
//	Note :
//	1. You may assume that the array does not change.
//	2. There are many calls to sumRange function.
//
//	Written by Zhanran Tang @ 8/31/2017
//
//	Ideas: Store sum for each index from the first. sumRange(i,j) = sum(j)-sum(i-1)
//	Complexity: O(n) in space, O(1) in time.

#include "Header.h"

using namespace std;

class NumArray {
public:
	vector<int> sumval;
	NumArray(vector<int> nums)
	{
		int sum = 0;
		for (int i = 0; i<nums.size(); i++)
		{
			sum += nums[i];
			sumval.push_back(sum);
		}
	}

	int sumRange(int i, int j)
	{
		if (i == 0)
			return sumval[j];
		return sumval[j] - sumval[i - 1];
	}
};

int main()
{
	vector<int> nums = { -2, 0, 3, -5, 2, -1 };
	NumArray obj = NumArray(nums);
	cout << obj.sumRange(2, 5) << endl;
	system("pause");
	return 0;
}
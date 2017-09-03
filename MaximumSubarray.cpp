//	53. Maximum Subarray
//
//	Find the contiguous subarray within an array(containing at least one number) which has the largest sum.
//
//	For example, given the array[-2, 1, -3, 4, -1, 2, 1, -5, 4],
//	the contiguous subarray[4, -1, 2, 1] has the largest sum = 6.
//
//	Written by Zhanran Tang @ 8/31/2017
//
//	Ideas: DP. OPT(i) = max(OPT(i-1)+val(i),val(i)). Result = max(OPT(i),result)
//	Complexity: O(n) in time, O(1) in space.

#include "Header.h"

using namespace std;

int maxSubArray(vector<int>& nums)
{
	if (nums.empty())
		return 0;
	int maximum = nums[0], last = nums[0];
	for (int i = 1; i<nums.size(); i++)
	{
		last = max(last + nums[i], nums[i]);
		maximum = max(last, maximum);
	}
	return maximum;
}

int main()
{
	vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
	cout << maxSubArray(nums) << endl;
	system("pause");
	return 0;
}
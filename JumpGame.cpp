//	55. Jump Game
//
//	Given an array of non - negative integers, you are initially positioned at the first index of the array.
//
//	Each element in the array represents your maximum jump length at that position.
//
//	Determine if you are able to reach the last index.
//
//	For example :
//	A = [2, 3, 1, 1, 4], return true.
//	A = [3, 2, 1, 0, 4], return false.
//
//	Written by Zhanran Tang @ 5/29/2017
//
//	Ideas: Check from back. Update finish point if it can reach the last index.
//	Complexity: O(n) in time, O(1) in space.

#include <vector>
#include <iostream>

using namespace std;

bool canJump(vector<int>& nums)
{
	int sz = nums.size();
	if (sz <= 1)
		return true;
	if (sz >= 2 && nums[0] == 0)
		return false;
	int finish = sz - 1;
	for (int i = sz - 2; i >= 0; i--)
	{
		if (nums[i] >= finish - i)
			finish = i;
	}
	if (finish == 0)
		return true;
	return false;
}

int main()
{
	vector<int> nums = { 2,3,1,1,4 };
	cout << canJump(nums) << endl;
	system("pause");
	return 0;
}
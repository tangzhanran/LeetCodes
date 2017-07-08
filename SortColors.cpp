//	75. Sort Colors
//
//	Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
//
//	Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
//
//	Note:
//		You are not suppose to use the library's sort function for this problem.
//
//	Written by Zhanran Tang @ 7/6/2017
//
//	Ideas: Dutch flag problem.
//	Complexity: O(n) in time and O(1) in space.

#include "Header.h"

using namespace std;

void sortColors(vector<int>& nums)
{
	int start = 0, cur = 0, end = nums.size() - 1;
	while (cur <= end)
	{
		if (nums[cur] == 0)
		{
			swap(nums[start], nums[cur]);
			start++;
			cur++;
		}
		else if (nums[cur] == 2)
		{
			swap(nums[end], nums[cur]);
			end--;
		}
		else
			cur++;
	}
}

int main()
{
	vector<int> nums = { 0,1,1,2,0,1,2 };
	sortColors(nums);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
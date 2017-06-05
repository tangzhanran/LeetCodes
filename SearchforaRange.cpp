//	34. Search for a Range
//
//	Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.
//
//	Your algorithm's runtime complexity must be in the order of O(log n).
//
//	If the target is not found in the array, return[-1, -1].
//
//	For example,
//		Given[5, 7, 7, 8, 8, 10] and target value 8,
//		return[3, 4].
//
//	Written by Zhanran Tang @ 6/3/2017
//	
//	Ideas: Binary search.
//	Complexity: O(logn) in time, O(1) in space.

#include "Header.h"

using namespace std;

vector<int> findTarget(vector<int>& nums, int start, int end, int target)
{
	vector<int> res(2, -1);
	if (start>end || (start == end && nums[start] != target))
		return res;
	if (start == end && nums[start] == target)
	{
		res[0] = start;
		res[1] = start;
		return res;
	}
	int mid = (start + end) / 2;
	if (nums[mid] > target)
		return findTarget(nums, start, mid - 1, target);
	else if (nums[mid] < target)
		return findTarget(nums, mid + 1, end, target);
	else
	{
		vector<int> leftrange = findTarget(nums, start, mid - 1, target);
		vector<int> rightrange = findTarget(nums, mid + 1, end, target);
		if (leftrange[0] == -1 && rightrange[0] == -1)
		{
			res[0] = mid;
			res[1] = mid;
		}
		else if (leftrange[0] == -1)
		{
			res[0] = mid;
			res[1] = rightrange[1];
		}
		else if (rightrange[0] == -1)
		{
			res[0] = leftrange[0];
			res[1] = mid;
		}
		else
		{
			res[0] = leftrange[0];
			res[1] = rightrange[1];
		}
	}
	return res;
}

vector<int> searchRange(vector<int>& nums, int target)
{
	return findTarget(nums, 0, nums.size() - 1, target);
}

int main()
{
	vector<int> nums = { 1,3 };
	vector<int> range = searchRange(nums, 1);
	cout << "[" << range[0] << "," << range[1] << "]" << endl;
	system("pause");
	return 0;
}
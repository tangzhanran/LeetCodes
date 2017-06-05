//	16. 3Sum Closest
//
//	Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.Return the sum of the three integers.You may assume that each input would have exactly one solution.
//
//	For example, given array S = { -1 2 1 - 4 }, and target = 1.
//	The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//
//	Written by Zhanran Tang @ 6/2/2017
//
//	Ideas: Sort and similar to 3Sum. Record the minimum difference and value.
//	Complexity: O(n^2) in time. O(1) in space.

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int threeSumClosest(vector<int>& nums, int target)
{
	sort(nums.begin(), nums.end());
	int mindiff = INT_MAX;
	int res = target;
	for (int i = 0; i<nums.size() - 2; i++)
	{
		if (i>0 && nums[i] == nums[i - 1])
			continue;
		int maxi = nums.size() - 1, mini = i + 1;
		while (mini < maxi)
		{
			int curval = nums[i] + nums[maxi] + nums[mini];
			int curdiff = abs(target - curval);
			if (curval == target)
				return target;
			else if (curval < target)
				mini++;
			else
				maxi--;
			if (curdiff < mindiff)
			{
				mindiff = curdiff;
				res = curval;
			}
		}
	}
	return res;
}

int main()
{
	vector<int> nums = { -1,2,1,-4 };
	int target = 1;
	cout << threeSumClosest(nums, target) << endl;
	system("pause");
	return 0;
}
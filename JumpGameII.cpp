//	45. Jump Game II
//
//	Given an array of non - negative integers, 
//	you are initially positioned at the first index of the array.
//
//	Each element in the array represents your maximum jump length at that position.
//
//	Your goal is to reach the last index in the minimum number of jumps.
//
//	For example :
//	Given array A = [2, 3, 1, 1, 4]
//
//	The minimum number of jumps to reach the last index is 2. 
//	(Jump 1 step from index 0 to 1, then 3 steps to the last index.)
//
//	Note :
//	You can assume that you can always reach the last index.
//
//	Written by Zhanran Tang @ 10/11/2017
//	
//	Ideas: Keep track the farthest index reached. From current index. Similar to BFS
//	Complexity: O(n) in time, O(1) in space.

#include "Header.h"

using namespace std;

int jump(vector<int>& nums)
{
	int n = nums.size();
	int cur = 0, res = 0, curlvl = 0, nextlvl = 0;
	while (cur < n - 1)
	{
		res++;
		for (; cur <= curlvl; cur++)
		{
			nextlvl = max(nextlvl, cur + nums[cur]);
			if (nextlvl >= n - 1)
				return res;
		}
		curlvl = nextlvl;
	}
	return res;
}
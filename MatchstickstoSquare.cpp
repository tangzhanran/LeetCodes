//	473. Matchsticks to Square
//
//	Remember the story of Little Match Girl ? By now, you know exactly what matchsticks the little match girl has, please find out a way you can make one square by using up all those matchsticks.You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.
//
//	Your input will be several matchsticks the girl has, represented with their stick length.Your output will either be true or false, to represent whether you could make one square using all the matchsticks the little match girl has.
//
//	Example 1 :
//	Input : [1, 1, 2, 2, 2]
//	Output : true
//	Explanation : You can form a square with length 2, one side of the square came two sticks with length 1.
//
//	Example 2 :
//	Input : [3, 3, 3, 3, 4]
//	Output : false
//	Explanation : You cannot find a way to form a square with all the matchsticks.
//
//	Note :
//	The length sum of the given matchsticks is in the range of 0 to 10 ^ 9.
//	The length of the given matchstick array will not exceed 15.
//
//	Written by Zhanran Tang @ 8/24/2017
//
//	Ideas: Using DFS to search result.
//	Complexity: O(4^n) in time, O(1) in space.

#include "Header.h"

using namespace std;

bool dfs(int target, vector<int> edges, vector<int>& nums, int curpos)
{
	if (curpos == nums.size())
	{
		if (edges[0] == target && edges[1] == target && edges[2] == target && edges[3] == target)
			return true;
		return false;
	}
	for (int i = 0; i<4; i++)
	{
		if (edges[i] + nums[curpos] <= target)
		{
			int j = i - 1;
			bool flag = false;
			while (j >= 0)
			{
				if (edges[j] == edges[i])
				{
					flag = true;
					break;
				}
				j--;
			}
			if (flag)
				continue;
			edges[i] += nums[curpos];
			if (dfs(target, edges, nums, curpos + 1))
				return true;
			edges[i] -= nums[curpos];
		}
	}
	return false;
}

bool makesquare(vector<int>& nums)
{
	if (nums.empty())
		return false;
	int sum = 0;
	for (int i = 0; i<nums.size(); i++)
		sum += nums[i];
	if (sum % 4 != 0)
		return false;
	int target = sum / 4;
	sort(nums.begin(), nums.end(), greater<int>());
	return dfs(target, vector<int>(4, 0), nums, 0);
}

int main()
{
	vector<int> nums = { 1,1,2,2,2 };
	cout << makesquare(nums) << endl;
	system("pause");
	return 0;
}
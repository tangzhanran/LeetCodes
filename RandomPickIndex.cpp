//	398. Random Pick Index
//
//	Given an array of integers with possible duplicates, randomly output the index of a given target number.You can assume that the given target number must exist in the array.
//
//	Note:
//	The array size can be very large.Solution that uses too much extra space will not pass the judge.
//
//	Example :
//	int[] nums = new int[] {1, 2, 3, 3, 3};
//	Solution solution = new Solution(nums);
//
//	// pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
//	solution.pick(3);
//
//	// pick(1) should return 0. Since in the array only nums[0] is equal to 1.
//	solution.pick(1);
//
//	Written by Zhanran Tang @ 7/30/2017
//
//	Ideas: Nothing special.
//	Complexity: O(n) in space and time or *O(n) in space O(1) in time with hash* NOT ACCEPTED on OJ

#include "Header.h"

using namespace std;

class Solution
{
private:
	//unordered_map<int,vector<int>> nummap;
	vector<int> num;
public:
	//     Solution(vector<int> nums) 
	//     {
	//         for (int i=0; i<nums.size(); i++)
	//         {
	//             if (nummap.find(nums[i]) == nummap.end())
	//                 nummap.insert(pair<int,vector<int>>(nums[i],vector<int>()));
	//             nummap[nums[i]].push_back(i);
	//         }
	//     }

	//     int pick(int target) 
	//     {
	//         return nummap[target][rand()%nummap[target].size()];
	//     }
	Solution(vector<int> nums)
	{
		num = nums;
	}
	int pick(int target)
	{
		int count = 1, res = 0;
		for (int i = 0; i<num.size(); i++)
		{
			if (num[i] == target)
			{
				if (count == 1)
					res = i;
				else
				{
					if ((rand() % count) == 0)
						res = i;
				}
				count++;
			}
		}
		return res;
	}
};

int main()
{
	srand(time(NULL));
	vector<int> nums = { 1,2,3,3,3 };
	Solution obj = Solution(nums);
	cout << obj.pick(3) << endl;
	system("pause");
	return 0;
}
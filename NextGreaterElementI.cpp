//	496. Next Greater Element I
//
//	You are given two arrays(without duplicates) nums1 and nums2 where nums1¡¯s elements are subset of nums2.
//	Find all the next greater numbers for nums1's elements in the corresponding places of nums2.
//
//	The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2.
//	If it does not exist, output - 1 for this number.
//
//	Example 1:
//	Input: nums1 = [4, 1, 2], nums2 = [1, 3, 4, 2].
//	Output : [-1, 3, -1]
//	Explanation :
//	For number 4 in the first array, you cannot find the next greater number for it in the second array, so output - 1.
//	For number 1 in the first array, the next greater number for it in the second array is 3.
//	For number 2 in the first array, there is no next greater number for it in the second array, so output - 1.
//
//	Example 2 :
//	Input : nums1 = [2, 4], nums2 = [1, 2, 3, 4].
//	Output : [3, -1]
//	Explanation :
//	For number 2 in the first array, the next greater number for it in the second array is 3.
//	For number 4 in the first array, there is no next greater number for it in the second array, so output - 1.
//
//	Note :
//	All elements in nums1 and nums2 are unique.
//	The length of both nums1 and nums2 would not exceed 1000.
//
//	Written by Zhanran Tang @ 8/27/2017
//
//	Ideas: Using stack to keep track on nums, store the first greater in hashmap.
//	Complexity: O(n) in space and time.

#include "Header.h"

using namespace std;

vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums)
{
	vector<int> res;
	if (findNums.empty() || nums.empty())
		return res;
	stack<int> stk;
	unordered_map<int, int> hashmap;
	for (int i = 0; i<nums.size(); i++)
	{
		if (!stk.empty())
		{
			while (!stk.empty() && nums[i]>stk.top())
			{
				hashmap[stk.top()] = nums[i];
				stk.pop();
			}
		}
		stk.push(nums[i]);
	}
	for (int i = 0; i<findNums.size(); i++)
	{
		if (hashmap.find(findNums[i]) == hashmap.end())
			res.push_back(-1);
		else
			res.push_back(hashmap[findNums[i]]);
	}
	return res;
}

int main()
{
	vector<int> findNums = { 4,1,2 };
	vector<int> nums = { 1,3,4,2 };
	vector<int> res = nextGreaterElement(findNums, nums);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}
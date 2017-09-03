//	503. Next Greater Element II
//
//	Given a circular array(the next element of the last element is the first element of the array), print the Next Greater Number for every element.The Next Greater Number of a number x is the first greater number to its traversing - order next in the array, which means you could search circularly to find its next greater number.If it doesn't exist, output -1 for this number.
//
//	Example 1:
//	Input: [1, 2, 1]
//	Output : [2, -1, 2]
//	Explanation : The first 1's next greater number is 2; 
//	The number 2 can't find next greater number; 
//	The second 1's next greater number needs to search circularly, which is also 2.
//
//	Note : The length of given array won't exceed 10000.
//
//	Written by Zhanran Tang @ 8/27/2017
//
//	Ideas: Using stack to store the index of number which has not find next greater yet. 
//		Loop at most 2*n times to find all next greater.
//	Complexity: O(n) in space and time.

#include "Header.h"

using namespace std;

vector<int> nextGreaterElements(vector<int>& nums)
{
	int n = nums.size();
	vector<int> res(n, -1);
	if (nums.empty())
		return res;
	stack<int> stk;
	for (int i = 0; i<2 * n; i++)
	{
		int index = i%n;
		while (!stk.empty() && nums[index]>nums[stk.top()])
		{
			res[stk.top()] = nums[index];
			stk.pop();
		}
		if (i < n)
			stk.push(i);
	}
	return res;
}

int main()
{
	vector<int> nums = { 5,4,3,2,1 };
	vector<int> res = nextGreaterElements(nums);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}
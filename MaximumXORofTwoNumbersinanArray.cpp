//	421. Maximum XOR of Two Numbers in an Array
//
//	Given a non - empty array of numbers, a0, a1, a2, ¡­, an - 1, where 0 ¡Ü ai < 231.
//
//	Find the maximum result of ai XOR aj, where 0 ¡Ü i, j < n.
//
//	Could you do this in O(n) runtime ?
//
//	Example :
//	Input : [3, 10, 5, 25, 2, 8]
//	Output : 28
//	Explanation : The maximum result is 5 ^ 25 = 28.
//
//	Written by Zhanran Tang @ 8/2/2017
//
//	Ideas: For the ith bit, separate the vector into 2 parts. 1 part with ith bit 1, the other 0.
//		For the 2 parts, separate the vector into 2 parts, 1 part with i-1th bit 1, the other 0, that is 4 parts in total.
//		Solve the 00-11 and 01-10 vectors recursively.
//	Complexity: O(31*n). As there are at most 31 level of recursion. Each recursion O(n).

#include "Header.h"

using namespace std;

int XORRecursion(vector<int> vecleft, vector<int> vecright, int bit)
{
	if (vecleft.empty() || vecright.empty() || bit<0)
		return 0;
	vector<int> vecleft0, vecleft1, vecright0, vecright1;
	int mask = pow(2, bit);
	for (int i = 0; i<vecleft.size(); i++)
	{
		if ((mask & vecleft[i]) == 0)
			vecleft0.push_back(vecleft[i]);
		else
			vecleft1.push_back(vecleft[i]);
	}
	for (int i = 0; i<vecright.size(); i++)
	{
		if ((mask & vecright[i]) == 0)
			vecright0.push_back(vecright[i]);
		else
			vecright1.push_back(vecright[i]);
	}
	if ((vecleft0.empty() && vecright0.empty()) || (vecleft1.empty() && vecright1.empty()))
		return XORRecursion(vecleft, vecright, bit - 1);
	int leftres = XORRecursion(vecleft0, vecright1, bit - 1);
	int rightres = XORRecursion(vecleft1, vecright0, bit - 1);
	return mask + max(leftres, rightres);
}
int findMaximumXOR(vector<int>& nums)
{
	if (nums.size() <= 1)
		return 0;
	int maxval = 0;
	for (int i = 0; i<nums.size(); i++)
	{
		if (nums[i] > maxval)
			maxval = nums[i];
	}
	int bit = 0;
	while (maxval > 0)
	{
		maxval /= 2;
		bit++;
	}
	vector<int> left, right;
	int mask = pow(2, bit - 1);
	while (mask>0 && (left.empty() || right.empty()))
	{
		left.clear();
		right.clear();
		for (int i = 0; i<nums.size(); i++)
		{
			if ((mask & nums[i]) == 0)
				left.push_back(nums[i]);
			else
				right.push_back(nums[i]);
		}
		if (left.empty() || right.empty())
		{
			mask /= 2;
			bit--;
		}
	}
	return mask + XORRecursion(left, right, bit - 2);
}

int main()
{
	vector<int> nums = { 4,6,7 };
	cout << findMaximumXOR(nums) << endl;
	system("pause");
	return 0;
}
//	152. Maximum Product Subarray
//
//	Find the contiguous subarray within an array(containing at least one number) which has the largest product.
//
//	For example, given the array[2, 3, -2, 4],
//	the contiguous subarray[2, 3] has the largest product = 6.
//
//	Subscribe to see which companies asked this question.
//
//	Written by Zhanran Tang @ 5/15/2017
//
//	Idea: The problem is actually compare products of at most 2 parts. Start from the front and end separately to compare the maximum.
//	Complexity:	O(n) in time and O(1) in space.

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int maxProduct(vector<int>& nums)
{
	int sz = nums.size();
	if (sz == 0)
		return 0;
	int fproduct = 1, bproduct = 1, res = INT_MIN;
	for (int i = 0; i<sz; i++)
	{
		fproduct *= nums[i];
		bproduct *= nums[sz - i - 1];
		res = max(res, max(fproduct, bproduct));
		if (fproduct == 0)
			fproduct = 1;
		if (bproduct == 0)
			bproduct = 1;
	}
	return res;
}

int main()
{
	int a[] = { 5,-8,1,0,6,7,-4,9,10,7,-3,8 };
	vector<int> nums(a, a+sizeof(a)/sizeof(int));
	cout << maxProduct(nums) << endl;
	system("pause");
	return 0;
}
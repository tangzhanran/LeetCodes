//	31. Next Permutation
//
//	Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//
//	If such arrangement is not possible, it must rearrange it as the lowest possible order(ie, sorted in ascending order).
//
//	The replacement must be in - place, do not allocate extra memory.
//
//	Here are some examples.Inputs are in the left - hand column and its corresponding outputs are in the right - hand column.
//	1, 2, 3 ¡ú 1, 3, 2
//	3, 2, 1 ¡ú 1, 2, 3
//	1, 1, 5 ¡ú 1, 5, 1
//	
//	Written by Zhanran Tang @ 5/25/2017
//
//	Ideas: Find the ascending sequence from the back, swap the first descending value A with the first value greater than A, reverse the ascending sequence.
//	Complexity: O(n) in time. O(1) in space.

#include <vector>
#include <iostream>

using namespace std;

void nextPermutation(vector<int>& nums)
{
	int l = nums.size();
	if (l <= 1)
		return;
	int pivot = l - 1, i = l - 2;
	while (i >= 0)
	{
		if (nums[i] < nums[i + 1])
			break;
		pivot--;
		i--;
	}
	int find = l - 1;
	while (i >= 0 && find >= pivot)
	{
		if (nums[i] < nums[find])
		{
			swap(nums[i], nums[find]);
			break;
		}
		find--;
	}
	reverse(nums.begin() + pivot, nums.end());
}

int main()
{
	vector<int> nums = { 2,3,4,8,4,6,1,6 };
	nextPermutation(nums);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
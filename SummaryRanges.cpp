//	228. Summary Ranges
//
//	Given a sorted integer array without duplicates, return the summary of its ranges.
//
//	For example, given[0, 1, 2, 4, 5, 7], return["0->2", "4->5", "7"].
//
//	Written by Zhanran Tang @ 5/27/2017
//
//	Ideas: Straight forward scan
//	Complexity: O(n) in time O(1) in space

#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> summaryRanges(vector<int>& nums)
{
	vector<string> res;
	int n = nums.size();
	if (n == 0)
		return res;
	int start = 0;
	for (int i = 1; i<n; i++)
	{
		if (nums[i] != nums[i - 1] + 1)
		{
			if (start != i - 1)
				res.push_back(to_string(nums[start]) + "->" + to_string(nums[i - 1]));
			else
				res.push_back(to_string(nums[start]));
			start = i;
		}
	}
	if (start != n - 1)
		res.push_back(to_string(nums[start]) + "->" + to_string(nums[n - 1]));
	else
		res.push_back(to_string(nums[start]));
	return res;
}

int main()
{
	vector<int> nums = { 17,20,21,22,24,25,26,27,30,31,34 };
	vector<string> res = summaryRanges(nums);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}
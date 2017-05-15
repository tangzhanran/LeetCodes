//	179. Largest Number
//
//	Given a list of non negative integers, arrange them such that they form the largest number.
//
//	For example, given[3, 30, 34, 5, 9], the largest formed number is 9534330.
//
//	Note: The result may be very large, so you need to return a string instead of an integer.
//
//	Written by Zhanran Tang @5/9/2017
//
//	Idea: Sort the array by comparing any two merge number
//	Complexity:	O(nlogn) n - size of input vector

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

bool mycompare(string a, string b)
{
	string aplusb = a + b;
	string bplusa = b + a;
	for (int i = 0; i < aplusb.length(); i++)
	{
		if (aplusb[i] < bplusa[i])
			return false;
		if (aplusb[i] > bplusa[i])
			return true;
	}
	return false;
}
string largestNumber(vector<int>& nums)
{
	vector<string> bucket;
	string res = "";
	if (nums.size() == 0)
		return res;
	for (int i = 0; i<nums.size(); i++)
	{
		bucket.push_back(to_string(nums[i]));
	}
	sort(bucket.begin(), bucket.end(), mycompare);
	if (bucket[0] == "0")
		return "0";
	for (int i = 0; i<bucket.size(); i++)
	{
		res += bucket[i];
	}
	return res;
}

int main()
{
	int tmp[] = {121,12};
	vector<int> nums(tmp, tmp+sizeof(tmp)/sizeof(int));
	cout << largestNumber(nums) << endl;
	system("pause");
	return 0;
}
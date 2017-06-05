//373. Find K Pairs with Smallest Sums
//
//You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
//
//	Define a pair(u, v) which consists of one element from the first array and one element from the second array.
//
//	Find the k pairs(u1, v1), (u2, v2) ...(uk, vk) with the smallest sums.
//
//	Example 1:
//		Given nums1 = [1, 7, 11], nums2 = [2, 4, 6], k = 3
//		Return : [1, 2], [1, 4], [1, 6]
//		The first 3 pairs are returned from the sequence :
//		[1, 2], [1, 4], [1, 6], [7, 2], [7, 4], [11, 2], [7, 6], [11, 4], [11, 6]
//
//	Example 2 :
//		Given nums1 = [1, 1, 2], nums2 = [1, 2, 3], k = 2
//		Return : [1, 1], [1, 1]
//		The first 2 pairs are returned from the sequence :
//		[1, 1], [1, 1], [1, 2], [2, 1], [1, 2], [2, 2], [1, 3], [1, 3], [2, 3]
//
//	Example 3 :
//		Given nums1 = [1, 2], nums2 = [3], k = 3
//		Return : [1, 3], [2, 3]
//		All possible pairs are returned from the sequence :
//		[1, 3], [2, 3]
//
//	Written by Zhanran Tang @ 6/1/2017
//
//	Ideas: Using minheap to store values, each time pop the smallest one and insert the next one
//	Complexity: O(klogk) in time, O(k) in space.

#include <queue>
#include <vector>
#include <iostream>

using namespace std;

class mycompare
{
public:
	bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
	{
		if (a.first > b.first)
			return true;
		return false;
	}
};

vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
{
	vector<pair<int, int>> res;
	int n = nums1.size(), m = nums2.size();
	if (n == 0 || m == 0 || k == 0)
		return res;
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, mycompare> minheap;
	int i = 0;
	while (i<n && i<k)
	{
		minheap.push(pair<int, pair<int, int>>(nums1[i] + nums2[0], pair<int, int>(i, 0)));
		i++;
	}
	while (res.size()<k && !minheap.empty())
	{
		pair<int, int> tmp = minheap.top().second;
		minheap.pop();
		int first = tmp.first, second = tmp.second;
		res.push_back(pair<int, int>(nums1[first], nums2[second]));
		if (second != m - 1)
			minheap.push(pair<int, pair<int, int>>(nums1[first] + nums2[second + 1], pair<int, int>(first, second + 1)));
	}
	return res;
}

int main()
{
	vector<int> nums1 = { -10,-4,0,0,6 };
	vector<int> nums2 = { 3,5,6,7,8,100 };
	int k = 10;
	vector<pair<int, int>> res = kSmallestPairs(nums1, nums2, k);
	for (int i = 0; i < res.size(); i++)
		cout << "[" << res[i].first << "," << res[i].second << "]" << " ";
	cout << endl;
	system("pause");
	return 0;
}

//	638. Shopping Offers
//
//	In LeetCode Store, there are some kinds of items to sell.Each item has a price.
//
//	However, there are some special offers, and a special offer consists of one or more different kinds of items with a sale price.
//
//	You are given the each item's price, a set of special offers, and the number we need to buy for each item. The job is to output the lowest price you have to pay for exactly certain items as given, where you could make optimal use of the special offers.
//
//	Each special offer is represented in the form of an array, the last number represents the price you need to pay for this special offer, other numbers represents how many specific items you could get if you buy this offer.
//
//	You could use any of special offers as many times as you want.
//
//	Example 1:
//	Input: [2, 5], [[3, 0, 5], [1, 2, 10]], [3, 2]
//	Output : 14
//	Explanation :
//	There are two kinds of items, A and B.Their prices are $2 and $5 respectively.
//	In special offer 1, you can pay $5 for 3A and 0B
//	In special offer 2, you can pay $10 for 1A and 2B.
//	You need to buy 3A and 2B, so you may pay $10 for 1A and 2B(special offer #2), and $4 for 2A.
//
//	Example 2:
//  Input: [2, 3, 4], [[1, 1, 0, 4], [2, 2, 1, 9]], [1, 2, 1]
//	Output : 11
//	Explanation :
//	The price of A is $2, and $3 for B, $4 for C.
//	You may pay $4 for 1A and 1B, and $9 for 2A, 2B and 1C.
//	You need to buy 1A, 2B and 1C, so you may pay $4 for 1A and 1B(special offer #1), and $3 for 1B, $4 for 1C.
//	You cannot add more items, though only $9 for 2A, 2B and 1C.
//
//	Note :
//	1. There are at most 6 kinds of items, 100 special offers.
//	2. For each item, you need to buy at most 6 of them.
//	3. You are not allowed to buy more items than you want, even if that would lower the overall price.
//
//	Written by Zhanran Tang @ 9/2/2017
//
//	Ideas: DFS with memorsize.
//	Complexity: O(n^2) in time, O(product(needs)) in space. n is the number of offers.

#include "Header.h"

using namespace std;

int offerRecursion(vector<vector<int>>& special, int start, string &needs, vector<int>& price, unordered_map<string, int> &needspay_map)
{
	if (needspay_map.find(needs) != needspay_map.end())
		return needspay_map[needs];
	int pay = 0;
	for (int i = 0; i<needs.length(); i++)
	{
		pay += price[i] * (needs[i] - '0');
	}
	string minneeds;
	for (int i = start; i<special.size(); i++)
	{
		string remains = needs;
		bool take = true;
		for (int j = 0; j<special[i].size() - 1; j++)
		{
			if (special[i][j] >(remains[j] - '0'))
			{
				take = false;
				break;
			}
			remains[j] -= special[i][j];
		}
		if (take)
		{
			int tmppay = 0;
			tmppay += special[i].back();
			tmppay += offerRecursion(special, i, remains, price, needspay_map);
			for (int i = 0; i<remains.length(); i++)
				tmppay += price[i] * (remains[i] - '0');
			if (tmppay < pay)
			{
				pay = tmppay;
				minneeds = remains;
			}
		}
	}
	needs = minneeds;
	needspay_map[needs] = pay;
	return pay;
}

int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs)
{
	string needstr = "";
	for (int i = 0; i<needs.size(); i++)
		needstr += needs[i] + '0';
	unordered_map<string, int> needspay_map;
	return offerRecursion(special, 0, needstr, price, needspay_map);
}

int main()
{
	vector<int> price = { 2,5 };
	vector<vector<int>> special = { { 3,0,5 },{ 1,2,10 } };
	vector<int> needs = { 3,2 };
	cout << shoppingOffers(price, special, needs) << endl;
	system("pause");
	return 0;
}
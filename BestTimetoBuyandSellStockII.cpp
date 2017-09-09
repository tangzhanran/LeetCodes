//	122. Best Time to Buy and Sell Stock II
//
//	Say you have an array for which the ith element is the price of a given stock on day i.
//
//	Design an algorithm to find the maximum profit.
//	You may complete as many transactions as you like(ie, buy one and sell one share of the stock multiple times).
//	However, you may not engage in multiple transactions at the same time(ie, you must sell the stock before you buy again).
//
//	Written by Zhanran Tang @ 9/9/2017
//
//	Ideas: DP solution. OPT(i) is defined as the maximum profit at day i.
//		OPT(i) = max(OPT(i-1),OPT(i-1)+V(i)-V(i-1)), which means do nothing on day i or sell at day i.
//	Complexity: O(n) in time and space. Space can be optimized to O(1).

#include "Header.h"

using namespace std;

int maxProfit(vector<int>& prices)
{
	int res = 0;
	for (int i = 1; i<prices.size(); i++)
	{
		res = max(res, res + prices[i] - prices[i - 1]);
	}
	return res;
}

int main()
{
	vector<int> prices = { 2,6,4,2,1,8,3,4,9,3 };
	cout << maxProfit(prices) << endl;
	system("pause");
	return 0;
}
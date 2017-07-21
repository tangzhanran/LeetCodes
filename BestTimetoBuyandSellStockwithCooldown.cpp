//	309. Best Time to Buy and Sell Stock with Cooldown
//
//	Say you have an array for which the ith element is the price of a given stock on day i.
//
//	Design an algorithm to find the maximum profit.
//	You may complete as many transactions as you like
//	(ie, buy one and sell one share of the stock multiple times) with the following restrictions :
//		1. You may not engage in multiple transactions at the same time(ie, you must sell the stock before you buy again).
//		2. After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
//
//	Example :
//		prices = [1, 2, 3, 0, 2]
//		maxProfit = 3
//		transactions = [buy, sell, cooldown, buy, sell]
//
//	Written by Zhanran Tang @ 7/21/2017
//
//	Idea: DP solution. sell[i] means the profit when selling at day i. keep[i] means the profit when keeping at day i.
//			sell[i] has 2 case: 1. sell at day i-1 then buy on day i-1 and sell at day i. 2. keep at day i-1.
//	Complexity: O(n) in time, O(1) in space.

#include "Header.h"

using namespace std;

int maxProfit(vector<int>& prices)
{
	int n = prices.size();
	int sell = 0, presell = 0, keep = 0, prekeep = 0;
	for (int i = 1; i<n; i++)
	{
		prekeep = keep;
		presell = sell;
		sell = max(presell + prices[i] - prices[i - 1], prekeep);
		keep = max(presell, prekeep);
	}
	return max(sell, keep);
}

int main()
{
	vector<int> prices = { 6,1,6,4,3,0,2 };
	cout << maxProfit(prices) << endl;
	system("pause");
	return 0;
}
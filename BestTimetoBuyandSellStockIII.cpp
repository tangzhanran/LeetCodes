//	123. Best Time to Buy and Sell Stock III
//
//	Say you have an array for which the ith element is the price of a given stock on day i.
//
//	Design an algorithm to find the maximum profit.You may complete at most two transactions.
//
//	Note:
//	You may not engage in multiple transactions at the same time(ie, you must sell the stock before you buy again).
//
//	Written by Zhanran Tang @ 9/9/2017
//
//	Ideas: DP solution. OPT(i,w) is defined as the maximum profit on day i using at most w transaction.
//		OPT(i,w) = OPT(i-1,w), which means do nothing on day i.
//		OPT(i,w) = max(OPT(j,w-1)+V(i)-V(j)) for all j in range [0,i), which can be written as:
//		OPT(i,w) = V(i) + max(OPT(j,w-1)-V(j)) for all j in range [0,i), which means sell at day i.
//		For all w=0 || i=0, OPT(i,w) = 0 because no profit can be made with 0 transaction or on the 1st day.
//	Complexity: O(2n) in time and space.

#include "Header.h"

using namespace std;

int maxProfit(vector<int>& prices)
{
	if (prices.empty())
		return 0;
	int n = prices.size();
	vector<vector<int>> dp(n, vector<int>(3, 0));
	for (int w = 1; w <= 2; w++)
	{
		int tmp = dp[0][w - 1] - prices[0];
		for (int i = 1; i<n; i++)
		{
			tmp = max(tmp, dp[i - 1][w - 1] - prices[i - 1]);
			dp[i][w] = max(dp[i - 1][w], prices[i] + tmp);
		}
	}
	return max(dp[n - 1][1], dp[n - 1][2]);
}

int main()
{
	vector<int> prices = { 2,6,4,2,1,8,3,4,9,3 };
	cout << maxProfit(prices) << endl;
	system("pause");
	return 0;
}
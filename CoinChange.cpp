//	322. Coin Change
//
//	You are given coins of different denominations and a total amount of money amount.Write a function to compute the fewest number of coins that you need to make up that amount.If that amount of money cannot be made up by any combination of the coins, return -1.
//
//	Example 1:
//	coins = [1, 2, 5], amount = 11
//	return 3 (11 = 5 + 5 + 1)
//
//	Example 2 :
//	coins = [2], amount = 3
//	return -1.
//
//	Note :
//		You may assume that you have an infinite number of each kind of coin.
//	
//	Written by Zhanran Tang @ 5/17/2017
//
//	Ideas: DP. OPT(v) = min(OPT(v-coin[0])+1, ..., OPT(v-coin[n])+1)
//	Complexity: O(n*v) in time. O(v) in space. n-coins number v-target amount

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int coinChange(vector<int>& coins, int amount)
{
	if (amount == 0)
		return 0;
	vector<int> opt(amount + 1, amount + 1);
	opt[0] = 0;
	for (int i = 1; i<amount + 1; i++)
	{
		for (int k = 0; k<coins.size(); k++)
		{
			if (i >= coins[k])
			{
				opt[i] = min(opt[i], opt[i - coins[k]] + 1);
			}
		}
	}
	if (opt[amount] == amount + 1)
		return -1;
	return opt[amount];
}

int main()
{
	vector<int> coins = { 1,2,5 };
	int amount = 11;
	cout << coinChange(coins, amount) << endl;
	system("pause");
	return 0;
}
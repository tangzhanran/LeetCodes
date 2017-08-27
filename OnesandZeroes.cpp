//	474. Ones and Zeroes
//
//	In the computer world, use restricted resource you have to generate maximum benefit is what we always want to pursue.
//
//	For now, suppose you are a dominator of m 0s and n 1s respectively.On the other hand, there is an array with strings consisting of only 0s and 1s.
//
//	Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s.Each 0 and 1 can be used at most once.
//
//	Note:
//	The given numbers of 0s and 1s will both not exceed 100
//	The size of given string array won't exceed 600.
//
//	Example 1 :
//	Input : Array = { "10", "0001", "111001", "1", "0" }, m = 5, n = 3
//	Output : 4
//	Explanation : This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are ¡°10, ¡±0001¡±, ¡±1¡±, ¡±0¡±
//
//	Example 2 :
//	Input : Array = { "10", "0", "1" }, m = 1, n = 1
//	Output : 2
//	Explanation : You could form "10", but then you'd have nothing left. Better form "0" and "1".
//
//	Written by Zhanran Tang @ 8/24/2017
//
//	Ideas: 3D 0-1 knapsack problem.
//	Complexity: O(lmn) in time, O(mn) in space. l is the length of input array.

#include "Header.h"

using namespace std;

int findMaxForm(vector<string>& strs, int m, int n)
{
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	for (int i = 0; i<strs.size(); i++)
	{
		int ones = 0, zeros = 0;
		for (int j = 0; j<strs[i].length(); j++)
		{
			if (strs[i][j] == '1')
				ones++;
			else
				zeros++;
		}
		for (int x = m; x >= zeros; x--)
		{
			for (int y = n; y >= ones; y--)
			{
				dp[x][y] = max(dp[x - zeros][y - ones] + 1, dp[x][y]);
			}
		}
	}
	return dp[m][n];
}

int main()
{
	vector<string> strs = { "10", "0001", "111001", "1", "0" };
	cout << findMaxForm(strs, 5, 3) << endl;
	system("pause");
	return 0;
}
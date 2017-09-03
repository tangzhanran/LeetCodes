//	516. Longest Palindromic Subsequence
//
//	Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.
//
//	Example 1:
//	Input: "bbbab"
//	Output: 4
//	One possible longest palindromic subsequence is "bbbb".
//
//	Example 2 :
//	Input: "cbbd"
//	Output: 2
//	One possible longest palindromic subsequence is "bb".
//
//	Written by Zhanran Tang @ 8/28/2017
//	
//	Ideas: DP solution. OPT(i,j) means the longest palindromic subsequence from i to j.
//		If s[i]==[j], OPT(i,j)=OPT(i+1,j-1)+2, else OPT(i,j)=MAX(OPT(i+1,j),OPT(i,j-1))
//	Complexity: O(n^2) in time and space.

#include "Header.h"

using namespace std;

int dpRecursion(vector<vector<int>>&dp, string &s, int i, int j)
{
	if (dp[i][j] == -1)
	{
		if (s[i] == s[j])
			dp[i][j] = dpRecursion(dp, s, i + 1, j - 1) + 2;
		else
			dp[i][j] = max(dpRecursion(dp, s, i + 1, j), dpRecursion(dp, s, i, j - 1));
	}
	return dp[i][j];
}
int longestPalindromeSubseq(string s)
{
	int n = s.length();
	if (n == 0)
		return 0;
	vector<vector<int>> dp(n, vector<int>(n, -1));
	for (int i = 0; i<n; i++)
		dp[i][i] = 1;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<i; j++)
			dp[i][j] = 0;
	}
	return dpRecursion(dp, s, 0, n - 1);
}

int main()
{
	string s = "bbbab";
	cout << longestPalindromeSubseq(s) << endl;
	system("pause");
	return 0;
}
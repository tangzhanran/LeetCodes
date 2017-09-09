//	44. Wildcard Matching
//
//	Implement wildcard pattern matching with support for '?' and '*'.
//
//	'?' Matches any single character.
//	'*' Matches any sequence of characters(including the empty sequence).
//
//	The matching should cover the entire input string(not partial).
//
//	The function prototype should be :
//	bool isMatch(const char *s, const char *p)
//
//	Some examples :
//	isMatch("aa", "a") ¡ú false
//	isMatch("aa", "aa") ¡ú true
//	isMatch("aaa", "aa") ¡ú false
//	isMatch("aa", "*") ¡ú true
//	isMatch("aa", "a*") ¡ú true
//	isMatch("ab", "?*") ¡ú true
//	isMatch("aab", "c*a*b") ¡ú false
//
//	Written by Zhanran Tang @ 9/5/2017
//
//	Ideas: 
//	1. Using DP similar to Regular Expression Matching.
//		OPT(0,0) is true as empty s can be match with empty regex.
//		OPT(i,0) with i>0 is false as s cannot be match with empty regex.
//		OPT(0,j) with j>0 is the same as OPT(0,j-1)
//		OPT(i,j) with i,j>0 is:
//		1. OPT(i,j)=OPT(i-1,j-1) if s[i-1]==p[j-1] or p[j-1]=='?'
//		2. When p[j-1]=='*': 
//			OPT(i,j) = OPT(i,j-1) which means a* is repeated 0 times.
//			OPT(i,j) = OPT(i,j-1) || OPT(i-1,j-1) || OPT(i-1,j)
//				which means: * is used for 0 characters, 1, and multiple.
//		3. Otherwise OPT(i,j) is false.
//	2. Using backtracking.
//		Use i to track s and j to track p. 
//			1. When matches,  i++ and j++
//			2. When p[j] is *, then record current i and j then j++ only, which means do not match s[i] with this * first.
//			3. When s[i] and p[j] does not match, if there exsist some * has not been used for matching, goes back and match.
//			4. If all star has been used for maximum matching and s[i] and p[j] does not match, return false.
//	Complexity: 
//		1. O(m*n) in time and space. m,n is length of s and p.
//		2. O(m*n) in time, O(1) in space.

#include "Header.h"

using namespace std;

#define METHOD 1

#if METHOD==1
bool isMatch(string s, string p)
{
	int m = s.length(), n = p.length();
	vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
	dp[0][0] = true;
	for (int i = 1; i <= n; i++)
	{
		if (p[i - 1] == '*')
			dp[0][i] = dp[0][i - 1];
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
				dp[i][j] = dp[i - 1][j - 1];
			else
			{
				if (p[j - 1] == '*')
					dp[i][j] = dp[i][j - 1] || dp[i - 1][j - 1] || dp[i - 1][j];
			}
		}
	}
	return dp[m][n];
}
#elif METHOD == 2
bool isMatch(string s, string p)
{
	int m = s.length(), n = p.length();
	int i = 0, j = 0, firstnotselect = -1, firststar = -1;
	while (i < m)
	{
		if (j<n && (s[i] == p[j] || p[j] == '?'))
		{
			i++;
			j++;
		}
		else
		{
			if (j<n && p[j] == '*')
			{
				firststar = j;
				firstnotselect = i;
				j++;
			}
			else
			{
				if (firststar != -1)
				{
					i = firstnotselect + 1;
					j = firststar + 1;
					firstnotselect++;
				}
				else
					return false;
			}
		}
	}
	while (j<n && p[j] == '*')
		j++;
	return j == n;
}
#endif // METHOD==1

int main()
{
	string s = "abefcdgiescdfimde";
	string p = "ab*cd?i*de";
	cout << isMatch(s, p) << endl;
	system("pause");
	return 0;
}
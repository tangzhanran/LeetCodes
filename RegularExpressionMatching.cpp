//	10. Regular Expression Matching
//
//	Implement regular expression matching with support for '.' and '*'.
//
//	'.' Matches any single character.
//	'*' Matches zero or more of the preceding element.
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
//	isMatch("aa", "a*") ¡ú true
//	isMatch("aa", ".*") ¡ú true
//	isMatch("ab", ".*") ¡ú true
//	isMatch("aab", "c*a*b") ¡ú true
//
//	Written by Zhanran Tang @ 9/3/2017
//
//	Ideas: Using DP. OPT(i,j) is defined as whether s[0~i-1] can be matched with p[0~j-1].
//		OPT(0,0) is true as empty s can be match with empty regex.
//		OPT(i,0) with i>0 is false as s cannot be match with empty regex.
//		OPT(0,j) with j>0 is true when p[j-1] is '*' and dp[i][j-2] is also true.
//		OPT(i,j) with i,j>0 is:
//		1. OPT(i,j)=OPT(i-1,j-1) if s[i-1]==p[j-1] or p[j-1]=='.'
//		2. When p[j-1]=='*':
//			2.1 OPT(i,j) = OPT(i,j-2) if p[j-2]!=s[i-1], which means a* is repeated 0 times.
//			2.2 OPT(i,j) = OPT(i,j-2) || OPT(i,j-1) || OPT(i-1,j) if p[j-2]==s[i-1] or p[j-2]=='.',
//				which means: a* is repeated 0 times, 1 times, multiple times.
//	Complexity: O(m*n) in time and space. m,n is length of s and p.

#include "Header.h"

using namespace std;

bool isMatch(string s, string p)
{
	int m = s.length(), n = p.length();
	vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
	dp[0][0] = true;
	for (int j = 2; j <= n; j++)
	{
		if (p[j - 1] == '*' && dp[0][j - 2])
			dp[0][j] = true;
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
				dp[i][j] = dp[i - 1][j - 1];
			else if (p[j - 1] == '*')
			{
				if (p[j - 2] != s[i - 1])
					dp[i][j] = dp[i][j - 2];
				if (p[j - 2] == s[i - 1] || p[j - 2] == '.')
					dp[i][j] = dp[i][j - 2] || dp[i][j - 1] || dp[i - 1][j];
			}
		}
	}
	return dp[m][n];
}

int main()
{
	string s = "aab";
	string p = "c*a*b";
	cout << isMatch(s, p) << endl;
	system("pause");
	return 0;
}
//	115. Distinct Subsequences
//
//	Given a string S and a string T, count the number of distinct subsequences of S which equals T.
//
//	A subsequence of a string is a new string which is formed from the original string by deleting some(can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
//
//	Here is an example :
//	S = "rabbbit", T = "rabbit"
//
//	Return 3.
//
//	Written by Zhanran Tang @ 9/9/2017
//
//	Ideas: Using DP. OPT(i,j) is defined as number of subsequence in s[0~i-1] equals to t[0~j-1] 
//		if s[i-1]==t[j-1] and i==j, then OPT(i,j) = OPT(i-1,j-1), which means s[i-1] is in the target subsequence.
//		if s[i-1]==t[j-1] and i!=j, then OPT(i,j) = OPT(i-1,j-1) + OPT(i-1,j), which means s[i-1] may or may not in the target subsequence.
//		if s[i-1]!=t[j-1] and i==j, then OPT(i,j) = 0. Because s and t are of same length but with at least 1 letter varies.
//		if s[i-1]!=t[j-1] and i!=j, then OPT(i,j) = OPT(i-1,j), which means s[i-1] is not in the target subsequence.
//	Complexity: O(mn) in time and space. space can be optimized to O(n). m, n is the length of s and t.

#include "Header.h"

using namespace std;

int numDistinct(string s, string t)
{
	int m = s.length(), n = t.length();
	vector<int> predp(n + 1, 0);
	vector<int> curdp(n + 1, 0);
	predp[0] = 1;
	curdp[0] = 1;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n&&j <= i; j++)
		{
			if (s[i - 1] == t[j - 1])
			{
				if (i == j)
					curdp[j] = predp[j - 1];
				else
					curdp[j] = predp[j] + predp[j - 1];
			}
			else
			{
				if (i == j)
					curdp[j] = 0;
				else
					curdp[j] = predp[j];
			}
		}
		predp = curdp;
	}
	return predp.back();
}

int main()
{
	string s1 = "aacaacca";
	string s2 = "ca";
	cout << numDistinct(s1, s2) << endl;
	system("pause");
	return 0;
}
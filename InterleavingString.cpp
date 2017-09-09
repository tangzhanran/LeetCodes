//	97. Interleaving String
//
//	Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//
//	For example,
//	Given:
//	s1 = "aabcc",
//	s2 = "dbbca",
//
//	When s3 = "aadbbcbcac", return true.
//	When s3 = "aadbbbaccc", return false.
//
//	Written by Zhanran Tang @ 9/8/2017
//	
//	Ideas: Do recusively or DP. m, n is the length of s1 and s2.
//		For recursion:
//			if s1[i]==s3[k], then try s1[i+1] with s3[k+1] recursively.
//			if s2[j]==s3[k], then try s2[j+1] with s3[k+1] recursively.
//			Note: same i,j may appears multiple times in different order.
//				So to improve speed, use a 2D vector to store whether s1[0~i]+s2[0~j] can form s3[0~i+j].
//		For DP:
//			OPT(i,j) is defined as whether s1[0~i-1] and s2[0~j-1] can form s3[i+j-1].
//			If both s1[i-1] and s[j-1]==s3[i+j-1], OPT(i,j) = OPT(i-1,j) || OPT(i,j-1);
//			If s1[i-1]==s3[i+j-1] only, OPT(i,j) = OPT(i-1,j);
//			If s2[j-1]==s3[i+j-1] only, OPT(i,j) = OPT(i,j-1);
//			else OPT(i,j) = false;
//			Note: space can be optimized to O(min(m,n)).
//	Complexity: 
//		Recursion: O(2(m+n)) in time, O(m*n) in space.
//		DP: O(m*n) in time, O(min(m,n)) in space.

#include "Header.h"

using namespace std;

#define DP 0

#if DP==0
bool helper(const string &s1, const string &s2, const string &s3, int i, int j, int k, vector<vector<int>> &record)
{
	if (i == s1.length() && j == s2.length() && k == s3.length())
	{
		record[i][j] = 1;
		return true;
	}
	if (record[i][j] != -1)
		return record[i][j];
	if (s1[i] == s3[k])
	{
		if (helper(s1, s2, s3, i + 1, j, k + 1, record))
		{
			record[i][j] = 1;
			return true;
		}
	}
	if (s2[j] == s3[k])
	{
		if (helper(s1, s2, s3, i, j + 1, k + 1, record))
		{
			record[i][j] = 1;
			return true;
		}
	}
	record[i][j] = 0;
	return false;
}
bool isInterleave(string s1, string s2, string s3)
{
	if (s1.length() + s2.length() != s3.length())
		return false;
	vector<vector<int>> record(s1.length() + 1, vector<int>(s2.length() + 1, -1));
	return helper(s1, s2, s3, 0, 0, 0, record);
}
#elif DP == 1
bool isInterleave(string s1, string s2, string s3)
{
	int m = s1.length(), n = s2.length();
	if (m + n != s3.length())
		return false;
	vector<bool> predp(n + 1, false);
	vector<bool> curdp(n + 1, false);
	predp[0] = true;
	for (int i = 1; i <= n; i++)
	{
		predp[i] = predp[i - 1] && (s2[i - 1] == s3[i - 1]);
	}
	for (int i = 1; i <= m; i++)
	{
		curdp[0] = predp[0] && (s1[i - 1] == s3[i - 1]);
		for (int j = 1; j <= n; j++)
		{
			if (s1[i - 1] == s3[i + j - 1] && s2[j - 1] == s3[i + j - 1])
				curdp[j] = curdp[j - 1] || predp[j];
			else if (s1[i - 1] == s3[i + j - 1])
				curdp[j] = predp[j];
			else if (s2[j - 1] == s3[i + j - 1])
				curdp[j] = curdp[j - 1];
			else
				curdp[j] = false;
		}
		predp = curdp;
	}
	return predp[n];
}
#endif // DP==0

int main()
{
	string s1 = "aabd";
	string s2 = "abdc";
	string s3 = "aabdbadc";
	cout << isInterleave(s1, s2, s3) << endl;
	system("pause");
	return 0;
}
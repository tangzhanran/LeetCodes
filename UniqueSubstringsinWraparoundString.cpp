//	467. Unique Substrings in Wraparound String
//
//	Consider the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so s will look like this: "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
//
//	Now we have another string p.Your job is to find out how many unique non - empty substrings of p are present in s.In particular, your input is the string p and you need to output the number of different non - empty substrings of p in the string s.
//
//	Note : p consists of only lowercase English letters and the size of p might be over 10000.
//
//	Example 1 :
//	Input : "a"
//	Output : 1
//	Explanation : Only the substring "a" of string "a" is in the string s.
//
//	Example 2:
//	Input: "cac"
//	Output : 2
//	Explanation : There are two substrings "a", "c" of string "cac" in the string s.
//
//	Example 3 :
//	Input : "zab"
//	Output : 6
//	Explanation : There are six substrings "z", "a", "b", "za", "ab", "zab" of string "zab" in the string s.
//
//	Written by Zhanran Tang @ 8/23/2017
//
//	Ideas: DP solution. Store the longest substring end with each letter, then sum them up.
//	Complexity: O(n) in time, O(1) in space.

#include "Header.h"

using namespace std;

int findSubstringInWraproundString(string p)
{
	if (p.length() == 0)
		return 0;
	vector<int> dp(26, 0); //length of substring end with 26 letters
	dp[p[0] - 'a'] = 1;
	int start = 0;
	for (int i = 1; i<p.length(); i++)
	{
		int pos = p[i] - 'a';
		if (!(p[i] == p[i - 1] + 1 || (p[i] == 'a' && p[i - 1] == 'z')))
			start = i;
		dp[pos] = max(dp[pos], i - start + 1);
	}
	int sum = 0;
	for (int i = 0; i<dp.size(); i++)
		sum += dp[i];
	return sum;
}

int main()
{
	string p = "cac";
	cout << findSubstringInWraproundString(p) << endl;
	system("pause");
	return 0;
}
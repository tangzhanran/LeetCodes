//	76. Minimum Window Substring
//
//	Given a string S and a string T, 
//	find the minimum window in S which will contain all the characters in T in complexity O(n).
//
//	For example,
//	S = "ADOBECODEBANC"
//	T = "ABC"
//	Minimum window is "BANC".
//
//	Note:
//	If there is no such window in S that covers all characters in T, return the empty string "".
//	If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
//
//	Written by Zhanran Tang @ 10/22/2017
//
//	Ideas: Find a window covers all letters in T then shrink the window.
//	Complexity: O(2*n) in time. O(1) in space.

#include "Header.h"

using namespace std;

string minWindow(string s, string t)
{
	int l = t.length();
	unordered_map<char, int> dict;
	for (int i = 0; i<l; i++)
	{
		dict[t[i]]++;
	}
	string res = "";
	int start = 0, cur = 0, count = 0;
	unordered_map<char, int> window;
	while (cur < s.length())
	{
		if (dict.find(s[cur]) != dict.end())
		{
			window[s[cur]]++;
			if (window[s[cur]] <= dict[s[cur]])
				count++;
		}
		if (count == l)
		{
			while (dict.find(s[start]) == dict.end() || window[s[start]]>dict[s[start]])
			{
				window[s[start]]--;
				start++;
			}
			if (res == "" || cur - start + 1<res.length())
				res = s.substr(start, cur - start + 1);
		}
		cur++;
	}
	return res;
}
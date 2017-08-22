//	395. Longest Substring with At Least K Repeating Characters
//
//	Find the length of the longest substring T of a given string(consists of lowercase letters only) such that every character in T appears no less than k times.
//
//	Example 1:
//	Input:
//	s = "aaabb", k = 3
//	Output :
//	3
//	The longest substring is "aaa", as 'a' is repeated 3 times.
//
//	Example 2 :
//	Input :
//	s = "ababbc", k = 2
//	Output :
//	5
//	The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
//
//	Written by Zhanran Tang @ 7/30/2017
//
//	Ideas:
//		1. Count the appearance time for each letter. Find the first one i appears less then k times. 
//			Split the string at i into two parts, solve 2 parts recursively.
//		2. Count the appearance time for each letter. Find the first one i appears less then k times.
//			Solve the left part recursively. Then find the next one j appears less then k times. Repeat this iteratively.
//	Complexity: O(1) in space.
//		1. O(n^2) in time. At most O(n) times recursion and each recursion in O(n) time.
//		2. O(n) in time. At most 26 times recursion and each recursion in O(n) time.

#include "Header.h"

using namespace std;

#define METHOD 1

#if METHOD == 1
int longestSubstring(string s, int k)
{
	if (s.length() < k)
		return 0;
	vector<int> countvec(26, 0);
	for (int i = 0; i<s.length(); i++)
	{
		countvec[s[i] - 'a']++;
	}
	int breakpos = s.length();
	for (int i = 0; i<s.length(); i++)
	{
		if (countvec[s[i] - 'a']>0 && countvec[s[i] - 'a']<k)
		{
			breakpos = i;
			break;
		}
	}
	if (breakpos == s.length())
		return breakpos;
	int left = longestSubstring(s.substr(0, breakpos), k);
	int right = longestSubstring(s.substr(breakpos + 1), k);
	return max(left, right);
}
#elif METHOD == 2
int longestSubstring(string s, int k)
{
	if (s.length() < k)
		return 0;
	vector<int> countvec(26, 0);
	for (int i = 0; i<s.length(); i++)
	{
		countvec[s[i] - 'a']++;
	}
	int start = 0, result = 0;
	while (start <= s.length() - k)
	{
		int breakpos = s.length();
		for (int i = start; i<s.length(); i++)
		{
			if (countvec[s[i] - 'a']>0 && countvec[s[i] - 'a']<k)
			{
				breakpos = i;
				break;
			}
		}
		if (start == 0 && breakpos == s.length())
			return breakpos - start;
		int left = longestSubstring(s.substr(start, breakpos - start), k);
		result = max(left, result);
		start = breakpos + 1;
	}
	return result;
}
#endif // METHOD==1

int main()
{
	string str = "aabcabb";
	cout << longestSubstring(str, 3) << endl;
	system("pause");
	return 0;
}
//	3. Longest Substring Without Repeating Characters
//
//	Given a string, find the length of the longest substring without repeating characters.
//
//	Examples:
//
//	Given "abcabcbb", the answer is "abc", which the length is 3.
//
//	Given "bbbbb", the answer is "b", with the length of 1.
//
//	Given "pwwkew", the answer is "wke", with the length of 3. 
//
//	Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
//
//	Written by Zhanran Tang @ 9/21/2017
//
//	Ideas: Using hash table to store the character's last position and 2 pointers to track.
//		When duplicate, first pointers goes to the next pos of the dup char.
//		When not duplicate, insert new pair to hash table.
//	Complexity: O(n) in time and space.

#include "Header.h"

using namespace std;

int lengthOfLongestSubstring(string s)
{
	int n = s.length();
	unordered_map<char, int> charindex;
	int i = 0, j = 0;
	int res = 0;
	while (j < n)
	{
		if (charindex.find(s[j]) != charindex.end())
		{
			i = max(i, charindex[s[j]] + 1);
		}
		charindex[s[j]] = j;
		j++;
		res = max(res, j - i);
	}
	return res;
}

int main()
{
	string s = "abba";
	cout << lengthOfLongestSubstring(s) << endl;
	system("pause");
	return 0;
}
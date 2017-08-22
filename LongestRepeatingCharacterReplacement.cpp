//	424. Longest Repeating Character Replacement
//
//	Given a string that consists of only uppercase English letters, you can replace any letter in the string with another letter at most k times.Find the length of a longest substring containing all repeating letters you can get after performing the above operations.
//
//	Note:
//	Both the string's length and k will not exceed 104.
//
//	Example 1 :
//		Input :
//		s = "ABAB", k = 2
//		Output :
//		4
//	Explanation :
//		Replace the two 'A's with two 'B's or vice versa.
//
//	Example 2 :
//		Input :
//		s = "AABABBA", k = 1
//		Output :
//		4
//	Explanation :
//	Replace the one 'A' in the middle with 'B' and form "AABBBBA".
//	The substring "BBBB" has the longest repeating letters, which is 4.
//
//	Written by Zhanran Tang @ 8/21/2017
//
//	Ideas: keep the longest substring, 
//			in which the length of the substring minus the number of the most frequent letter is not greater than k
//	Complexity: O(n) in time, O(1) in space.

#include "Header.h"

using namespace std;

int characterReplacement(string s, int k)
{
	vector<int> alpha(26, 0);
	int maxcnt = 0, start = 0, res = 0;
	for (int i = 0; i<s.length(); i++)
	{
		alpha[s[i] - 'A']++;
		maxcnt = max(maxcnt, alpha[s[i] - 'A']);
		if (i - start - maxcnt + 1 > k)
		{
			alpha[s[start] - 'A']--;
			for (int j = 0; j<26; j++)
				maxcnt = max(maxcnt, alpha[j]);
			start++;
		}
		res = max(res, i - start + 1);
	}
	return res;
}

int main()
{
	string s = "ABAB";
	cout << characterReplacement(s, 2) << endl;
	system("pause");
	return 0;
}
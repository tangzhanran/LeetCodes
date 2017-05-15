//	5. Longest Palindromic Substring
//
//	Given a string s, find the longest palindromic substring in s.You may assume that the maximum length of s is 1000.
//
//	Example:
//	Input: "babad"
//
//	Output : "bab"
//
//	Note : "aba" is also a valid answer.
//
//	Example :
//	Input : "cbbd"
//
//	Output : "bb"
//
//	Written by Zhanran Tang @ 5/14/2017
//
//	Idea:	Using Dynamic Programing
//	Complexity:	O(n^2)	n - length of the input string

#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<vector<bool>> palidrome;

string longestPalindrome(string s)
{
	int l = s.length();
	if (l == 0)
		return s;
	string res = "";
	palidrome = vector<vector<bool>>(l, vector<bool>(l, false));
	for (int i = l - 1; i >= 0; i--)
	{
		for (int j = i; j < l; j++)
		{
			if ((i == j) || (s[i] == s[j]) && ((j - i == 1) || palidrome[i + 1][j - 1]))
			{
				palidrome[i][j] = true;
				if (j - i + 1 > res.length())
					res = s.substr(i, j - i + 1);
			}
		}
	}
	return res;
}

int main()
{
	string s = "babad";
	cout << longestPalindrome(s) << endl;
	system("pause");
	return 0;
}
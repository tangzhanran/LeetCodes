//	87. Scramble String
//
//	Given a string s1, we may represent it as a binary tree by partitioning it to two non - empty substrings recursively.
//
//	Below is one possible representation of s1 = "great":
//		great
//		 / \
//		gr eat
//	   / \ / \
//	  g  r e  at
//			  / \
//			 a   t
//	To scramble the string, we may choose any non - leaf node and swap its two children.
//	For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
//		rgeat
//		 / \
//		rg eat
//	   / \ / \
//	  r  g e  at
//			 / \
//			a   t
//	We say that "rgeat" is a scrambled string of "great".
//
//	Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
//		rgtae
//		 / \
//		rg tae
//	   / \  / \
//	  r  g ta  e
//		   / \
//		  t   a
//	We say that "rgtae" is a scrambled string of "great".
//
//	Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
//
//	Written by Zhanran Tang @ 9/7/2017
//
//	Ideas: Do recursively. 
//		For every s1 and s2, try£º
//			1. s1[0~i]&s2[0~i] and s1[i+1~end]&s2[i+1~end]
//			2. s1[0~i]&s2[end-i+1~end] and s1[i+1~end]&s2[0~end-i]
//		If 1 or 2 is true, then return true. If all i no true, then false.
//	Complexity: exponential in time, O(1) in space.

#include "Header.h"

using namespace std;

bool isScramble(string s1, string s2)
{
	if (s1 == s2)
		return true;
	int n = s1.length();
	if (s2.length() != n)
		return false;
	vector<int> letters(26, 0);
	for (int i = 0; i<n; i++)
	{
		letters[s1[i] - 'a']++;
		letters[s2[i] - 'a']--;
	}
	for (int i = 0; i<26; i++)
	{
		if (letters[i] != 0)
			return false;
	}
	for (int i = 1; i<n; i++)
	{
		if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
			return true;
		if (isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i)))
			return true;
	}
	return false;
}

int main()
{
	string s1 = "great", s2 = "rgtae";
	cout << isScramble(s1, s2) << endl;
	system("pause");
	return 0;
}
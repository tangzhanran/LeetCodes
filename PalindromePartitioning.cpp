//	131. Palindrome Partitioning
//
//	Given a string s, partition s such that every substring of the partition is a palindrome.
//
//	Return all possible palindrome partitioning of s.
//
//	For example, given s = "aab",
//	Return
//	[
//		["aa", "b"],
//		["a", "a", "b"]
//	]
//
//	Written by Zhanran Tang @ 7/12/2017
//
//	Ideas: Backtracking.
//	Complexity: Polynomial in time.

#include "Header.h"

using namespace std;

bool isPalindrome(string s)
{
	int i = 0, j = s.length() - 1;
	while (i <= j)
	{
		if (s[i] != s[j])
			return false;
		i++;
		j--;
	}
	return true;
}
void partitionRecursion(vector<vector<string>>&res, vector<string> &cur, string &s, int start)
{
	if (start >= s.length())
		res.push_back(cur);
	else
	{
		for (int i = start; i<s.length(); i++)
		{
			string str = s.substr(start, i - start + 1);
			if (isPalindrome(str))
			{
				cur.push_back(str);
				partitionRecursion(res, cur, s, i + 1);
				cur.pop_back();
			}
		}
	}
}
vector<vector<string>> partition(string s)
{
	vector<vector<string>> res;
	vector<string> cur;
	partitionRecursion(res, cur, s, 0);
	return res;
}

int main()
{
	string s = "aabba";
	vector<vector<string>> res = partition(s);
	for (int i = 0; i < res.size(); i++)
	{
		cout << "[ ";
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << "]" << endl;
	}
	system("pause");
	return 0;
}
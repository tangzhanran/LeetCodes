//	522. Longest Uncommon Subsequence II
//
//	Given a list of strings, you need to find the longest uncommon subsequence among them.The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.
//
//	A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements.Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.
//
//	The input will be a list of strings, and the output needs to be the length of the longest uncommon subsequence.If the longest uncommon subsequence doesn't exist, return -1.
//
//	Example 1:
//		Input: "aba", "cdc", "eae"
//		Output : 3
//
//	Note :
//		All the given strings' lengths will not exceed 10.
//		The length of the given list will be in the range of[2, 50].
//	
//	Written by Zhanran Tang @ 5/30/2017
//
//	Ideas: Find the longest non-duplicate string.
//	Complexity: O(n^2) in time. O(n) in space.

#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;

bool isSubstr(string sstr, string lstr)
{
	if (sstr.length() > lstr.length())
		return false;
	int scnt = 0;
	for (int i = 0; i<lstr.length(); i++)
	{
		if (sstr[scnt] == lstr[i])
			scnt++;
	}
	if (scnt == sstr.length())
		return true;
	return false;
}
bool mycompare(string a, string b)
{
	if (a.length() > b.length())
		return true;
	else if (a.length() < b.length())
		return false;
	else
	{
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] > b[i])
				return true;
			if (a[i] < b[i])
				return false;
		}
	}
	return false;
}
int findLUSlength(vector<string>& strs)
{
	unordered_set<string> strset;
	sort(strs.begin(), strs.end(), mycompare);
	string longest = "";
	for (int i = 0; i<strs.size(); i++)
	{
		int l = strs[i].length();
		if (strset.find(strs[i]) == strset.end())
		{
			bool substrflag = false;
			for (auto itr = strset.begin(); itr != strset.end(); itr++)
			{
				if (isSubstr(strs[i], *itr))
				{
					if (longest == strs[i])
						longest = "";
					substrflag = true;
					break;
				}
			}
			if (longest=="" && !substrflag)
			{
				longest = strs[i];
				strset.insert(strs[i]);
			}
		}
		else
		{
			if (longest == strs[i])
				longest = "";
		}
	}
	if (longest == "")
		return -1;
	return longest.length();
}

int main()
{
	vector<string> strs = { "aabbcc", "aabbcc","c","e","aabbcd" };
	cout <<findLUSlength(strs) << endl;
	system("pause");
	return 0;
}
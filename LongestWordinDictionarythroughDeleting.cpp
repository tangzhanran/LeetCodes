//	524. Longest Word in Dictionary through Deleting
//
//	Given a string and a string dictionary, 
//	find the longest string in the dictionary that can be formed by deleting some characters of the given string.
//	If there are more than one possible results, return the longest word with the smallest lexicographical order.
//	If there is no possible result, return the empty string.
//
//	Example 1:
//	Input: s = "abpcplea", d = ["ale", "apple", "monkey", "plea"]
//	Output: "apple"
//
//	Example 2:
//	Input: s = "abpcplea", d = ["a", "b", "c"]
//	Output: "a"
//
//	Note :
//	1. All the strings in the input will only contain lower - case letters.
//	2. The size of the dictionary won't exceed 1,000.
//	3. The length of all the strings in the input won't exceed 1,000.
//
//	Written by Zhanran Tang @ 8/28/2017
//
//	Ideas: For each string in d, find it in s.
//	Complexity: l is length of s, n is length of d, m is max length of string in d
//		O(mnlongn+nl) in time with sorting, O(nl) without sorting. O(1) in space.

#include "Header.h"

using namespace std;

bool mycompare(string s1, string s2)
{
	if (s1.length() > s2.length())
		return true;
	if (s1.length() < s2.length())
		return false;
	for (int i = 0; i<s1.length(); i++)
	{
		if (s1[i] < s2[i])
			return true;
		else if (s1[i] > s2[i])
			return false;
	}
	return true;
}
string findLongestWord(string s, vector<string>& d)
{
	//sort(d.begin(),d.end(),mycompare);
	string res = "";
	for (int i = 0; i<d.size(); i++)
	{
		if (d[i].length() > s.length())
			continue;
		int j = 0, k = 0;
		while (j<s.length())
		{
			if (s[j] == d[i][k])
				k++;
			j++;
		}
		if (k == d[i].length())
		{
			if ((d[i].length()>res.length()) || (d[i].length() == res.length() && d[i]<res))
				res = d[i];
		}
		// if (k == d[i].length())
		//     return d[i];               
	}
	return res;
}

int main()
{
	string s = "abpcplea";
	vector<string> d = { "ale","apple","monkey","plea" };
	cout << findLongestWord(s, d) << endl;
	system("pause");
	return 0;
}
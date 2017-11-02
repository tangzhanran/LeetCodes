//	14. Longest Common Prefix
//
//	Write a function to find the longest common prefix string amongst an array of strings.
//
//	Written by Zhanran Tang @ 9/27/2017
//
//	Ideas:
//		1. Straight forward compare each string
//		2. Sort the strings, then compare only the first and last one.
//	Complexity: O(1) in space.
//		1. O(n*l) in time. 
//		2. O(nlogn+l) in time.
//		n is the number of strings, l is the average length of the strings.

#include "Header.h"

using namespace std;

#define METHOD 1

#if METHOD == 1
string longestCommonPrefix(vector<string>& strs)
{
	if (strs.empty())
		return "";
	string prefix = strs[0];
	for (int i = 1; i<strs.size(); i++)
	{
		int m = 0, n = 0;
		while (m<prefix.length() && n<strs[i].length())
		{
			if (prefix[m] != strs[i][n])
			{
				prefix = prefix.substr(0, m);
				break;
			}
			m++;
			n++;
		}
		if (n == strs[i].length())
			prefix = strs[i];
	}
	return prefix;
}
#elif
 string longestCommonPrefix(vector<string>& strs) 
 {
     if (strs.empty())
         return "";
     if (strs.size() == 1)
         return strs[0];
     sort(strs.begin(), strs.end());
     string prefix = "";
     string last = strs.back();
     for (int i=0; i<strs[0].length(); i++)
     {
         if (strs[0][i] == last[i])
             prefix += last[i];
         else
             break;
     }
     return prefix;
 }
#endif // METHOD == 1
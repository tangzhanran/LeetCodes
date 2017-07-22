//	318. Maximum Product of Word Lengths
//
//	Given a string array words, 
//	find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters.
//	You may assume that each word will contain only lower case letters.If no such two words exist, return 0.
//
//	Example 1:
//	Given["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
//	Return 16
//	The two words can be "abcw", "xtfn".
//
//	Example 2 :
//	Given["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
//	Return 4
//	The two words can be "ab", "cd".
//
//	Example 3 :
//	Given["a", "aa", "aaa", "aaaa"]
//	Return 0
//	No such pair of words.
//
//	Written by Zhanran Tang @ 7/21/2017
//
//	Ideas:
//		1. Brute Force.
//		2. Change string to 26 bit to represent the letters. Compare bits to find non-common words.
//	Complexity: l is the max length of the string in vector.
//		1. O((n^2)*l) in time, O(l) in space. 
//		2. O(n^2+nl) in time, O(n) in space.

#include "Header.h"

using namespace std;

#define METHOD 2

#if METHOD == 1
int maxProduct(vector<string>& words)
{
	int res = 0;
	for (int i = 0; i<words.size(); i++)
	{
		unordered_set<char> wordset;
		int ilength = words[i].length();
		for (int j = 0; j<ilength; j++)
		{
			wordset.insert(words[i][j]);
		}
		for (int j = i + 1; j<words.size(); j++)
		{
			bool common = false;
			int jlength = words[j].length();
			for (int k = 0; k<jlength; k++)
			{
				if (wordset.find(words[j][k]) != wordset.end())
				{
					common = true;
					break;
				}
			}
			if (!common)
				res = max(res, ilength*jlength);
		}
	}
	return res;
}
#elif METHOD == 2
int maxProduct(vector<string>& words)
{
	int res = 0;
	unordered_map<int, int> maskmap;
	for (int i = 0; i<words.size(); i++)
	{
		int mask = 0;
		for (int j = 0; j<words[i].length(); j++)
		{
			int bit = 1 << (words[i][j] - 'a');
			mask = mask | bit;
		}
		maskmap[mask] = max(maskmap[mask], (int)words[i].length());
	}
	for (auto itri = maskmap.begin(); itri != maskmap.end(); itri++)
	{
		for (auto itrj = maskmap.begin(); itrj != maskmap.end(); itrj++)
		{
			if (((*itri).first & (*itrj).first) == 0)
				res = max(res, (*itri).second * (*itrj).second);
		}
	}
	return res;
}
#endif // METHOD == 1

int main()
{
	vector<string> words = { "abcw","baz","foo","bar","xtfn","abcdef" };
	cout << maxProduct(words) << endl;
	system("pause");
	return 0;
}
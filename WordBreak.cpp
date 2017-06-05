//	139. Word Break
//
//	Given a non - empty string s and a dictionary wordDict containing a list of non - empty words, determine if s can be segmented into a space - separated sequence of one or more dictionary words.You may assume the dictionary does not contain duplicate words.
//
//	For example, given
//	s = "leetcode",
//	dict = ["leet", "code"].
//
//	Return true because "leetcode" can be segmented as "leet code".
//
//	Written by Zhanran Tang @ 5/28/2017
//
//	Ideas: DP. OPT(i) is defined as if str[0-i] is in the dictionary.
//	Complexity: O(n^2) in time. O(n) in space.

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict)
{
	unordered_set<string> dictionary;
	vector<int> truePos;
	vector<bool> opt(s.length() + 1, false);
	opt[0] = true;
	truePos.push_back(0);
	for (int i = 0; i<wordDict.size(); i++)
		dictionary.insert(wordDict[i]);
	for (int i = 1; i <= s.length(); i++)
	{
		for (int j = 0; j<truePos.size(); j++)
		{
			if (dictionary.find(s.substr(truePos[j], i - truePos[j])) != dictionary.end())
			{
				opt[i] = true;
				truePos.push_back(i);
				break;
			}
		}
	}
	return opt.back();
}

int main()
{
	string s = "leetcode";
	vector<string> wordDict = { "leet", "code" };
	cout << wordBreak(s, wordDict) << endl;
	system("pause");
	return 0;
}
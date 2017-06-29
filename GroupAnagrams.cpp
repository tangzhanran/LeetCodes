//	49. Group Anagrams
//
//	Given an array of strings, group anagrams together.
//
//	For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
//	Return :
//	[
//		["ate", "eat", "tea"],
//		["nat", "tan"],
//		["bat"]
//	]
//	Note: All inputs will be in lower - case.
//
//	Written by Zhanran Tang @ 6/29/2017
//
//	Ideas: Using Hashmap
//	Complexity: O(nklogk) in time. n is the size of input vector, k is the length of each string in the vector.

#include "Header.h"

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
	unordered_map<string, vector<string>> resmap;
	for (int i = 0; i<strs.size(); i++)
	{
		string str = strs[i];
		sort(str.begin(), str.end());
		resmap[str].push_back(strs[i]);
	}
	vector<vector<string>> res;
	for (auto mapitr = resmap.begin(); mapitr != resmap.end(); mapitr++)
	{
		res.push_back(mapitr->second);
	}
	return res;
}

int main()
{
	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<vector<string>> res = groupAnagrams(strs);
	cout << "[" << endl;
	for (int i = 0; i < res.size(); i++)
	{
		cout << "  [ ";
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << "]" << endl;
	}
	cout << "]" << endl;
	system("pause");
	return 0;
}

//	187. Repeated DNA Sequences
//
//	All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG".When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
//
//	Write a function to find all the 10 - letter - long sequences(substrings) that occur more than once in a DNA molecule.
//
//	For example,
//		Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
//		Return:
//		["AAAAACCCCC", "CCCCCAAAAA"].
//
//	Written by Zhanran Tang @ 6/1/2017
//
//	Ideas: Using hashset
//	Complexity: O(n) in time, O(n) in space.

#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

vector<string> findRepeatedDnaSequences(string s)
{
	vector<string> res;
	if (s.length() <= 10)
		return res;
	unordered_set<string> explored;
	unordered_set<string> duplicate;
	for (int i = 0; i<s.length() - 9; i++)
	{
		string str = s.substr(i, 10);
		if (explored.find(str) != explored.end())
		{
			if (duplicate.find(str) == duplicate.end())
			{
				res.push_back(str);
				duplicate.insert(str);
			}
		}
		else
			explored.insert(str);
	}
	return res;
}

int main()
{
	string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	vector<string> res = findRepeatedDnaSequences(s);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}
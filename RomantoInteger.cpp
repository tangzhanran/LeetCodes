//	13. Roman to Integer
//
//	Given a roman numeral, convert it to an integer.
//
//	Input is guaranteed to be within the range from 1 to 3999.
//	
//	Written by Zhanran Tang @ 9/27/2017
//
//	Ideas: Straight forward.
//	Complexity: O(n) in time, O(1) in space.

#include "Header.h"

using namespace std;

int romanToInt(string s)
{
	if (s.empty())
		return 0;
	unordered_map<char, int> romanTable;
	romanTable['I'] = 1;
	romanTable['V'] = 5;
	romanTable['X'] = 10;
	romanTable['L'] = 50;
	romanTable['C'] = 100;
	romanTable['D'] = 500;
	romanTable['M'] = 1000;
	int res = romanTable[s[0]];
	for (int i = 1; i<s.length(); i++)
	{
		if (romanTable[s[i]] > romanTable[s[i - 1]])
		{
			res -= romanTable[s[i - 1]];
			res += romanTable[s[i]] - romanTable[s[i - 1]];
		}
		else
		{
			res += romanTable[s[i]];
		}
	}
	return res;
}
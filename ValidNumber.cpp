//	65. Valid Number
//
//	Validate if a given string is numeric.
//
//	Some examples :
//	"0" = > true
//	" 0.1 " = > true
//	"abc" = > false
//	"1 a" = > false
//	"2e10" = > true
//	Note: It is intended for the problem statement to be ambiguous.
//		You should gather all requirements up front before implementing one.
//
//	Written by Zhanran Tang @ 10/17/2017
//
//	Ideas: Using DFA.
//	Complexity: O(n) in time, O(1) in space.

#include "Header.h"

using namespace std;

bool isNumber(string s)
{
	unordered_map<char, int> indexmap;
	vector<vector<int>> dfa;
	unordered_set<int> endstate;
	// Initial DFA model
	indexmap.insert(pair<char, int>('+', 0));
	indexmap.insert(pair<char, int>('-', 0));
	indexmap.insert(pair<char, int>('.', 2));
	indexmap.insert(pair<char, int>('e', 3));
	indexmap.insert(pair<char, int>(' ', 4));
	for (int i = 0; i <= 9; i++)
		indexmap.insert(pair<char, int>(i + '0', 1));
	dfa = vector<vector<int>>(9, vector<int>(5, -1));
	dfa[0][0] = 1;
	dfa[0][1] = 2;
	dfa[0][2] = 3;
	dfa[0][4] = 0;
	dfa[1][1] = 2;
	dfa[1][2] = 3;
	dfa[2][1] = 2;
	dfa[2][2] = 4;
	dfa[2][3] = 5;
	dfa[2][4] = 8;
	dfa[3][1] = 4;
	dfa[4][1] = 4;
	dfa[4][3] = 5;
	dfa[4][4] = 8;
	dfa[5][0] = 6;
	dfa[5][1] = 7;
	dfa[6][1] = 7;
	dfa[7][1] = 7;
	dfa[7][4] = 8;
	dfa[8][4] = 8;
	endstate.insert(2);
	endstate.insert(4);
	endstate.insert(7);
	endstate.insert(8);

	// start check validation
	int curstate = 0;
	for (int i = 0; i<s.length(); i++)
	{
		if (indexmap.find(s[i]) == indexmap.end())
			return false;
		int colindex = indexmap[s[i]];
		if (colindex == -1)
			return false;
		curstate = dfa[curstate][colindex];
		if (curstate == -1)
			return false;
	}
	if (endstate.find(curstate) == endstate.end())
		return false;
	return true;
}
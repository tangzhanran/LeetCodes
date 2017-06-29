//	17. Letter Combinations of a Phone Number
//
//	Given a digit string, return all possible letter combinations that the number could represent.
//
//	A mapping of digit to letters(just like on the telephone buttons) is given below.
//
//	Input:Digit string "23"
//	Output : ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//	Note :
//		Although the above answer is in lexicographical order, your answer could be in any order you want.
//
//	Written by Zhanran Tang @ 6/27/2017
//
//	Ideas: Do recursively.
//	Complexity: O(1) in space, O(4^n) in time.

#include "Header.h"

using namespace std;

vector<vector<char>> letterTable = { { 'a','b','c' },{ 'd','e','f' },{ 'g','h','i' },{ 'j','k','l' },{ 'm','n','o' },{ 'p','q','r','s' },{ 't','u','v' },{ 'w','x','y','z' } };

vector<string> recursive(string digits)
{
	vector<string> res;
	if (digits.size() <= 0)
	{
		res.push_back("");
		return res;
	}
	vector<char> letters = letterTable[digits[0] - '2'];
	vector<string> next = recursive(digits.substr(1));
	for (int i = 0; i<letters.size(); i++)
	{
		for (int j = 0; j<next.size(); j++)
			res.push_back(letters[i] + next[j]);
	}
	return res;
}

vector<string> letterCombinations(string digits)
{
	if (digits.length() == 0)
		return vector<string>();
	for (int i = 0; i<digits.length(); i++)
	{
		if (digits[i]>'9' || digits[i]<'2')
			return vector<string>();
	}
	return recursive(digits);
}

int main()
{
	vector<string> res = letterCombinations("239");
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
	system("pause");
	return 0;
}
//	32. Longest Valid Parentheses
//
//	Given a string containing just the characters '(' and ')', find the length of the longest valid(well - formed) parentheses substring.
//
//	For "(()", the longest valid parentheses substring is "()", which has length = 2.
//
//	Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
//
//	Written by Zhanran Tang @ 9/4/2017
//
//	Ideas: Using stack to keep the index of the parentheses. When a pair appear, make maxlength be max(maxlength,curindex-topindex).
//	Complexity: O(n) in time and space.

#include "Header.h"

using namespace std;

int longestValidParentheses(string s)
{
	stack<int> stk;
	int res = 0;
	for (int i = 0; i<s.length(); i++)
	{
		if (!stk.empty() && s[i] == ')' && s[stk.top()] == '(')
		{
			int tmp = -1;
			stk.pop();
			if (!stk.empty())
				tmp = stk.top();
			res = max(res, i - tmp);
		}
		else
			stk.push(i);
	}
	return res;
}

int main()
{
	string s = ")()())()()(";
	cout << longestValidParentheses(s) << endl;
	system("pause");
	return 0;
}
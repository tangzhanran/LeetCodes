//	20. Valid Parentheses
//
//	Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//	The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
//
//	Written by Zhanran Tang @ 9/2/2017
//
//	Ideas: Using stack
//	Complexity: O(n) in time and space.

#include "Header.h"

using namespace std;

bool isValid(string s)
{
	if (s.size() % 2 != 0)
		return false;
	stack<char> parentheses;
	for (int i = 0; i<s.size(); i++)
	{
		if (parentheses.empty())
		{
			if (s[i] == ')' || s[i] == ']' || s[i] == '}')
				return false;
			else
				parentheses.push(s[i]);
		}
		else
		{
			if (s[i] == ')')
			{
				if (parentheses.top() == '(')
					parentheses.pop();
				else
					return false;
			}
			else if (s[i] == '}')
			{
				if (parentheses.top() == '{')
					parentheses.pop();
				else
					return false;
			}
			else if (s[i] == ']')
			{
				if (parentheses.top() == '[')
					parentheses.pop();
				else
					return false;
			}
			else
				parentheses.push(s[i]);
		}
	}
	if (parentheses.empty())
		return true;
	return false;
}
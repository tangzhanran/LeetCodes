//	150. Evaluate Reverse Polish Notation
//
//	Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//
//	Valid operators are + , -, *, / .Each operand may be an integer or another expression.
//
//	Some examples :
//		["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//		["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
//
//	Written by Zhanran Tang @ 5/19/2017
//
//	Ideas: Using stack to solve.
//	Complexity: O(n) in time and space. n-the length of input tokens.

#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int StringtoInt(string s)
{
	int res = 0;
	for (int i = 0; i<s.length(); i++)
	{
		res = res * 10 + s[i] - 48;
	}
	return res;
}
int evalRPN(vector<string>& tokens)
{
	stack<int> stk;
	for (int i = 0; i<tokens.size(); i++)
	{
		string cur = tokens[i];
		if (cur.length()>1 || (cur[0] >= '0' && cur[0] <= '9'))
		{
			if (cur[0] == '-')
			{
				cur = cur.substr(1);
				stk.push(-StringtoInt(cur));
			}
			else
				stk.push(StringtoInt(cur));
		}
		else
		{
			if (stk.size() >= 2)
			{
				int second = stk.top();
				stk.pop();
				int first = stk.top();
				stk.pop();
				if (cur == "+")
					stk.push(first + second);
				else if (cur == "-")
					stk.push(first - second);
				else if (cur == "*")
					stk.push(first*second);
				else
					stk.push(first / second);
			}
		}
	}
	return stk.top();
}

int main()
{
	vector<string> tokens = { "18" };
	cout << evalRPN(tokens) << endl;
	system("pause");
	return 0;
}
//	227. Basic Calculator II
//
//	Implement a basic calculator to evaluate a simple expression string.
//
//	The expression string contains only non - negative integers, +, -, *, / operators and empty spaces.
//	The integer division should truncate toward zero.
//
//	You may assume that the given expression is always valid.
//
//	Some examples :
//		"3+2*2" = 7
//		" 3/2 " = 1
//		" 3+5 / 2 " = 5
//	Note : Do not use the eval built - in library function.
//	
//	Written by Zhanran Tang @ 5/27/2017
//
//	Ideas: Using Stack.
//	Complexity: O(n) in time and space.
//	Note: Can be done without stack.

#include <string>
#include <stack>
#include <iostream>

using namespace std;

int getNum(string &s, int &i)
{
	int res = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + s[i] - 48;
		i++;
	}
	return res;
}
int calculate(string s)
{
	stack<int> numbers;
	stack<char> operaters;
	int i = 0;
	while (i < s.length())
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			int res = getNum(s, i);
			if (!operaters.empty() && (operaters.top() == '*' || operaters.top() == '/'))
			{
				if (operaters.top() == '*')
					res = numbers.top() * res;
				else
					res = numbers.top() / res;
				numbers.pop();
				numbers.push(res);
				operaters.pop();
			}
			else
				numbers.push(res);
		}
		else
		{
			if (s[i] != ' ')
				operaters.push(s[i]);
			i++;
		}
	}
	int res = 0;
	while (!operaters.empty())
	{
		int a = numbers.top();
		numbers.pop();
		if (operaters.top() == '-')
			a = -a;
		res += a;
		operaters.pop();
	}
	res += numbers.top();
	return res;
}

int main()
{
	string s = " 3+5 / 2 ";
	cout << calculate(s) << endl;
	system("pause");
	return 0;
}
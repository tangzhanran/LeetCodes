//	22. Generate Parentheses
//
//	Given n pairs of parentheses, write a function to generate all combinations of well - formed parentheses.
//
//	For example, given n = 3, a solution set is :
//	[
//		"((()))",
//		"(()())",
//		"(())()",
//		"()(())",
//		"()()()"
//	]
//
//	Written by Zhanran Tang @ 6/27/2017
//
//	Ideas: Do recursively. Count how many parentheses left on both sides.
//	Complexity: Exponential in time.

#include "Header.h"

using namespace std;

vector<string> res;

void recursion(string str, int left, int right, int n)
{
	if (right > left)
		return;
	if (left == n && right == n)
	{
		res.push_back(str);
		return;
	}
	if (left < n)
		recursion(str + "(", left + 1, right, n);
	if (right < n)
		recursion(str + ")", left, right + 1, n);
}

vector<string> generateParenthesis(int n)
{
	recursion("", 0, 0, n);
	return res;
}

int main()
{
	vector<string> res = generateParenthesis(100);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
	system("pause");
	return 0;
}
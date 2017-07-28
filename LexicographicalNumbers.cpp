//	386. Lexicographical Numbers
//
//	Given an integer n, return 1 - n in lexicographical order.
//
//	For example, given 13, return: [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9].
//
//	Please optimize your algorithm to use less time and space.The input size may be as large as 5,000,000.
//
//	Written by Zhanran Tang @ 7/27/2017
//
//	Ideas: If 10*cur number is valid, cur=cur*10. Otherwise cur++. If cur>n or cur carry next bit, cur/=10.
//	Complexity: O(n) in time, O(1) in space.

#include "Header.h"

using namespace std;

vector<int> lexicalOrder(int n)
{
	vector<int> res;
	int cur = 1;
	while (res.size() < n)
	{
		res.push_back(cur);
		if (cur * 10 <= n)
			cur *= 10;
		else
		{
			if (cur >= n)
				cur /= 10;
			cur++;
			while (cur % 10 == 0)
				cur /= 10;
		}
	}
	return res;
}

int main()
{
	vector<int> res = lexicalOrder(237);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	system("pause");
	return 0;
}
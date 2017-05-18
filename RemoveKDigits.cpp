//	402. Remove K Digits
//
//	Given a non - negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.
//
//	Note:
//		The length of num is less than 10002 and will be ¡Ý k.
//		The given num does not contain any leading zero.
//
//	Example 1 :
//	Input : num = "1432219", k = 3
//	Output : "1219"
//	Explanation : Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
//
//	Example 2 :
//	Input : num = "10200", k = 1
//	Output : "200"
//	Explanation : Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
//
//	Example 3 :
//	Input : num = "10", k = 2
//	Output : "0"
//	Explanation : Remove all the digits from the number and it is left with nothing which is 0.
//
//	Written by Zhanran Tang @ 5/17/2017
//
//	Ideas: Loop K times, each time find the last number in a non-decreasing series from the beginning and remove it.
//	Complexity: O(k*n) in time and O(1) in space k - input parameter, n - the length of the string
//			or O(n) in time and O(n) in space using stack.

#include <string>
#include <stack>
#include <iostream>

using namespace std;

#define SAVETIME 0

#if SAVETIME  
	string removeKdigits(string num, int k)
	{
		if (num.length() == k)
			return "0";
		int n = k;
		stack<char> final;
		for (int i = 0; i<num.length(); i++)
		{
			while (!final.empty() && k>0 && final.top()>num[i])
			{
				final.pop();
				k--;
			}
			final.push(num[i]);
		}
		string res = "";
		while (!final.empty())
		{
			res += final.top();
			final.pop();
		}
		reverse(res.begin(), res.end());
		int start = 0;
		while (res[start] == '0')
			start++;
		res = res.substr(start, num.length() - n);
		if (res.length() == 0)
			return "0";
		else
			return res;
	}
#else
	string removeKdigits(string num, int k)
	{
		if (num.length() == k)
			return "0";
		while (k > 0)
		{
			int cur = 0;
			while (cur < num.length())
			{
				if (cur == 0)
				{
					if (num[cur] > num[cur + 1])
					{
						num.erase(num.begin() + cur);
						k--;
						break;
					}
				}
				else if (cur == num.length() - 1)
				{
					if (num[cur] >= num[cur - 1])
					{
						num.erase(num.begin() + cur);
						k--;
						break;
					}
				}
				else
				{
					if (num[cur] > num[cur + 1] && num[cur] >= num[cur - 1])
					{
						num.erase(num.begin() + cur);
						k--;
						break;
					}
				}
				cur++;
			}
		}
		int start = 0;
		while (num[start] == '0')
			start++;
		num = num.substr(start, num.length() - start);
		if (num.length() == 0)
			return "0";
		return num;
	}
#endif

int main()
{
	string num = "1432219";
	int k = 3;
	cout << removeKdigits(num, k) << endl;
	system("pause");
	return 0;
}
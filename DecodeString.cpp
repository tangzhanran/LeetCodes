//	394. Decode String
//
//	Given an encoded string, return it's decoded string.
//
//	The encoding rule is : k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times.Note that k is guaranteed to be a positive integer.
//
//	You may assume that the input string is always valid; No extra white spaces, square brackets are well - formed, etc.
//
//	Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k.For example, there won't be input like 3a or 2[4].
//
//	Examples:
//	s = "3[a]2[bc]", return "aaabcbc".
//	s = "3[a2[c]]", return "accaccacc".
//	s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
//
//	Written by Zhanran Tang @ 7/29/2017
//
//	Ideas: 1. Using stack to do interatively. 2. Doing recursively.
//	Complexity: O(n) in time. 1. O(n) in space. 2. O(1) in space.

#include "Header.h"

using namespace std;

#define ITERA 0

#if ITERA
string decodeString(string s)
{
	stack<string> stk;
	int i = 0;
	while (i < s.length())
	{
		string num = "";
		string str = "";
		while (isdigit(s[i]))
		{
			num += s[i];
			i++;
		}
		while (i<s.length() && !isdigit(s[i]) && s[i] != ']')
		{
			if (s[i] != '[')
				str += s[i];
			i++;
		}
		if (num != "")
		{
			stk.push(num);
			if (str != "")
				stk.push(str);
		}
		else
		{
			if (str != "")
			{
				if (!stk.empty() && !isdigit(stk.top()[0]))
				{
					string tmp = stk.top() + str;
					stk.pop();
					stk.push(tmp);
				}
				else
					stk.push(str);
			}
		}
		if (s[i] == ']')
		{
			string topstr = stk.top();
			stk.pop();
			int repeat = 1;
			if (!stk.empty() && isdigit(stk.top()[0]))
			{
				repeat = stoi(stk.top());
				stk.pop();
			}
			string newstr = "";
			for (int k = 0; k<repeat; k++)
				newstr += topstr;
			if (!stk.empty() && !isdigit(stk.top()[0]))
			{
				newstr = stk.top() + newstr;
				stk.pop();
			}
			stk.push(newstr);
			i++;
		}
	}
	string res = "";
	while (!stk.empty())
	{
		res = stk.top() + res;
		stk.pop();
	}
	return res;
}
#else
string decodeRecursion(const string &s, int &i)
{
	string res = "";
	while (i<s.length() && s[i] != ']')
	{
		if (i<s.length() && !isdigit(s[i]))
		{
			res += s[i];
			i++;
		}
		if (i<s.length() && isdigit(s[i]))
		{
			int count = 0;
			while (i<s.length() && isdigit(s[i]))
			{
				count = count * 10 + s[i] - '0';
				i++;
			}
			i++;
			string nextstr = decodeRecursion(s, i);
			i++;
			while (count > 0)
			{
				res += nextstr;
				count--;
			}
		}
	}
	return res;
}

string decodeString(string s)
{
	int i = 0;
	return decodeRecursion(s, i);
}
#endif // ITERA

int main()
{
	string str = "sd2[f2[e]g]i";
	cout << decodeString(str) << endl;
	system("pause");
	return 0;
}
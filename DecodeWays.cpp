//	91. Decode Ways
//	A message containing letters from A - Z is being encoded to numbers using the following mapping :
//
//	'A' -> 1
//	'B' -> 2
//	...
//	'Z' -> 26
//	Given an encoded message containing digits, determine the total number of ways to decode it.
//
//	For example,
//	Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
//
//	The number of ways decoding "12" is 2.
//
//	Written by Zhanran Tang @5/3/2017
//
//	Idea:	Store the number of single digit at the end and the total number of ways.
//			If the new char can be merge, single = total && total += single
//			If can not merge, single = total
//	Complexity:	O(n) n - string length

#include <string>
#include <iostream>

using namespace std;

int numDecodings(string s)
{
	if (s == "")
		return 0;
	int single = 1, total = 1;
	int last = s[0] - 48;
	if (last == 0)
		return 0;
	for (int i = 1; i<s.length(); i++)
	{
		int newnum = s[i] - 48;
		int join = last * 10 + newnum;
		if (last != 0 && join <= 26 && newnum>0)
		{
			int old_single = single;
			single = total;
			total = total + old_single;
		}
		else if (last != 0 && join <= 26 && newnum == 0)
		{
			total = single;
			single = 0;
		}
		else
		{
			if (newnum == 0)
				return 0;
			single = total;
		}
		last = newnum;
	}
	return total;
}

int main()
{
	string s = "123456789120";
	cout << numDecodings(s) << endl;
	system("pause");
	return 0;
}
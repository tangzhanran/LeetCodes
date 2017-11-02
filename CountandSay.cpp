//	38. Count and Say
//
//	The count - and-say sequence is the sequence of integers with the first five terms as following :
//
//	1.     1
//	2.     11
//	3.     21
//	4.     1211
//	5.     111221
//	1 is read off as "one 1" or 11.
//	11 is read off as "two 1s" or 21.
//	21 is read off as "one 2, then one 1" or 1211.
//	Given an integer n, generate the nth term of the count - and-say sequence.
//
//	Note: Each term of the sequence of integers will be represented as a string.
//
//	Example 1 :
//	Input : 1
//	Output : "1"
//
//	Example 2 :
//	Input : 4
//	Output : "1211"
//
//	Written by Zhanran Tang 10/3/2017
//	
//	Ideas: Simple store last string and count.
//	Complexity: O(n*l) in time, O(1) in space. l is the average length of each string.

#include "Header.h"

using namespace std;

string countAndSay(int n)
{
	string prev = "1";
	for (int i = 2; i <= n; i++)
	{
		string cur = "";
		int count = 1;
		for (int j = 1; j<prev.length(); j++)
		{
			if (prev[j] == prev[j - 1])
				count++;
			else
			{
				cur += to_string(count);
				cur.push_back(prev[j - 1]);
				count = 1;
			}
		}
		cur += to_string(count);
		cur.push_back(prev.back());
		prev = cur;
	}
	return prev;
}
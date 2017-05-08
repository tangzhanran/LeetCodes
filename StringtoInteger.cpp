//	8. String to Integer (atoi)
//	Implement atoi to convert a string to an integer.
//
//	Written by Zhanran Tang @ 5/1/2017
//
//	Idea:	Straight forward. 
//			Valid string ignore starting spaces and start with + or - or number
//			Number ends when encounters non-number characters.
//	Complexity: O(n) n - length of str

#include <iostream>

using namespace std;

int myAtoi(string str)
{
	unsigned int res = 0;
	bool neg = false, num_start = false;
	int l = str.length();
	for (int i = 0; i<l; i++)
	{
		if (!num_start && str[i] != '+' && str[i] != '-' && !('0' <= str[i] && '9' >= str[i]) && str[i] != ' ')
			return 0;
		if (str[i] == '-' && i<l - 1)
		{
			if ('0' <= str[i + 1] && '9' >= str[i + 1])
				neg = true;
			else
				return 0;
		}
		else if (str[i] == '+' && i<l - 1)
		{
			if (!('0' <= str[i + 1] && '9' >= str[i + 1]))
				return 0;
		}
		else if ('0' <= str[i] && '9' >= str[i])
		{
			num_start = true;
			if (!neg)
			{
				if (res >((2147483647 - (str[i] - 48)) / 10.0))
					return 2147483647;
			}
			else
			{
				if (res > ((2147483648 - (str[i] - 48)) / 10.0))
					return -2147483648;
			}
			res = 10 * res + (str[i] - 48);
		}
		else if (num_start)
			break;
	}
	if (neg)
		return -res;
	else
		return res;
}

int main()
{
	string test_string = "     +445878895";
	cout << myAtoi(test_string) << endl;
	system("pause");
	return 0;
}
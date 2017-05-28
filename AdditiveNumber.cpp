//	306. Additive Number
//
//	Additive number is a string whose digits can form additive sequence.
//
//	A valid additive sequence should contain at least three numbers.Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.
//
//	For example :
//	"112358" is an additive number because the digits can form an additive sequence : 1, 1, 2, 3, 5, 8.
//	1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
//
//	"199100199" is also an additive number, the additive sequence is : 1, 99, 100, 199.
//	1 + 99 = 100, 99 + 100 = 199
//
//	Note : Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.
//
//	Given a string containing only digits '0' - '9', write a function to determine if it's an additive number.
//
//	Written by Zhanran Tang @ 5/22/2017
//
//	Ideas: Check straight forward recursively
//	Complexity: Ploynomial in input length n.

#include <string>
#include <iostream>

using namespace std;

string calNext(string s1, string s2)
{
	string res = "";
	int i = s1.length() - 1, j = s2.length() - 1;
	int carry = 0;
	while (i >= 0 || j >= 0 || carry != 0)
	{
		int digit = carry;
		carry = 0;
		if (i >= 0)
		{
			digit += s1[i] - 48;
			i--;
		}
		if (j >= 0)
		{
			digit += s2[j] - 48;
			j--;
		}
		if (digit >= 10)
			carry = digit / 10;
		res += 48 + digit % 10;
	}
	reverse(res.begin(), res.end());
	return res;
}

bool checkAdditvie(string first, string second, string remain)
{
	if ((first.length() > 1 && first[0] == '0') || (second.length() > 1 && second[0] == '0'))
		return false;
	string next = calNext(first, second);
	if (next.length() > remain.length() || remain.substr(0,next.length()) != next)
		return false;
	if (next == remain)
		return true;
	return checkAdditvie(second, next, remain.substr(next.length()));
}

bool isAdditiveNumber(string num)
{
	for (int i = 0; i <= num.length() / 2; i++)
	{
		for (int j = i + 1; j < num.length(); j++)
		{
			if (checkAdditvie(num.substr(0, i + 1), num.substr(i + 1, j - i), num.substr(j + 1)))
				return true;
		}
	}
	return false;
}

int main()
{
	string num = "101";
	cout << isAdditiveNumber(num) << endl;
	system("pause");
	return 0;
}
//	43. Multiply Strings
//
//	Given two non - negative integers num1 and num2 represented as strings, return the product of num1 and num2.
//
//	Note:
//		The length of both num1 and num2 is < 110.
//		Both num1 and num2 contains only digits 0 - 9.
//		Both num1 and num2 does not contain any leading zero.
//		You must not use any built - in BigInteger library or convert the inputs to integer directly.
//
//	Written by Zhanran Tang @ 5/19/2017
//
//	Ideas: Straight forward multiply 2 num. Using a vector to store each digit. 
//	Complexity:	O(m*n) in time, O(m+n) in space. m,n-the length of the 2 input string.

#include <vector>
#include <string>
#include <iostream>

using namespace std;

string multiply(string num1, string num2)
{
	int l1 = num1.length();
	int l2 = num2.length();
	vector<int> resvec(l1 + l2, 0);
	int k = l1 + l2 - 1;
	for (int i = l1 - 1; i >= 0; i--)
	{
		int m = k;
		for (int j = l2 - 1; j >= 0; j--)
		{
			int res = 0;
			res = (num2[j] - 48)*(num1[i] - 48);
			resvec[m] += res;
			m--;
		}
		k--;
	}
	int carry = 0;
	for (int i = l1 + l2 - 1; i >= 0; i--)
	{
		int tmp = resvec[i];
		tmp += carry;
		carry = 0;
		if (tmp >= 10)
		{
			carry = tmp / 10;
			tmp = tmp % 10;
		}
		resvec[i] = tmp;
	}
	string str = "";
	int start = 0;
	while (resvec[start] == 0)
		start++;
	for (int i = start; i<resvec.size(); i++)
		str += resvec[i] + 48;
	if (str == "")
		return "0";
	return str;
}

int main()
{
	string num1 = "128";
	string num2 = "134";
	cout << multiply(num1, num2) << endl;
	system("pause");
	return 0;
}
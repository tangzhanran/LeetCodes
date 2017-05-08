//	468. Validate IP Address
//
//	Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.
//	IPv4 addresses are canonically represented in dot - decimal notation, which consists of four decimal numbers, 
//	each ranging from 0 to 255, separated by dots("."), e.g., 172.16.254.1;
//	Besides, leading zeros in the IPv4 is invalid.For example, the address 172.16.254.01 is invalid.
//
//	IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits.The groups are separated by colons(":").
//	For example, the address 2001:0db8 : 85a3 : 0000 : 0000 : 8a2e : 0370 : 7334 is a valid one.
//	Also, we could omit some leading zeros among four hexadecimal digits and some low - case characters in the address to upper - case ones, 
//	so 2001:db8:85a3 : 0 : 0 : 8A2E : 0370 : 7334 is also a valid IPv6 address(Omit leading zeros and using upper cases).
//	However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity. 
//	For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.
//
//	Besides, extra leading zeros in the IPv6 is also invalid.For example, the address 02001 : 0db8 : 85a3 : 0000 : 0000 : 8a2e : 0370 : 7334 is invalid.
//
//	Note : You may assume there is no extra space or special characters in the input string.
//
//	Example 1 :
//	Input : "172.16.254.1"
//
//	Output : "IPv4"
//
//	Explanation : This is a valid IPv4 address, return "IPv4".
//	Example 2 :
//	Input : "2001:0db8:85a3:0:0:8A2E:0370:7334"
//
//	Output : "IPv6"
//
//	Explanation : This is a valid IPv6 address, return "IPv6".
//	Example 3 :
//	Input : "256.256.256.256"
//
//	Output : "Neither"
//
//	Explanation : This is neither a IPv4 address nor a IPv6 address.
//
//	Written by Zhanran Tang @ 5/4/2017
//
//	Idea: Split input.
//	Complexity: O(n) n-the length of IP

#include <vector>
#include <string>
#include <iostream>

using namespace std;

string validIPAddress(string IP)
{
	int judge = -1;
	vector<string> segments;
	string str = "";
	for (int i = 0; i<IP.length(); i++)
	{
		if (IP[i] == '.')
		{
			if (judge == 1 || str == "")
				return "Neither";
			judge = 0;
			segments.push_back(str);
			str = "";
			continue;
		}
		else if (IP[i] == ':')
		{
			if (judge == 0 || str == "")
				return "Neither";
			judge = 1;
			segments.push_back(str);
			str = "";
			continue;
		}
		str += IP[i];
	}
	segments.push_back(str);
	int sz = segments.size();
	if (judge == 0)
	{
		if (sz != 4)
			return "Neither";
		for (int i = 0; i<sz; i++)
		{
			string s = segments[i];
			int l = s.length();
			if (l<1 || l>3 || (l>1 && s[0] == '0'))
				return "Neither";
			int val = 0;
			for (int k = 0; k<l; k++)
			{
				if (s[k]>'9' || s[k]<'0')
					return "Neither";
				val = 10 * val + (s[k] - 48);
			}
			if (val > 255)
				return "Neither";
		}
		return "IPv4";
	}
	else if (judge == 1)
	{
		if (sz != 8)
			return "Neither";
		for (int i = 0; i<sz; i++)
		{
			string s = segments[i];
			int l = s.length();
			if (l<1 || l>4)
				return "Neither";
			for (int k = 0; k<l; k++)
			{
				if (s[k]<'0' || (s[k]>'9' && s[k]<'A') || (s[k]>'F' && s[k] <'a') || s[k]>'f')
					return "Neither";
			}
		}
		return "IPv6";
	}
	else
		return "Neither";
}

int main()
{
	string ip = "2001:0db8:85a3:0:0:8A2E:0370:7334:";
	cout << validIPAddress(ip) << endl;
	system("pause");
	return 0;
}
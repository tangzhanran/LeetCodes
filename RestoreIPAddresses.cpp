//	93. Restore IP Addresses
//
//	Given a string containing only digits, restore it by returning all possible valid IP address combinations.
//
//	For example :
//	Given "25525511135",
//	return["255.255.11.135", "255.255.111.35"]. (Order does not matter)
//
//	Written by Zhanran Tang @ 5/20/2017
//
//	Ideas: Check each segment recursively.
//	Complexity: 

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<string> checkAddress(string substring, int segment)
{
	vector<string> posibleIP;
	if (segment > 4 || substring.length() == 0)
		return posibleIP;
	if (segment == 4)
	{
		if (substring.length() == 1 || (substring.length() <= 3 && substring[0] != '0' && stoi(substring) <= 255))
			posibleIP.push_back(substring);
		return posibleIP;
	}
	int maxLength = 3;
	if (substring[0] == '0')
		maxLength = 1;
	for (int i = 0; i<maxLength; i++)
	{
		if (i >= substring.length())
			break;
		int num = stoi(substring.substr(0, i + 1));
		if (num > 255 || num < 0)
			continue;
		vector<string> tmp = checkAddress(substring.substr(i + 1), segment + 1);
		for (int j = 0; j<tmp.size(); j++)
		{
			string ip = substring.substr(0, i + 1) + "." + tmp[j];
			posibleIP.push_back(ip);
		}
	}
	return posibleIP;
}

vector<string> restoreIpAddresses(string s)
{
	if (s.length()<4 || s.length()>12)
		return vector<string>();
	return checkAddress(s, 1);
}

int main()
{
	string s = "172162541";
	vector<string> res = restoreIpAddresses(s);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
	system("pause");
	return 0;
}
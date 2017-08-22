//	423. Reconstruct Original Digits from English
//
//	Given a non - empty string containing an out - of - order English representation of digits 0 - 9, output the digits in ascending order.
//
//	Note:
//	Input contains only lowercase English letters.
//	Input is guaranteed to be valid and can be transformed to its original digits.That means invalid inputs such as "abc" or "zerone" are not permitted.
//	Input length is less than 50, 000.
//
//	Example 1 :
//	Input : "owoztneoer"
//	Output : "012"
//
//	Example 2 :
//	Input : "fviefuro"
//	Output : "45"
//
//	Written by Zhanran Tang @ 8/3/2017
//
//	Ideas: Find all 0/2/4/6/8 first as they have unique letters. Then find 1/3/5/7. The reset letters are all 9.
//	Complexity: O(n) in time, O(1) in space.

#include "Header.h"

using namespace std;

string originalDigits(string s)
{
	vector<int> letters(26, 0);
	vector<int> nums(10, 0);
	for (int i = 0; i<s.length(); i++)
		letters[s[i] - 'a']++;
	nums[0] = letters['z' - 'a'];
	nums[2] = letters['w' - 'a'];
	nums[4] = letters['u' - 'a'];
	nums[6] = letters['x' - 'a'];
	nums[8] = letters['g' - 'a'];
	nums[1] = letters['o' - 'a'] - nums[0] - nums[2] - nums[4];
	nums[3] = letters['r' - 'a'] - nums[0] - nums[4];
	nums[5] = letters['f' - 'a'] - nums[4];
	nums[7] = letters['s' - 'a'] - nums[6];
	nums[9] = letters['i' - 'a'] - nums[5] - nums[6] - nums[8];
	string res = "";
	for (int i = 0; i<10; i++)
	{
		for (int j = 0; j<nums[i]; j++)
			res += i + '0';
	}
	return res;
}

int main()
{
	string s = "owoztneoer";
	cout << originalDigits(s) << endl;
	system("pause");
	return 0;
}
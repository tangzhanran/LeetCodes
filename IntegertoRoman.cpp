//	12. Integer to Roman
//
//	Given an integer, convert it to a roman numeral.
//	Input is guaranteed to be within the range from 1 to 3999.
//
//	Written by Zhanran Tang @ 6/27/2017
//
//	Ideas: Store number mapping in hash table.
//	Complexity: O(1) in time and space.

#include "Header.h"

using namespace std;

string intToRoman(int num)
{
	unordered_map<int, string> romanTable;
	romanTable[1] = "I";
	romanTable[2] = "II";
	romanTable[3] = "III";
	romanTable[4] = "IV";
	romanTable[5] = "V";
	romanTable[6] = "VI";
	romanTable[7] = "VII";
	romanTable[8] = "VIII";
	romanTable[9] = "IX";
	romanTable[10] = "X";
	romanTable[40] = "XL";
	romanTable[50] = "L";
	romanTable[90] = "XC";
	romanTable[100] = "C";
	romanTable[400] = "CD";
	romanTable[500] = "D";
	romanTable[900] = "CM";
	romanTable[1000] = "M";
	string res = "";
	int div = 1000;
	while (div > 0)
	{
		if (romanTable.find(num) != romanTable.end())
		{
			res += romanTable[num];
			break;
		}
		int digit = num / div;
		if (digit > 0)
		{
			int tmp = digit * div;
			if (romanTable.find(tmp) != romanTable.end())
				res += romanTable[tmp];
			else
			{
				if (digit > 5)
				{
					res += romanTable[5 * div];
					digit -= 5;
				}
				for (int i = 1; i <= digit; i++)
					res += romanTable[div];
			}
		}
		num = num % div;
		div /= 10;
	}
	return res;
}

int main()
{
	cout << intToRoman(2763) << endl;
	system("pause");
	return 0;
}
//	165. Compare Version Numbers
//
//	Compare two version numbers version1 and version2.
//	If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
//
//	You may assume that the version strings are non - empty and contain only digits and the.character.
//	The.character does not represent a decimal point and is used to separate number sequences.
//	For instance, 2.5 is not "two and a half" or "half way to version three", 
//	it is the fifth second - level revision of the second first - level revision.
//
//	Here is an example of version numbers ordering :
//
//	0.1 < 1.1 < 1.2 < 13.37
//
//	Written by Zhanran Tang @ 5/4/2017
//
//	Ideas:	Straight forward.
//	Complexity:	O(n) n - min(length(v1),length(v2)) 

#include <string>
#include <iostream>

using namespace std;

int compareVersion(string version1, string version2)
{
	int i = 0, j = 0, l1 = version1.length(), l2 = version2.length();
	int prefix1 = 0, prefix2 = 0;
	while (1)
	{
		if (i >= l1 && j >= l2)
			return 0;
		while (i < l1)
		{
			if (version1[i] != '.')
			{
				prefix1 = 10 * prefix1 + (version1[i] - 48);
				i++;
			}
			else
			{
				while (i < l1 - 1 && version1[i + 1] == '.')
					i++;
				i++;
				break;
			}
		}
		while (j < l2)
		{
			if (version2[j] != '.')
			{
				prefix2 = 10 * prefix2 + (version2[j] - 48);
				j++;
			}
			else
			{
				while (j < l2 - 1 && version2[j + 1] == '.')
					j++;
				j++;
				break;
			}
		}
		if (prefix1 > prefix2)
			return 1;
		else if (prefix1 < prefix2)
			return -1;
		prefix1 = 0;
		prefix2 = 0;
	}
}

int main()
{
	string version1 = "15.23.1.14.85";
	string version2 = "15.4.3.4.84.6.234";
	cout << compareVersion(version1, version2) << endl;
	system("pause");
	return 0;
}
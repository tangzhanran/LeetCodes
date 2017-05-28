//	60. Permutation Sequence
//
//	The set[1, 2, 3, бн, n] contains a total of n!unique permutations.
//
//	By listing and labeling all of the permutations in order,
//	We get the following sequence(ie, for n = 3) :
//		"123"
//		"132"
//		"213"
//		"231"
//		"312"
//		"321"
//	Given n and k, return the kth permutation sequence.
//
//	Note: Given n will be between 1 and 9 inclusive.
//
//	Written by Zhanran Tang @ 5/23/2017
//
//	Ideas: Separate the string into groups, find permutation recursively
//	Complexity: O(n) in time

#include <string>
#include <iostream>

using namespace std;

string findPermutation(string s, int k)
{
	int l = s.length();
	if (l <= 1)
		return s;
	int numpergroup = 1, c = 2;
	while (c < l)
	{
		numpergroup *= c;
		c++;
	}
	int group = k / numpergroup, offset = k%numpergroup;
	string newstr = s.substr(0, group) + s.substr(group + 1);
	return s[group] + findPermutation(newstr, offset);

}
string getPermutation(int n, int k)
{
	string res = "";
	for (int i = 1; i <= n; i++)
		res += i + 48;
	return findPermutation(res, k-1);
}

int main()
{
	cout << getPermutation(6, 23) << endl;
	system("pause");
	return 0;
}
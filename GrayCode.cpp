//	89. Gray Code
//
//	The gray code is a binary numeral system where two successive values differ in only one bit.
//
//	Given a non - negative integer n representing the total number of bits in the code, print the sequence of gray code.A gray code sequence must begin with 0.
//
//	For example, given n = 2, return[0, 1, 3, 2].Its gray code sequence is :
//
//	00 - 0
//	01 - 1
//	11 - 3
//	10 - 2
//
//	Note :
//		For a given n, a gray code sequence is not uniquely defined.
//		For example, [0, 2, 3, 1] is also a valid gray code sequence according to the above definition.
//		For now, the judge is able to judge based on one instance of gray code sequence.Sorry about that.
//	
//	Written by Zhanran Tang @ 7/9/2017
//
//	Ideas: For each i bits number, do bit or for each number with i+1 bits number with highest bit 1.
//	Complexity: O(2^n) in time and O(1) in space.

#include "Header.h"

using namespace std;

vector<int> grayCode(int n)
{
	vector<int> res;
	res.push_back(0);
	for (int i = 0; i<n; i++)
	{
		int sz = res.size();
		for (int j = sz - 1; j >= 0; j--)
		{
			res.push_back(res[j] | 1 << i);
		}
	}
	return res;
}

int main()
{
	vector<int> res = grayCode(2);
	cout << "[ ";
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << "]" << endl;
	system("pause");
	return 0;
}
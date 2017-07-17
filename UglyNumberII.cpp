//	264. Ugly Number II
//
//	Write a program to find the n - th ugly number.
//
//	Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
//	For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
//
//	Note that 1 is typically treated as an ugly number, and n does not exceed 1690.
//
//	Ideas: The nth ugly number equals to min(ugly[i]*2, ugly[j]*3, ugly[k]*5). Do it in DP
//	Complexity: O(n) in time and space.

#include "Header.h"

using namespace std;

int nthUglyNumber(int n)
{
	vector<int> res;
	res.push_back(1);
	int two = 0, three = 0, five = 0;
	while (res.size() < n)
	{
		res.push_back(min(res[two] * 2, min(res[three] * 3, res[five] * 5)));
		if (res.back() == res[two] * 2)
			two++;
		if (res.back() == res[three] * 3)
			three++;
		if (res.back() == res[five] * 5)
			five++;
	}
	return res.back();
}

int main()
{
	cout << nthUglyNumber(1500) << endl;
	system("pause");
	return 0;
}
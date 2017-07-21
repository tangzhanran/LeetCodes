//	313. Super Ugly Number
//
//	Write a program to find the nth super ugly number.
//
//	Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k.For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.
//
//	Note:
//		(1) 1 is a super ugly number for any given primes.
//		(2) The given numbers in primes are in ascending order.
//		(3) 0 < k ¡Ü 100, 0 < n ¡Ü 106, 0 < primes[i] < 1000.
//		(4) The nth super ugly number is guaranteed to fit in a 32 - bit signed integer.
//
//	Written by Zhanran Tang @ 7/20/2017
//
//	Ideas: Same idea as 264. Ugly Number II. Use 2 vector of size k to store the index and current number.
//	Complexity: O(nk) in time, O(n+k) in space.

#include "Header.h"

using namespace std;

int nthSuperUglyNumber(int n, vector<int>& primes)
{
	vector<int> res(n, INT_MAX);
	res[0] = 1;
	int k = primes.size();
	vector<int> primeindex(k, 0);
	for (int i = 1; i<n; i++)
	{
		for (int j = 0; j<k; j++)
		{
			res[i] = min(res[i], res[primeindex[j]] * primes[j]);
		}
		for (int j = 0; j<k; j++)
		{
			if (res[i] == res[primeindex[j]] * primes[j])
				primeindex[j]++;
		}
	}
	return res.back();
}

int main()
{
	vector<int> primes = { 2,3,5 };
	cout << nthSuperUglyNumber(15, primes) << endl;
	system("pause");
	return 0;
}
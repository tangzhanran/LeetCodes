//	50. Pow(x, n)
//
//	Implement pow(x, n).
//
//	Written by Zhanran Tang @ 5/19/2017
//
//	Ideas: Divide n by 2 until reach 0
//	Complexity: log(n) in time. n-the power parameter

#include <iostream>

using namespace std;

double helper(double x, long long n)
{
	if (n == 0)
		return 1;
	double res = helper(x, n / 2);
	if (n % 2 != 0)
		return x*res*res;
	else
		return res*res;
}

double myPow(double x, int n)
{
	int sign = 1;
	long long longn = n;
	if (longn < 0)
	{
		sign = 0;
		longn = -longn;
	}
	double res = helper(x, longn);
	if (sign == 1)
		return res;
	else
		return 1.0 / res;
}

int main()
{
	double x = 8.88023;
	int n = 3;
	cout << myPow(x, n) << endl;
	system("pause");
	return 0;
}
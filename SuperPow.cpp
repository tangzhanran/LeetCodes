//	372. Super Pow
//
//	Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.
//
//	Example1:
//	a = 2
//	b = [3]
//	Result : 8
//
//	Example2 :
//	a = 2
//	b = [1, 0]
//	Result : 1024
//	
//	Written by Zhanran Tang @ 7/23/2017
//
//	Ideas: (a*b)%k = ((a%k)*(b%k))%k. 
//		Say f(a,b) = (a^b)%k, then f(a,12345) = (a^12345)%k = ((a^12340)*a^5)%k
//					= (((a^1234)^10) * (a^5)) % k
//					= (((a^1234)^10)%k * (a^5)%k) % k = ((((a^1234)%k)^10)%k * (a^5)%k) % k
//					= f(f(a,1234),10)*f(a,5) % k
//
//	Complexity: Polynomial.

#include "Header.h"

using namespace std;

int calMod(int a, int k)
{
	int modval = a % 1337;
	int res = 1;
	for (int i = 1; i <= k; i++)
	{
		res = (res*modval) % 1337;
	}
	return res;
}

int superPow(int a, vector<int>& b)
{
	if (b.empty())
		return 1;
	int last = b.back();
	b.pop_back();
	return calMod(superPow(a, b), 10)*calMod(a, last) % 1337;
}

int main()
{
	vector<int> b = { 1,2,3,4,5,6,7,8 };
	cout << superPow(7, b) << endl;
	system("pause");
	return 0;
}
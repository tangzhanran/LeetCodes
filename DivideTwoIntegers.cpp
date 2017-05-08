//	29. Divide Two Integers
//	Divide two integers without using multiplication, division and mod operator.
//
//	If it is overflow, return MAX_INT.
//
//	Written by Zhanran Tang @ 5/1/2017
//	
//	Idea: Bit Operation.

#include <cmath>
#include <iostream>

using namespace std;

int divide(int dividend, int divisor)
{
	if (divisor == 0 || ((dividend == -2147483648) && (divisor == -1)))
		return INT_MAX;
	long long divd = labs(dividend);
	long long divs = labs(divisor);
	int sign = 1;
	if (((dividend<0) && (divisor>0)) || ((dividend>0) && (divisor<0)))
		sign = -1;
	if (divd == 0 || divd<divs)
		return 0;
	long long shiftres = divs;
	int res = 1;
	while (shiftres <= divd)
	{
		shiftres = shiftres << 1;
		if (shiftres > divd)
		{
			shiftres = shiftres >> 1;
			break;
		}
		res = res << 1;
	}
	int reminder = divd - shiftres;
	return sign*(res + divide(reminder, divs));
}

int main()
{
	int dividend = 1564, divisor = 8;
	cout << divide(dividend, divisor) << endl;
	system("pause");
	return 0;
}
#include "Header.h"

using namespace std;

int helper(int start, int end)
{
	if (start >= end)
		return 0;
	if (start == end - 1)
		return start;
	if (start == end - 2)
		return start + 1;
	int sum = 0;
	for (int i = start; i <= end; i++)
		sum += i;
	int halfsum = sum / 2;
	int rightsum = 0, lend = end;
	while (rightsum <= halfsum)
	{
		rightsum += lend;
		lend--;
	}
	int minval = sum;
	if ((end - lend) % 2 == 0)
		lend++;
	for (int i = lend; i < end; i = i + 2)
	{
		minval = min((i + max(helper(start, i - 1), helper(i + 1, end))), minval);
	}
	return minval;
}
int getMoneyAmount(int n)
{
	return helper(1, n);
}

int main()
{
	cout << getMoneyAmount(100) << endl;
	system("pause");
	return 0;
}
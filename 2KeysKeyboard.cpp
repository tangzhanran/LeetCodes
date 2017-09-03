//	650. 2 Keys Keyboard
//
//	Initially on a notepad only one character 'A' is present.You can perform two operations on this notepad for each step:
//
//	Copy All : You can copy all the characters present on the notepad(partial copy is not allowed).
//	Paste : You can paste the characters which are copied last time.
//	Given a number n.You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted.Output the minimum number of steps to get n 'A'.
//
//	Example 1 :
//	Input : 3
//	Output : 3
//	Explanation :
//	Intitally, we have one character 'A'.
//	In step 1, we use Copy All operation.
//	In step 2, we use Paste operation to get 'AA'.
//	In step 3, we use Paste operation to get 'AAA'.
//
//	Note :
//	1. The n will be in the range[1, 1000].
//
//	Written by Zhanran Tang @ 9/2/2017
//
//	Ideas: n 'A' can be get from res(n/i)+i.
//	Complexity: O(n) in time, O(1) in space.

#include "Header.h"

using namespace std;

int minSteps(int n)
{
	int res = 0;
	for (int i = 2; i <= n; i++)
	{
		while (n%i == 0)
		{
			res += i;
			n /= i;
		}
	}
	return res;
}

int main()
{
	cout << minSteps(9) << endl;
	system("pause");
	return 0;
}